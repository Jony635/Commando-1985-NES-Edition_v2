#include "Application.h"
#include "Enemy_Motorbike.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
#include "ModuleAudio.h"
Enemy_Motorbike::Enemy_Motorbike(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	
	//Left Animation
	Motorbike_Left.PushBack({ 1, 112, 45, 22 });
	
	//Right Animation
	Motorbike_Right.PushBack({ 143, 177, 45, 22 });
	

	collider = App->collision->AddCollider({ 0, 0, 16, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &Motorbike_Left;
	original_pos.x = x;
	original_pos.y = y;
}

bool* Enemy_Motorbike::getMoving() const
{
	return movingptr;
}
void Enemy_Motorbike::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.7f }, 70, &Motorbike_Left);
	path.Reset();
}

void Enemy_Motorbike::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &Motorbike_Left);
	path.Reset();
}


void Enemy_Motorbike::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &Motorbike_Left);
	path.Reset();
}

void Enemy_Motorbike::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &Motorbike_Left);
	path.Reset();
}

void Enemy_Motorbike::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.7f, 0 }, 70, &Motorbike_Left);
	path.Reset();
}

void Enemy_Motorbike::ColPathLeft()
{
	path.PushBack({ -0.7f, 0 }, 12, &Motorbike_Left);
	path.Reset();
}
void Enemy_Motorbike::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.7f, 0 }, 70, &Motorbike_Left);
	path.Reset();
}

void Enemy_Motorbike::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &Motorbike_Left);
	path.Reset();
}
Animation Enemy_Motorbike::getDie()
{
	return Motorbike_Left;
}
void Enemy_Motorbike::Move()
{
	if(App->player->position.y==position.y)
	{
		if (App->player->position.x < position.x)
		{
			path.PushBack({-2.0f, 0.0f}, 500, &Motorbike_Left);
			App->audio->PlaySound("Resources/Audio/Sound Effects/Motorbike_Car is here.wav");
		}
		else
		{
			path.PushBack({ 2.0f, 0.0f }, 500, &Motorbike_Right);
			App->audio->PlaySound("Resources/Audio/Sound Effects/Motorbike_Car is here.wav");
		}
	}

	position = original_pos + path.GetCurrentPosition(&animation);

}