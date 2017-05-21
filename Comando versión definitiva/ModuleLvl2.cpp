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
	App->enemies->Enable();

	//Cameras positions
	App->render->camera.x = App->render->camera.y = 0;

	App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1, 2 Theme.ogg", true);

	//Init things
	top = -2880 + SCREEN_HEIGHT;
	current_stair1_animation = &stair;
	current_stair2_animation = &stair;
	current_stair3_animation = &stair;
	current_stair4_animation = &stair;
	current_stair5_animation = &stair;
	current_stair6_animation = &stair;

	//respawn
	if (App->secretareas->actual_room == ROOM2 || App->secretareas->actual_room == ROOM3) {
		App->player->position.y -= 1000;
		App->render->camera.y -= 1000;
	}

	//Add Enemies
	App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200 - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200 - 200 - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, App->player->position.x, App->player->position.y - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200 - 200);
	
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
	downstairs[j++] = App->collision->AddCollider({ 138, -(2880 - 1544 - SCREEN_HEIGHT), 8, 8 }, COLLIDER_DOWNSTAIRS);
	downstairs[j++] = App->collision->AddCollider({ 235, -(2880 - 1426 - SCREEN_HEIGHT), 8, 8 }, COLLIDER_DOWNSTAIRS);

	//Colliders Water

	i = 0;
	water[i++] = App->collision->AddCollider({ 141, -(2880 - 2388 - SCREEN_HEIGHT), 71, 10 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 26, -(2880 - 2404 - SCREEN_HEIGHT), 28, 10 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 0, -(2880 - 2339 - SCREEN_HEIGHT), 84, 11 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 92, -(2880 - 2276 - SCREEN_HEIGHT), 56, 10 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 188, -(2880 - 2292 - SCREEN_HEIGHT), 68, 10 }, COLLIDER_WATER);

	water[i++] = App->collision->AddCollider({ 189, -(2880 - 2211 - SCREEN_HEIGHT), 67, 12 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 42, -(2880 - 2099 - SCREEN_HEIGHT), 45, 12 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 186, -(2880 - 2003 - SCREEN_HEIGHT), 13, 11 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 44, -(2880 - 2003 - SCREEN_HEIGHT), 58, 12 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 43, -(2880 - 1874 - SCREEN_HEIGHT), 26, 13 }, COLLIDER_WATER);

	water[i++] = App->collision->AddCollider({ 106, -(2880 - 1843 - SCREEN_HEIGHT), 107, 12 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 0, -(2880 - 1763 - SCREEN_HEIGHT), 85, 12 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 107, -(2880 - 1523 - SCREEN_HEIGHT), 42, 12 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 144, -(2880 - 1053 - SCREEN_HEIGHT), 112, 126 }, COLLIDER_WATER);
	water[i++] = App->collision->AddCollider({ 0, -(2880 - 1053 - SCREEN_HEIGHT), 64, 126 }, COLLIDER_WATER);
	
	return true;
}

update_status ModuleLvl2::Update(){

	//Render Map
	App->render->Blit(background, 0, -2880 + SCREEN_HEIGHT, NULL);
	App->render->Blit(items, 232, -(2880 - 2632 - SCREEN_HEIGHT), &(current_stair1_animation->GetCurrentFrame()));
	App->render->Blit(items, 120, -(2880 - 1544 - SCREEN_HEIGHT), &(current_stair2_animation->GetCurrentFrame()));
	App->render->Blit(items, 208, -(2880 - 1424 - SCREEN_HEIGHT), &(current_stair3_animation->GetCurrentFrame()));

	////Fade to black to next lvl
	//if (App->input->keyboard[SDL_SCANCODE_F2]) {
	//	App->fade->FadeToBlack(this, App->endlvl2, 0);
	//}

	return UPDATE_CONTINUE;

}

bool ModuleLvl2::CleanUp(){

	LOG("Unloading lvl2 scene");

	//Disables
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

