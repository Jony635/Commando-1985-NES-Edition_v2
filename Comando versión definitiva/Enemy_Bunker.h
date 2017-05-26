#ifndef __ENEMY_BUNKER_H__
#define __ENEMY_BUNKER_H__

#include "Enemy.h"

class Enemy_Bunker : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;

	Animation LEFT_Bunker_Top;
	Animation LEFT_Bunker_Mid;
	Animation LEFT_Bunker_Bot;

	Animation RIGHT_Bunker_Top;
	Animation RIGHT_Bunker_Mid;
	Animation RIGHT_Bunker_Bot;

	Animation iddle;
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
	Enemy_Bunker(int x, int y);
	void Move();


	float vx = 0.0f, vy = 0.0f;
	int frames = 1;



	double sino = 0.0;
	double cosino = 0.0;
	double angle = 0.0;
	int shoots = 4;
	bool shootmadafuka = true;
	float shoot_counter = 0.0f;
	int shoot_vx = 0, shoot_vy = 0;
	int distance = 0;

};

#endif 