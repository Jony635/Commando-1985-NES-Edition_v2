#include "Application.h"
#include "Enemy_Car.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
#include "ModuleAudio.h"
Enemy_Car::Enemy_Car(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	//Default Animation
	Car_Down.PushBack({ 198,91,32,28 });
	

	

	collider = App->collision->AddCollider({ 0, 0, 32, 28 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	animation = &Car_Down;
	original_pos.x = x;
	original_pos.y = y;
	
}

Animation Enemy_Car::getDie()
{
	return Car_Down;
}
void Enemy_Car::Move()
{
	if (!firstSpawn)
	{
		position.x = App->player->position.x;
		firstSpawn = true;
		App->audio->PlaySound("Resources/Audio/Sound Effects/Motorbike_Car is here.wav");
		path.PushBack({ 0.0f, 2.0f }, 1000, &Car_Down);
	}

	
	position = original_pos + path.GetCurrentPosition(&animation);
}