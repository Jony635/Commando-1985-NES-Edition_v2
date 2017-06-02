#include "Application.h"
#include "Enemy_Hole.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
#include "ModuleParticles.h"
Enemy_Hole::Enemy_Hole(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	
	
	
	//Down Animation
	Hole_Down.PushBack({ 70, 84, 13, 16 });
	Hole_Down.PushBack({ 110, 81, 13, 16 });
	Hole_Down.PushBack({ 90, 81, 12, 16 });
	Hole_Down.PushBack({ 110, 81, 13, 16 });
	Hole_Down.speed = 0.05f;

	collider = App->collision->AddCollider({ 0, 0, 13, 16 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	animation = &Hole_Down;
	original_pos.x = x;
	original_pos.y = y;
}

bool* Enemy_Hole::getMoving() const
{
	return movingptr;
}
void Enemy_Hole::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.7f }, 70, &Hole_Down);
	path.Reset();
}

void Enemy_Hole::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &Hole_Down);
	path.Reset();
}


void Enemy_Hole::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &Hole_Down);
	path.Reset();
}

void Enemy_Hole::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &Hole_Down);
	path.Reset();
}

void Enemy_Hole::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.7f, 0 }, 70, &Hole_Down);
	path.Reset();
}

void Enemy_Hole::ColPathLeft()
{
	path.PushBack({ -0.7f, 0 }, 12, &Hole_Down);
	path.Reset();
}
void Enemy_Hole::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.7f, 0 }, 70, &Hole_Down);
	path.Reset();
}

void Enemy_Hole::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &Hole_Down);
	path.Reset();
}
Animation Enemy_Hole::getDie()
{
	return Hole_Down;
}
void Enemy_Hole::Move()
{
	if ((int)animation->current_frame == 0  && ABS(ABS(App->player->position.x)-ABS(position.x))<10 && shootcounter==0.0f)
	{
		App->particles->bullet.life = 10000;
		App->particles->bullet.speed.x = 0;
		App->particles->bullet.speed.y = 2;
		App->particles->AddParticle(App->particles->bullet, position.x, position.y, COLLIDER_ENEMY_SHOT);
		runcounterrun = true;
	}
	if (runcounterrun)
	{
		shootcounter += 0.2f;
	}
	if (shootcounter >= 4.0f)
	{
		shootcounter = 0.0f;
		runcounterrun = false;
	}
	position = original_pos + path.GetCurrentPosition(&animation);

}