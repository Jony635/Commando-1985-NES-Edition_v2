#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLvl1.h"
#include "ModuleWelcome.h"
#include "ModuleLvl2.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"




ModuleLvl1::ModuleLvl1()
{
	
	

	//ally animation
	ally.PushBack({ 0, 0, 16, 22 });
	ally.PushBack({ 17, 0, 16, 22 });
	ally.speed = 0.08f;
	//ally2 animation
	ally2.PushBack({ 0, 0, 16, 22 });
	ally2.PushBack({ 17, 0, 16, 22 });
	ally2.speed = 0.08f;
	//ally3 animation
	ally3.PushBack({ 0, 0, 16, 22 });
	ally3.PushBack({ 17, 0, 16, 22 });
	ally3.speed = 0.08f;

	//enemyally animation
	enemyally.PushBack({ 17, 0, 16, 22 });
	enemyally.PushBack({ 0, 0, 16, 22 });
	enemyally.PushBack({ 34, 0, 16, 22 });
	enemyally.PushBack({ 0, 0, 16, 22 });
	enemyally.speed = 0.08f;
		//enemyally2 animation
	enemyally2.PushBack({ 17, 0, 16, 22 });
	enemyally2.PushBack({ 0, 0, 16, 22 });
	enemyally2.PushBack({ 34, 0, 16, 22 });
	enemyally2.PushBack({ 0, 0, 16, 22 });
	enemyally2.speed = 0.08f;

	//box animation
	box.PushBack({ 27, 18, 23, 15 });
	box.PushBack({ 27, 1, 23, 15 });
	box.PushBack({ 1, 18, 23, 15 });
	box.PushBack({ 1, 1, 23, 15 });
	box.speed = 0.08f;
	//box2 animation
	box2.PushBack({ 27, 18, 23, 15 });
	box2.PushBack({ 27, 1, 23, 15 });
	box2.PushBack({ 1, 18, 23, 15 });
	box2.PushBack({ 1, 1, 23, 15 });
	box2.speed = 0.08f;
	//box3 animation
	box3.PushBack({ 27, 18, 23, 15 });
	box3.PushBack({ 27, 1, 23, 15 });
	box3.PushBack({ 1, 18, 23, 15 });
	box3.PushBack({ 1, 1, 23, 15 });
	box3.speed = 0.08f;
	//box4 animation
	box4.PushBack({ 27, 18, 23, 15 });
	box4.PushBack({ 27, 1, 23, 15 });
	box4.PushBack({ 1, 18, 23, 15 });
	box4.PushBack({ 1, 1, 23, 15 });
	box4.speed = 0.08f;
	//box5 animation
	box5.PushBack({ 27, 18, 23, 15 });
	box5.PushBack({ 27, 1, 23, 15 });
	box5.PushBack({ 1, 18, 23, 15 });
	box5.PushBack({ 1, 1, 23, 15 });
	box5.speed = 0.08f;
	//box6 animation
	box6.PushBack({ 27, 18, 23, 15 });
	box6.PushBack({ 27, 1, 23, 15 });
	box6.PushBack({ 1, 18, 23, 15 });
	box6.PushBack({ 1, 1, 23, 15 });
	box6.speed = 0.08f;
}


ModuleLvl1::~ModuleLvl1()
{}

