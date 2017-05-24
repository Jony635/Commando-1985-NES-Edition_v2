#include "Application.h"
#include "Runner.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModuleLvl2.h"
#include "ModuleSecretAreas.h"
Runner::Runner(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	
	//Points Animation
	RunnerRight_Points.PushBack({ 10, 209, 16, 32 });
	RunnerRight_Points.PushBack({ 30, 209, 16, 32 });
	RunnerRight_Points.speed = 0.07f;
	//MachineGun Animation
	RunnerRight_MachineGun.PushBack({ 54, 209, 16, 32 });
	RunnerRight_MachineGun.PushBack({ 74, 209, 16, 31 });
	RunnerRight_MachineGun.speed = 0.07f;
	//Grenades Animation
	RunnerRight_Grenades.PushBack({ 139, 212, 16, 32 });
	RunnerRight_Grenades.PushBack({ 159, 212, 16, 31 });
	RunnerRight_Grenades.speed = 0.07f;
	

	collider = App->collision->AddCollider({ 0, 0, 10, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	animation = &RunnerRight_Points;
	original_pos.x = x;
	original_pos.y = y;
	
}

bool* Runner::getMoving() const
{
	return movingptr;
}
void Runner::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.7f }, 70, &RunnerRight_Grenades);
	path.Reset();
}

void Runner::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &RunnerRight_Grenades);
	path.Reset();
}


void Runner::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &RunnerRight_Grenades);
	path.Reset();
}

void Runner::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &RunnerRight_Grenades);
	path.Reset();
}

void Runner::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.7f, 0 }, 70, &RunnerRight_Grenades);
	path.Reset();
}

void Runner::ColPathLeft()
{
	path.PushBack({ -0.7f, 0 }, 12, &RunnerRight_Grenades);
	path.Reset();
}
void Runner::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.7f, 0 }, 70, &RunnerRight_Grenades);
	path.Reset();
}

void Runner::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &RunnerRight_Grenades);
	path.Reset();
}
Animation Runner::getDie()
{
	return RunnerRight_Grenades;
}
void Runner::Move()
{
	if (!App->secretareas->IsEnabled())
	{
		path.Reset();
		path.ResetlastStep();
		path.PushBack({1.0f, 0.0f}, 2000, &RunnerRight_Points);
	}
	else if (App->secretareas->actual_room == SECRETROOM::ROOM4)
	{
		path.Reset();
		path.ResetlastStep();
		path.PushBack({ 1.0f, 0.0f }, 2000, &RunnerRight_Grenades);
	}
	else
	{
		path.Reset();
		path.ResetlastStep();
		path.PushBack({ 1.0f, 0.0f }, 2000, &RunnerRight_MachineGun);
	}

	position = original_pos + path.GetCurrentPosition(&animation);

}