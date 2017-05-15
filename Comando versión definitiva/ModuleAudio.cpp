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
	/*App->audio->Enable();
	LOG("Loading general audio");
	Mix_Init(MIX_INIT_OGG);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);*/

	return true;
}


bool ModuleAudio::Play(const char* path,bool loop)
{
	bool ret;

	//soundtrack = Mix_LoadMUS(path);
	//if (soundtrack == nullptr) {
	//	LOG("Error");
	//	ret = false;
	//}
	//else {
	//	LOG("Music Loaded");
		ret = true;
	/*}
	if(loop)
	Mix_PlayMusic(soundtrack, -1);
	if (!loop)
	Mix_PlayMusic(soundtrack, 1);*/
		return ret;
}

bool ModuleAudio::PlaySound(const char* path)
{
	bool ret;
	//sounfeffect1 = Mix_LoadWAV(path);
	//if (sounfeffect1 == nullptr)
	//{
	//	LOG("Error loading sound effect 1: %s", Mix_GetError());
	//	ret = false;
	//}
	//else
	//{
	//	//LOG("Sound effect 1 Loaded");
	//	Mix_PlayChannel(-1, sounfeffect1, 0);
		ret = true;
	//}
	return ret;
}


bool ModuleAudio::Stop()
{
	/*if (App->stop_music) {
		Mix_PauseMusic();
	}*/
	return true;
}


bool ModuleAudio::CleanUp()
{
	/*LOG("Quitting SDL input event subsystem");
	Stop();
	Mix_FreeMusic(soundtrack);
	Mix_Pause(-1);
	Mix_Quit();*/
	return true;
}
