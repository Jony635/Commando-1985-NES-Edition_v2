#include "Application.h"
#include "Enemy_WhiteGuard.h"
#include "ModuleCollision.h"

Enemy_WhiteGuard::Enemy_WhiteGuard(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 5,6,24,24 });
	fly.PushBack({ 38, 6, 24, 24 });
	fly.PushBack({ 71, 6, 24, 24 });
	fly.PushBack({ 104, 6, 24, 24 });
	fly.PushBack({ 137, 6, 24, 24 });
	fly.PushBack({ 170, 6, 24, 24 });
	fly.PushBack({ 203, 6, 24, 24 });
	fly.PushBack({ 236, 6, 24, 24 });
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_WhiteGuard::Move()
{
	/*if (going_up)
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
	}*/

	path.PushBack({ -0.3f, 0.0f }, 150, &fly);
	position = original_pos + path.GetCurrentPosition();
}