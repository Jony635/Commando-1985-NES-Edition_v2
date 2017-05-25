#ifndef __PATH_H__
#define __PATH_H__

#include "p2Point.h"
#include "Animation.h"
#define MAX_STEPS 25

struct Step
{
	uint frames = 1;
	fPoint speed;
	Animation* animation = nullptr;
};

class Path
{
public:
	bool loop = true;
	Step steps[MAX_STEPS];
	fPoint accumulated_speed = {0.0f, 0.0f};
	bool first_move = true;
	bool finished = false;
private:
	uint current_frame = 0;
	uint last_step = 0;

public:

	void PushBack(fPoint speed, uint frames, Animation* animation = nullptr)
	{
		steps[last_step].animation = animation;
		steps[last_step].frames = frames;
		steps[last_step++].speed = speed;
		finished = false;
	}

	iPoint GetCurrentPosition(Animation** current_animation = nullptr)
	{
		current_frame += 1;

		uint count = 0;
		uint i = 0;
		bool need_loop = true;
		for(; i < last_step; ++i)
		{
			count += steps[i].frames;
			if(current_animation != nullptr)
				*current_animation = steps[i].animation;
			if(count >= current_frame)
			{
				accumulated_speed += steps[i].speed;
				need_loop = false;
				break;
			}
			else
			{
				finished = true;
			}
		}

		if (need_loop)
		{
			current_frame = 0;
			finished = true;
		}
			

		return iPoint((int)accumulated_speed.x, (int)accumulated_speed.y);
	}
	void ResetlastStep()
	{
		last_step = 0;
	}
	void Reset()
	{
		current_frame = 0;
		finished = false;
		loop = true;
	}
	uint getCurrent_Frame() const
	{
		return current_frame;
	}
};

#endif // __PATH_H__