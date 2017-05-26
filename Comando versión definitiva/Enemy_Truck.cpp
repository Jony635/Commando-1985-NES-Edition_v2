#include "Application.h"
#include "Enemy_Truck.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
#include "ModuleAudio.h"
Enemy_Truck::Enemy_Truck(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	//Default Animation
	Truck_Left.PushBack({ 14,141,48,31 });




	collider = App->collision->AddCollider({ 0, 0, 48, 31 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &Truck_Left;
	original_pos.x = x;
	original_pos.y = y;
	
}

Animation Enemy_Truck::getDie()
{
	return Truck_Left;
}
void Enemy_Truck::Move()
{
	if (!firstSpawn)
	{
		firstSpawn = true;
		App->audio->PlaySound("Resources/Audio/Sound Effects/Motorbike_Car is here.wav");
	}
	if (move)
	{
		path.Reset();
		path.ResetlastStep();
		path.PushBack({ -2.0f, 0.0f }, 10000, &Truck_Left);
	}

	counterTruck += 0.2;

	if (counterTruck >= 20.0f )
	{
		move = true;
	}
	else if (counterTruck >= 10.0f)
	{
		path.Reset();
		path.ResetlastStep();
		move = false;
	}


	position = original_pos + path.GetCurrentPosition(&animation);
}