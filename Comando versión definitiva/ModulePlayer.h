#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

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
	
	SDL_Texture* graphics = nullptr;
	SDL_Texture* ui_stuff = nullptr;
	SDL_Texture* graphparticles = nullptr;
	int font_score = -1;
	char score_text[10];
	char lives_text[10];
	char grenades_text[10];
	uint score = 0;
	uint live_counter = 0;
	uint granade_counter = 0;
	Animation* current_animation = nullptr;
	Animation up;
	Animation down;
	Animation left;
	Animation right;
	Animation ur;
	Animation ul;
	Animation dl;
	Animation dr;
	Animation die;
	Animation die_w;
	SDL_Rect bridgelvl2;
	SDL_Rect granade;
	SDL_Rect lives;
	iPoint position;
	Collider* col;
	bool dead = false;
	bool colup = false;
	bool coldown = false;
	bool colleft = false;
	bool colright = false;
	bool blockUL = false;
	bool blockUR = false;
	bool blockDL = false;
	bool blockDR = false;
};

#endif