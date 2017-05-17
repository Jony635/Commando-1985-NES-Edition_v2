#include "Application.h"
#include "Enemy_Knife.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
Enemy_Knife::Enemy_Knife(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	//Die Animation
	Knife_Die.PushBack({ 2, 68, 16, 26 });
	Knife_Die.PushBack({ 20, 68, 16, 26 });
	Knife_Die.PushBack({ 36, 68, 16, 26 });
	Knife_Die.PushBack({ 51, 68, 16, 26 });
	Knife_Die.loop = false;
	Knife_Die.speed = 0.07f;
	//Left Animation
	Knife_Left.PushBack({ 200, 147, 16, 22 });
	Knife_Left.PushBack({ 153, 81, 16, 22 });
	Knife_Left.speed = 0.07f;
	//Right Animation
	Knife_Right.PushBack({ 183, 147, 16, 22 });
	Knife_Right.PushBack({ 178, 81, 16, 22 });
	Knife_Right.speed = 0.07f;
	//Up Animation
	Knife_Up.PushBack({ 235, 147, 11, 22 });
	Knife_Up.PushBack({ 248, 147, 11, 22 });
	Knife_Up.speed = 0.07f;
	//Down Animation
	Knife_Down.PushBack({ 218, 147, 15, 22 });
	Knife_Down.PushBack({ 129, 81, 15, 22 });
	Knife_Down.speed = 0.07f;

	collider = App->collision->AddCollider({ 0, 0, 10, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	animation = &Knife_Left;
	original_pos.x = x;
	original_pos.y = y;
}

bool* Enemy_Knife::getMoving() const
{
	return movingptr;
}
void Enemy_Knife::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.7f }, 70, &Knife_Up);
	path.Reset();
}

void Enemy_Knife::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &Knife_Up);
	path.Reset();
}


void Enemy_Knife::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &Knife_Down);
	path.Reset();
}

void Enemy_Knife::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &Knife_Down);
	path.Reset();
}

void Enemy_Knife::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.7f, 0 }, 70, &Knife_Left);
	path.Reset();
}

void Enemy_Knife::ColPathLeft()
{
	path.PushBack({ -0.7f, 0 }, 12, &Knife_Left);
	path.Reset();
}
void Enemy_Knife::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.7f, 0 }, 70, &Knife_Right);
	path.Reset();
}

void Enemy_Knife::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &Knife_Right);
	path.Reset();
}
Animation Enemy_Knife::getDie()
{
	return Knife_Die;
}
void Enemy_Knife::Move()
{
	int move = rand() % 4;
	if (move == MOVE_STATE::GOING_UP && !moving[MOVE_STATE::GOING_UP] && path.getCurrent_Frame() == 0)
	{
		PathUp();
	}
	else if (move == MOVE_STATE::GOING_DOWN && !moving[MOVE_STATE::GOING_DOWN] && path.getCurrent_Frame() == 0)
	{
		PathDown();
	}
	else if (move == MOVE_STATE::GOING_LEFT && !moving[MOVE_STATE::GOING_LEFT] && path.getCurrent_Frame() == 0)
	{
		PathLeft();
	}
	else if (move == MOVE_STATE::GOING_RIGHT && !moving[MOVE_STATE::GOING_RIGHT] && path.getCurrent_Frame() == 0)
	{
		PathRight();
	}

	position = original_pos + path.GetCurrentPosition(&animation);

}