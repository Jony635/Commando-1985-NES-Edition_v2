#ifndef __MODULELVL2_H__
#define __MODULELVL2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"



struct SDL_Texture;

class ModuleLvl2 : public Module
{
public:
	ModuleLvl2();
	~ModuleLvl2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;

};

#endif // __MODULELVL2_H__
