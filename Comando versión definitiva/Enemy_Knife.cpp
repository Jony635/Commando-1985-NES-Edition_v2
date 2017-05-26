#include "Application.h"
#include "Enemy_Knife.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
Enemy_Knife::Enemy_Knife(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	
	//Left Animation
	Knife_Left.PushBack({ 194, 39, 16, 8 });
	//Right Animation
	Knife_Right.PushBack({ 213, 39, 16, 8 });

	collider = App->collision->AddCollider({ 0, 0, 16, 8 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
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

	path.PushBack({ 0, -0.7f }, 70, &Knife_Left);
	path.Reset();
}

void Enemy_Knife::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &Knife_Left);
	path.Reset();
}


void Enemy_Knife::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &Knife_Left);
	path.Reset();
}

void Enemy_Knife::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &Knife_Left);
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

	path.PushBack({ 0.7f, 0 }, 70, &Knife_Left);
	path.Reset();
}

void Enemy_Knife::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &Knife_Left);
	path.Reset();
}
Animation Enemy_Knife::getDie()
{
	return Knife_Left;
}
void Enemy_Knife::Move()
{
	if (App->player->position.y == position.y)
	{
		if (App->player->position.x < position.x)
		{
			path.PushBack({ -2.0f, 0.0f }, 500, &Knife_Left);
		}
		else
		{
			path.PushBack({ 2.0f, 0.0f }, 500, &Knife_Right);
		}
	}
	position = original_pos + path.GetCurrentPosition(&animation);

}