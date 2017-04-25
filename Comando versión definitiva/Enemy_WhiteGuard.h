#ifndef __ENEMY_WHITEGUARD_H__
#define __ENEMY_WHITEGUARD_H__

#include "Enemy.h"

class Enemy_WhiteGuard : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	Animation default;
	Animation WhiteGuard_Die;
	Animation WhiteGuard_Left;
	Animation WhiteGuard_Right;
	Animation WhiteGuard_Up;
	Animation WhiteGuard_Down;
	bool moving[4] = {false, false, false, false};
	bool* movingptr = moving;
public:
	bool* getMoving() const;
	void PathUp();
	void PathDown();
	void PathLeft();
	void PathRight();
	Animation getDie();
	Enemy_WhiteGuard(int x, int y);
	void Move();
};

#endif 