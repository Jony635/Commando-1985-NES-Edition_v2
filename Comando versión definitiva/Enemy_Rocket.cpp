#include "Application.h"
#include "Enemy_Rocket.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
#include "ModuleParticles.h"

Enemy_Rocket::Enemy_Rocket(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	
	//Down Animation
	Rocket_Down.PushBack({ 172, 0, 16, 27 });
	Rocket_Down.PushBack({ 189, 0, 16, 28 });
	Rocket_Down.speed = 0.07f;

	collider = App->collision->AddCollider({ 0, 0, 16, 28 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	animation = &Rocket_Down;
	original_pos.x = x;
	original_pos.y = y;
}

bool* Enemy_Rocket::getMoving() const
{
	return movingptr;
}
void Enemy_Rocket::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.7f }, 70, &Rocket_Down);
	path.Reset();
}

void Enemy_Rocket::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &Rocket_Down);
	path.Reset();
}


void Enemy_Rocket::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &Rocket_Down);
	path.Reset();
}

void Enemy_Rocket::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &Rocket_Down);
	path.Reset();
}

void Enemy_Rocket::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.7f, 0 }, 70, &Rocket_Down);
	path.Reset();
}

void Enemy_Rocket::ColPathLeft()
{
	path.PushBack({ -0.7f, 0 }, 12, &Rocket_Down);
	path.Reset();
}
void Enemy_Rocket::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.7f, 0 }, 70, &Rocket_Down);
	path.Reset();
}

void Enemy_Rocket::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &Rocket_Down);
	path.Reset();
}
Animation Enemy_Rocket::getDie()
{
	return Rocket_Down;
}
void Enemy_Rocket::Move()
{
	if (App->player->position.x - position.x < -5 ) //Muevete pa la iskierda
	{
		vx = -0.8f;
		vy = 0.0f;
		anim = &Rocket_Down;
		frames = position.x - App->player->position.x;


	}
	else if (App->player->position.x - position.x > 5) //Muevete pa la deresha
	{
		vx = 0.8f;
		vy = 0.0f;
		anim = &Rocket_Down;
		frames = App->player->position.x - position.x;
	}
	else
	{
		anim = &Rocket_Down;
	}
	if (numRockets < 3)
	{
		App->particles->Rocket.life = 500;
		App->particles->Rocket.speed.x = 0;
		App->particles->Rocket.speed.y = 5;
		App->particles->AddParticle(App->particles->Rocket, position.x, position.y, COLLIDER_ENEMY_SHOT);
		numRockets++;
	}

	if (!(numRockets < 3))
	{
		ShootCounter += 0.2f;
	}
	if (ShootCounter >= 50.0f)
	{
		ShootCounter = 0.0f;
		numRockets = 0;
	}

	path.Reset();
	path.ResetlastStep();
	path.PushBack({ vx, vy }, frames, anim);
	position = original_pos + path.GetCurrentPosition(&animation);

}