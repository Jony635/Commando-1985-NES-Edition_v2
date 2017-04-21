#ifndef __MODULEDIE_H__
#define __MODULEDIE_H__

#include "Module.h"
#include "Animation.h"
#include "ModulePlayer.h"

struct SDL_Texture;

class ModuleDie : public Module
{
public:
	ModuleDie();
	~ModuleDie();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	float time = 0;
	//SDL_Texture* backgroundie = nullptr;
};

#endif //  __MODULEDIE_H__

