#include "Application.h"
#include "Enemy_WhiteGuard.h"
#include "ModuleCollision.h"

Enemy_WhiteGuard::Enemy_WhiteGuard(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 0,22,16,23 });
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;

	//path.PushBack({ -0.3f, 0.0f }, 150, &fly);
}

void Enemy_WhiteGuard::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	
	position = original_pos + path.GetCurrentPosition();
}