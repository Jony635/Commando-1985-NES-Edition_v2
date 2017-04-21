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
#include "ModuleDie.h"



ModuleDie::ModuleDie()
{
	//joe diying 
	/*joed.PushBack({ 2, 72, 17, 27 });
	joed.PushBack({ 20, 72, 17, 27 });
	joed.PushBack({ 37, 72, 17, 27 });
	joed.PushBack({ 20, 72, 17, 27 });
	joed.PushBack({ 2, 72, 17, 27 });
	joed.speed = 0.05f;*/


}

ModuleDie::~ModuleDie()
{}

// Load assets
bool ModuleDie::Start()
{

	App->audio->Play("Resources/Audio/Themes_SoundTrack/Commando (NES) Music - Game Over.ogg");

	LOG("Loading Die scene");

	//backgroundie = App->textures->Load("Resources/Screens/CommandoArea1.png");//foto del fondo
	//App->render->camera.x = App->render->camera.y = 0;
	App->player->Disable();

	return true;
}

// UnLoad assets
bool ModuleDie::CleanUp()
{
	App->audio->Stop();
	//App->player->Disable();


	

	LOG("Unloading gameover scene");

	//App->textures->Unload(backgroundie);

	return true;
}

// Update: draw background
update_status ModuleDie::Update()
{


	time += 0.02f;

	// Draw everything --------------------------------------
	//App->render->Blit(backgroundie, 0, -2880 + SCREEN_HEIGHT, NULL);


	if (App->input->keyboard[SDL_SCANCODE_2]){//time>6.3) {
		time = 0;
		App->fade->FadeToBlack(this, App->welcome, 0);
	}

	return UPDATE_CONTINUE;
}