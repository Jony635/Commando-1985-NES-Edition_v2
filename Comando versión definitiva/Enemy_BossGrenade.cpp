#include "Application.h"
#include "Enemy_BossGrenade.h"
#include "ModuleCollision.h"
#include <time.h>
#include<stdlib.h>
#include "ModulePlayer.h"
#include "ModuleParticles.h"
Enemy_BossGrenade::Enemy_BossGrenade(int x, int y) : Enemy(x, y)
{
	srand(time(NULL));
	//Stand Animation
	BossGrenade_Stand.PushBack({ 121,27,16,22 });
	BossGrenade_Stand.PushBack({ 138,27,16,22 });
	BossGrenade_Stand.speed = 0.08f;

	//DownGrenade Animation
	BossGrenade_DownGrenade.PushBack({ 155,29,15,20 });
	BossGrenade_DownGrenade.PushBack({ 171,32,14,17 });
	BossGrenade_DownGrenade.speed = 0.02f;
	BossGrenade_DownGrenade.loop = false;

	collider = App->collision->AddCollider({ 0, 0, 16, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	animation = &BossGrenade_Stand;
	original_pos.x = x;
	original_pos.y = y;

	vx = -0.8f;
	vy = 0.0f;
	anim = &BossGrenade_Stand;
	frames = 3;
}

Animation Enemy_BossGrenade::getDie()
{
	return BossGrenade_Stand;
}
void Enemy_BossGrenade::Move()
{
	
	if (App->player->position.x - position.x < -5 && grenadecounter < 20.0f) //Muevete pa la iskierda
	{
		vx = -0.8f;
		vy = 0.0f;
		anim = &BossGrenade_Stand;
		frames = position.x - App->player->position.x;
		

	}
	else if (App->player->position.x - position.x > 5 && grenadecounter < 20.0f) //Muevete pa la deresha
	{
		vx = 0.8f;
		vy = 0.0f;
		anim = &BossGrenade_Stand;
		frames = App->player->position.x - position.x;
		

	}
	grenadecounter += 0.2f;
	if (grenadecounter >= 20.0f)
	{
		vx = 0.0f;
		vy = 0.0f;
		anim = &BossGrenade_DownGrenade;
		if ((int)anim->current_frame == 1 && !grenading)
		{
			grenading = true;
			App->particles->grenade.speed.y = 2;
			App->particles->grenade.speed.x = 0;
			App->particles->grenade.life = 1000;
			App->particles->AddParticle(App->particles->grenade, position.x, position.y, COLLIDER_ENEMY_GRENADE);
		}
	}
	if (BossGrenade_DownGrenade.Finished())
	{
		BossGrenade_DownGrenade.Reset();
		grenadecounter = 0.0f;
		grenading = false;
		anim = &BossGrenade_Stand;
	}
	path.Reset();
	path.ResetlastStep();
	path.PushBack({vx, vy}, frames, anim);
	position = original_pos + path.GetCurrentPosition(&animation);
}