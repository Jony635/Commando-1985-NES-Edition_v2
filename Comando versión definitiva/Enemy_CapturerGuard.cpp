#include "Application.h"
#include "Enemy_CapturerGuard.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
Enemy_CapturerGuard::Enemy_CapturerGuard(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	//Default Animation
	CapturerGuard_Default.PushBack({ 69,54,16,22 });
	CapturerGuard_Default.PushBack({ 86,54,16,22 });
	CapturerGuard_Default.PushBack({ 103,54,16,22 });
	CapturerGuard_Default.speed = 0.08f;

	//Die Animation
	CapturerGuard_Die.PushBack({ 2, 68, 16, 26 });
	CapturerGuard_Die.PushBack({ 20, 68, 16, 26 });
	CapturerGuard_Die.PushBack({ 36, 68, 16, 26 });
	CapturerGuard_Die.PushBack({ 51, 68, 16, 26 });
	CapturerGuard_Die.loop = false;
	CapturerGuard_Die.speed = 0.08f;

	collider = App->collision->AddCollider({ 0, 0, 16, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	animation = &CapturerGuard_Default;
	original_pos.x = x;
	original_pos.y = y;
}

Animation Enemy_CapturerGuard::getDie()
{
	return CapturerGuard_Die;
}
void Enemy_CapturerGuard::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);
}