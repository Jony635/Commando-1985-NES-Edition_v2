@@ - 1, 107 + 1, 106 @@
//#include "Application.h"
//#include "Enemy_Bosslvl1.h"
//#include "ModuleCollision.h"
//#include <time.h>
//#include<stdlib.h>
//Enemy_Bosslvl1::Enemy_Bosslvl1(int x, int y) : Enemy(x, y)
//{
//	srand(time(NULL));
//	//Default Animation
//	default.PushBack({ 177,54,15,23 });
//	default.PushBack({ 195,54,19,22 });
//	default.speed = 0.1f;
//	//Die Animation
//	Bosslvl1_Die.PushBack({ 215, 55, 16, 26 });
//	Bosslvl1_Die.PushBack({ 232, 54, 16, 27 });
//	Bosslvl1_Die.PushBack({ 248, 54, 16, 27 });
//	Bosslvl1_Die.PushBack({ 51, 68, 16, 26 });
//	Bosslvl1_Die.firstTime = false;
//	Bosslvl1_Die.loop = false;
//	Bosslvl1_Die.speed = 0.07f;
//	//Right Animation
//	Bosslvl1_Right.PushBack({ 165, 146, 15, 23 });
//	Bosslvl1_Right.PushBack({143, 146, 21, 22});
//	Bosslvl1_Right.speed = 0.1f;
//	//Original Pos
//	original_pos.x = x;
//	original_pos.y = y;
//	//Collider
//	collider = App->collision->AddCollider({ 0, 0, 10, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
//	//Default Animation
//	//animation = &default;
//	//Path Definition
//	path.PushBack({0.8f, 0.8f}, 100, &Bosslvl1_Right);
//	path.PushBack({ 0.0f, -0.8f }, 100, &Bosslvl1_Right);
//	path.PushBack({ -0.8f, 0.8f }, 100, &default);
//	path.PushBack({ 0.0f, -0.8f }, 100, &default);
//}
//
//void Enemy_Bosslvl1::PathUp()
//{
//	moving[MOVE_STATE::GOING_UP] = true;
//	moving[MOVE_STATE::GOING_DOWN] = false;
//	moving[MOVE_STATE::GOING_LEFT] = false;
//	moving[MOVE_STATE::GOING_RIGHT] = false;
//
//	path.PushBack({ 0, 0.3f }, 5, &default);
//	path.Reset();
//}
//
//void Enemy_Bosslvl1::PathDown()
//{
//	moving[MOVE_STATE::GOING_UP] = false;
//	moving[MOVE_STATE::GOING_DOWN] = true;
//	moving[MOVE_STATE::GOING_LEFT] = false;
//	moving[MOVE_STATE::GOING_RIGHT] = false;
//
//	path.PushBack({ 0, -0.3f }, 5, &default);
//	path.Reset();
//}
//
//void Enemy_Bosslvl1::PathLeft()
//{
//	moving[MOVE_STATE::GOING_UP] = false;
//	moving[MOVE_STATE::GOING_DOWN] = false;
//	moving[MOVE_STATE::GOING_LEFT] = true;
//	moving[MOVE_STATE::GOING_RIGHT] = false;
//
//	path.PushBack({ -0.3f, 0 }, 5, &default);
//	path.Reset();
//}
//void Enemy_Bosslvl1::PathRight()
//{
//	moving[MOVE_STATE::GOING_UP] = false;
//	moving[MOVE_STATE::GOING_DOWN] = false;
//	moving[MOVE_STATE::GOING_LEFT] = false;
//	moving[MOVE_STATE::GOING_RIGHT] = true;
//
//	path.PushBack({ 0.3f, 0 }, 5, &Bosslvl1_Right);
//	path.Reset();
//}
//Animation Enemy_Bosslvl1::getDie()
//{
//	return Bosslvl1_Die;
//}
//void Enemy_Bosslvl1::Move()
//{
//	/*int move = rand() % 4;
//	if (move == MOVE_STATE::GOING_UP && !moving[MOVE_STATE::GOING_UP] && path.getCurrent_Frame()==0)
//	{
//	PathUp();
//	}
//	else if (move == MOVE_STATE::GOING_DOWN && !moving[MOVE_STATE::GOING_DOWN] &&path.getCurrent_Frame()==0)
//	{
//	PathDown();
//	}
//	else if (move == MOVE_STATE::GOING_LEFT && !moving[MOVE_STATE::GOING_LEFT] && path.getCurrent_Frame() == 0)
//	{
//	PathLeft();
//	}
//	else if (move == MOVE_STATE::GOING_RIGHT && !moving[MOVE_STATE::GOING_RIGHT] && path.getCurrent_Frame() == 0)
//	{
//	PathRight();
//	}*/
//
//	position = original_pos + path.GetCurrentPosition(&animation);
//
//}
\ No newline at end of file
#include "Application.h"
#include "Enemy_Bosslvl1.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
Enemy_Bosslvl1::Enemy_Bosslvl1(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	//Default Animation
	default.PushBack({ 177,54,15,23 });
	default.PushBack({ 195,54,19,22 });
	default.speed = 0.1f;
	//Die Animation
	Bosslvl1_Die.PushBack({ 215, 55, 16, 26 });
	Bosslvl1_Die.PushBack({ 232, 54, 16, 27 });
	Bosslvl1_Die.PushBack({ 248, 54, 16, 27 });
	Bosslvl1_Die.PushBack({ 51, 68, 16, 26 });
	Bosslvl1_Die.loop = false;
	Bosslvl1_Die.speed = 0.07f;
	//Right Animation
	Bosslvl1_Right.PushBack({ 165, 146, 15, 23 });
	Bosslvl1_Right.PushBack({ 143, 146, 21, 22 });
	Bosslvl1_Right.speed = 0.1f;
	//Original Pos
	original_pos.x = x;
	original_pos.y = y;
	//Collider
	collider = App->collision->AddCollider({ 0, 0, 10, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	//Default Animation
	//animation = &default;
	//Path Definition
	path.PushBack({ 0.8f, 0.8f }, 100, &Bosslvl1_Right);
	path.PushBack({ 0.0f, -0.8f }, 100, &Bosslvl1_Right);
	path.PushBack({ -0.8f, 0.8f }, 100, &default);
	path.PushBack({ 0.0f, -0.8f }, 100, &default);
}

void Enemy_Bosslvl1::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.3f }, 5, &default);
	path.Reset();
}

void Enemy_Bosslvl1::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.3f }, 5, &default);
	path.Reset();
}

void Enemy_Bosslvl1::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.3f, 0 }, 5, &default);
	path.Reset();
}
void Enemy_Bosslvl1::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.3f, 0 }, 5, &Bosslvl1_Right);
	path.Reset();
}
Animation Enemy_Bosslvl1::getDie()
{
	return Bosslvl1_Die;
}
void Enemy_Bosslvl1::Move()
{
	/*int move = rand() % 4;
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
	}*/

	position = original_pos + path.GetCurrentPosition(&animation);

}