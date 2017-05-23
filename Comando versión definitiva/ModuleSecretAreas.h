#ifndef __MODULESECRETAREAS_H__
#define __MODULESECRETAREAS_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define NUM_COLLIDERSWALL 9
#define NUM_COLLIDERSUPSTAIRS 1

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
	SDL_Texture* rect = nullptr;
	SDL_Texture* items = nullptr;
	SDL_Texture* background1 = nullptr;
	Collider* wall[NUM_COLLIDERSWALL];
	Collider* upstairs[NUM_COLLIDERSUPSTAIRS];

	Animation gascounter;
	Animation welcometo;
	Animation yellowstair;


	bool isup = false;
	bool isdown = false;

};




#endif // __MODULESECRETAREAS_H__

