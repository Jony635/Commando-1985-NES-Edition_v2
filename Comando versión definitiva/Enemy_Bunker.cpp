#include "Application.h"
#include "Enemy_Bunker.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
#include "ModuleParticles.h"
Enemy_Bunker::Enemy_Bunker(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));

	LEFT_Bunker_Top.PushBack({ 85, 249, 38, 47 });
	LEFT_Bunker_Mid.PushBack({ 44, 248, 39, 47 });
	LEFT_Bunker_Bot.PushBack({ 4, 248, 38, 47 });

	RIGHT_Bunker_Top.PushBack({ 131, 248, 38, 47 });
	RIGHT_Bunker_Mid.PushBack({ 172, 247, 39, 47 });
	RIGHT_Bunker_Bot.PushBack({ 216, 243, 38, 47 });

	iddle.PushBack({ 192, 215, 22, 25 });

	collider = App->collision->AddCollider({ 0, 0, 39, 47 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	animation = &iddle;
	original_pos.x = x;
	original_pos.y = y;
}

bool* Enemy_Bunker::getMoving() const
{
	return movingptr;
}
void Enemy_Bunker::PathUp()
{
	moving[MOVE_STATE::GOING_UP] = true;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, -0.7f }, 70, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::ColPathUp()
{
	path.PushBack({ 0, -0.7f }, 12, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::PathDown()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = true;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ 0, 0.7f }, 70, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::ColPathDown()
{
	path.PushBack({ 0, 0.7f }, 12, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::PathLeft()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = true;
	moving[MOVE_STATE::GOING_RIGHT] = false;

	path.PushBack({ -0.7f, 0 }, 70, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::ColPathLeft()
{
	path.PushBack({ -0.7f, 0 }, 12, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::PathRight()
{
	moving[MOVE_STATE::GOING_UP] = false;
	moving[MOVE_STATE::GOING_DOWN] = false;
	moving[MOVE_STATE::GOING_LEFT] = false;
	moving[MOVE_STATE::GOING_RIGHT] = true;

	path.PushBack({ 0.7f, 0 }, 70, &LEFT_Bunker_Mid);
	path.Reset();
}
void Enemy_Bunker::ColPathRight()
{
	path.PushBack({ 0.7f, 0 }, 12, &LEFT_Bunker_Mid);
	path.Reset();
}
Animation Enemy_Bunker::getDie()
{
	return LEFT_Bunker_Mid;
}

void Enemy_Bunker::Move()
{
	




	position = original_pos + path.GetCurrentPosition(&animation);

}