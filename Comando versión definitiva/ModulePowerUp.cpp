#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModulePowerUp.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"

ModulePowerUp::ModulePowerUp()
{
	for (uint i = 0; i < MAX_POWERUP; ++i)
	{
		powerups[i] = nullptr;
	}

	binocular.PushBack({ 155,70,16,16 });
	binocular.PushBack({ 179,70,16,16 });
	binocular.PushBack({ 155,93,16,16 });
	binocular.PushBack({ 178,93,16,16 });
	binocular.speed = 0.08f;

	bulletproof_vest.PushBack({ 54,71,14,14 });
	bulletproof_vest.PushBack({ 77,71,14,14 });
	bulletproof_vest.PushBack({ 54,93,14,14 });
	bulletproof_vest.PushBack({ 77,93,14,14 });
	bulletproof_vest.speed = 0.08f;

	gasoline.PushBack({ 151,27,12,15 });
	gasoline.PushBack({ 175,27,12,15 });
	gasoline.PushBack({ 152,50,12,15 });
	gasoline.PushBack({ 176,50,12,15 });
	gasoline.speed = 0.08f;

	grenadex4.PushBack({ 99,76,23,15 });
	grenadex4.PushBack({ 125,76,23,15 });
	grenadex4.PushBack({ 99,93,23,15 });
	grenadex4.PushBack({ 125,93,23,15 });
	grenadex4.speed = 0.08f;

	grenadex5.PushBack({ 126,3,21,16 });
	grenadex5.PushBack({ 102,3,21,16 });	
	grenadex5.PushBack({ 150,3,21,16 });
	grenadex5.PushBack({ 175,4,21,16 });
	grenadex5.speed = 0.08f;

	medal.PushBack({ 101,27,16,10 });
	medal.PushBack({ 124,27,16,10 });
	medal.PushBack({ 101,55,16,10 });
	medal.PushBack({ 124,54,16,10 });
	medal.speed = 0.08f;

	medal_of_honor.PushBack({ 35,0,10,16 });
	medal_of_honor.PushBack({ 47,0,10,16 });
	medal_of_honor.PushBack({ 59,0,10,16 });
	medal_of_honor.PushBack({ 71,0,10,16 });
	medal_of_honor.speed = 0.08f;

	barrel.PushBack({ 203,73,12,16 });
	barrel.PushBack({ 228,73,12,16 });
	barrel.PushBack({ 204,96,12,16 });
	barrel.PushBack({ 228,96,12,16 });
	barrel.speed = 0.08f;

	bag.PushBack({ 6,23,12,15 });
	bag.PushBack({ 32,23,12,15 });
	bag.PushBack({ 6,46,12,15 });
	bag.PushBack({ 33,47,12,15 });
	bag.speed = 0.08f;

	ally_captured.PushBack({ 176,122,16,22 });
	ally_captured.PushBack({ 193,122,16,22 });
	ally_captured.speed = 0.02f;

}

ModulePowerUp::~ModulePowerUp()
{}

// Load assets
bool ModulePowerUp::Start()
{
	LOG("Loading power ups");
	graphics = App->textures->Load("Resources/Animations/Items.png");

	return true;
}

