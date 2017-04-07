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
#include "ModuleGameOver.h"
#include "ModulePlayer.h"



ModuleGameOver::ModuleGameOver()
{}

ModuleGameOver::~ModuleGameOver()
{}

// Load assets
bool ModuleGameOver::Start()
{
	App->audio->Play("Resources/Audio/Themes_SoundTrack/Commando (NES) Music - Ending Theme.ogg");

	LOG("Loading gameover scene");

	background = App->textures->Load("Resources/Screens/EndGame.png");//foto del fondo
	App->render->camera.x = App->render->camera.y = 0;
	App->player->Disable();

	return true;
}

// UnLoad assets
bool ModuleGameOver::CleanUp()
{
	App->audio->Stop();

	LOG("Unloading gameover scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleGameOver::Update()
{




	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);


	if (App->input->keyboard[SDL_SCANCODE_SPACE]) {

		App->fade->FadeToBlack(this, App->welcome, 1);
	}

	return UPDATE_CONTINUE;
}