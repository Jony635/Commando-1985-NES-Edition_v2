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
	//App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, (SCREEN_WIDTH / 2) - 7 + 20, -(2880 - 2796 - SCREEN_HEIGHT) - 200);
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 113, -(2880 - 35 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 59, -(2880 - 298 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 104, -(2880 - 361 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 136, -(2880 - 360 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 152, -(2880 - 359 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::BOSSGRENADE, 184, -(2880 - 296 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 237, -(2880 - 2844 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 237, -(2880 - 2787 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 237, -(2880 - 2756 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 238, -(2880 - 2785 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 236, -(2880 - 2757 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 11, -(2880 - 2661 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 15, -(2880 - 2666 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 28, -(2880 - 2692 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 40, -(2880 - 2641 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 225, -(2880 - 2697 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 241, -(2880 - 2675 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 219, -(2880 - 2663 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 61, -(2880 - 2646 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 49, -(2880 - 2625 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 65, -(2880 - 2608 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 200, -(2880 - 2587 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 170, -(2880 - 2548 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 153, -(2880 - 2541 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 134, -(2880 - 2536 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 35, -(2880 - 2518 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 20, -(2880 - 2490 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 223, -(2880 - 2497 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 218, -(2880 - 2472 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 195, -(2880 - 2427 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 150, -(2880 - 2415 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 133, -(2880 - 2441 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 23, -(2880 - 2368 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 55, -(2880 - 2373 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 87, -(2880 - 2377 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 179, -(2880 - 2327 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 202, -(2880 - 2316 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 242, -(2880 - 2352 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 4, -(2880 - 2320 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 28, -(2880 - 2299 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 21, -(2880 - 2292 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 205, -(2880 - 2275 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 187, -(2880 - 2270 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 207, -(2880 - 2251 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 42, -(2880 - 2230 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 50, -(2880 - 2204 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 5, -(2880 - 2146 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 107, -(2880 - 2137 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 147, -(2880 - 2133 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 159, -(2880 - 2163 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 228, -(2880 - 2150 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 179, -(2880 - 2106 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 19, -(2880 - 2036 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 47, -(2880 - 2030 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 204, -(2880 - 2042 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 238, -(2880 - 2044 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 219, -(2880 - 1968 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 236, -(2880 - 1988 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 91, -(2880 - 1958 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 61, -(2880 - 1953 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 63, -(2880 - 1983 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 30, -(2880 - 1849 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 45, -(2880 - 1860 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 194, -(2880 - 1879 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 230, -(2880 - 1886 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 238, -(2880 - 1820 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 67, -(2880 - 1793 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 108, -(2880 - 1787 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 9, -(2880 - 1706 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 38, -(2880 - 1701 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 26, -(2880 - 1731 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 237, -(2880 - 1669 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 246, -(2880 - 1646 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 219, -(2880 - 1632 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 158, -(2880 - 1657 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 135, -(2880 - 1642 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 110, -(2880 - 1622 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 15, -(2880 - 1541 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 54, -(2880 - 1540 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 26, -(2880 - 1513 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 90, -(2880 - 1455 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 127, -(2880 - 1468 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 205, -(2880 - 1484 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 233, -(2880 - 1475 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 11, -(2880 - 1302 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 43, -(2880 - 1300 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 28, -(2880 - 1325 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 229, -(2880 - 1253 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 73, -(2880 - 1119 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 81, -(2880 - 1091 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 75, -(2880 - 1069 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 235, -(2880 - 1014 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 203, -(2880 - 1021 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 221, -(2880 - 993 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 232, -(2880 - 967 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 171, -(2880 - 967 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 118, -(2880 - 973 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 71, -(2880 - 933 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 52, -(2880 - 896 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 65, -(2880 - 868 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 16, -(2880 - 830 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 21, -(2880 - 806 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 45, -(2880 - 795 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 108, -(2880 - 809 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 159, -(2880 - 829 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 180, -(2880 - 850 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 170, -(2880 - 767 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 170, -(2880 - 736 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 200, -(2880 - 732 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 220, -(2880 - 708 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 21, -(2880 - 691 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 46, -(2880 - 692 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 188, -(2880 - 639 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 166, -(2880 - 622 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 198, -(2880 - 604 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 149, -(2880 - 598 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 46, -(2880 - 590 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 62, -(2880 - 567 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 183, -(2880 - 511 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 170, -(2880 - 483 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 186, -(2880 - 446 - SCREEN_HEIGHT));

	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 115, -(2880 - 463 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 92, -(2880 - 451 - SCREEN_HEIGHT));
	App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 70, -(2880 - 466 - SCREEN_HEIGHT));

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

