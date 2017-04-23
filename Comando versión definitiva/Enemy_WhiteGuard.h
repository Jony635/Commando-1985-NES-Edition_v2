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
public:
	void PathUp();
	void PathDown();
	void PathLeft();
	void PathRight();
	Animation getWhiteGuard_Die();
	Enemy_WhiteGuard(int x, int y);
	void Move();
};

#endif // __ENEMY_REDBIRD_H__