// Load assets
bool ModuleLvl1::Start()
{
	LOG("Loading lvl1 scene");
	cont = 0;
	intro = true;
	big = true;
	medium = false;
	small = false;
	contanimh = 0;
	forward = false;
	

	App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1, 2 Theme.ogg",true);
	background = App->textures->Load("Resources/Screens/CommandoArea1.png");//foto del fondo
	graphics = App->textures->Load("Resources/Animations/Ally soldier alone.png");
	graphics2 = App->textures->Load("Resources/Animations/Guard Enemy.png");
	graphics3 = App->textures->Load("Resources/Animations/handgranadesx4.png");
	App->render->camera.x = App->render->camera.y = 0;
 	App->enemies->Enable();
	App->collision->Enable(); 
	App->player->Enable();
	App->particles->Enable();
	
	
		// Colliders ---
		int i = 0;
		wall[i++] = App->collision->AddCollider({ 193, -(2880 - 2706 - SCREEN_HEIGHT), 63, 46 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 2642 - SCREEN_HEIGHT), 46, 32 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 86, -(2880 - 2642 - SCREEN_HEIGHT), 25, 23 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 134, -(2880 - 2594 - SCREEN_HEIGHT), 25, 24 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 149, -(2880 - 2578 - SCREEN_HEIGHT), 26, 22 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 86, -(2880 - 2530 - SCREEN_HEIGHT), 25, 24 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 22, -(2880 - 2770 - SCREEN_HEIGHT), 25, 24 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 135, -(2880 - 2819 - SCREEN_HEIGHT), 22, 21 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 150, -(2880 - 2802 - SCREEN_HEIGHT), 24, 21 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 166, -(2880 - 2818 - SCREEN_HEIGHT), 24, 22 }, COLLIDER_WALL);
		
		wall[i++] = App->collision->AddCollider({ 197, -(2880 - 2509 - SCREEN_HEIGHT), 59, 30 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 212, -(2880 - 2484 - SCREEN_HEIGHT), 44, 25 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 203, -(2880 - 2491 - SCREEN_HEIGHT), 17, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 5, -(2880 - 2419 - SCREEN_HEIGHT), 26, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 22, -(2880 - 2402 - SCREEN_HEIGHT), 24, 22 }, COLLIDER_WALL);
		
		wall[i++] = App->collision->AddCollider({ 37, -(2880 - 2418 - SCREEN_HEIGHT), 26, 23 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 165, -(2880 - 2595 - SCREEN_HEIGHT), 26, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 127, -(2880 - 2384 - SCREEN_HEIGHT), 62, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 86, -(2880 - 2338 - SCREEN_HEIGHT), 25, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 150, -(2880 - 2290 - SCREEN_HEIGHT), 25, 22 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 2260 - SCREEN_HEIGHT), 46, 58 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 39, -(2880 - 2282 - SCREEN_HEIGHT), 20, 23 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 41, -(2880 - 2269 - SCREEN_HEIGHT), 11, 19 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 214, -(2880 - 2226 - SCREEN_HEIGHT), 25, 24 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1988 - SCREEN_HEIGHT), 108, 56 }, COLLIDER_WALL);		

		wall[i++] = App->collision->AddCollider({ 103, -(2880 - 2007 - SCREEN_HEIGHT), 20, 30 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 96, -(2880 - 1990 - SCREEN_HEIGHT), 20, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 211, -(2880 - 1925 - SCREEN_HEIGHT), 45, 53 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 197, -(2880 - 1944 - SCREEN_HEIGHT), 27, 28 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 203, -(2880 - 1932 - SCREEN_HEIGHT), 20, 17 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 76, -(2880 - 1861 - SCREEN_HEIGHT), 70, 55 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 68, -(2880 - 1882 - SCREEN_HEIGHT), 88, 23 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 212, -(2880 - 1748 - SCREEN_HEIGHT), 44, 56 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 197, -(2880 - 1768 - SCREEN_HEIGHT), 33, 28 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 203, -(2880 - 1755 - SCREEN_HEIGHT), 17, 18 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1700 - SCREEN_HEIGHT), 45, 56 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 38, -(2880 - 1721 - SCREEN_HEIGHT), 22, 26 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 35, -(2880 - 1707 - SCREEN_HEIGHT), 17, 19 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 70, -(2880 - 1697 - SCREEN_HEIGHT), 25, 23 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 86, -(2880 - 1682 - SCREEN_HEIGHT), 25, 20 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 101, -(2880 - 1699 - SCREEN_HEIGHT), 26, 21 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 150, -(2880 - 1538 - SCREEN_HEIGHT), 25, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 22, -(2880 - 1539 - SCREEN_HEIGHT), 24, 21 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 85, -(2880 - 1474 - SCREEN_HEIGHT), 26, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 191, -(2880 - 1472 - SCREEN_HEIGHT), 62, 8 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1343 - SCREEN_HEIGHT), 98, 82 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 158, -(2880 - 1343 - SCREEN_HEIGHT), 98, 82 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1205 - SCREEN_HEIGHT), 25, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 50, -(2880 - 1141 - SCREEN_HEIGHT), 26, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 163, -(2880 - 1141 - SCREEN_HEIGHT), 25, 18 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 194, -(2880 - 1088 - SCREEN_HEIGHT), 57, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 35, -(2880 - 1061 - SCREEN_HEIGHT), 24, 17 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 114, -(2880 - 1028 - SCREEN_HEIGHT), 26, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1008 - SCREEN_HEIGHT), 57, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 178, -(2880 - 997 - SCREEN_HEIGHT), 26, 18 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 162, -(2880 - 933 - SCREEN_HEIGHT), 26, 17 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 18, -(2880 - 853 - SCREEN_HEIGHT), 26, 17 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 114, -(2880 - 853 - SCREEN_HEIGHT), 27, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 210, -(2880 - 853 - SCREEN_HEIGHT), 26, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 221, -(2880 - 719 - SCREEN_HEIGHT), 35, 82 }, COLLIDER_WALL);
		
		wall[i++] = App->collision->AddCollider({ 211, -(2880 - 729 - SCREEN_HEIGHT), 20, 68 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 66, -(2880 - 752 - SCREEN_HEIGHT), 54, 9 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 6, -(2880 - 738 - SCREEN_HEIGHT), 24, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 22, -(2880 - 722 - SCREEN_HEIGHT), 25, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 37, -(2880 - 739 - SCREEN_HEIGHT), 26, 21 }, COLLIDER_WALL);
		
		wall[i++] = App->collision->AddCollider({ 147, -(2880 - 672 - SCREEN_HEIGHT), 70, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 640 - SCREEN_HEIGHT), 57, 7 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 98, -(2880 - 576 - SCREEN_HEIGHT), 54, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 512 - SCREEN_HEIGHT), 70, 7 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 214, -(2880 - 389 - SCREEN_HEIGHT), 42, 76 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 421 - SCREEN_HEIGHT), 29, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 65, -(2880 - 373 - SCREEN_HEIGHT), 28, 18 }, COLLIDER_WALL);		
		wall[i++] = App->collision->AddCollider({ 131, -(2880 - 342 - SCREEN_HEIGHT), 25, 16 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 195, -(2880 - 309 - SCREEN_HEIGHT), 25, 17 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 132, -(2880 - 288 - SCREEN_HEIGHT), 54, 8 }, COLLIDER_WALL);
		
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 117 - SCREEN_HEIGHT), 46, 123 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 214, -(2880 - 100 - SCREEN_HEIGHT), 42, 125 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 32, -(2880 - 80 - SCREEN_HEIGHT), 60, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 161, -(2880 - 80 - SCREEN_HEIGHT), 60, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - SCREEN_HEIGHT), 96, 40 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 159, -(2880 - SCREEN_HEIGHT), 97, 39 }, COLLIDER_WALL);
		/*wall[i++] = App->collision->AddCollider({ 65, -(2880 - 373 - SCREEN_HEIGHT), 28, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 131, -(2880 - 342 - SCREEN_HEIGHT), 25, 16 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 195, -(2880 - 309 - SCREEN_HEIGHT), 25, 17 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 132, -(2880 - 288 - SCREEN_HEIGHT), 54, 8 }, COLLIDER_WALL);*/


		//Colliders Water

		i = 0;
		water[i++] = App->collision->AddCollider({ 0, -(2880 - 2471 - SCREEN_HEIGHT), 57, 54 }, COLLIDER_WATER);
		water[i++] = App->collision->AddCollider({ 39, -(2880 - 1256 - SCREEN_HEIGHT), 50, 37 }, COLLIDER_WATER);
		water[i++] = App->collision->AddCollider({ 167, -(2880 - 1205 - SCREEN_HEIGHT), 89, 88 }, COLLIDER_WATER);
		water[i++] = App->collision->AddCollider({ 0, -(2880 - 244 - SCREEN_HEIGHT), 89, 74 }, COLLIDER_WATER);



		//Enemies
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 93, -(2880 - 2491 - SCREEN_HEIGHT));
		//}
		return true;
	
}

