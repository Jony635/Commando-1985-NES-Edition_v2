#ifndef __MODULELVL2_H__
#define __MODULELVL2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define NUM_COLLIDERSWALL 100
#define NUM_COLLIDERSWATER 100

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

	//Colliders
	Collider* wall[NUM_COLLIDERSWALL];
	Collider* water[NUM_COLLIDERSWATER];

};

#endif // __MODULELVL2_H__
