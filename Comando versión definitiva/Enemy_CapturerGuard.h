#ifndef __ENEMY_CAPTURERGUARD_H__
#define __ENEMY_CAPTURERGUARD_H__

#include "Enemy.h"

class Enemy_CapturerGuard : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	Animation CapturerGuard_Default;
	Animation CapturerGuard_Die;
	
	bool moving[4];
	enum MOVE_STATE {
		GOING_UP,
		GOING_DOWN,
		GOING_LEFT,
		GOING_RIGHT,
		NO_STATE
	};
public:
	Animation getDie();
	Enemy_CapturerGuard(int x, int y);
	void Move();
};

#endif // __ENEMY_REDBIRD_H__