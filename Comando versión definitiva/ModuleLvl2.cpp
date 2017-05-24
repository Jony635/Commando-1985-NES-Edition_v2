#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLvl2.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleAudio.h"
#include "ModuleParticles.h"
#include "ModulePowerUp.h"
#include "ModuleSecretAreas.h"

ModuleLvl2::ModuleLvl2(){
	//stair visible
	stair.PushBack({ 0, 0, 16, 16 });
	stair.loop = false;
	stair.speed = 0.02f;

	//stair not visible
	stairinv.PushBack({ 21, 19, 6, 6 });
	stairinv.loop = false;
	stairinv.speed = 0.02f;

	current_stair1_animation = &stairinv;
	current_stair2_animation = &stairinv;
	current_stair3_animation = &stairinv;
	current_stair4_animation = &stairinv;
	current_stair5_animation = &stairinv;
	current_stair6_animation = &stairinv;
}

ModuleLvl2::~ModuleLvl2(){}

bool ModuleLvl2::Start() {

	LOG("Loading lvl2 scene");

	for (uint i = 0; i < MAX_COLLIDER_DOWNSTAIRS; ++i)
		downstairs[i] = nullptr;

	//Textures
	background = App->textures->Load("Resources/Screens/CommandoArea2.png");//foto del fondo
	items = App->textures->Load("Resources/Animations/Items.png");//foto del fondo

	//Enables & Disables
	App->audio->Enable();
	App->textures->Enable();
	App->player->Enable();
	App->collision->Enable();
	App->particles->Enable();
	App->powerup->Enable();

	//Cameras positions
	App->render->camera.x = App->render->camera.y = 0;


	//Init things
	top = -2880 + SCREEN_HEIGHT;

	//respawn
	if (App->secretareas->actual_room == ROOM2 || App->secretareas->actual_room == ROOM3) {
		App->player->position.y = -1000 + 140;
		App->render->camera.y = -1000;
	}
	if (App->secretareas->actual_room == ROOM4) {
		App->player->position.y = -1500 + 140;
		App->render->camera.y = -1500;
	}
	if (App->secretareas->actual_room == ROOM5) {
		App->player->position.y = -2000 + 140;
		App->render->camera.y = -2000;
	}
	if (App->secretareas->actual_room == ROOM6) {
		App->player->position.y = -2500 + 140;
		App->render->camera.y = -2500;
	}if (checkpointpassed
		&& App->secretareas->actual_room != ROOM4
		&& App->secretareas->actual_room != ROOM5
		&& App->secretareas->actual_room != ROOM6) {
		App->player->position.y = -1470 + 140;
		App->render->camera.y = -1470;
	}

	//Add Enemies
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, (SCREEN_WIDTH / 2) - 7, -(2880 - 2796 - SCREEN_HEIGHT) - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7, -(2880 - 2796 - SCREEN_HEIGHT) - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7, -(2880 - 2796 - SCREEN_HEIGHT) - 200 - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200 - 200 - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200);
	
	//PowerUps
	App->powerup->AddPowerUp(PowerUp_Types::GRENADEx4, 48, -(2880 - 2432 - SCREEN_HEIGHT), false);
	App->powerup->AddPowerUp(PowerUp_Types::BINOCULAR, 216, -(2880 - 1992 - SCREEN_HEIGHT), true);
	App->powerup->AddPowerUp(PowerUp_Types::BULLETPROOF_VEST, 174, -(2880 - 1648 - SCREEN_HEIGHT), true);
	App->powerup->AddPowerUp(PowerUp_Types::GRENADEx4, 32, -(2880 - 1216 - SCREEN_HEIGHT), false);
	App->powerup->AddPowerUp(PowerUp_Types::GRENADEx4, 200, -(2880 - 734 - SCREEN_HEIGHT), false);

	// Colliders ---
	int i = 0;
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 2166 - SCREEN_HEIGHT), 23, 111 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 197, -(2880 - 1687 - SCREEN_HEIGHT), 59, 107 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1558 - SCREEN_HEIGHT), 38, 109 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 213, -(2880 - 1494 - SCREEN_HEIGHT), 43, 108 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1344 - SCREEN_HEIGHT), 99, 85 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 156, -(2880 - 1344 - SCREEN_HEIGHT), 100, 85 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 870 - SCREEN_HEIGHT), 38, 78 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 230, -(2880 - 823 - SCREEN_HEIGHT), 26, 75 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 101, -(2880 - 726 - SCREEN_HEIGHT), 51, 32 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 229, -(2880 - 727 - SCREEN_HEIGHT), 27, 46 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 214, -(2880 - 615 - SCREEN_HEIGHT), 42, 77 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 566 - SCREEN_HEIGHT), 23, 49 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 438 - SCREEN_HEIGHT), 53, 112 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 100, -(2880 - 484 - SCREEN_HEIGHT), 52, 34 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 230, -(2880 - 454 - SCREEN_HEIGHT), 26, 31 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 213, -(2880 - 245 - SCREEN_HEIGHT), 43, 111 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 245 - SCREEN_HEIGHT), 39, 111 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 228, -(2880 - 48 - SCREEN_HEIGHT), 28, 183 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 48 - SCREEN_HEIGHT), 26, 183 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 215, -(2880 - 214 - SCREEN_HEIGHT), 41, 16 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 215, -(2880 - 180 - SCREEN_HEIGHT), 41, 12 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 214, -(2880 - 150 - SCREEN_HEIGHT), 42, 17 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 214, -(2880 - 115 - SCREEN_HEIGHT), 42, 13 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 214, -(2880 - 87 - SCREEN_HEIGHT), 42, 16 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 215, -(2880 - 51 - SCREEN_HEIGHT), 41, 12 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 51 - SCREEN_HEIGHT), 41, 14 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 86 - SCREEN_HEIGHT), 41, 17 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 115 - SCREEN_HEIGHT), 41, 14 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 153 - SCREEN_HEIGHT), 41, 14 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 181 - SCREEN_HEIGHT), 41, 12 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 215 - SCREEN_HEIGHT), 41, 15 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 0 - SCREEN_HEIGHT), 98, 32 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 157, -(2880 - 0 - SCREEN_HEIGHT), 99, 33 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 9, -(2880 - 992 - SCREEN_HEIGHT), 28, 11 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 18, -(2880 - 981 - SCREEN_HEIGHT), 28, 11 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 27, -(2880 - 976 - SCREEN_HEIGHT), 11, 17 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 20, -(2880 - 997 - SCREEN_HEIGHT), 14, 10 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 195, -(2880 - 904 - SCREEN_HEIGHT), 28, 9 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 200, -(2880 - 912 - SCREEN_HEIGHT), 29, 10 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 207, -(2880 - 920 - SCREEN_HEIGHT), 13, 7 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 196, -(2880 - 897 - SCREEN_HEIGHT), 19, 11 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 193, -(2880 - 775 - SCREEN_HEIGHT), 29, 9 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 200, -(2880 - 783 - SCREEN_HEIGHT), 30, 11 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 207, -(2880 - 793 - SCREEN_HEIGHT), 13, 7 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 198, -(2880 - 770 - SCREEN_HEIGHT), 15, 11 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 19, -(2880 - 742 - SCREEN_HEIGHT), 28, 9 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 10, -(2880 - 751 - SCREEN_HEIGHT), 30, 9 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 18, -(2880 - 759 - SCREEN_HEIGHT), 16, 8 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 26, -(2880 - 736 - SCREEN_HEIGHT), 15, 10 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 38, -(2880 - 628 - SCREEN_HEIGHT), 25, 11 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 27, -(2880 - 640 - SCREEN_HEIGHT), 30, 9 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 35, -(2880 - 647 - SCREEN_HEIGHT), 15, 8 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 42, -(2880 - 624 - SCREEN_HEIGHT), 14, 13 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 209, -(2880 - 501 - SCREEN_HEIGHT), 26, 11 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 218, -(2880 - 512 - SCREEN_HEIGHT), 27, 10 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 223, -(2880 - 520 - SCREEN_HEIGHT), 13, 7 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 215, -(2880 - 497 - SCREEN_HEIGHT), 14, 7 }, COLLIDER_WALL);
	//wall[i++] = App->collision->AddCollider({ 42, -(2880 - 624 - SCREEN_HEIGHT), 14, 13 }, COLLIDER_WALL);
	//wall[i++] = App->collision->AddCollider({ 209, -(2880 - 501 - SCREEN_HEIGHT), 26, 11 }, COLLIDER_WALL);
	//wall[i++] = App->collision->AddCollider({ 218, -(2880 - 512 - SCREEN_HEIGHT), 27, 10 }, COLLIDER_WALL);

	//downstairs colliders
	int j = 0;
	downstairs[j++] = App->collision->AddCollider({ 242, -(2880 - 2632 - SCREEN_HEIGHT), 8, 8 }, COLLIDER_DOWNSTAIRS);
	downstairs[j++] = App->collision->AddCollider({ 130, -(2880 - 1544 - SCREEN_HEIGHT), 8, 8 }, COLLIDER_DOWNSTAIRS);
	downstairs[j++] = App->collision->AddCollider({ 217, -(2880 - 1426 - SCREEN_HEIGHT), 8, 8 }, COLLIDER_DOWNSTAIRS);
	downstairs[j++] = App->collision->AddCollider({ 104, -(2880 - 1065 - SCREEN_HEIGHT), 8, 8 }, COLLIDER_DOWNSTAIRS);
	downstairs[j++] = App->collision->AddCollider({ 88, -(2880 - 743 - SCREEN_HEIGHT), 8, 8 }, COLLIDER_DOWNSTAIRS);
	downstairs[j++] = App->collision->AddCollider({ 128, -(2880 - 528 - SCREEN_HEIGHT), 8, 8 }, COLLIDER_DOWNSTAIRS);
	//Colliders Water

	i = 0;
	water[i++] = App->collision->AddCollider({ 141 + 5, -(2880 - 2388 - SCREEN_HEIGHT), 71 - 5, 10 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 26 + 5, -(2880 - 2404 - SCREEN_HEIGHT), 28 - 5, 10 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 0 + 5, -(2880 - 2339 - SCREEN_HEIGHT), 84 - 5, 11 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 92 + 5, -(2880 - 2276 - SCREEN_HEIGHT), 56 - 5, 10 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 188 + 5, -(2880 - 2292 - SCREEN_HEIGHT), 68 - 5, 10 - 5 }, COLLIDER_WATER);

	water[i++] = App->collision->AddCollider({ 189 + 5, -(2880 - 2211 - SCREEN_HEIGHT), 67 - 5, 12 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 42 + 5, -(2880 - 2099 - SCREEN_HEIGHT), 45 - 5, 12 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 186 + 5, -(2880 - 2003 - SCREEN_HEIGHT), 13 - 5, 11 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 44 + 5, -(2880 - 2003 - SCREEN_HEIGHT), 58 - 5, 12 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 43 + 5, -(2880 - 1874 - SCREEN_HEIGHT), 26 - 5, 13 - 5 }, COLLIDER_WATER);

	water[i++] = App->collision->AddCollider({ 106 + 5, -(2880 - 1843 - SCREEN_HEIGHT), 107 - 5, 12 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 0 + 5, -(2880 - 1763 - SCREEN_HEIGHT), 85 - 5, 12 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 107 + 5, -(2880 - 1523 - SCREEN_HEIGHT), 42 - 5, 12 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 144 + 5, -(2880 - 1053 - SCREEN_HEIGHT), 112 - 5, 126 - 5 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 0 + 5, -(2880 - 1053 - SCREEN_HEIGHT), 64 - 5, 126 - 5 }, COLLIDER_WATER);
	
	return true;
}

