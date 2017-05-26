#ifndef __ENEMY_HOLE_H__
#define __ENEMY_HOLE_H__

#include "Enemy.h"

class Enemy_Hole : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	
	Animation Hole_Down;

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
	Enemy_Hole(int x, int y);
	void Move();
};

#endif 