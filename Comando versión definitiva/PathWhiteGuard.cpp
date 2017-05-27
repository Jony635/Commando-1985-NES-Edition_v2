#include "Application.h"
#include "PathWhiteGuard.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include <math.h>

Enemy_PathWhiteGuard::Enemy_PathWhiteGuard(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	//Default Animation
	default.PushBack({ 67,0,12,23 });
	default.speed = 0.2f;

	//Die Animation
	PathWhiteGuard_Die.PushBack({ 2, 68, 16, 26 });
	PathWhiteGuard_Die.PushBack({ 20, 68, 16, 26 });
	PathWhiteGuard_Die.PushBack({ 36, 68, 16, 26 });
	PathWhiteGuard_Die.PushBack({ 51, 68, 16, 26 });
	PathWhiteGuard_Die.speed = 0.07f;
	//Left Animation
	PathWhiteGuard_Left.PushBack({ 50, 23, 16, 22 });
	PathWhiteGuard_Left.PushBack({ 68, 24, 16, 22 });
	PathWhiteGuard_Left.speed = 0.07f;
	//Right Animation
	PathWhiteGuard_Right.PushBack({ 32, 0, 16, 22 });
	PathWhiteGuard_Right.PushBack({ 49, 0, 16, 22 });
	PathWhiteGuard_Right.speed = 0.07f;

	//Up Animation
	PathWhiteGuard_Up.PushBack({ 35, 46, 11, 21 });
	PathWhiteGuard_Up.PushBack({ 49, 46, 11, 22 });
	PathWhiteGuard_Up.speed = 0.07f;
	//Down Animation
	PathWhiteGuard_Down.PushBack({ 1, 23, 15, 22 });
	PathWhiteGuard_Down.PushBack({ 17, 23, 15, 22 });
	PathWhiteGuard_Down.speed = 0.07f;

	collider = App->collision->AddCollider({ 0, 0, 16, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	path.PushBack({ +0.8f, 0 }, 120, &PathWhiteGuard_Right);
	path.PushBack({ 0, +0.8f }, 70, &PathWhiteGuard_Down);
	path.PushBack({ +0.8f, 0 }, 90, &PathWhiteGuard_Right);
	path.PushBack({ 0, +0.8f }, 100, &PathWhiteGuard_Down);
	path.PushBack({ +0.8f, 0 }, 20, &PathWhiteGuard_Right);
	path.PushBack({ 0, -0.8f }, 210, &PathWhiteGuard_Up);
	path.PushBack({ -0.8f, 0 }, 160, &PathWhiteGuard_Left);
	path.PushBack({ 0, +0.8f }, 200, &PathWhiteGuard_Down);
	path.PushBack({ -0.8f, 0 }, 50, &PathWhiteGuard_Left);
	path.PushBack({ 0, -0.8f }, 80, &PathWhiteGuard_Up);
	path.PushBack({ +0.8f, 0 }, 80, &PathWhiteGuard_Right);
	path.PushBack({ 0, +0.8f }, 60, &PathWhiteGuard_Down);
	path.PushBack({ +0.8f, 0 }, 50, &PathWhiteGuard_Right);
	path.PushBack({ 0, -0.8f }, 100, &PathWhiteGuard_Up);
	path.PushBack({ -0.8f, 0 }, 150, &PathWhiteGuard_Left);
	path.PushBack({ 0, -0.8f }, 40, &PathWhiteGuard_Up);


}

bool* Enemy_PathWhiteGuard::getMoving() const
{
	return movingptr;
}
void Enemy_PathWhiteGuard::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.7f }, 70, &PathWhiteGuard_Up);
	path.Reset();
}

void Enemy_PathWhiteGuard::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &PathWhiteGuard_Up);
	path.Reset();
}


void Enemy_PathWhiteGuard::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &PathWhiteGuard_Down);
	path.Reset();
}

void Enemy_PathWhiteGuard::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &PathWhiteGuard_Down);
	path.Reset();
}

void Enemy_PathWhiteGuard::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.7f, 0 }, 70, &PathWhiteGuard_Left);
	path.Reset();
}

void Enemy_PathWhiteGuard::ColPathLeft()
{
	path.PushBack({ -0.7f, 0 }, 12, &PathWhiteGuard_Left);
	path.Reset();
}
void Enemy_PathWhiteGuard::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.7f, 0 }, 70, &PathWhiteGuard_Right);
	path.Reset();
}

void Enemy_PathWhiteGuard::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &PathWhiteGuard_Right);
	path.Reset();
}
Animation Enemy_PathWhiteGuard::getDie()
{
	return PathWhiteGuard_Die;
}
void Enemy_PathWhiteGuard::Move()
{
	
		
	if (shoots > 0)
	{
		if (App->player->position.y < position.y) // Dispara hacia arriba
		{

			if ((App->player->position.y < 0 && position.y < 0) || (App->player->position.y > 0 && position.y > 0))
			{
				distance = ABS(ABS(App->player->position.y) - ABS(position.y));

			}
			else
			{
				distance = ABS(App->player->position.y) + ABS(position.y);
			}
		}
		else if (App->player->position.y > position.y) //Dispara hacia abajo
		{
			if ((App->player->position.y < 0 && position.y < 0) || (App->player->position.y > 0 && position.y > 0))
			{
				distance = ABS(ABS(App->player->position.y) - ABS(position.y));
			}
			else
			{
				distance = ABS(App->player->position.y) + ABS(position.y);
			}
		}

		if (distance < 150 && App->player->position.y<0 && position.y<0 && shootmadafuka)
		{
			angle = atan2((double)ABS(App->player->position.y) - ABS(position.y), (double)App->player->position.x - position.x); //Angulo en radianes, enemigo arriba
			this->sino = sin(angle);
			this->cosino = cos(angle);


			if (cosino < 0) cosino *= -1;
			if (sino < 0) sino *= -1;

			if (App->player->position.x < position.x)
				shoot_vx = -2 * cosino;
			else if (App->player->position.x > position.x)
				shoot_vx = 2 * cosino;
			else shoot_vx = 0;
			if (App->player->position.y < position.y)
				shoot_vy = -2 * sino;
			else if (App->player->position.y > position.y)
				shoot_vy = 2 * sino;
			else
				shoot_vy = 2;

			App->particles->bullet.life = 10000;
			App->particles->bullet.speed.x = shoot_vx;
			App->particles->bullet.speed.y = shoot_vy;
			App->particles->AddParticle(App->particles->bullet, position.x, position.y, COLLIDER_ENEMY_SHOT);
			shoots--;
			shootmadafuka = false;
		}
		if (shoots == 1)
		{
			shoot_counter += 0.2f;
		}
		if (shoot_counter >= 30.0f)
		{
			shootmadafuka = true;
		}

	}

	position = original_pos + path.GetCurrentPosition(&animation);
}