#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_WhiteGuard.h"
#include "Enemy_Bosslvl1.h"
#include "Enemy_CapturerGuard.h"
#include "Enemy_Knife.h"
#include "ModulePlayer.h"
#include "Enemy_BossGrenade.h"

#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("Resources/Sprites/Enemies/All_Enemies.png");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].y > App->render->camera.y - SPAWN_MARGIN)
			{
				LOG("Spawning enemy at %d", queue[i].y);
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.y>App->render->camera.y + SCREEN_HEIGHT + SPAWN_MARGIN)
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::WHITEGUARD:
			enemies[i] = new Enemy_WhiteGuard(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::WHITEGUARD;
			enemies[i]->collider->enemytype = ENEMY_TYPES::WHITEGUARD;
			break;
		case ENEMY_TYPES::CAPTURERGUARD:
			enemies[i] = new Enemy_CapturerGuard(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::CAPTURERGUARD;
			enemies[i]->collider->enemytype = ENEMY_TYPES::CAPTURERGUARD;
			break;
		case ENEMY_TYPES::BOSSLVL1:
			enemies[i] = new Enemy_Bosslvl1(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BOSSLVL1;
			enemies[i]->collider->enemytype = ENEMY_TYPES::BOSSLVL1;
			break;
		case ENEMY_TYPES::KNIFE:
			enemies[i] = new Enemy_Knife(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::KNIFE;
			enemies[i]->collider->enemytype = ENEMY_TYPES::KNIFE;
			break;
		case ENEMY_TYPES::BOSSGRENADE:
			enemies[i] = new Enemy_BossGrenade(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BOSSGRENADE;
			enemies[i]->collider->enemytype = ENEMY_TYPES::BOSSGRENADE;
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			if ((c2->type == COLLIDER_PLAYER_SHOT || c2->type == COLLIDER_PLAYER_GRENADE_EXPL) && c1->enemytype != BOSSGRENADE)
			{
				if (c1->enemytype != ENEMY_TYPES::BOSSLVL1)
				{
					App->player->score += 150;
					App->particles->AddParticle(App->particles->die_Grey, enemies[i]->position.x, enemies[i]->position.y, COLLIDER_DIE);
					delete enemies[i];
					enemies[i] = nullptr;
				}
				else
				{
					App->player->score += 2000;
					
					enemies[i]->OnCollision(c2);
					delete enemies[i];
					enemies[i] = nullptr;
				}
				break;
			}
			else if (c1->enemytype == BOSSGRENADE && c2->type == COLLIDER_PLAYER_GRENADE_EXPL)
			{
				App->player->score += 300;
				App->particles->AddParticle(App->particles->die_Green, enemies[i]->position.x, enemies[i]->position.y, COLLIDER_DIE);
				delete enemies[i];
				enemies[i] = nullptr;

			}
			if ((c2->type == COLLIDER_WALL || c2->type == COLLIDER_WATER || c2->type == COLLIDER_ANTIBULLET) && c1->enemytype != ENEMY_TYPES::BOSSLVL1)
			{



				if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
					&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
					&& (c2->rect.y + c2->rect.h) - c1->rect.y == 1
					&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1)
				{
					enemies[i]->path.ResetlastStep();
					enemies[i]->path.Reset();
					enemies[i]->ColPathDown();
				}
				else if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
					&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
					&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
					&& (c1->rect.y + c1->rect.h) - c2->rect.y == 1)
				{
					enemies[i]->path.ResetlastStep();
					enemies[i]->path.Reset();
					enemies[i]->ColPathUp();
				}
				else if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
					&& (c2->rect.x + c2->rect.w) - c1->rect.x == 1
					&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
					&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1)
				{
					enemies[i]->path.ResetlastStep();
					enemies[i]->path.Reset();
					enemies[i]->ColPathRight();
				}
				else if ((c1->rect.x + c1->rect.w) - c2->rect.x == 1
					&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
					&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
					&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1)
				{
					enemies[i]->path.ResetlastStep();
					enemies[i]->path.Reset();
					enemies[i]->ColPathLeft();
				}
				break;
			}
		}
	}
}