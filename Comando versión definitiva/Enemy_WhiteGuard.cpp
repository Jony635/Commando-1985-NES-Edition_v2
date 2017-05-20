#include "Application.h"
#include "Enemy_WhiteGuard.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
Enemy_WhiteGuard::Enemy_WhiteGuard(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	//Default Animation
	default.PushBack({ 67,0,12,23 });
	default.speed = 0.2f;

	//Die Animation
	WhiteGuard_Die.PushBack({ 2, 68, 16, 26 });
	WhiteGuard_Die.PushBack({ 20, 68, 16, 26 });
	WhiteGuard_Die.PushBack({ 36, 68, 16, 26 });
	WhiteGuard_Die.PushBack({ 51, 68, 16, 26 });
	WhiteGuard_Die.speed = 0.07f;
	//Left Animation
	WhiteGuard_Left.PushBack({ 50, 23, 16, 22 });
	WhiteGuard_Left.PushBack({ 68, 24, 16, 22 });
	WhiteGuard_Left.speed = 0.07f;
	//Right Animation
	WhiteGuard_Right.PushBack({ 32, 0, 16, 22 });
	WhiteGuard_Right.PushBack({ 49, 0, 16, 22 });
	WhiteGuard_Right.speed = 0.07f;
	
	//Up Animation
	WhiteGuard_Up.PushBack({ 35, 46, 11, 21 });
	WhiteGuard_Up.PushBack({ 49, 46, 11, 22 });
	WhiteGuard_Up.speed = 0.07f;
	//Down Animation
	WhiteGuard_Down.PushBack({ 1, 23, 15, 22 });
	WhiteGuard_Down.PushBack({ 17, 23, 15, 22 });
	WhiteGuard_Down.speed = 0.07f;

	collider = App->collision->AddCollider({ 0, 0, 10, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ -0.7f, 0 }, 0, &WhiteGuard_Left);
	path.loop = false;
}

bool* Enemy_WhiteGuard::getMoving() const
{
	return movingptr;
}
void Enemy_WhiteGuard::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.7f }, 70, &WhiteGuard_Up);
	path.Reset();
}

void Enemy_WhiteGuard::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &WhiteGuard_Up);
	path.Reset();
}


void Enemy_WhiteGuard::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &WhiteGuard_Down);
	path.Reset();
}

void Enemy_WhiteGuard::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &WhiteGuard_Down);
	path.Reset();
}

void Enemy_WhiteGuard::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.7f, 0 }, 70, &WhiteGuard_Left);
	path.Reset();
}

void Enemy_WhiteGuard::ColPathLeft()
{
	path.PushBack({ -0.7f, 0 }, 12, &WhiteGuard_Left);
	path.Reset();
}
void Enemy_WhiteGuard::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.7f, 0 }, 70, &WhiteGuard_Right);
	path.Reset();
}

void Enemy_WhiteGuard::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &WhiteGuard_Right);
	path.Reset();
}
Animation Enemy_WhiteGuard::getDie()
{
	return WhiteGuard_Die;
}
void Enemy_WhiteGuard::Move()
{
	if (App->player->position.x - position.x < -5 && !rightleftcentered) //Muevete pa la iskierda
	{
		vx = -0.8f;
		vy = 0.0f;
		anim = &WhiteGuard_Left;
		frames = position.x - App->player->position.x;
		path.Reset();
		path.ResetlastStep();
		path.PushBack({ vx, vy }, frames, anim);
	}
	else if (App->player->position.x - position.x > 5 && !rightleftcentered) //Muevete pa la deresha
	{
		vx = 0.8f;
		vy = 0.0f;
		anim = &WhiteGuard_Right;
		frames = App->player->position.x - position.x;
		path.Reset();
		path.ResetlastStep();
		path.PushBack({ vx, vy }, frames, anim);
	}
	if (App->player->position.x == position.x)
	{
		rightleftcentered = true;
	}

	if (rightleftcentered)
	{
		if (App->player->position.y < position.y) //Movite parriba
		{
			vx = 0.0f;
			vy = -0.8f;
			anim = &WhiteGuard_Up;
			if ((App->player->position.y < 0 && position.y < 0) || (App->player->position.y > 0 && position.y > 0))
			{
				frames = ABS(ABS(App->player->position.y) - ABS(position.y));
			}
			else
			{
				frames = ABS(App->player->position.y) + ABS(position.y);
			}

			path.Reset();
			path.ResetlastStep();
			path.PushBack({ vx, vy }, frames, anim);
		}
		else if (App->player->position.y > position.y) //Movite pabajo
		{
			vx = 0.0f;
			vy = 0.8f;
			anim = &WhiteGuard_Down;
			if ((App->player->position.y < 0 && position.y < 0) || (App->player->position.y > 0 && position.y > 0))
			{
				frames = ABS(ABS(App->player->position.y) - ABS(position.y));
			}
			else
			{
				frames = ABS(App->player->position.y) + ABS(position.y);
			}

			path.Reset();
			path.ResetlastStep();
			path.PushBack({ vx, vy }, frames, anim);

		}
	}
	position = original_pos + path.GetCurrentPosition(&animation);
	rightleftcentered = false;
}