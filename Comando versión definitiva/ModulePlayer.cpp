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
#include "ModuleWelcome.h"
#include "ModuleGameOver.h"




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
	die.PushBack({ 2, 72, 17, 27 });
	die.loop = false;
	die.speed = 0.05f;

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
	
	dead = false;
	contdead = 0;
	graphics = App->textures->Load("Resources/Animations/Main Character Blue.png");

	position.x = (SCREEN_WIDTH / 2)-7;
	position.y = 140;

	p = App->collision->AddCollider({ 0, 0, 17, 23 }, COLLIDER_PLAYER, (Module*)App->player);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	App->particles->Disable();
	App->collision->Disable();
	App->textures->Unload(graphics);
	App->input->Disable();

	return true;
}


// Update: draw background
update_status ModulePlayer::Update()
{
	timeintro += 0.02f;


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


		//Player Movement----------------------------------------------------------------------------------------------------


		//LEFT
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT &&position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			)
		{
			if (colleft == false)
				position.x -= speed;

			if (current_animation != &left)
			{
				left.Reset();
				current_animation = &left;
			}
		}


		//RIGHT
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT &&position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			)
		{
			if (colright == false)
				position.x += speed;

			if (current_animation != &right)
			{
				right.Reset();
				current_animation = &right;
			}
		}


		//DOWN
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT &&position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->player->position.y != (202 - App->lvl1->cont)
			)
		{
			if (coldown == false)
				position.y += speed;
			if (current_animation != &down)
			{
				down.Reset();
				current_animation = &down;
			}
		}


		//UP
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			)
		{
			if (colup == false)
				position.y -= speed;
			//App->render->camera.y += speed;

			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;

			}

		}


		//DEFAULT ANIMATION
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&&App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)

			current_animation = &idle;

		//UP-RIGHT
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
		{
			if (blockUR == false)
			{
				if (colright == false)
					position.x += speed;
				if (colup == false)
					position.y -= speed;
			}

			if (current_animation != &ur)
			{
				ur.Reset();
				current_animation = &ur;
			}
		}

		//UP-LEFT
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		{
			if (blockUL == false)
			{
				if (colleft == false)
					position.x -= speed;
				if (colup == false)
					position.y -= speed;
			}

			if (current_animation != &ul)
			{
				ul.Reset();
				current_animation = &ul;
			}
		}

		//DOWN-RIGHT
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE&& App->player->position.y != (202 - App->lvl1->cont))
		{
			if (blockDR == false)
			{
				if (colright == false)
					position.x += speed;
				if (coldown == false)
					position.y += speed;
			}

			if (current_animation != &dr)
			{
				dr.Reset();
				current_animation = &dr;
			}
		}

		//DOWN-LEFT
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE&& App->player->position.y != (202 - App->lvl1->cont))
		{
			if (blockDL == false)
			{
				if (colleft == false)
					position.x -= speed;
				if (coldown == false)
					position.y += speed;
			}

			if (current_animation != &dl)
			{
				dl.Reset();
				current_animation = &dl;
			}
		}

		//ALTERNATIVE DOWN
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE&& App->player->position.y != (202 - App->lvl1->cont))
		{
			if (coldown == false)
				position.y += speed;
			if (current_animation != &down)
			{
				down.Reset();
				current_animation = &down;
			}
		}

		//ALTERNATIVE UP
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			if (colup == false)
				position.y -= speed;
			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;
			}
		}

		//ALTERNATIVE RIGHT
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE&& App->player->position.y != (202 - App->lvl1->cont))
		{
			if (colright == false)
				position.x += speed;
			if (current_animation != &right)
			{
				right.Reset();
				current_animation = &right;
			}
		}

		//ALTERNATIVE LEFT
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		{
			if (colleft == false)
				position.x -= speed;
			if (current_animation != &left)
			{
				left.Reset();
				current_animation = &left;
			}
		}



		colup = false;
		coldown = false;
		colleft = false;
		colright = false;
		blockUL = false;
		blockUR = false;
		blockDL = false;
		blockDR = false;

		//Player collision
		/*if(App->lvl2->IsEnabled())
		if (p->CheckCollision(App->lvl2->enemy->rect) )
			App->collision->OnCollision(p, App->lvl2->enemy);*/
			// Draw everything --------------------------------------
	}
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	p->SetPos(position.x, position.y);

	if (dead){
		time += 0.02f;
	if ( time > 5 && contlives>0) {
		time = 0;
		contlives--;
		App->fade->FadeToBlack(App->lvl1, App->lvl1,0);
	}
	if ( time > 7.5 && contlives == 0) {
		time = 0;
		contlives=4;
		App->fade->FadeToBlack(App->lvl1, App->welcome, 0);
		}
	}
	if(dead && contdead==0 && contlives > 0) {
		contdead++;
		App->input->Disable();
		App->audio->Stop();
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Life Lost.ogg",false);
		if (current_animation != &die)
		{
			die.Reset();
			current_animation = &die;
		}
	}
	if (dead && contdead == 0 && contlives == 0) {
		contdead++;
		App->input->Disable();
		App->audio->Stop();
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Commando (NES) Music - Game Over.ogg", false);
		if (current_animation != &die)
		{
			die.Reset();
			current_animation = &die;
		}
	}

	return UPDATE_CONTINUE;
}



void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	//If it collides with a wall	

	if ((c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_WALL))
	{
		//Check collision Right
		if ((c1->rect.x + c1->rect.w) - c2->rect.x == 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1)
		{
			colright = true;
		}

		//Check collision Left
		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x == 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1)
		{
			colleft = true;
		}

		//Check collision Up
		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y == 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1)
		{
			colup = true;
		}

		//Check collision Down
		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y == 1)
		{
			coldown = true;
		}

		//Block Up-Right Diagonal
		if ((c1->rect.x + c1->rect.w) - c2->rect.x == 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y == 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1
			&& colup == false
			&& coldown == false
			&& colleft == false
			&& colright == false)
		{
			blockUR = true;
		}

		//Block Up-Left Diagonal
		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x == 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y == 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y != 1
			&& colup == false
			&& coldown == false
			&& colleft == false
			&& colright == false)
		{
			blockUL = true;
		}

		//Block Down-Left Diagonal
		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x == 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y == 1
			&& colup == false
			&& coldown == false
			&& colleft == false
			&& colright == false)
		{
			blockDL = true;
		}

		//Block Down-Right Diagonal
		if ((c1->rect.x + c1->rect.w) - c2->rect.x == 1
			&& (c2->rect.x + c2->rect.w) - c1->rect.x != 1
			&& (c2->rect.y + c2->rect.h) - c1->rect.y != 1
			&& (c1->rect.y + c1->rect.h) - c2->rect.y == 1
			&& colup == false
			&& coldown == false
			&& colleft == false
			&& colright == false)
		{
			blockDR = true;
		}

	}


		//If it collides with an enemy

		if ((c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY))
		{
		dead = true;
		}

	
}

