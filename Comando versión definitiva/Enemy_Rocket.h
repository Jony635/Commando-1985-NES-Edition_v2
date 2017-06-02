#ifndef __ENEMY_ROCKET_H__
#define __ENEMY_ROCKET_H__

#include "Enemy.h"

class Enemy_Rocket : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	
	Animation Rocket_Down;

	bool moving[4] = { false, false, false, false };
	bool* movingptr = moving;
public:
	
	float vx = 0.0f;
	float vy = 0.0f;
	int frames = 0;

	Animation* anim = nullptr;

	float ShootCounter = 0.0f;
	int numRockets = 3;

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
	Enemy_Rocket(int x, int y);
	void Move();
};

#endif 