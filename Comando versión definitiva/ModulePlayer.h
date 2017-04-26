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
	SDL_Texture* graphics2 = nullptr;
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
	Animation die_w;
	Collider* p;
	Collider* bridge;
	Animation right;
	iPoint position;
	SDL_Rect bridgelvl1;
	int contdead = 0;
	float time = 0;
	int contlives = 4;
	float timeintro = 0;
	bool musend = false;
	int score = 0;
	int hs[6];
	int sc[6];
	int exp1, exp2;
	bool win = false;
	int highscore = 0;
	bool ftimediemusic = false;
	bool fhs = false;

};

#endif