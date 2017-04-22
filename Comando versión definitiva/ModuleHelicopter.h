#ifndef _MODULEHELICOPTER_H_
#define _MODULEHELICOPTER_H_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleHelicopter : public Module
{
public:
	ModuleHelicopter();
	~ModuleHelicopter();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics4 = nullptr;
	SDL_Texture* graphics5 = nullptr;
	SDL_Texture* background = nullptr;
	Animation bigh;
	Animation medh;
	Animation smallh;
	Animation joevoid;
	Animation joejump;
	Animation joegoodbye;
	Animation joerun;
	Animation* current_animationh = nullptr;
	Animation* current_animationjoe = nullptr;


	float positionhy;
	float positionhx;
	float positionjoex;
	float positionjoey;
	float contanimh = 0;
	float contanimj = 0;

	

};

#endif // _MODULEHELICOPTER_H_

