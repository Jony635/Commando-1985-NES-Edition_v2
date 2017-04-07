#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "SDL_mixer\include\SDL_mixer.h"




ModuleAudio::ModuleAudio()
{}

ModuleAudio::~ModuleAudio()
{}

// Load assets
bool ModuleAudio::Start()
{
	App->audio->Enable();
	LOG("Loading general audio");
	Mix_Init(MIX_INIT_OGG);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	return true;
}


bool ModuleAudio::Play(const char* path)
{
	bool ret;

	soundtrack = Mix_LoadMUS(path);
	if (soundtrack == nullptr) {
		LOG("Error");
		ret = false;
	}
	else {
		LOG("Music Loaded");
		ret = true;
	}
	Mix_PlayMusic(soundtrack, -1);
	return ret;
}


bool ModuleAudio::Stop()
{
	if (App->stop_music) {
		Mix_PauseMusic();
	}
	return true;
}


bool ModuleAudio::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	Stop();
	Mix_FreeMusic(soundtrack);
	Mix_Quit();
	return true;
}
