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
	yellowstair.PushBack({ 22,22,6,6 });
}

ModuleSecretAreas::~ModuleSecretAreas() {}

bool ModuleSecretAreas::Start() {

	//General textures
	rect = App->textures->Load("Resources/ui/Power_up_rect.png");
	items = App->textures->Load("Resources/Animations/Items.png");

	LOG("Loading SecretAreas scene");
	if(App->secretareas->actual_room == SECRETROOM::ROOM1){
	//SECRETAREA1

	//Textures
	background1 = App->textures->Load("Resources/Screens/sa1.png");//foto del fondo

	//Enables & Disables
	App->audio->Enable();
	App->textures->Enable();
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	//Cameras positions
	App->render->camera.x = App->render->camera.y = 0;
	App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker 2 Purple.ogg", true);
	//Add Enemies
	//App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
	//INIT THINGS
	App->lvl2->top = 0;
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

																	   //Enables & Disables
		App->audio->Enable();
		App->textures->Enable();
		App->player->Enable();
		App->collision->Enable();
		App->enemies->Enable();
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

		//Enables & Disables
		App->audio->Enable();
		App->textures->Enable();
		App->player->Enable();
		App->collision->Enable();
		App->enemies->Enable();
		//Cameras positions
		App->render->camera.x = App->render->camera.y = 0;
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker 2 Purple.ogg", true);
		//Add Enemies
		//App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
		//INIT THINGS
		App->lvl2->top = 0;
		App->player->position.x = SCREEN_WIDTH / 2;
		App->player->position.y = SCREEN_HEIGHT - 35;

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
		App->audio->Enable();
		App->textures->Enable();
		App->player->Enable();
		App->collision->Enable();
		App->enemies->Enable();
		//Cameras positions
		App->render->camera.x = 0;
		App->render->camera.y = 0;
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker Blue.ogg", true);
		//Add Enemies

		//INIT THINGS
		isdown = true;
		isup = false;
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
		App->render->Blit(items, 32, 41, &(yellowstair.frames[0]));
		if (time_Counters[gas]>5)
			App->render->Blit(alphabet, 128, 121, &(gascounter.GetCurrentFrame()));
		if (time_Counters[gas] > 18)
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
		break;
	case ROOM6:
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
	App->textures->Disable();
	App->collision->Disable();
	App->audio->Disable();
	App->lvl2->top = -2880 + SCREEN_HEIGHT;
	App->player->Disable();
	App->enemies->Disable();
	//Unload textures
	App->textures->Unload(background1);

	time_Counters[gas] = 0;

	return true;
}

