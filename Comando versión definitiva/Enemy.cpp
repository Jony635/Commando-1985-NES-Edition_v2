#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"

Enemy::Enemy(int x, int y) : position(x, y)
{}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Draw(SDL_Texture* sprites)
{
	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
	App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void Enemy::OnCollision(Collider* collider)
{
	if (this->type == ENEMY_TYPES::WHITEGUARD)
	{
		if (collider->type == COLLIDER_PLAYER_SHOT)
		{
			if (this->animation != &this->getDie())
			{
				this->animation->Reset();
				this->animation = &this->getDie();
			}
		}
		
		if (collider->type == COLLIDER_WALL || collider->type==COLLIDER_WATER)
		{
			
		}
	}
	else if (this->type == ENEMY_TYPES::CAPTURERGUARD)
	{
		if (collider->type == COLLIDER_PLAYER_SHOT)
		{
			if (this->animation != &this->getDie())
			{
				this->animation->Reset();
				this->animation = &this->getDie();
			}
		}
	}
}