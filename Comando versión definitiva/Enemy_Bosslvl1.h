#ifndef __ENEMY_BOSSLVL1_H__
#define __ENEMY_BOSSLVL1_H__

#include "Enemy.h"

class Enemy_Bosslvl1 : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	Animation default;
	Animation Bosslvl1_Die;
	Animation Bosslvl1_Left;
	Animation Bosslvl1_Right;
	Animation Bosslvl1_Up;
	Animation Bosslvl1_Down;
	bool moving[4];
	enum MOVE_STATE {
		GOING_UP,
		GOING_DOWN,
		GOING_LEFT,
		GOING_RIGHT,
		NO_STATE
	};
public:
	void PathUp();
	void PathDown();
	void PathLeft();
	void PathRight();
	Animation getDie();
	Enemy_Bosslvl1(int x, int y);
	void Move();
};

#endif 