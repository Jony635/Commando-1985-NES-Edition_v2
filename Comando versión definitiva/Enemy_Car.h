#ifndef __ENEMY_CAR_H__
#define __ENEMY_CAR_H__

#include "Enemy.h"

class Enemy_Car : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	
	Animation Car_Down;

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
	Enemy_Car(int x, int y);
	void Move();
	bool firstSpawn = false;
};

#endif 