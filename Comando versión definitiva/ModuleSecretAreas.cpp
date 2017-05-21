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

ModuleSecretAreas::ModuleSecretAreas() {}

ModuleSecretAreas::~ModuleSecretAreas() {}

bool ModuleSecretAreas::Start() {

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
		//SECRETAREA1

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
		wall[i++] = App->collision->AddCollider({ 224, 88, 16, 136 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, 216, 256, 8 }, COLLIDER_WALL);
		wall[i++] = wall[i];
		wall[i++] = wall[i];
		wall[i++] = wall[i];


		//UPSTAIRS
		int j = 0;
		upstairs[j++] = App->collision->AddCollider({ 116, 159, 23, 5 }, COLLIDER_UPSTAIRS);

	}
	//else if (App->secretareas->actual_room == SECRETROOM::ROOM2) {
	//	//SECRETAREA1

	//	//Textures
	//	background1 = App->textures->Load("Resources/Screens/sa3.png");//foto del fondo

	//																   //Enables & Disables
	//	App->audio->Enable();
	//	App->textures->Enable();
	//	App->player->Enable();
	//	App->collision->Enable();
	//	App->enemies->Enable();
	//	//Cameras positions
	//	App->render->camera.x = App->render->camera.y = 0;
	//	App->audio->Play("Resources/Audio/Themes_SoundTrack/Underground Bunker 2 Purple.ogg", true);
	//	//Add Enemies
	//	//App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, App->player->position.x, App->player->position.y - 200);
	//	//INIT THINGS
	//	App->lvl2->top = 0;
	//	App->player->position.x = SCREEN_WIDTH / 2;
	//	App->player->position.y = SCREEN_HEIGHT - 35;
	//	//colliders 

	//	//WALL
	//	int i = 0;
	//	wall[i++] = App->collision->AddCollider({ 0, 0, 256, 37 }, COLLIDER_WALL);
	//	wall[i++] = App->collision->AddCollider({ 0, 0, 16, 224 }, COLLIDER_WALL);
	//	wall[i++] = App->collision->AddCollider({ 240, 0, 16, 224 }, COLLIDER_WALL);
	//	wall[i++] = App->collision->AddCollider({ 112, 0, 32, 159 }, COLLIDER_WALL);
	//	wall[i++] = App->collision->AddCollider({ 224, 88, 16, 136 }, COLLIDER_WALL);
	//	wall[i++] = App->collision->AddCollider({ 0, 216, 256, 8 }, COLLIDER_WALL);
	//	wall[i++] = wall[i];
	//	wall[i++] = wall[i];
	//	wall[i++] = wall[i];


	//	//UPSTAIRS
	//	int j = 0;
	//	upstairs[j++] = App->collision->AddCollider({ 116, 159, 23, 5 }, COLLIDER_UPSTAIRS);

	//}

	return true;
}

update_status ModuleSecretAreas::Update() {

	//Render Map
	App->render->Blit(background1, 0, 0, NULL);

	////Fade to black to next lvl
	//if (App->input->keyboard[SDL_SCANCODE_F2]) {
	//	App->fade->FadeToBlack(this, App->endlvl2, 0);
	//}

	return UPDATE_CONTINUE;

}

bool ModuleSecretAreas::CleanUp() {

	LOG("Unloading secretareas scene");



	/*for (int i = 0; i < NUM_COLLIDERSWALL; i++)
	{
		if (wall[i] != nullptr) {
			delete wall[i];
			wall[i] = nullptr;
		}
	}

	for (int i = 0; i < NUM_COLLIDERSUPSTAIRS; i++)
	{
		if (upstairs[i] != nullptr) {
			delete upstairs[i];
			upstairs[i] = nullptr;
		}
	}*/

	//Disables
	App->textures->Disable();
	App->collision->Disable();
	App->audio->Disable();
	App->lvl2->top = -2880 + SCREEN_HEIGHT;
	App->player->Disable();
	App->enemies->Disable();
	//Unload textures
	App->textures->Unload(background1);

	return true;
}