update_status ModuleLvl2::Update(){

	if (!App->player->respawn && playsoundlvl2) {
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1, 2 Theme.ogg", true);
		playsoundlvl2 = false;
	}

	//checkpoint
	if (App->player->position.y < -1400) {
		checkpointpassed = true;
	}

	//Render Map
	App->render->Blit(background, 0, -2880 + SCREEN_HEIGHT, NULL);
	App->render->Blit(items, 232, -(2880 - 2632 - SCREEN_HEIGHT), &(current_stair1_animation->GetCurrentFrame()));
	App->render->Blit(items, 120, -(2880 - 1544 - SCREEN_HEIGHT), &(current_stair2_animation->GetCurrentFrame()));
	App->render->Blit(items, 208, -(2880 - 1424 - SCREEN_HEIGHT), &(current_stair3_animation->GetCurrentFrame()));
	App->render->Blit(items, 96, -(2880 - 1065 - SCREEN_HEIGHT), &(current_stair4_animation->GetCurrentFrame()));
	App->render->Blit(items, 80, -(2880 - 743 - SCREEN_HEIGHT), &(current_stair5_animation->GetCurrentFrame()));
	App->render->Blit(items, 120, -(2880 - 528 - SCREEN_HEIGHT), &(current_stair6_animation->GetCurrentFrame()));

	////Fade to black to next lvl
	//if (App->input->keyboard[SDL_SCANCODE_F2]) {
	//	App->fade->FadeToBlack(this, App->endlvl2, 0);
	//}

	return UPDATE_CONTINUE;

}

bool ModuleLvl2::CleanUp(){

	LOG("Unloading lvl2 scene");

	//Disables
	App->particles->Disable();
	App->powerup->Disable();
	App->enemies->Disable();
	App->textures->Disable();
	App->collision->Disable();
	App->audio->Disable();
	App->player->Disable();

	//Unload textures
	App->textures->Unload(background);
	App->textures->Unload(items);

	return true;
}

