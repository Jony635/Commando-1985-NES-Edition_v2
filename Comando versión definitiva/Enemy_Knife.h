#ifndef __ENEMY_KNIFE_H__
#define __ENEMY_KNIFE_H__

#include "Enemy.h"

class Enemy_Knife : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	Animation default;
	Animation Knife_Die;
	Animation Knife_Left;
	Animation Knife_Right;
	Animation Knife_Up;
	Animation Knife_Down;
	bool moving[4] = { false, false, false, false };
	bool* movingptr = moving;
public:
	bool* getMoving() const;
	void ColPathDown();
	void ColPathUp();
	void ColPathRight();
	void ColPathLeft();
	void PathUp();
	void PathDown();
	void PathLeft();
	void PathRight();
	Animation getDie();
	Enemy_Knife(int x, int y);
	void Move();
};

#endif 