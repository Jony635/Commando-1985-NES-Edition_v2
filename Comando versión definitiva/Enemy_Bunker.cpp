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

	collider = App->collision->AddCollider({ 0, 0, 39, 47 }, COLLIDER_TYPE::COLLIDER_DIE, (Module*)App->enemies);
	animation = &iddle;
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
	//ANIMATIONS
	if (App->player->position.x > position.x + 39)
	{
		if (App->player->position.y < position.y +20)
		{
			animation = &LEFT_Bunker_Top;
		}
		else if (App->player->position.y > position.y + 37)
		{
			animation = &LEFT_Bunker_Bot;
		}
		else
			animation = &LEFT_Bunker_Mid;
	}
	
	else if (App->player->position.x < position.x)
	{
		if (App->player->position.y < position.y + 20)
		{
			animation = &RIGHT_Bunker_Top;
		}
		else if (App->player->position.y > position.y + 37)
		{
			animation = &RIGHT_Bunker_Bot;
		}
		else
			animation = &RIGHT_Bunker_Mid;
	}
	else
	{
		animation = &iddle;
	}
	//SHOOTS
	if (shoots > 0 && !gominicounter)
	{
		if (App->player->position.y<0 && position.y<0)
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

			App->particles->mega_bullet.life = 8000;
			App->particles->mega_bullet.speed.x = shoot_vx;
			App->particles->mega_bullet.speed.y = shoot_vy;
			if(animation==&LEFT_Bunker_Bot || animation==&LEFT_Bunker_Mid || animation == &LEFT_Bunker_Top)
				App->particles->AddParticle(App->particles->mega_bullet, position.x+39, position.y+24, COLLIDER_ENEMY_SHOT);
			else if(animation == &RIGHT_Bunker_Bot || animation == &RIGHT_Bunker_Mid || animation == &RIGHT_Bunker_Top)
				App->particles->AddParticle(App->particles->mega_bullet, position.x, position.y+24, COLLIDER_ENEMY_SHOT);
			shoots--;
			gominicounter = true;
			
		}
	}
	if (gominicounter)
	{
		minicounter += 0.2f;
	}
	if (minicounter >= 1.2f)
	{
		minicounter = 0.0f;
		gominicounter = false;
	}
	if (shoots == 0)
	{
		shoot_counter += 0.2f;
	}
	if (shoot_counter >= 30.0f)
	{

		shoots = 4;
		shoot_counter = 0.0f;
	}

	position = original_pos + path.GetCurrentPosition(&animation);

}