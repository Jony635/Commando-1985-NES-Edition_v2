#ifndef __ENEMY_PATHWHITEGUARD_H__
#define __ENEMY_PATHWHITEGUARD_H__

#include "Enemy.h"

class Enemy_PathWhiteGuard : public Enemy
{
private:
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;

	Animation default;
	Animation PathWhiteGuard_Die;
	Animation PathWhiteGuard_Left;
	Animation PathWhiteGuard_Right;
	Animation PathWhiteGuard_Up;
	Animation PathWhiteGuard_Down;

	Animation* anim = &PathWhiteGuard_Up;

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

	Enemy_PathWhiteGuard(int x, int y);
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