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
	bool rightleftcentered = false;
	bool updowncentered = false;
	bool moving[4] = {false, false, false, false};
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
	Enemy_WhiteGuard(int x, int y);
	void Move();
	//I WANNA DIE
	Animation* anim = &WhiteGuard_Up;
	float vx = 0.0f, vy = 0.0f;
	int frames = 1;
};

#endif 