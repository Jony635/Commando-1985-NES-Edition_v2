#include "Application.h"
#include "Enemy_Bunker.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
#include "ModuleParticles.h"
Enemy_Bunker::Enemy_Bunker(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));

	LEFT_Bunker_Top.PushBack({ 85, 249, 38, 47 });
	LEFT_Bunker_Mid.PushBack({ 44, 248, 39, 47 });
	LEFT_Bunker_Bot.PushBack({ 4, 248, 38, 47 });

	RIGHT_Bunker_Top.PushBack({ 131, 248, 38, 47 });
	RIGHT_Bunker_Mid.PushBack({ 172, 247, 39, 47 });
	RIGHT_Bunker_Bot.PushBack({ 216, 243, 38, 47 });

	iddle.PushBack({ 192, 215, 22, 25 });

	collider = App->collision->AddCollider({ 0, 0, 39, 47 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	animation = &LEFT_Bunker_Mid;
	original_pos.x = x;
	original_pos.y = y;
}

bool* Enemy_Bunker::getMoving() const
{
	return movingptr;
}
void Enemy_Bunker::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.7f }, 70, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.7f, 0 }, 70, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::ColPathLeft()
{
	path.PushBack({ -0.7f, 0 }, 12, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.7f, 0 }, 70, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &LEFT_Bunker_Mid);
	path.Reset();
}
Animation Enemy_Bunker::getDie()
{
	return LEFT_Bunker_Mid;
}

void Enemy_Bunker::Move()
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

		if (distance < 300 && App->player->position.y<0 && position.y<0 && shootmadafuka)
		{
			angle = atan2((double)ABS(App->player->position.y) - ABS(position.y), (double)App->player->position.x - position.x); //Angulo en radianes, enemigo arriba
			this->sino = sin(angle);
			this->cosino = cos(angle);


			if (cosino < 0) cosino *= -1;
			if (sino < 0) sino *= -1;

			if (App->player->position.x < position.x)
			{
				shoot_vx = -2 * cosino;
				if (cosino >= 0.75)
					animation = &LEFT_Bunker_Bot;
				if (cosino > 0.25 && cosino < 0.75)
					animation = &LEFT_Bunker_Mid;
				else
					animation = &LEFT_Bunker_Top;
				
			}

			else if (App->player->position.x > position.x)
			{
				shoot_vx = 2 * cosino;
				if (cosino >= 0.75)
					animation = &LEFT_Bunker_Bot;
				if (cosino > 0.25 && cosino < 0.75)
					animation = &LEFT_Bunker_Mid;
				else
					animation = &LEFT_Bunker_Top;
			}
				
			else
			{
				shoot_vx = 0;
				animation = &iddle;
			}
			if (App->player->position.y < position.y)
				shoot_vy = -2 * sino;
			else if (App->player->position.y > position.y)
				shoot_vy = 2 * sino;
			else
				shoot_vy = 2;

			App->particles->mega_bullet.life = 10000;
			App->particles->mega_bullet.speed.x = shoot_vx;
			App->particles->mega_bullet.speed.y = shoot_vy;
			App->particles->AddParticle(App->particles->mega_bullet, position.x, position.y, COLLIDER_ENEMY_SHOT);
			shoots++;
		}
		if (shoots == 4)
		{
			shootmadafuka = false;
			shoot_counter += 0.2f;
		}
		if (shoot_counter >= 30.0f)
		{
			shootmadafuka = true;
			shoot_counter = 0.0f;
		}

	}


	position = original_pos + path.GetCurrentPosition(&animation);

}