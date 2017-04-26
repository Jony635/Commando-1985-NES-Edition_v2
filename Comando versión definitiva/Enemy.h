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
enum MOVE_STATE {
	GOING_UP,
	GOING_DOWN,
	GOING_LEFT,
	GOING_RIGHT,
	NO_STATE
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
	friend class ModuleEnemies;
	Enemy(int x, int y);
	virtual ~Enemy();
	ENEMY_TYPES type;
	virtual Animation getDie()  = 0;
	Path path;
	const Collider* GetCollider() const;
	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
	virtual void PathUp() {};
	virtual void PathDown() {};
	virtual void PathLeft() {};
	virtual void PathRight() {};
	virtual void ColPathUp() {};
	virtual void ColPathDown() {};
	virtual void ColPathLeft() {};
	virtual void ColPathRight() {};
	virtual bool* getMoving() const { bool* buf=nullptr; return buf; };
};

#endif // __ENEMY_H__