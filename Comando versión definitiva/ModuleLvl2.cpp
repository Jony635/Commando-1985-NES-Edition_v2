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

ModuleLvl2::ModuleLvl2(){}

ModuleLvl2::~ModuleLvl2(){}

bool ModuleLvl2::Start() {

	LOG("Loading lvl2 scene");

	//Textures
	background = App->textures->Load("Resources/Screens/CommandoArea2.png");//foto del fondo
	
	//Enables & Disables
	App->audio->Enable();
	App->textures->Enable();
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	//Caeras positions
	App->render->camera.x = App->render->camera.y = 0;
	App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1, 2 Theme.ogg", true);
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
	return true;
}

update_status ModuleLvl2::Update(){

	//Render Map
	App->render->Blit(background, 0, -2880 + SCREEN_HEIGHT, NULL);

	////Fade to black to next lvl
	//if (App->input->keyboard[SDL_SCANCODE_F2]) {
	//	App->fade->FadeToBlack(this, App->endlvl2, 0);
	//}

	return UPDATE_CONTINUE;

}

bool ModuleLvl2::CleanUp(){

	LOG("Unloading lvl1 scene");

	//Disables
	App->textures->Disable();
	App->collision->Disable();
	App->audio->Disable();

	//Unload textures
	App->textures->Unload(background);

	return true;
}

