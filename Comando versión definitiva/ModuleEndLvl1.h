#ifndef __MODULEWELCOME_H__
#define __MODULEWELCOME_H__

#include "Module.h"

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

	SDL_Texture* background = nullptr;
};

#endif // _MODULEWELCOME_H