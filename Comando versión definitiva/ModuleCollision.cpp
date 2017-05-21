#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModuleCollision::ModuleCollision()
{
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[COLLIDER_PLAYER_GRENADE][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_GRENADE][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_GRENADE][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_GRENADE][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_GRENADE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_GRENADE][COLLIDER_WATER] = false;
	matrix[COLLIDER_PLAYER_GRENADE][COLLIDER_ANTIBULLET] = true;
	matrix[COLLIDER_PLAYER_GRENADE][COLLIDER_UPSTAIRS] = false;
	matrix[COLLIDER_PLAYER_GRENADE][COLLIDER_DOWNSTAIRS] = true;

	matrix[COLLIDER_DOWNSTAIRS][COLLIDER_WALL] = false;
	matrix[COLLIDER_DOWNSTAIRS][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_DOWNSTAIRS][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_DOWNSTAIRS][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_DOWNSTAIRS][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_DOWNSTAIRS][COLLIDER_WATER] = false;
	matrix[COLLIDER_DOWNSTAIRS][COLLIDER_ANTIBULLET] = false;
	matrix[COLLIDER_DOWNSTAIRS][COLLIDER_UPSTAIRS] = false;
	matrix[COLLIDER_DOWNSTAIRS][COLLIDER_PLAYER_GRENADE] = true;

	matrix[COLLIDER_UPSTAIRS][COLLIDER_WALL] = false;
	matrix[COLLIDER_UPSTAIRS][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_UPSTAIRS][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_UPSTAIRS][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_UPSTAIRS][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_UPSTAIRS][COLLIDER_WATER] = false;
	matrix[COLLIDER_UPSTAIRS][COLLIDER_ANTIBULLET] = false;
	matrix[COLLIDER_UPSTAIRS][COLLIDER_UPSTAIRS] = false;
	matrix[COLLIDER_UPSTAIRS][COLLIDER_DOWNSTAIRS] = false;
	matrix[COLLIDER_UPSTAIRS][COLLIDER_PLAYER_GRENADE] = false;

	matrix[COLLIDER_WATER][COLLIDER_WALL] = false;
	matrix[COLLIDER_WATER][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WATER][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_WATER][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_WATER][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_WATER][COLLIDER_WATER] = false;
	matrix[COLLIDER_WATER][COLLIDER_ANTIBULLET] = false;
	matrix[COLLIDER_WATER][COLLIDER_UPSTAIRS] = false;
	matrix[COLLIDER_WATER][COLLIDER_DOWNSTAIRS] = false;
	matrix[COLLIDER_WATER][COLLIDER_PLAYER_GRENADE] = false;

	matrix[COLLIDER_WALL][COLLIDER_WALL] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_WATER] = false;
	matrix[COLLIDER_WALL][COLLIDER_ANTIBULLET] = false;
	matrix[COLLIDER_WALL][COLLIDER_UPSTAIRS] = false;
	matrix[COLLIDER_WALL][COLLIDER_DOWNSTAIRS] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_GRENADE] = true;

	matrix[COLLIDER_PLAYER][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_WATER] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_ANTIBULLET] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_UPSTAIRS] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_DOWNSTAIRS] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_GRENADE] = false;

	matrix[COLLIDER_ENEMY][COLLIDER_WALL] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_WATER] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ANTIBULLET] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_UPSTAIRS] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_DOWNSTAIRS] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_GRENADE] = true;

	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_WATER] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ANTIBULLET] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_UPSTAIRS] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_DOWNSTAIRS] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_GRENADE] = false;

	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_WATER] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ANTIBULLET] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_UPSTAIRS] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_DOWNSTAIRS] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_GRENADE] = false;

	matrix[COLLIDER_ANTIBULLET][COLLIDER_WALL] = false;
	matrix[COLLIDER_ANTIBULLET][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_ANTIBULLET][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_ANTIBULLET][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ANTIBULLET][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_ANTIBULLET][COLLIDER_WATER] = false;
	matrix[COLLIDER_ANTIBULLET][COLLIDER_ANTIBULLET] = false;
	matrix[COLLIDER_ANTIBULLET][COLLIDER_UPSTAIRS] = false;
	matrix[COLLIDER_ANTIBULLET][COLLIDER_DOWNSTAIRS] = false;
	matrix[COLLIDER_ANTIBULLET][COLLIDER_PLAYER_GRENADE] = false; 
}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr && colliders[i]->to_delete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleCollision::Update()
{
	Collider* c1;
	Collider* c2;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if(colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for(uint k = i+1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if(colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->CheckCollision(c2->rect) == true)
			{
				if (matrix[c1->type][c2->type] && c1->callback)
				{
					if (c1->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT)
					{
						if (c2->callback)
						{
							c2->callback->OnCollision(c2, c1);
						}
						c1->callback->OnCollision(c1, c2);
					}
					else
					{
						c1->callback->OnCollision(c1, c2);
						if (c2->callback)
							c2->callback->OnCollision(c2, c1);
					}
				}
				else if ((matrix[c2->type][c1->type] && c2->callback))
					c2->callback->OnCollision(c2, c1);
			}
		}
	}

	DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	if(App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	if(debug == false)
		return;

	Uint8 alpha = 80;
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
			continue;
		
		switch(colliders[i]->type)
		{
		case COLLIDER_NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_WALL: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case COLLIDER_PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case COLLIDER_ENEMY: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case COLLIDER_PLAYER_SHOT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_ENEMY_SHOT: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case COLLIDER_WATER: // dark yellow
			App->render->DrawQuad(colliders[i]->rect, 51, 51, 0, alpha);
			break;
		case COLLIDER_ANTIBULLET: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case COLLIDER_UPSTAIRS: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_DOWNSTAIRS: // black
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 0, alpha);
			break;
		case COLLIDER_PLAYER_GRENADE: // pink
			App->render->DrawQuad(colliders[i]->rect, 199, 40, 114, alpha);
			break;
		}
	}
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = nullptr;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

bool ModuleCollision::EraseCollider(Collider* collider)
{
	if(collider != nullptr)
	{
		// we still search for it in case we received a dangling pointer
		for(uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if(colliders[i] == collider)
			{
				collider->to_delete = true;
				break;
			}
		}
	}
		

	return false;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
			rect.x + rect.w > r.x &&
			rect.y < r.y + r.h &&
			rect.h + rect.y > r.y);
}