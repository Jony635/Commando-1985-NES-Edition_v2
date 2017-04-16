#ifndef __MODULELVL1_H__
#define __MODULELVL1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

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
	Collider* wall1;
	int cont = 0;



};

#endif // __MODULELVL1_H__

