#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_timer.h"
#include "ModulePlayer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	bullet.anim.PushBack({ 41, 18, 5, 5 });

	grenade_explodes.anim.PushBack({ 43,63,15,14 });
	grenade_explodes.anim.PushBack({ 3, 58, 25, 24 });
	grenade_explodes.anim.speed = 0.07f;
	grenade_explodes.anim.loop = false;

	grenade.anim.PushBack({ 103, 69, 5, 6 });
	grenade.anim.PushBack({ 79,69,5,6 });
	grenade.anim.speed = 0.09f;
	grenade.anim.loop = true;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	//graphics = App->textures->Load("Resources/Sprites/Shoots and Explosions/common bullet.png");

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	//App->textures->Unload(graphics);

	// Unload fx

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			App->render->Blit(App->player->graphparticles, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));			
			if(p->fx_played == false)
			{
				App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
				p->fx_played = true;
				// play the audio SFX
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE && collider_type != COLLIDER_PLAYER_GRENADE_EXPL)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			if (collider_type == COLLIDER_PLAYER_GRENADE_EXPL)
			{
				p->collider = App->collision->AddCollider(p->anim.frames[1], collider_type, this);
			}
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if(active[i] != nullptr && active[i]->collider == c1)
		{
			//AddParticle(explosion, active[i]->position.x, active[i]->position.y);
			if (c1->type == COLLIDER_PLAYER_GRENADE)
			{
				App->particles->grenade_explodes.life = 1000;
				App->particles->AddParticle(App->particles->grenade_explodes, c1->rect.x, c1->rect.y, COLLIDER_PLAYER_GRENADE_EXPL);
			}
			if (c1->type != COLLIDER_PLAYER_GRENADE_EXPL)
			{
				delete active[i];
				active[i] = nullptr;
			}
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if(collider != nullptr)
		App->collision->EraseCollider(collider);
}

bool Particle::Update()
{
	bool ret = true;

	if(life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
		{
			ret = false;
			if (this->collider->type == COLLIDER_PLAYER_GRENADE)
			{
				App->particles->grenade_explodes.life = 1000;
				App->particles->AddParticle(App->particles->grenade_explodes, this->position.x, this->position.y, COLLIDER_PLAYER_GRENADE_EXPL);
			}
		}
	}
	else
		if(anim.Finished())
			ret = false;

	if (this->collider->type != COLLIDER_PLAYER_GRENADE)
	{
		position.x += speed.x;
		position.y += speed.y;
	}
	else
	{
		position.x += speed.x;
		position.y += speed.y;
	}

	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

