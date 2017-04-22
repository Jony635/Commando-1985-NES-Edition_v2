#ifndef __MODULEAUDIO_H__
#define __MODULEAUDIO_H__

#include "Module.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Start();
	bool Play(const char*,bool);
	bool PlaySound(const char*);
	bool Stop();
	bool CleanUp();

public:
	int loop = 0;
	Mix_Music* soundtrack = nullptr;
	Mix_Chunk* sounfeffect1 = nullptr;
};

#endif // __MODULEAUDIO_H__