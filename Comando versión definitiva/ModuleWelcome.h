#ifndef __MODULEWELCOME_H__
#define __MODULEWELCOME__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"



struct SDL_Texture;

class ModuleWelcome : public Module
{
public:
	ModuleWelcome();
	~ModuleWelcome();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	enum MENU {
		Lvl2,
		exit
	}Menu_Options;
	SDL_Texture* Area2Option = nullptr;
	SDL_Texture* ExitOption = nullptr;

};

#endif // __MODULELVL2_H__
