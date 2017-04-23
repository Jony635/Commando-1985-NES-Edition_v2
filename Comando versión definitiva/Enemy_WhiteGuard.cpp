#include "Application.h"
#include "Enemy_WhiteGuard.h"
#include "ModuleCollision.h"

Enemy_WhiteGuard::Enemy_WhiteGuard(int x, int y) : Enemy(x, y)
{
	//Default Animation
	default.PushBack({ 0,22,16,23 });
	default.speed = 0.2f;
	
	//Die Animation
	WhiteGuard_Die.PushBack({ 2, 68, 16, 26 });
	WhiteGuard_Die.PushBack({ 20, 68, 16, 26 });
	WhiteGuard_Die.PushBack({ 36, 68, 16, 26 });
	WhiteGuard_Die.PushBack({ 51, 68, 16, 26 });
	WhiteGuard_Die.firstTime = false;
	WhiteGuard_Die.loop = false;
	WhiteGuard_Die.speed = 0.07f;
	//Left Animation
	WhiteGuard_Left.PushBack({50, 23, 16, 22});
	WhiteGuard_Left.PushBack({ 68, 24, 16, 22 });
	WhiteGuard_Left.speed = 0.07f;
	//Right Animation
	WhiteGuard_Right.PushBack({ 32, 0, 16, 22 });
	WhiteGuard_Right.PushBack({ 49, 0, 16, 22 });
	WhiteGuard_Right.speed = 0.07f;
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	animation = &WhiteGuard_Left;
	original_pos.x = x;
	original_pos.y = y;
	//Up Animation
	WhiteGuard_Up.PushBack({ 35, 46, 11, 21 });
	WhiteGuard_Up.PushBack({ 49, 46, 11, 22 });
	WhiteGuard_Up.speed = 0.07f;
	//Down Animation
	WhiteGuard_Down.PushBack({1, 23, 15, 22});
	WhiteGuard_Down.PushBack({ 17, 23, 15, 22 });




	//Path Definition
	/*path.PushBack({ -0.3f, 0.0f }, 100, &WhiteGuard_Left);
	path.PushBack({ 0.3f, 0.0f }, 70, &WhiteGuard_Right);*/
	
	//path.PushBack({ -0.3f, 0.0f }, 150, &fly);
	
}

void Enemy_WhiteGuard::PathUp()
{
	path.Reset();
	path.PushBack({0, 0.3f}, 50, &WhiteGuard_Up);
}

void Enemy_WhiteGuard::PathDown()
{
	path.Reset();
	path.PushBack({ 0, -0.3f }, 50, &WhiteGuard_Down);
}

void Enemy_WhiteGuard::PathLeft()
{
	path.Reset();
	path.PushBack({ -0.3f, 0 }, 50, &WhiteGuard_Left);
}
void Enemy_WhiteGuard::PathRight()
{
	path.Reset();
	path.PushBack({ 0.3f, 0 }, 50, &WhiteGuard_Right);
}
Animation Enemy_WhiteGuard::getWhiteGuard_Die() 
{
	
	return WhiteGuard_Die;
}
void Enemy_WhiteGuard::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);
}