// Unload assets
bool ModulePowerUp::CleanUp()
{
	LOG("Unloading power ups");
	App->textures->Unload(graphics);

	// Unload fx

	for (uint i = 0; i < MAX_POWERUP; ++i)
	{
		if (powerups[i] != nullptr)
		{
			delete powerups[i];
			powerups[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModulePowerUp::Update()
{
	for (uint i = 0; i < MAX_POWERUP; ++i)
	{
		if (powerups[i] != nullptr && !powerups[i]->hidden)
		{
			if (powerups[i]->type == PowerUp_Types::BINOCULAR)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &binocular.GetCurrentFrame());
			}
			else if (powerups[i]->type == PowerUp_Types::BULLETPROOF_VEST)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &bulletproof_vest.GetCurrentFrame());
			}
			else if (powerups[i]->type == PowerUp_Types::GASOLINE)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &gasoline.GetCurrentFrame());
			}
			else if (powerups[i]->type == PowerUp_Types::GRENADEx4)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &grenadex4.GetCurrentFrame());
			}
			else if (powerups[i]->type == PowerUp_Types::GRENADEx5)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &grenadex5.GetCurrentFrame());
			}
			else if (powerups[i]->type == PowerUp_Types::MEDAL_OF_HONOR)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &medal_of_honor.GetCurrentFrame());
			}
			else if (powerups[i]->type == PowerUp_Types::MEDAL)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &medal.GetCurrentFrame());
			}
			else if (powerups[i]->type == PowerUp_Types::BARREL)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &barrel.GetCurrentFrame());
			}
			else if (powerups[i]->type == PowerUp_Types::BAG)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &bag.GetCurrentFrame());
			}
			else if (powerups[i]->type == PowerUp_Types::ALLY_CAPTURED)
			{
				App->render->Blit(graphics, powerups[i]->position.x, powerups[i]->position.y, &ally_captured.GetCurrentFrame());
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModulePowerUp::AddPowerUp(const PowerUp_Types type, int x, int y, bool hidden)
{
	for (uint i = 0; i < MAX_POWERUP; ++i)
	{
		if (powerups[i] == nullptr)
		{
			PowerUp* powerup = new PowerUp();
			SDL_Rect col;
			col.x = x;
			col.y = y;
			switch(type)
			{
			case PowerUp_Types::BINOCULAR:
				col.w = 16;
				col.h = 16;
				break;
			case PowerUp_Types::BULLETPROOF_VEST:
				col.w = 14;
				col.h = 14;
				break;
			case PowerUp_Types::GASOLINE:
				col.w = 12;
				col.h = 15;
				break;
			case PowerUp_Types::GRENADEx4:
				col.w = 23;
				col.h = 15;
				break;
			case PowerUp_Types::GRENADEx5:
				col.w = 21;
				col.h = 16;
				break;
			case PowerUp_Types::MEDAL_OF_HONOR:
				col.w = 10;
				col.h = 16;
				break;
			case PowerUp_Types::MEDAL:
				col.w = 16;
				col.h = 10;
				break;
			case PowerUp_Types::BARREL:
				col.w = 12;
				col.h = 16;
				break;
			case PowerUp_Types::BAG:
				col.w = 12;
				col.h = 15;
				break;
			case PowerUp_Types::ALLY_CAPTURED:
				col.w = 16;
				col.h = 22;
				break;
			}
			powerup->position.x = x;
			powerup->position.y = y;
			powerup->collider = App->collision->AddCollider(col, COLLIDER_POWERUP, this);
			powerup->collider->poweruptype = type;
			powerup->type = type;
			powerup->hidden = hidden;
			powerups[i] = powerup;
			break;
		}
	}
}

void ModulePowerUp::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_POWERUP; ++i)
	{
		// Always destroy particles that collide
		if (powerups[i] != nullptr && powerups[i]->collider == c1)
		{
			if (c2->type == COLLIDER_PLAYER && !powerups[i]->hidden)
			{
				App->audio->PlaySound("Resources/Audio/Sound Effects/Grenades_Powerups Taken.wav");
				switch (c1->poweruptype)
				{
				case PowerUp_Types::BINOCULAR:
					App->player->PlayerPowerUps[PowerUp_Types::BINOCULAR] = true;
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				case PowerUp_Types::BULLETPROOF_VEST:
					App->player->godmode = true;
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				case PowerUp_Types::GASOLINE:
					App->player->score += 1000;
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				case PowerUp_Types::GRENADEx4:
					App->player->granade_counter += 4;
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				case PowerUp_Types::GRENADEx5:
					App->player->granade_counter += 5;
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				case PowerUp_Types::MEDAL_OF_HONOR:
					App->player->score += 1000;
					App->player->live_counter += 1;
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				case PowerUp_Types::MEDAL:
					App->player->score += 10000;
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				case PowerUp_Types::BARREL:
					App->player->score += 1000;
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				case PowerUp_Types::BAG:
					App->player->score += 1000;
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				case PowerUp_Types::ALLY_CAPTURED:
					App->player->score += 1000;
					App->enemies->AddEnemy(ENEMY_TYPES::RUNNER, powerups[i]->position.x, powerups[i]->position.y);
					c1->to_delete = true;
					delete powerups[i];
					powerups[i] = nullptr;
					break;
				}
			}
			else if (c2->type == COLLIDER_PLAYER_GRENADE_EXPL && powerups[i]->hidden)
			{
				powerups[i]->hidden = false;
			}
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

PowerUp::PowerUp()
{
	position.SetToZero();
	type = PowerUp_Types::POWERUP_NO_TYPE;
}

PowerUp::~PowerUp()
{
	if (collider != nullptr)
		App->collision->EraseCollider(collider);
}