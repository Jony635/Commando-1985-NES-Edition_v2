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
	SDL_Texture* leters = nullptr;

	SDL_Rect redzero;
	SDL_Rect redone;
	SDL_Rect redtwo;
	SDL_Rect redthree;
	SDL_Rect redfour;
	SDL_Rect redfive;
	SDL_Rect redsix;
	SDL_Rect redseven;
	SDL_Rect redeight;
	SDL_Rect rednine;
	SDL_Rect highsc;
	SDL_Rect zero;
	SDL_Rect one;
	SDL_Rect two;
	SDL_Rect three;
	SDL_Rect four;
	SDL_Rect five;
	SDL_Rect six;
	SDL_Rect seven;
	SDL_Rect eight;
	SDL_Rect nine;
	SDL_Rect pone;
};

#endif // _MODULEWELCOME_H