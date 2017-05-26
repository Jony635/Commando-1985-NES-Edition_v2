#ifndef __ENEMY_MOTORBIKE_H__
#define __ENEMY_MOTORBIKE_H__

#include "Enemy.h"

class Enemy_Motorbike : public Enemy
{
private:
	int original_y = 0;
	int original_x = 0;
	
	Animation Motorbike_Left;
	Animation Motorbike_Right;
	
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
	Enemy_Motorbike(int x, int y);
	void Move();
};

#endif 