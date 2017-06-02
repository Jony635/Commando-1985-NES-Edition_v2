#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"

#include "Enemy.h"
#include "Enemy_WhiteGuard.h"
#include "Enemy_Bosslvl1.h"
#include "Enemy_CapturerGuard.h"
#include "Enemy_Knife.h"

#define MAX_ENEMIES 200


class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
	char* cpath = "NULL";
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y, char* cpath="NULL");

	uint Enemies_Alive();

private:

	void SpawnEnemy(const EnemyInfo& info);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
};

#endif // __ModuleEnemies_H__