#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLvl1.h"
#include "ModuleWelcome.h"
#include "ModuleLvl2.h"
#include "ModuleGameOver.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleHelicopter.h"



ModuleWelcome::ModuleWelcome()
{

}

ModuleWelcome::~ModuleWelcome()
{}

// Load assets
bool ModuleWelcome::Start()
{
	App->textures->Enable();
	App->audio->Enable();
	App->input->Enable();
	App->audio->Play("Resources/Audio/Themes_SoundTrack/Title Theme.ogg",true);
	LOG("Loading welcome scene");
	bool ret = true;
	background = App->textures->Load("Resources/Screens/Commandowelcome.png");//foto del fondo
	App->render->camera.x = App->render->camera.y = 0;



	return ret;
}

// UnLoad assets
bool ModuleWelcome::CleanUp()
{
	//App->audio->Disable();
	App->audio->Stop();

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleWelcome::Update()
{
	



	// Draw everything --------------------------------------
	App->render->Blit(background, 0,  0, NULL);


	if (App->input->keyboard[SDL_SCANCODE_RETURN]) {

		App->fade->FadeToBlack(this, App->helicopter, 0);
	}

	return UPDATE_CONTINUE;
}