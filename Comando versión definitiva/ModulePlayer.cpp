#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleLvl1.h"
#include "ModuleLvl2.h"
#include "ModuleAudio.h"


ModulePlayer::ModulePlayer()
{
	// idle animation (just the ship)
	idle.PushBack({ 40, 2, 11, 22 });
	//idle.PushBack({ 40, 2, 11, 22 });
	/*idle.loop = false;
	idle.speed = 0.1f;*/

	//die animation
	die.PushBack({ 2, 72, 17, 27 });
	die.PushBack({ 21, 80, 15, 19 });
	die.PushBack({ 37, 72, 16, 27 });
	die.PushBack({ 21, 80, 15, 19 });
	die.speed = 0.07f;

	// move upwards
	up.PushBack({ 28, 1, 11, 22 });
	up.PushBack({ 40, 2, 11, 22 });
	up.speed = 0.1f;

	// Move down
	down.PushBack({ 14, 0, 13, 23 });
	down.PushBack({ 0, 0, 13, 23 });
	down.speed = 0.1f;

	// Move left
	left.PushBack({ 2, 49, 16, 22 });
	left.PushBack({ 20, 49, 16, 22 });
	left.speed = 0.1f;

	// Move right
	right.PushBack({ 38, 49, 16, 22 });
	right.PushBack({ 56, 49, 16, 22 });
	right.speed = 0.1f;

	// Move ur
	ur.PushBack({ 34, 25, 16, 22 });
	ur.PushBack({ 50, 25, 17, 22 });
	ur.speed = 0.1f;

	// Move ul
	ul.PushBack({ 16, 25, 16, 22 });
	ul.PushBack({ 1, 25, 14, 22 });
	ul.speed = 0.1f;

	// Move dr
	dr.PushBack({ 85, 1, 15, 22 });
	dr.PushBack({ 101, 1, 15, 22 });
	dr.speed = 0.1f;

	// Move dl
	dl.PushBack({ 69, 1, 15, 22 });
	dl.PushBack({ 53, 1, 15, 22 });
	dl.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	App->particles->Enable();
	App->player->dead = false;
	App->collision->Enable();
	graphics = App->textures->Load("Resources/Animations/Main Character Blue.png");

	position.x = (SCREEN_WIDTH / 2) - 7;
	position.y = 140;

	p = App->collision->AddCollider({ 0, 0, 17, 23 }, COLLIDER_PLAYER);
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	App->particles->Disable();
	App->collision->Disable();
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{

	if (!dead) {



		int speed = 1;
		//Check if Player Shoots
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
		{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
			if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
				&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				App->particles->bullet.speed.x = 5;
				App->particles->bullet.speed.y = -5;
				App->particles->bullet.life = 1000;
				App->particles->AddParticle(App->particles->bullet, position.x + 20, position.y - 20, COLLIDER_PLAYER_SHOT);

			}
			else if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
				&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				App->particles->bullet.speed.x = -5;
				App->particles->bullet.speed.y = -5;
				App->particles->bullet.life = 1000;
				App->particles->AddParticle(App->particles->bullet, position.x - 20, position.y - 20, COLLIDER_PLAYER_SHOT);

			}
			else if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
				&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				App->particles->bullet.speed.x = 5;
				App->particles->bullet.speed.y = 5;
				App->particles->bullet.life = 1000;
				App->particles->AddParticle(App->particles->bullet, position.x + 20, position.y + 20, COLLIDER_PLAYER_SHOT);

			}
			else if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
				&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				App->particles->bullet.speed.x = -5;
				App->particles->bullet.speed.y = 5;
				App->particles->bullet.life = 1000;
				App->particles->AddParticle(App->particles->bullet, position.x - 20, position.y + 20, COLLIDER_PLAYER_SHOT);

			}
			else if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				App->particles->bullet.speed.x = 0;
				App->particles->bullet.speed.y = 5;
				App->particles->bullet.life = 1000;
				App->particles->AddParticle(App->particles->bullet, position.x, position.y + 20, COLLIDER_PLAYER_SHOT);

			}
			else if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
			{
				App->particles->bullet.speed.x = 0;
				App->particles->bullet.speed.y = -5;
				App->particles->bullet.life = 1000;
				App->particles->AddParticle(App->particles->bullet, position.x, position.y - 20, COLLIDER_PLAYER_SHOT);

			}
			else if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				App->particles->bullet.speed.y = 0;
				App->particles->bullet.speed.x = -5;
				App->particles->bullet.life = 1000;
				App->particles->AddParticle(App->particles->bullet, position.x - 20, position.y, COLLIDER_PLAYER_SHOT);

			}
			else if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				App->particles->bullet.speed.y = 0;
				App->particles->bullet.speed.x = 5;
				App->particles->bullet.life = 1000;
				App->particles->AddParticle(App->particles->bullet, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);

			}
			else
			{
				App->particles->bullet.speed.y = -5;
				App->particles->bullet.speed.x = 0;
				App->particles->bullet.life = 1000;
				App->particles->AddParticle(App->particles->bullet, position.x, position.y - 20, COLLIDER_PLAYER_SHOT);

			}
		}

		//Player Movement


		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT &&position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&&App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&&App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE)
		{
			position.x -= speed;
			if (current_animation != &left)
			{
				left.Reset();
				current_animation = &left;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT &&position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE)
		{
			position.x += speed;

			if (current_animation != &right)
			{
				right.Reset();
				current_animation = &right;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT &&position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE && App->player->position.y != (202 - App->lvl1->cont))
		{
			position.y += speed;
			if (current_animation != &down)
			{
				down.Reset();
				current_animation = &down;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		{
			position.y -= speed;
			//App->render->camera.y += speed;

			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;



			}

		}





		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&&App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)

			current_animation = &idle;

		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
		{
			position.x += speed;
			position.y -= speed;
			if (current_animation != &ur)
			{
				ur.Reset();
				current_animation = &ur;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		{
			position.x -= speed;
			position.y -= speed;
			if (current_animation != &ul)
			{
				ul.Reset();
				current_animation = &ul;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE&& App->player->position.y != (202 - App->lvl1->cont))
		{
			position.x += speed;
			position.y += speed;
			if (current_animation != &dr)
			{
				dr.Reset();
				current_animation = &dr;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE&& App->player->position.y != (202 - App->lvl1->cont))
		{
			position.x -= speed;
			position.y += speed;
			if (current_animation != &dl)
			{
				dl.Reset();
				current_animation = &dl;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE&& App->player->position.y != (202 - App->lvl1->cont))
		{
			position.y += speed;
			if (current_animation != &down)
			{
				down.Reset();
				current_animation = &down;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			position.y -= speed;
			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE&& App->player->position.y != (202 - App->lvl1->cont))
		{
			position.x += speed;
			if (current_animation != &right)
			{
				right.Reset();
				current_animation = &right;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		{
			position.x -= speed;
			if (current_animation != &left)
			{
				left.Reset();
				current_animation = &left;
			}
		}

	}
	//Player collision
	if (App->lvl2->IsEnabled())
		if (p->CheckCollision(App->lvl2->enemy->rect))
			App->collision->OnCollision(p, App->lvl2->enemy);
	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	p->SetPos(position.x, position.y);

	return UPDATE_CONTINUE;
}

