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
		App->player->position.y = -1470 + 140;
		App->render->camera.y = -1470;
	}
	if (App->secretareas->actual_room == ROOM5 || App->secretareas->actual_room == ROOM6) {
		App->player->position.y = -2000 + 140;
		App->render->camera.y = -2000;
	}if (checkpointpassed
		&& App->secretareas->actual_room != ROOM4
		&& App->secretareas->actual_room != ROOM5
		&& App->secretareas->actual_room != ROOM6) {
		App->player->position.y = -1470 + 140;
		App->render->camera.y = -1470;
	}

	//Add Enemies
	//App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200);
	
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 113, -(2880 - 35 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 59, -(2880 - 298 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 104, -(2880 - 361 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 152, -(2880 - 359 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 184, -(2880 - 296 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 48, -(2880 - 2778 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 191, -(2880 - 2776 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 49, -(2880 - 2552 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 175, -(2880 - 2445 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 105, -(2880 - 2206 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 195, -(2880 - 1912 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 114, -(2880 - 1636 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 189, -(2880 - 1212 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 96, -(2880 - 1021 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 152, -(2880 - 917 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 68, -(2880 - 584 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 165, -(2880 - 284 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 68, -(2880 - 584 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 110, -(2880 - 105 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 46, -(2880 - 2382 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 46, -(2880 - 1953 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 83, -(2880 - 331 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 114, -(2880 - 2650 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 114, -(2880 - 2086 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 114, -(2880 - 1454 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 117, -(2880 - 2707 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 120, -(2880 - 2510 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 142, -(2880 - 2084 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 122, -(2880 - 2908 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 103, -(2880 - 1253 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 105, -(2880 - 849 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 116, -(2880 - 606 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 113, -(2880 - 386 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 109, -(2880 - 155 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 120, -(2880 - 2323 - SCREEN_HEIGHT), "pathcenter");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 90, -(2880 - 1494 - SCREEN_HEIGHT), "pathcenter");

	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 11, -(2880 - 2664 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 23, -(2880 - 2450 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 45, -(2880 - 2134 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 58, -(2880 - 1592 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 70, -(2880 - 450 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 51, -(2880 - 80 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 46, -(2880 - 2252 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 61, -(2880 - 2045 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 44, -(2880 - 1714 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 52, -(2880 - 1472 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 67, -(2880 - 823 - SCREEN_HEIGHT), "pathleft");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 68, -(2880 - 226 - SCREEN_HEIGHT), "pathleft");

	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 134, -(2880 - 2582 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 211, -(2880 - 2509 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 224, -(2880 - 2329 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 220, -(2880 - 2034 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 155, -(2880 - 1610 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 185, -(2880 - 708 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 183, -(2880 - 79 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 211, -(2880 - 2242 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 164, -(2880 - 845 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 171, -(2880 - 561 - SCREEN_HEIGHT), "pathright");
	App->enemies->AddEnemy(ENEMY_TYPES::PATHWHITEGUARD, 161, -(2880 - 235 - SCREEN_HEIGHT), "pathright");

	App->enemies->AddEnemy(ENEMY_TYPES::CAR, 117, -(2880 - 2605 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::TRUCK, 260, -(2880 - 2698 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::MOTORBIKE, 260, -(2880 - 2229 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::MOTORBIKE, -50, -(2880 - 2117 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 42, -(2880 - 2398 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 153, -(2880 - 2382 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 187, -(2880 - 2382 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 56, -(2880 - 2334 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 212, -(2880 - 2286 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 123, -(2880 - 2270 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 233, -(2880 - 2206 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 197, -(2880 - 2206 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 58, -(2880 - 2094 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 67, -(2880 - 1998 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 55, -(2880 - 1870 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 124, -(2880 - 1838 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 156, -(2880 - 1838 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 189, -(2880 - 1838 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 42, -(2880 - 1758 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::HOLE, 120, -(2880 - 1518 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::ROCKET, 42, -(2880 - 1195 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::ROCKET, 89, -(2880 - 1243 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::ROCKET, 20, -(2880 - 1282 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::BOSSLVL1, 117, -(2880 - 88 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::BUNKER, 0, -(2880 - 977 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BUNKER, 218, -(2880 - 921 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BUNKER, 0, -(2880 - 737 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BUNKER, 0, -(2880 - 643 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BUNKER, 218, -(2880 - 503 - SCREEN_HEIGHT));

	//PowerUps
	if (!App->powerups_taken[pu_taken_lvl2::granade1]) {
		App->powerup->AddPowerUp(PowerUp_Types::GRENADEx4, 48, -(2880 - 2432 - SCREEN_HEIGHT), false, "granade1");
	}
	if (!App->powerups_taken[pu_taken_lvl2::binocular]) {
		App->powerup->AddPowerUp(PowerUp_Types::BINOCULAR, 216, -(2880 - 1992 - SCREEN_HEIGHT), true, "binocular");
	}
	if (!App->powerups_taken[pu_taken_lvl2::godmode]) {
		App->powerup->AddPowerUp(PowerUp_Types::BULLETPROOF_VEST, 174, -(2880 - 1648 - SCREEN_HEIGHT), true, "godmode");
	}
	if (!App->powerups_taken[pu_taken_lvl2::granade2]) {
		App->powerup->AddPowerUp(PowerUp_Types::GRENADEx4, 32, -(2880 - 1216 - SCREEN_HEIGHT), false, "granade2");
	}
	if (!App->powerups_taken[pu_taken_lvl2::granade3]) {
		App->powerup->AddPowerUp(PowerUp_Types::GRENADEx4, 200, -(2880 - 734 - SCREEN_HEIGHT), false, "granade3");
	}
	if (!App->powerups_taken[pu_taken_lvl2::granade4]) {
		App->powerup->AddPowerUp(PowerUp_Types::GRENADEx4, 39, -(2880 - 71 - SCREEN_HEIGHT), false, "granade4");
	}
	if (!App->powerups_taken[pu_taken_lvl2::ally1]) {
		App->powerup->AddPowerUp(PowerUp_Types::ALLY_CAPTURED, 216, -(2880 - 869 - SCREEN_HEIGHT), false, "ally1");
	}
	if (!App->powerups_taken[pu_taken_lvl2::ally2]) {
		App->powerup->AddPowerUp(PowerUp_Types::ALLY_CAPTURED, 0, -(2880 - 709 - SCREEN_HEIGHT), false, "ally2");
		App->powerups_taken[pu_taken_lvl2::ally2] = true;
	}
	// Colliders ---
	int i = 0;
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 2166 - SCREEN_HEIGHT), 23, 111 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 197, -(2880 - 1687 - SCREEN_HEIGHT), 59, 107 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1558 - SCREEN_HEIGHT), 38, 109 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 213, -(2880 - 1494 - SCREEN_HEIGHT), 43, 108 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1359 - SCREEN_HEIGHT), 100, 67 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 156, -(2880 - 1359 - SCREEN_HEIGHT), 100, 68 }, COLLIDER_WALL);
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
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 996 - SCREEN_HEIGHT), 28, 14 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 11, -(2880 - 985 - SCREEN_HEIGHT), 27, 10 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 228, -(2880 - 939 - SCREEN_HEIGHT), 28, 14 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 218, -(2880 - 928 - SCREEN_HEIGHT), 27, 12 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 755 - SCREEN_HEIGHT), 27, 14 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 12, -(2880 - 744 - SCREEN_HEIGHT), 26, 12 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 0, -(2880 - 660 - SCREEN_HEIGHT), 29, 16 }, COLLIDER_WALL);

	wall[i++] = App->collision->AddCollider({ 12, -(2880 - 650 - SCREEN_HEIGHT), 26, 12 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 226, -(2880 - 521 - SCREEN_HEIGHT), 30, 14 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 218, -(2880 - 511 - SCREEN_HEIGHT), 28, 11 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 95, -(2880 - 0 - SCREEN_HEIGHT), 6, 49 }, COLLIDER_WALL);
	wall[i++] = App->collision->AddCollider({ 155, -(2880 - 0 - SCREEN_HEIGHT), 6, 49 }, COLLIDER_WALL);


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
	water[i++] = App->collision->AddCollider({ 0, -(2880 - 1053 - SCREEN_HEIGHT), 64 - 5, 126 - 5 }, COLLIDER_WATER);

	//Colliders antibullets y antienemys

	anti_enemy[i++] = App->collision->AddCollider({ 144 + 5, -(2880 - 1053 - SCREEN_HEIGHT), 112 - 5, 126 - 5 }, COLLIDER_ANTIENEMY);
	anti_enemy[i++] = App->collision->AddCollider({ 0, -(2880 - 1053 - SCREEN_HEIGHT), 64 - 5, 126 - 5 }, COLLIDER_ANTIENEMY);

	anti_bullet[i++] = App->collision->AddCollider({ 0, -(2880 - 1344 - SCREEN_HEIGHT), 99, 82 }, COLLIDER_ANTIBULLET);
	anti_bullet[i++] = App->collision->AddCollider({ 157, -(2880 - 1344 - SCREEN_HEIGHT), 99, 82 }, COLLIDER_ANTIBULLET);
	anti_bullet[i++] = App->collision->AddCollider({ 142, -(2880 - 1343 - SCREEN_HEIGHT), 20, 66 }, COLLIDER_ANTIBULLET);
	anti_bullet[i++] = App->collision->AddCollider({ 92, -(2880 - 1343 - SCREEN_HEIGHT), 20, 66 }, COLLIDER_ANTIBULLET);
	
	return true;
}

update_status ModuleLvl2::Update(){

	if (!App->player->respawn && playsoundlvl2 && !App->player->win) {
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

