#ifndef __ENEMY_BOSSGRENADE_H__
#define __ENEMY_BOSSGRENADE_H__

#include "Enemy.h"

class Enemy_BossGrenade : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	Animation BossGrenade_Stand;
	Animation BossGrenade_DownGrenade;

	bool moving[4];
	enum MOVE_STATE {
		GOING_UP,
		GOING_DOWN,
		GOING_LEFT,
		GOING_RIGHT,
		NO_STATE
	};
public:
	float vx = 0.0f;
	float vy = 0.0f;
	int frames=0;
	bool grenading = false;
	Animation* anim = nullptr;


	float grenadecounter = 0.0f;
	float counterReset = 0.0f;
	Animation getDie();
	Enemy_BossGrenade(int x, int y);
	void Move();
};

#endif 