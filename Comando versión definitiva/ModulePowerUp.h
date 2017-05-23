#ifndef MODULE_POWER_UP_H
#define MODULE_POWER_UP_H

#include "Module.h"
#include "Animation.h"
#include "ModuleTextures.h" 
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_POWERUP 100


enum PowerUp_Types 
{
	POWERUP_NO_TYPE = -1,
	BINOCULAR,
	BULLETPROOF_VEST,
	GASOLINE,
	GRENADEx4,
	GRENADEx5,
	MEDAL,
	MEDAL_OF_HONOR,
	BARREL,
	BAG,
	MAX_POWERUP_TYPE
};

struct PowerUp
{
	Collider* collider = nullptr;
	Animation anim;
	iPoint position;
	PowerUp_Types type;
	bool fx_played = false;


	PowerUp();
	~PowerUp();
};

class ModulePowerUp : public Module
{
public:
	ModulePowerUp();
	~ModulePowerUp();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddPowerUp(const PowerUp_Types type, int x, int y);

	Animation binocular;
	Animation bulletproof_vest;
	Animation gasoline;
	Animation grenadex4;
	Animation grenadex5;
	Animation medal;
	Animation medal_of_honor;
	Animation barrel;
	Animation bag;
	SDL_Texture* graphics = nullptr;

private:

	//SDL_Texture* graphics = nullptr;
	PowerUp* powerups[MAX_POWERUP];
};

#endif