// UnLoad assets
bool ModuleLvl1::CleanUp()
{
	App->audio->Stop();
	App->player->Disable();
	App->collision->Disable();

	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->textures->Unload(graphics);

	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);
	
	App->textures->Disable();
	//App->audio->Stop();
	return true;
}

// Update: draw background
update_status ModuleLvl1::Update()
{



	// Move camera forward -----------------------------
	int speed = 3;

	if (App->player->position.y == (135 - cont) && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->render->camera.y < ((2880 - SCREEN_HEIGHT)*SCREEN_SIZE) - speed) {
		cont++;
		App->render->camera.y += speed;
	}

	App->render->Blit(background, 0, -2880 + SCREEN_HEIGHT, NULL);


	App->render->Blit(graphics, 50, -(2880 - 1675 - SCREEN_HEIGHT), &(ally.GetCurrentFrame()), 1.0f); // ally animation
	App->render->Blit(graphics, 47, -(2880 - 765 - SCREEN_HEIGHT), &(ally2.GetCurrentFrame()), 1.0f); // ally2 animation
	App->render->Blit(graphics, 15, -(2880-765-SCREEN_HEIGHT), &(ally3.GetCurrentFrame()), 1.0f); // ally3 animation
	App->render->Blit(graphics2, 34, -(2880 - 1675 - SCREEN_HEIGHT), &(enemyally.GetCurrentFrame()), 1.0f); // enemyally animation
	App->render->Blit(graphics2, 66, -(2880 - 1675 - SCREEN_HEIGHT), &(enemyally2.GetCurrentFrame()), 1.0f); // enemyally2 animation
	App->render->Blit(graphics3, 161, -(2880 - 2482 - SCREEN_HEIGHT), &(box.GetCurrentFrame()), 1.0f); // box animation
	App->render->Blit(graphics3, 32, -(2880 - 1958 - SCREEN_HEIGHT), &(box2.GetCurrentFrame()), 1.0f); // box2 animation
	App->render->Blit(graphics3, 25, -(2880 - 977 - SCREEN_HEIGHT), &(box3.GetCurrentFrame()), 1.0f); // box3 animation
	App->render->Blit(graphics3, 55, -(2880 - 718 - SCREEN_HEIGHT), &(box4.GetCurrentFrame()), 1.0f); // box4 animation
	App->render->Blit(graphics3, 2, -(2880 - 492 - SCREEN_HEIGHT), &(box5.GetCurrentFrame()), 1.0f); // box5 animation
	App->render->Blit(graphics3, 166, -(2880 - 258 - SCREEN_HEIGHT), &(box6.GetCurrentFrame()), 1.0f); // box6 animation




	if (App->input->keyboard[SDL_SCANCODE_1]) {

		App->fade->FadeToBlack(this, App->lvl2, 1);

	}

	return UPDATE_CONTINUE;
}