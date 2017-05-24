#ifndef __RUNNER_H__
#define __RUNNER_H__

#include "Enemy.h"

class Runner : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	Animation RunnerRight_Points;
	Animation RunnerRight_MachineGun;
	Animation RunnerRight_Grenades;

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
	Runner(int x, int y);
	void Move();
};

#endif 