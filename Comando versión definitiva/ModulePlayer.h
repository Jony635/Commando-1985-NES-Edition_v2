#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "ModulePowerUp.h"

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
	SDL_Texture* byebye = nullptr;
	SDL_Texture* ui_stuff = nullptr;
	SDL_Texture* graphparticles = nullptr;
	SDL_Texture* bridge = nullptr;
	SDL_Texture* bunkers = nullptr;
	SDL_Texture* room1 = nullptr;
	SDL_Texture* room4 = nullptr;
	SDL_Texture* room5 = nullptr;
	SDL_Texture* room6 = nullptr;
	int font_score = -1;
	char score_text[10];
	char lives_text[10];
	char grenades_text[10];
	char high_score_text[10];
	uint score = 0;
	uint live_counter = 4;
	uint granade_counter = 5;
	uint highscore = 0;
	Animation* current_animation = nullptr;
	Animation throwing;
	Animation throwing_godmode;
	Animation upgodmode;
	Animation downgodmode;
	Animation leftgodmode;
	Animation rightgodmode;
	Animation urgodmode;
	Animation ulgodmode;
	Animation dlgodmode;
	Animation drgodmode;
	Animation upstairs;
	Animation downstairs;
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
	bool move = true;
	bool playsounddie = false;
	bool playsounddead = false;
	bool playsoundresp = false;
	bool respawn = false;
	bool godmode = false;
	bool shortgodmode = false;
	bool PlayerPowerUps[PowerUp_Types::MAX_POWERUP_TYPE] = { false, false, false, false, false, false, false, false , false , false, false, false};
	bool soundhighscore = true;
	bool win = false;
	bool winsound = true;
	bool endaudio = true;
};

#endif