#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

#define SPEED_PLAYER 1

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:
	bool dead = false;
	bool colup = false;
	bool coldown = false;
	bool colleft = false;
	bool colright = false;
	bool blockUL = false;
	bool blockUR = false;
	bool blockDL = false;
	bool blockDR = false;
	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation up;
	Animation down;
	Animation left;
	Animation ur;
	Animation ul;
	Animation dr;
	Animation dl;
	Animation die;
	Collider* p;
	Animation right;
	iPoint position;
	int contd = 0;
};

#endif