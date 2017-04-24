#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"
#include "Path.h"
struct SDL_Texture;
struct Collider;
enum ENEMY_TYPES
{
	NO_TYPE,
	WHITEGUARD,
	CAPTURERGUARD,
	BOSSLVL1

};
class Enemy
{
protected:
	Animation* animation = nullptr;
	Collider* collider = nullptr;

public:
	iPoint position;
	iPoint original_pos;

public:
	Enemy(int x, int y);
	virtual ~Enemy();
	ENEMY_TYPES type;
	virtual Animation getDie()  = 0;
	Path path;
	const Collider* GetCollider() const;
	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
};

#endif // __ENEMY_H__