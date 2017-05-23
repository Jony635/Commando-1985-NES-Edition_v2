#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLvl2.h"
#include "ModuleSecretAreas.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModulePowerUp.h"

ModuleSecretAreas::ModuleSecretAreas() {
	//WELCOME ANIMATION
	welcometo.PushBack({ 0, 33, 128, 33 });
	welcometo.PushBack({ 0, 99, 128, 33 });
	welcometo.loop = false;
	welcometo.speed = 0.005f;


	//GAS ANIMATION
	gascounter.PushBack({ 72, 0, 8, 8 });
	gascounter.PushBack({ 64, 0, 8, 8 });
	gascounter.PushBack({ 56, 0, 8, 8 });
	gascounter.PushBack({ 48, 0, 8, 8 });
	gascounter.PushBack({ 40, 0, 8, 8 });
	gascounter.PushBack({ 32, 0, 8, 8 });
	gascounter.PushBack({ 24, 0, 8, 8 });
	gascounter.PushBack({ 16, 0, 8, 8 });
	gascounter.PushBack({ 8, 0, 8, 8 });
	gascounter.PushBack({ 0, 0, 8, 8 });

	gascounter.loop = false;
	gascounter.speed = 0.015f;

	//YELLOWSTAIR ANIMATION
	yellowstair.PushBack({ 16,0,16,16 });

	yellowstairinv.PushBack({ 22,22,6,6 });
}

ModuleSecretAreas::~ModuleSecretAreas() {}

