#ifndef __ENEMY_TRUCK_H__
#define __ENEMY_TRUCK_H__

#include "Enemy.h"

class Enemy_Truck : public Enemy
{
private:
	int original_y = 0;
	int original_x = 0;

	Animation Truck_Left;

	bool moving[4] = { false, false, false, false };
	bool* movingptr = moving;

public:
	bool move = true;
	bool firstSpawn = false;
	float counterTruck = 0.0f;

	/*bool* getMoving() const;
	void ColPathDown();
	void ColPathUp();
	void ColPathRight();
	void ColPathLeft();
	void PathUp();
	void PathDown();
	void PathLeft();
	void PathRight();*/
	Animation getDie();
	Enemy_Truck(int x, int y);
	void Move();
};

#endif 