#ifndef __ENEMY_WHITEGUARD_H__
#define __ENEMY_WHITEGUARD_H__

#include "Enemy.h"

class Enemy_WhiteGuard : public Enemy
{
private:
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

	Animation* anim = &WhiteGuard_Up;

	Animation getDie();

	bool rightleftcentered = false;
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

	Enemy_WhiteGuard(int x, int y);
	void Move();
	//I WANNA DIE

	float vx = 0.0f, vy = 0.0f;
	int frames = 1;

	int P_relative_y = 0;
	int E_relative_y = 0;

	double sino = 0.0;
	double cosino = 0.0;
	double angle = 0.0;
	int shoots = 2;
	bool shootmadafuka = true;
	float shoot_counter = 0.0f;
	int shoot_vx = 0, shoot_vy = 0;
	int distance = 0;
};

#endif 