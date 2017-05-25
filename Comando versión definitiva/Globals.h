#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "SDL\include\SDL_rect.h"

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);
void log(const char file[], int line, const char* format, ...);

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define ABS(a)	   (((a) < 0) ? -(a) : (a))
#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

enum COUNTERS
{
	Player_Die,
	Helicopter,
	stairs,
	gas,
	respawn,
	//Add your counter types here
	MAX_COUNTER
};
enum PowerUp_Types
{
	POWERUP_NO_TYPE = -1,
	BINOCULAR,
	BULLETPROOF_VEST,
	GASOLINE,
	GRENADEx4,
	GRENADEx5,
	MEDAL,
	MEDAL_OF_HONOR,
	BARREL,
	BAG,
	ALLY_CAPTURED,
	MEGA_SHOOT,
	MAX_POWERUP_TYPE
};

float time_Counters[COUNTERS::MAX_COUNTER];

// Useful typedefs ---------
typedef unsigned int uint;

// Configuration -----------
#define SCREEN_SIZE 1
#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 224
#define WIN_FULLSCREEN 0
#define WIN_FULLSCREEN_DESKTOP 0
#define WIN_BORDERLESS 0
#define WIN_RESIZABLE 1
#define REN_VSYNC 1

#endif // __GLOBALS_H__
