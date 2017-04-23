#include "Application.h"
#include "Enemy_WhiteGuard.h"
#include "ModuleCollision.h"

Enemy_WhiteGuard::Enemy_WhiteGuard(int x, int y) : Enemy(x, y)
{
	default.PushBack({ 0,22,16,23 });
	default.speed = 0.2f;
	animation = &default;

	WhiteGuard_Die.PushBack({ 2, 68, 16, 26 });
	WhiteGuard_Die.PushBack({ 20, 68, 16, 26 });
	WhiteGuard_Die.PushBack({ 36, 68, 16, 26 });
	WhiteGuard_Die.PushBack({ 51, 68, 16, 26 });
	WhiteGuard_Die.firstTime = false;
	WhiteGuard_Die.loop = false;
	WhiteGuard_Die.speed = 0.07f;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
	path.PushBack({})
	//path.PushBack({ -0.3f, 0.0f }, 150, &fly);
}

Animation Enemy_WhiteGuard::getWhiteGuard_Die() 
{
	//if (!WhiteGuard_Die.firstTime)
	//{
	//	/*WhiteGuard_Die.Reset();*/
	//	WhiteGuard_Die.firstTime = true;
	//}
	return WhiteGuard_Die;
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
	}
*/
	
	position = original_pos + path.GetCurrentPosition();
}