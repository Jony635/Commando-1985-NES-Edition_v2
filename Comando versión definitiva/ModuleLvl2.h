#ifndef __MODULELVL2_H__
#define __MODULELVL2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define NUM_COLLIDERSWALL 100
#define NUM_COLLIDERSWATER 100
#define MAX_COLLIDER_DOWNSTAIRS 20

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
	SDL_Texture* items = nullptr;
	int top;
	Collider* downstairs[MAX_COLLIDER_DOWNSTAIRS];
	Animation* current_stair1_animation = nullptr;
	Animation* current_stair2_animation = nullptr;
	Animation* current_stair3_animation = nullptr;
	Animation* current_stair4_animation = nullptr;
	Animation* current_stair5_animation = nullptr;
	Animation* current_stair6_animation = nullptr;
	Animation stair;
	Animation stairinv;

	//Colliders
	Collider* wall[NUM_COLLIDERSWALL];
	Collider* water[NUM_COLLIDERSWATER];

	bool playsoundlvl2 = false;
	bool checkpointpassed = false;

};

#endif // __MODULELVL2_H__
