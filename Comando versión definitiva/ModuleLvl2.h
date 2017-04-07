#ifndef __MODULELVL2_H__
#define __MODULELVL2_H__

#include "Module.h"

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
	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	Animation enemyally;
	Animation enemydie;
	Collider* enemy;
	bool enemydie_indicator = false;
};

#endif // __MODULELVL2_H__
