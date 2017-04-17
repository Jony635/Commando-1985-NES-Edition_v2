//#include "Application.h"
//#include "Helicopter.h"
//
//Helicopter::Helicopter(int x, int y) : Helicopter(x, y)
//{
//	fly.PushBack({ 5,6,24,24 });
//	fly.PushBack({ 38, 6, 24, 24 });
//	fly.PushBack({ 71, 6, 24, 24 });
//	fly.PushBack({ 104, 6, 24, 24 });
//	fly.PushBack({ 137, 6, 24, 24 });
//	fly.PushBack({ 170, 6, 24, 24 });
//	fly.PushBack({ 203, 6, 24, 24 });
//	fly.PushBack({ 236, 6, 24, 24 });
//	fly.speed = 0.2f;
//
//	animation = &flybig;
//
//
//	original_y = y;
//}
//
//void Helicopter::Move()
//{
//	if (going_up)
//	{
//		if (wave > 1.0f)
//			going_up = false;
//		else
//			wave += 0.05f;
//	}
//	else
//	{
//		if (wave < -1.0f)
//			going_up = true;
//		else
//			wave -= 0.05f;
//	}
//
//	position.y = original_y + (25.0f * sinf(wave));
//	position.x -= 1;
//}