bool ModuleSecretAreas::Start() {
	
	//Enables & Disables
	App->audio->Enable();
	App->textures->Enable();
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();
	App->powerup->Enable();


	//General textures
	rect = App->textures->Load("Resources/ui/Power_up_rect.png");
	items = App->textures->Load("Resources/Animations/Items.png");

	LOG("Loading SecretAreas scene");
	if (App->secretareas->actual_room == SECRETROOM::ROOM1) {
		//SECRETAREA1

		//Textures
		background1 = App->textures->Load("Resources/Screens/sa1.png");//foto del fondo


		//Cameras positions
		App->render->camera.x = App->render->camera.y = 0;
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker 2 Purple.ogg", true);
		//Add Enemies
		//App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
		//INIT THINGS
		App->lvl2->top = 0;
		isdown = true;
		isup = false;
		App->player->position.x = SCREEN_WIDTH / 2;
		App->player->position.y = SCREEN_HEIGHT - 35;
		//colliders 

		//WALL
		int i = 0;
		wall[i++] = App->collision->AddCollider({ 0, 0, 256, 31 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 44, 31, 212, 25 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, 31, 16, 193 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 16, 88, 16, 136 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 224, 88, 16, 136 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 240, 31, 16, 193 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, 210, 256, 14 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 32, 88, 80, 49 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 144, 88, 80, 49 }, COLLIDER_WALL);

		//UPSTAIRS
		int j = 0;
		upstairs[j++] = App->collision->AddCollider({ 20, 32, 23, 5 }, COLLIDER_UPSTAIRS);
	}
	else if (App->secretareas->actual_room == SECRETROOM::ROOM2) {
		//SECRETAREA2

		//Textures
		background1 = App->textures->Load("Resources/Screens/sa2.png");//foto del fondo

		//Cameras positions
		App->render->camera.x = App->render->camera.y = 0;
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker Blue.ogg", true);
		//Add Enemies
		//App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
		//INIT THINGS
		App->lvl2->top = 0;
		App->player->position.x = SCREEN_WIDTH / 2;
		App->player->position.y = SCREEN_HEIGHT - 35;
		//colliders 

		//WALL
		int i = 0;
		wall[i++] = App->collision->AddCollider({ 0, 0, 256, 37 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, 0, 16, 224 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 240, 0, 16, 224 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 112, 0, 32, 159 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, 216, 256, 8 }, COLLIDER_WALL);


		//UPSTAIRS
		int j = 0;
		upstairs[j++] = App->collision->AddCollider({ 116, 159, 23, 5 }, COLLIDER_UPSTAIRS);

	}
	else if (App->secretareas->actual_room == SECRETROOM::ROOM3) {

		//SECRETAREA3

		//Textures
		background1 = App->textures->Load("Resources/Screens/sa3.png");//foto del fondo
		alphabet = App->textures->Load("Resources/ui/Alphabet.png");

		//Cameras positions
		App->render->camera.x = App->render->camera.y = 0;
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker 2 Purple.ogg", true);
		//Add Enemies
		//App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
		//INIT THINGS
		App->lvl2->top = 0;
		App->player->position.x = SCREEN_WIDTH / 2;
		App->player->position.y = SCREEN_HEIGHT - 35;
		ystair = &yellowstairinv;

		gascounter.Reset();
		welcometo.Reset();

		//colliders 

		//WALL
		int i = 0;
		wall[i++] = App->collision->AddCollider({ 0, 0, 256, 37 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, 0, 16, 224 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 240, 0, 16, 224 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, 216, 256, 8 }, COLLIDER_WALL);


		//UPSTAIRS
		int j = 0;
		upstairs[j++] = App->collision->AddCollider({ 40, 44, 2, 2 }, COLLIDER_UPSTAIRS);



	}
	else if (App->secretareas->actual_room == SECRETROOM::ROOM4) {

		//SECRETAREA3

		//Textures
		background1 = App->textures->Load("Resources/Screens/sa4.png");//foto del fondo

																	   //Enables & Disables
		//Cameras positions
		App->render->camera.x = 0;
		App->render->camera.y = 0;
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker Blue.ogg", true);
		//Add Enemies
		//App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
		//INIT THINGS
		App->lvl2->top = -448 + SCREEN_HEIGHT;
		App->player->position.x = SCREEN_WIDTH / 2;
		App->player->position.y = SCREEN_HEIGHT - 35;


		//colliders 

		//WALL
		int i = 0;
		wall[i++] = App->collision->AddCollider({ 0, -(448 - SCREEN_HEIGHT), 32, 448 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(448 - 0 - SCREEN_HEIGHT), 256, 40 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 240, -(448 - SCREEN_HEIGHT), 16, 448 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(448 - 35 - SCREEN_HEIGHT), 64, 60 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 32, -(448 - 95 - SCREEN_HEIGHT), 4, 25 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 60, -(448 - 95 - SCREEN_HEIGHT), 4, 25 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 31, -(448 - 216 - SCREEN_HEIGHT), 17, 48 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 32, -(448 - 442 - SCREEN_HEIGHT), 208, 6 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 80, -(448 - 216 - SCREEN_HEIGHT), 160, 50 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 96, -(448 - 72 - SCREEN_HEIGHT), 16, 144 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 112, -(448 - 72 - SCREEN_HEIGHT), 48, 48 }, COLLIDER_WALL);


		//UPSTAIRS
		int j = 0;
		upstairs[j++] = App->collision->AddCollider({ 36, -(448 - 95 - SCREEN_HEIGHT), 24, 5 }, COLLIDER_UPSTAIRS);



	}
	else if (App->secretareas->actual_room == SECRETROOM::ROOM5) {

		//SECRETAREA3

		//Textures
		background1 = App->textures->Load("Resources/Screens/sa5.png");
		swall = App->textures->Load("Resources/Screens/Secret_wall.png");


		//Cameras positions
		App->render->camera.x = 0;
		App->render->camera.y = 0;
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker Blue.ogg", true);
		//Add Enemies
		//App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
		//INIT THINGS
		App->lvl2->top = -448 + SCREEN_HEIGHT;
		App->player->position.x = SCREEN_WIDTH / 2;
		App->player->position.y = SCREEN_HEIGHT - 35;


		//colliders 

		//WALL
		int i = 0;
		wall[i++] = App->collision->AddCollider({ 0, -(448 - SCREEN_HEIGHT), 16, 448 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(448 - 0 - SCREEN_HEIGHT), 256, 31 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 240, -(448 - SCREEN_HEIGHT), 16, 448 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 48, -(448 - 27 - SCREEN_HEIGHT), 16, 81 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 32, -(448 - 95 - SCREEN_HEIGHT), 4, 25 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 176, -(448 - 104 - SCREEN_HEIGHT), 16, 112 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 16, -(448 - 216 - SCREEN_HEIGHT), 17, 48 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 71, -(448 - 216 - SCREEN_HEIGHT), 169, 48 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 96, -(448 - 298 - SCREEN_HEIGHT), 64, 87 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 140, -(448 - 385 - SCREEN_HEIGHT), 20, 25 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 96, -(448 - 385 - SCREEN_HEIGHT), 20, 25 }, COLLIDER_WALL);


		//UPSTAIRS
		int j = 0;
		upstairs[j++] = App->collision->AddCollider({ 217, -(448 - 35 - SCREEN_HEIGHT), 12, 3 }, COLLIDER_UPSTAIRS);
		upstairs[j++] = App->collision->AddCollider({ 117, -(448 - 386 - SCREEN_HEIGHT), 23, 4 }, COLLIDER_UPSTAIRS);



	}
	else if (App->secretareas->actual_room == SECRETROOM::ROOM6) {

		//SECRETAREA3

		//Textures
		background1 = App->textures->Load("Resources/Screens/sa6.png");//foto del fondo

		//Cameras positions
		App->render->camera.x = 0;
		App->render->camera.y = 0;
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker 2 Purple.ogg", true);
		//Add Enemies
		//App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
		//INIT THINGS
		App->lvl2->top = -448 + SCREEN_HEIGHT;
		App->player->position.x = SCREEN_WIDTH / 2;
		App->player->position.y = SCREEN_HEIGHT - 35;


		//colliders 

		//WALL
		int i = 0;
		wall[i++] = App->collision->AddCollider({ 0, -(448 - SCREEN_HEIGHT), 16, 448 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(448 - 442 - SCREEN_HEIGHT), 256, 6 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 240, -(448 - SCREEN_HEIGHT), 16, 448 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 16, -(448 - 266 - SCREEN_HEIGHT), 64, 42 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 176, -(448 - 266 - SCREEN_HEIGHT), 64, 42 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 15, -(448 - 0 - SCREEN_HEIGHT), 97, 88 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 144, -(448 - 0 - SCREEN_HEIGHT), 97, 88 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 111, -(448 - 30 - SCREEN_HEIGHT), 6, 26 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 139, -(448 - 30 - SCREEN_HEIGHT), 5, 26 }, COLLIDER_WALL);


		//UPSTAIRS
		int j = 0;
		upstairs[j++] = App->collision->AddCollider({ 117, -(448 - 32 - SCREEN_HEIGHT), 22, 4 }, COLLIDER_UPSTAIRS);



	}


	return true;
}

