#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#define MAX_COLLIDERS 500

#include "Module.h"
#include "Enemy.h"
#include "ModulePowerUp.h"

enum COLLIDER_TYPE
{
	COLLIDER_NONE = -1,
	COLLIDER_WALL,
	COLLIDER_PLAYER,
	COLLIDER_ENEMY,
	COLLIDER_PLAYER_SHOT,
	COLLIDER_ENEMY_SHOT,
	COLLIDER_WATER,
	COLLIDER_ANTIBULLET,
	COLLIDER_PLAYER_GRENADE,
	COLLIDER_UPSTAIRS,
	COLLIDER_DOWNSTAIRS, 
	COLLIDER_PLAYER_GRENADE_EXPL,
	COLLIDER_ENEMY_GRENADE_EXPL,
	COLLIDER_ENEMY_GRENADE,
	COLLIDER_POWERUP,
	COLLIDER_DIE,
	COLLIDER_MAX
};

struct Collider
{
	SDL_Rect rect;
	bool to_delete = false;
	COLLIDER_TYPE type;
	Module* callback = nullptr;
	ENEMY_TYPES enemytype = ENEMY_TYPES::NO_TYPE;
	PowerUp_Types poweruptype = PowerUp_Types::POWERUP_NO_TYPE;
	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = nullptr) :
		rect(rectangle),
		type(type),
		callback(callback)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	update_status PreUpdate();
	update_status Update();
	//update_status PostUpdate();
	bool CleanUp();

	Collider* AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback = nullptr);
	bool EraseCollider(Collider* collider);
	void DebugDraw();

private:

	Collider* colliders[MAX_COLLIDERS];
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];
	bool debug = false;
};

#endif // __ModuleCollision_H__