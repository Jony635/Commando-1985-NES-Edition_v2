#ifndef __MODULELVL1_H__
#define __MODULELVL1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define NUM_COLLIDERSWALL 90
#define NUM_COLLIDERSWATER 5

struct SDL_Texture;

class ModuleLvl1 : public Module
{
public:
	ModuleLvl1();
	~ModuleLvl1();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	SDL_Texture* graphics3 = nullptr;
	SDL_Texture* background = nullptr;
	Animation ally;
	Animation ally2;
	Animation ally3;
	Animation box;
	Animation box2;
	Animation box3;
	Animation box4;
	Animation box5;
	Animation box6;
	Animation enemyally;
	Animation enemyally2;
	Animation bigh;
	Animation medh;
	Animation smallh;
	Animation* current_animationh = nullptr;

	

	iPoint positionh;


	//Colliders
	Collider* wall[NUM_COLLIDERSWALL];
	Collider* water[NUM_COLLIDERSWATER];


	int cont = 0;
	bool intro = true;
	bool big = true;
	bool medium = false;
	bool small = false;
	float contanimh = 0;
	bool forward = false;

};

#endif // __MODULELVL1_H__