update_status ModuleSecretAreas::Update() {

	time_Counters[gas] += 0.02;


	//Blits in rooms
	switch (actual_room)
	{
	case ROOM1:
		App->render->Blit(background1, 0, 0, NULL);
		break;
	case ROOM2:
		App->render->Blit(background1, 0, 0, NULL);
		break;
	case ROOM3:
		App->render->Blit(background1, 0, 0, NULL);
		App->render->Blit(rect, 64, 55, &(welcometo.GetCurrentFrame()));
		App->render->Blit(items, 32, 41, &(ystair->frames[0]));
		if (time_Counters[gas]>5)
			App->render->Blit(alphabet, 128, 121, &(gascounter.GetCurrentFrame()));
		if (time_Counters[gas] > 18 && App->player->current_animation != &App->player->upstairs)
			App->player->dead = true;
		break;
	case ROOM4:
		App->render->Blit(background1, 0, -448 + SCREEN_HEIGHT, NULL);

		if (isdown && App->player->position.y<0 && App->render->camera.y != App->lvl2->top + 2) {
			App->render->camera.y -= 3;
			App->player->position.y--;
		}
		if (App->render->camera.y == App->lvl2->top + 2) {
			isdown = false;
			isup = true;
		}
		if (isup&&App->player->position.y > -23 && App->render->camera.y != 0) {
			App->render->camera.y += 3;
			App->player->position.y++;
		}
		if (App->render->camera.y == 0) {
			isdown = true;
			isup = false;
		}
		if (App->render->camera.y != 0 && App->render->camera.y != App->lvl2->top + 2) {
			App->player->move = false;
		}
		else {
			App->player->move = true;
		}


		break;
	case ROOM5:

		if (App->player->position.x < 50 && App->player->position.y == -(448 - 282 - SCREEN_HEIGHT) && (int)swallposition.y != 221) {
			swallposition.y += 0.1;
			App->player->move = false;
			if (playdorosound) {
				App->audio->PlaySound("Resources/Audio/Sound Effects/Terremoto _ Efecto de sonido.wav");
				playdorosound = false;
			}
		}
		else if ((int)swallposition.y == 221 && (int)swallposition.x != 71) {
			swallposition.x += 0.3;
		}
		else if ((int)swallposition.x == 71 && !App->player->move) {
			App->player->move = true;
			gateopened = true;
		}
		else if ((int)swallposition.x != 71 && App->player->move) {
			swallposition.x = 33;
			swallposition.y = 216;
		}

		//swallposition.x = (int)swallposition.x;
		//swallposition.y = (int)swallposition.y;
		if (gateopened) {
			if (isdown && App->player->position.y < 0 && App->render->camera.y != App->lvl2->top + 2) {
				App->render->camera.y -= 3;
				App->player->position.y--;
			}
			if (App->render->camera.y == App->lvl2->top + 2) {
				isdown = false;
				isup = true;
			}
			if (isup&&App->player->position.y > -23 && App->render->camera.y != 0) {
				App->render->camera.y += 3;
				App->player->position.y++;
			}
			if (App->render->camera.y == 0) {
				isdown = true;
				isup = false;
			}
			if (App->render->camera.y != 0 && App->render->camera.y != App->lvl2->top + 2) {
				App->player->move = false;
			}
			else {
				App->player->move = true;
			}
		}

		App->render->Blit(background1, 0, -448 + SCREEN_HEIGHT, NULL);
		App->render->Blit(swall, (int)swallposition.x, -(448 - (int)swallposition.y - SCREEN_HEIGHT), NULL);

		break;
	case ROOM6:
		App->render->Blit(background1, 0, -448 + SCREEN_HEIGHT, NULL);

		if (isdown && App->player->position.y<0 && App->render->camera.y != App->lvl2->top + 2) {
			App->render->camera.y -= 6;
			App->player->position.y--;
		}
		if (App->render->camera.y == App->lvl2->top + 2) {
			isdown = false;
			isup = true;
		}
		if (isup&&App->player->position.y > -23 && App->render->camera.y != 0) {
			App->render->camera.y += 6;
			App->player->position.y++;
		}
		if (App->render->camera.y == 0) {
			isdown = true;
			isup = false;
		}
		if (App->render->camera.y != 0 && App->render->camera.y != App->lvl2->top + 2) {
			App->player->move = false;
		}
		else {
			App->player->move = true;
		}
		break;
	case MAX_COUNTER_ROOM:
		break;
	default:
		break;
	}



	return UPDATE_CONTINUE;

}

bool ModuleSecretAreas::CleanUp() {

	LOG("Unloading secretareas scene");



	//Disables
	App->powerup->Disable();
	App->particles->Disable();
	App->textures->Disable();
	App->collision->Disable();
	App->audio->Disable();
	App->lvl2->top = -2880 + SCREEN_HEIGHT;
	App->player->Disable();
	App->enemies->Disable();
	//Unload textures
	App->textures->Unload(background1);
	App->textures->Unload(items);
	App->textures->Unload(rect);

	time_Counters[gas] = 0;

	return true;
}


