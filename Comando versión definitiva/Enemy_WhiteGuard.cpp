#include "Application.h"
#include "Enemy_WhiteGuard.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
Enemy_WhiteGuard::Enemy_WhiteGuard(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	//Default Animation
	default.PushBack({ 67,0,12,23 });
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
	WhiteGuard_Down.speed = 0.07f;
	
	


	//Path Definition
	/*path.PushBack({ -0.3f, 0.0f }, 70, &WhiteGuard_Left);
	path.PushBack({ 0.3f, 0.0f }, 70, &WhiteGuard_Right);
	*/
}
bool* Enemy_WhiteGuard::getMoving() const
{
	return movingptr;
}
void Enemy_WhiteGuard::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;
	
	path.PushBack({0, -0.3f}, 100, &WhiteGuard_Up);
	path.Reset();
}

void Enemy_WhiteGuard::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;
	
	path.PushBack({ 0, 0.3f }, 100, &WhiteGuard_Down);
	path.Reset();
}

void Enemy_WhiteGuard::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;
	
	path.PushBack({ -0.3f, 0 }, 100, &WhiteGuard_Left);
	path.Reset();
}
void Enemy_WhiteGuard::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;
	
	path.PushBack({ 0.3f, 0 }, 100, &WhiteGuard_Right);
	path.Reset();
}
Animation Enemy_WhiteGuard::getDie() 
{
	return WhiteGuard_Die;
}
void Enemy_WhiteGuard::Move()
{
	int move = rand() % 4;
	if (move == MOVE_STATE::GOING_UP && !moving[MOVE_STATE::GOING_UP] && path.getCurrent_Frame()==0)
	{
		PathUp();
	}
	else if (move == MOVE_STATE::GOING_DOWN && !moving[MOVE_STATE::GOING_DOWN] &&path.getCurrent_Frame()==0)
	{
		PathDown();
	}
	else if (move == MOVE_STATE::GOING_LEFT && !moving[MOVE_STATE::GOING_LEFT] && path.getCurrent_Frame() == 0)
	{
		PathLeft();
	}
	else if (move == MOVE_STATE::GOING_RIGHT && !moving[MOVE_STATE::GOING_RIGHT] && path.getCurrent_Frame() == 0)
	{
		PathRight();
	}
	
	position = original_pos + path.GetCurrentPosition(&animation);
	
}