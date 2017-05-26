#ifndef __MODULESECRETAREAS_H__
#define __MODULESECRETAREAS_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModulePowerUp.h"

#define NUM_COLLIDERSWALL 9
#define NUM_COLLIDERSUPSTAIRS 10
#define NUM_POWERUPS_SA 50

enum SECRETROOM {
	ROOM1,
	ROOM2,
	ROOM3,
	ROOM4,
	ROOM5,
	ROOM6,
	MAX_COUNTER_ROOM
};

struct SDL_Texture;
struct PowerUp;

class ModuleSecretAreas : public Module
{
public:
	ModuleSecretAreas();
	~ModuleSecretAreas();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	
	SECRETROOM secret_room[SECRETROOM::MAX_COUNTER_ROOM];
	SECRETROOM actual_room;
	SDL_Texture* alphabet = nullptr;
	SDL_Texture* swall = nullptr;
	SDL_Texture* rect = nullptr;
	SDL_Texture* items = nullptr;
	SDL_Texture* background1 = nullptr;
	Collider* wall[NUM_COLLIDERSWALL];
	Collider* upstairs[NUM_COLLIDERSUPSTAIRS];
	PowerUp* powerups_sa[NUM_POWERUPS_SA];

	Animation gascounter;
	Animation welcometo;
	Animation* ystair = nullptr;
	Animation yellowstair;
	Animation yellowstairinv;

	bool isup = false;
	bool isdown = false;
	bool gateopened = false;
	bool playdorosound = true;

	fPoint swallposition;
	uint hgcounter = 0;
	uint mgcounter = 0;

	SDL_Rect* gpointer = nullptr;
	SDL_Rect hg_rect;
	SDL_Rect mg_rect;

};




#endif // __MODULESECRETAREAS_H__

