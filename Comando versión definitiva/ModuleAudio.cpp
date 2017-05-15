#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "SDL\include\SDL.h"




ModuleAudio::ModuleAudio()
{}

ModuleAudio::~ModuleAudio()
{}

// Load assets
bool ModuleAudio::Start()
{
	LOG("Loading Audio Mixer");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		LOG("SDL_INIT_AUDIO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	// load support for the OGG format
	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("Could not initialize Mixer lib. Mix_Init: %s", Mix_GetError());
		ret = false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		LOG("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		ret = false;
	}

	return ret;
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
	if (App->stop_music) {
		Mix_PauseMusic();
	}
	return true;
}


bool ModuleAudio::CleanUp()
{
	LOG("Freeing sound FX, closing Mixer and Audio subsystem");
	if (soundtrack != NULL)
	{
		Mix_FreeMusic(soundtrack);
	}
	if (sounfeffect1 != nullptr)
	{
		Mix_FreeChunk(sounfeffect1);
	}
	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	return true;
}
