#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleLvl2.h"
#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Resources/Sprites/common bullet.png");

	// Explosion particle
	die.anim.PushBack({274, 296, 33, 30});
	die.anim.PushBack({313, 296, 33, 30});
	die.anim.PushBack({346, 296, 33, 30});
	die.anim.loop = false;
	die.anim.speed = 0.3f;

	bullet.anim.PushBack({0, 0, 5, 5});
	
	


	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

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
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if(p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if(collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
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
			if (c2->type == COLLIDER_WALL || c2->type==COLLIDER_ENEMY || c2->type==COLLIDER_ANTIBULLET)
			{
				delete active[i];
				active[i] = nullptr;
				break;
			}
			
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
		if((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if(anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

