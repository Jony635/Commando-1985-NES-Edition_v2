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
#include "ModuleLvl2.h"
#include "ModuleSecretAreas.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	bullet.anim.PushBack({ 41, 18, 5, 5 });

	grenade_explodes.anim.PushBack({ 43,63,15,14 });
	grenade_explodes.anim.PushBack({ 3, 58, 25, 24 });
	grenade_explodes.anim.speed = 0.07f;
	grenade_explodes.anim.loop = false;

	MEGA_grenade_explodes.anim.PushBack({ 64,38,28,23 });
	MEGA_grenade_explodes.anim.PushBack({ 122, 37, 44, 40 });
	MEGA_grenade_explodes.anim.speed = 0.07f;
	MEGA_grenade_explodes.anim.loop = false;

	grenade.anim.PushBack({ 103, 69, 5, 6 });
	grenade.anim.PushBack({ 79,69,5,6 });
	grenade.anim.speed = 0.09f;
	grenade.anim.loop = true;

	die_Green.anim.PushBack({ 102, 5, 16, 27 });
	die_Green.anim.PushBack({ 119, 5, 16, 27 });
	die_Green.anim.PushBack({ 138, 13, 10, 8 });
	die_Green.anim.speed = 0.07f;
	die_Green.anim.loop = false;
	die_Green.life = 1000;

	die_Grey.anim.PushBack({ 59, 5, 16, 26 });
	die_Grey.anim.PushBack({ 77, 5, 16, 26 });
	die_Grey.anim.PushBack({ 5, 90, 10, 8 });
	die_Grey.anim.speed = 0.07f;
	die_Grey.anim.loop = false;
	die_Grey.life = 1000;

	mega_bullet.anim.PushBack({ 11, 17, 6, 6 });

	Rocket.anim.PushBack({ 11, 33, 8, 11 });
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
			// play the audio SFX
			if (p->collider->type == COLLIDER_PLAYER_SHOT && !p->fx_played)
			{
				App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
				p->fx_played = true;
			}
			else if (p->collider->type == COLLIDER_PLAYER_GRENADE && !p->fx_played && (SDL_GetTicks() - p->born) > p->life / 1.1)
			{
				App->audio->PlaySound("Resources/Audio/Sound Effects/Stairs Down Appeared.wav");
				p->fx_played = true;
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
			if (c1->type == COLLIDER_PLAYER_GRENADE_EXPL&&c2->type == COLLIDER_DOWNSTAIRS) {

				if (App->player->position.y > -(2880 - 2500 - SCREEN_HEIGHT)) {
					App->lvl2->current_stair1_animation = &App->lvl2->stair;
				}
				else if (App->player->position.y < -(2880 - 2500 - SCREEN_HEIGHT) && App->player->position.y > -(2880 - 1544 - SCREEN_HEIGHT)) {
					App->lvl2->current_stair2_animation = &App->lvl2->stair;
				}
				else if (App->player->position.y < -(2880 - 1544 - SCREEN_HEIGHT) && App->player->position.y > -(2880 - 1200 - SCREEN_HEIGHT)) {
					App->lvl2->current_stair3_animation = &App->lvl2->stair;
				}
				else if (App->player->position.y < -(2880 - 1200 - SCREEN_HEIGHT) && App->player->position.y > -(2880 - 1000 - SCREEN_HEIGHT)) {
					App->lvl2->current_stair4_animation = &App->lvl2->stair;
				}
				else if (App->player->position.y < -(2880 - 1000 - SCREEN_HEIGHT) && App->player->position.y > -(2880 - 735 - SCREEN_HEIGHT)) {
					App->lvl2->current_stair5_animation = &App->lvl2->stair;
				}
				else if (App->player->position.y < -(2880 - 735 - SCREEN_HEIGHT) && App->player->position.y > -(2880 - SCREEN_HEIGHT)) {
					App->lvl2->current_stair6_animation = &App->lvl2->stair;
				}



			}
			if (c1->type == COLLIDER_PLAYER_GRENADE_EXPL&&c2->type == COLLIDER_UPSTAIRS) {
				if (App->secretareas->actual_room == ROOM3) {
					App->secretareas->ystair = &App->secretareas->yellowstair;
				}
			}
			if (c1->type != COLLIDER_PLAYER_GRENADE_EXPL && c1->type != COLLIDER_PLAYER_GRENADE && c1->type != COLLIDER_ENEMY_GRENADE_EXPL && c1->type != COLLIDER_ENEMY_GRENADE && c1->type != COLLIDER_DIE)
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
				if (!App->player->PlayerPowerUps[PowerUp_Types::HANDGRANADE])
				{
					App->particles->grenade_explodes.life = 1000;
					App->particles->AddParticle(App->particles->grenade_explodes, this->position.x, this->position.y, COLLIDER_PLAYER_GRENADE_EXPL);
				}
				else
				{
					App->particles->MEGA_grenade_explodes.life = 1000;
					App->particles->AddParticle(App->particles->MEGA_grenade_explodes, this->position.x, this->position.y, COLLIDER_PLAYER_GRENADE_EXPL);
				}
			}
			else if (this->collider->type == COLLIDER_ENEMY_GRENADE)
			{

				App->particles->grenade_explodes.life = 1000;
				App->particles->AddParticle(App->particles->grenade_explodes, this->position.x, this->position.y, COLLIDER_PLAYER_GRENADE_EXPL);

			}
		}
	}
	else
		if(anim.Finished())
			ret = false;

	if (this->collider->type != COLLIDER_PLAYER_GRENADE && this->collider->type != COLLIDER_ENEMY_GRENADE)
	{
		position.x += speed.x;
		position.y += speed.y;
	}
	else if (this->collider->type == COLLIDER_PLAYER_GRENADE || this->collider->type == COLLIDER_ENEMY_GRENADE)
	{
		if ((SDL_GetTicks() - born) > life / 1.1)
		{
			position.x -= speed.x / 2;
			position.y -= speed.y / 2;
		}
		else
		{
			position.x += speed.x;
			position.y += speed.y;
		}
	}
	else if (this->collider->type == COLLIDER_DIE)
	{
		position.x += 0;
		position.y += 0;
	}
	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

