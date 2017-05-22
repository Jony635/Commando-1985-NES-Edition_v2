#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleLvl2.h"
#include "ModuleSecretAreas.h"
#include "ModuleEnemies.h"

#include<stdio.h>


ModulePlayer::ModulePlayer()
{
	//bridge lvl1
	bridgelvl2.x = 0;
	bridgelvl2.y = 0;
	bridgelvl2.w = 256;
	bridgelvl2.h = 95;

	//upstairs
	upstairs.PushBack({ 40, 2, 11, 21 });
	upstairs.PushBack({ 81, 31, 14, 16 });
	upstairs.PushBack({ 98, 28, 14, 16 });
	upstairs.loop = false;
	upstairs.speed = 0.02f;

	//downstairs
	downstairs.PushBack({ 68, 25, 11, 16 });
	downstairs.PushBack({ 98, 28, 14, 16 });
	downstairs.loop = false;
	downstairs.speed = 0.02f;

	//die animation
	die.PushBack({ 2, 72, 17, 27 });
	die.PushBack({ 21, 80, 15, 19 });
	die.PushBack({ 37, 72, 16, 27 });
	die.PushBack({ 21, 80, 15, 19 });
	die.PushBack({ 2, 72, 17, 27 });
	die.loop = false;
	die.speed = 0.05f;

	//die water animation	
	die_w.PushBack({ 68, 23, 11, 16 });
	die_w.PushBack({ 98, 27, 12, 14 });
	die_w.loop = false;
	die_w.speed = 0.05f;

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
	right.PushBack({ 56, 49, 16, 22 });
	right.PushBack({ 38, 49, 16, 22 });
	right.speed = 0.1f;

	// Move ur
	ur.PushBack({ 50, 25, 17, 22 });
	ur.PushBack({ 34, 25, 16, 22 });
	ur.speed = 0.1f;

	// Move ul
	ul.PushBack({ 1, 25, 14, 22 });
	ul.PushBack({ 16, 25, 16, 22 });
	ul.speed = 0.1f;

	// Move dr
	dr.PushBack({ 85, 1, 15, 22 });
	dr.PushBack({ 101, 1, 15, 22 });
	dr.speed = 0.1f;

	// Move dl
	dl.PushBack({ 69, 1, 15, 22 });
	dl.PushBack({ 53, 1, 15, 22 });
	dl.speed = 0.1f;

	//Granade UI
	granade.x = 0;
	granade.y = 3;
	granade.w = 10;
	granade.h = 12;

	//Lives
	lives.x = 10;
	lives.y = 0;
	lives.w = 11;
	lives.h = 15;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	dead = false;
	current_animation = &up;
	graphics = App->textures->Load("Resources/Animations/Main Character Blue.png");
	ui_stuff = App->textures->Load("Resources/ui/ui_stuff.png");
	graphparticles = App->textures->Load("Resources/Sprites/Shoots and Explosions/Shoots_and_explosions.png");
	position.x = (SCREEN_WIDTH / 2) - 7;
	position.y = 140;
	score = 0;
	live_counter = 4;
	granade_counter = 15;
	col = App->collision->AddCollider({position.x, position.y, 16, 20}, COLLIDER_PLAYER, this);
	font_score = App->fonts->Load("Resources/ui/Alphabet.png", "0123456789abcdefghiklmnoprstuvwxyq<HIGH=!'·$%&/()-.€@ASD_GHJ", 6);

	//An Example of Starting one timer:
	time_Counters[COUNTERS::Player_Die] = 12.5f;
	time_Counters[stairs] = 0;

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->textures->Unload(ui_stuff);
	App->textures->Unload(graphparticles);
	App->collision->EraseCollider(col);
	App->fonts->UnLoad(font_score);
	
	//An example of cleaning up all timers:
	for (int i = 0; i < COUNTERS::MAX_COUNTER; i++)
	{
		if (time_Counters[i] != 0)
		{
			time_Counters[i] = 0;
		}
	}

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//counters
	if (current_animation == &upstairs || current_animation == &downstairs)
		time_Counters[stairs] += 0.02;

	int speed = 1;

	//Grenades
	if (granade_counter > 0 && 
		(App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttons[SDL_CONTROLLER_BUTTON_Y] == KEY_STATE::KEY_DOWN))
	{
		granade_counter--;
		App->particles->grenade.speed.y = -2;
		App->particles->grenade.speed.x = 0;
		App->particles->grenade.life = 1000;
		App->particles->AddParticle(App->particles->grenade, position.x + (col->rect.w / 2), position.y, COLLIDER_PLAYER_GRENADE);
	}


	//Shoots
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->buttons[SDL_CONTROLLER_BUTTON_X]==KEY_STATE::KEY_DOWN)
		if (current_animation == &up)
		{
			App->particles->bullet.speed.y = -5;
			App->particles->bullet.speed.x = 0;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x + (col->rect.w / 2), position.y, COLLIDER_PLAYER_SHOT);
		}
		else if (current_animation == &down)
		{
			App->particles->bullet.speed.x = 0;
			App->particles->bullet.speed.y = 5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x, position.y + 20, COLLIDER_PLAYER_SHOT);

		}
		else if (current_animation == &right)
		{

			App->particles->bullet.speed.y = 0;
			App->particles->bullet.speed.x = 5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, (position.x + col->rect.w), position.y + 5, COLLIDER_PLAYER_SHOT);

		}
		else if (current_animation == &left)
		{

			App->particles->bullet.speed.y = 0;
			App->particles->bullet.speed.x = -5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x, position.y + 5, COLLIDER_PLAYER_SHOT);

		}
		else if (current_animation == &ur)
		{

			App->particles->bullet.speed.x = 5;
			App->particles->bullet.speed.y = -5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x + col->rect.w, position.y, COLLIDER_PLAYER_SHOT);

		}
		else if (current_animation == &ul)
		{

			App->particles->bullet.speed.x = -5;
			App->particles->bullet.speed.y = -5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x, position.y, COLLIDER_PLAYER_SHOT);

		}
		else if (current_animation == &dr)
		{
			App->particles->bullet.speed.x = 5;
			App->particles->bullet.speed.y = 5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x + col->rect.w, position.y + col->rect.h, COLLIDER_PLAYER_SHOT);

		}
		else if (current_animation == &dl)
		{

			App->particles->bullet.speed.x = -5;
			App->particles->bullet.speed.y = 5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x, position.y + col->rect.h, COLLIDER_PLAYER_SHOT);

		}

	if (current_animation != &downstairs&&current_animation != &upstairs) {
		//MOVEMENT

		//LEFT

			//KEYBOARD
		if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT &&position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE)
			|| (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > App->lvl2->top
				&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
				&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
				&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
			//CONTROLLER
			|| ((App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_REPEAT &&position.x > 0
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_IDLE)
				|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_REPEAT && position.y > App->lvl2->top
					&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_REPEAT && position.x > 0
					&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_REPEAT
					&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_IDLE)))
		{
			if (colleft == false) {
				position.x -= speed;

			}

			if (current_animation != &left)
			{
				left.Reset();
				current_animation = &left;
			}
		}

		//RIGHT

			//KEYBOARD
		if ((App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT &&position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE)
			|| (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
				&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
				&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
				&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
			//CONTROLLER
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_REPEAT &&position.x < SCREEN_WIDTH - 16
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_IDLE)
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_REPEAT
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_IDLE))
		{
			if (colright == false) {
				position.x += speed;

			}

			if (current_animation != &right)
			{
				right.Reset();
				current_animation = &right;
			}
		}


		//DOWN
			//KEYBOARD
		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT &&position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			)
			|| (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
				&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
				&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT
				&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
			//CONTROLLER
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_REPEAT &&position.y < SCREEN_HEIGHT - 22
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_IDLE
				)
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_REPEAT && position.x > 0
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_REPEAT
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_IDLE))
		{
			if (coldown == false && position.y < App->render->camera.y + SCREEN_HEIGHT - 22) {
				position.y += speed;

			}

			if (current_animation != &down)
			{
				down.Reset();
				current_animation = &down;
			}
		}


		//UP
			//KEYBOARD
		if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > App->lvl2->top
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
			|| (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
				&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
				&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
				&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			//CONTROLLER
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_IDLE)
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_REPEAT && position.x > 0
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_REPEAT))
		{
			if (colup == false) {
				position.y -= speed;

			}

			//App->render->camera.y += speed;

			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;

			}
		}

		//UP-RIGHT
			//KEYBOARD
		if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
			//CONTROLLER
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_IDLE))
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
			//KEYBOARD
		if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
			//CONTROLLER
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_REPEAT && position.x > 0
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_IDLE))
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
			//KEYBOARD
		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
			//CONTROLLER
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_IDLE))
		{
			if (blockDR == false)
			{
				if (colright == false)
					position.x += speed;
				if (coldown == false && position.y < App->render->camera.y + SCREEN_HEIGHT - 22)
					position.y += speed;

			}

			if (current_animation != &dr)
			{
				dr.Reset();
				current_animation = &dr;
			}
		}

		//DOWN-LEFT
			//KEYBOARD
		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
			//CONTROLLER
			|| (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_REPEAT && position.x > 0
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_IDLE))
		{
			if (blockDL == false)
			{
				if (colleft == false)
					position.x -= speed;
				if (coldown == false && position.y < App->render->camera.y + SCREEN_HEIGHT - 22)
					position.y += speed;

			}

			if (current_animation != &dl)
			{
				dl.Reset();
				current_animation = &dl;
			}
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




	//if (current_animation == &up || current_animation == &down) {
	//	col->rect.w = 11;
	//}
	//else {
	//	col->rect.w = 16;
	//}

	col->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	if (dead == false) {
		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&&App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
			&& (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_IDLE
				&&App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_IDLE) 
			&& current_animation != &upstairs
			&& current_animation != &downstairs)
			App->render->Blit(graphics, position.x, position.y, &(current_animation->frames[0]));
		else
			App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	}
	// Draw UI (score) --------------------------------------
	sprintf(score_text, "%06d", score);
	sprintf(lives_text, "%01d", live_counter);
	sprintf(grenades_text, "%02d", granade_counter);

	App->fonts->BlitText(16, 9, font_score, score_text);
	App->render->Blit(ui_stuff, 18, 209, &lives, false);
	App->render->Blit(ui_stuff, 123, 212, &granade, false);
	App->fonts->BlitText(32, 215, font_score, lives_text);
	App->fonts->BlitText(136, 215, font_score, grenades_text);

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

	if ((c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY)/* && !godmode*/)
	{
		dead = true;
	}

	//If it collides with the water

	if ((c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_WATER))
	{
		if (c2->rect.x == (c1->rect.x + (c1->rect.w / 2))
			|| (c2->rect.x + c2->rect.w) == (c1->rect.x + (c1->rect.w / 2))
			|| c2->rect.y == (c1->rect.y + (c1->rect.h / 2))
			|| (c2->rect.y + c2->rect.h) == (c1->rect.y + (c1->rect.h / 2)))
		{
			if (current_animation != &die_w)
			{
				die_w.Reset();
				current_animation = &die_w;
			}
			current_animation = &die_w;
			/*dead = true;*/
		}
	}
	
	if (c2->type == COLLIDER_UPSTAIRS&&dead == false) {
		if (current_animation != &upstairs)
		{
			upstairs.Reset();
			current_animation = &upstairs;
		}

		if (time_Counters[stairs]>3 && time_Counters[stairs]<4)
			App->fade->FadeToBlack(App->secretareas, App->lvl2, 0);
	}
	if (c2->type == COLLIDER_DOWNSTAIRS&&dead == false) {
		if (position.y > -(2880 - 2500 - SCREEN_HEIGHT)) {
			App->secretareas->actual_room = SECRETROOM::ROOM1;
			App->player->position.x = 234;
			App->player->position.y = -(2880 - 2632 - SCREEN_HEIGHT);
			App->enemies->Disable();
		}
		else if (position.y < -(2880 - 2500 - SCREEN_HEIGHT) && position.y > -(2880 - 1500 - SCREEN_HEIGHT)) {
			App->secretareas->actual_room = SECRETROOM::ROOM2;
			App->player->position.x = 129;
			App->player->position.y = -(2880 - 1544 - SCREEN_HEIGHT);
			App->enemies->Disable();
		}
		else if (position.y < -(2880 - 1500 - SCREEN_HEIGHT) && position.y > -(2880 - 1200 - SCREEN_HEIGHT)) {
			App->secretareas->actual_room = SECRETROOM::ROOM3;
			App->player->position.x = 217;
			App->player->position.y = -(2880 - 1424 - SCREEN_HEIGHT);
			App->enemies->Disable();

		}
		else if (position.y < -(2880 - 1200 - SCREEN_HEIGHT) && position.y > -(2880 - 1000 - SCREEN_HEIGHT)) {
			App->secretareas->actual_room = SECRETROOM::ROOM4;
			App->player->position.x = 217;
			App->player->position.y = -(2880 - 1065 - SCREEN_HEIGHT);
			App->enemies->Disable();
		}
		else if (position.y < -(2880 - 1000 - SCREEN_HEIGHT) && position.y > -(2880 - 600 - SCREEN_HEIGHT)) {
			App->secretareas->actual_room = SECRETROOM::ROOM5;
			App->player->position.x = 217;
			App->player->position.y = -(2880 - 743 - SCREEN_HEIGHT);
			App->enemies->Disable();
		}
		else if (position.y < -(2880 - 600 - SCREEN_HEIGHT) && position.y > -(2880 - SCREEN_HEIGHT)) {
			App->secretareas->actual_room = SECRETROOM::ROOM6;
			App->player->position.x = 217;
			App->player->position.y = -(2880 - 528 - SCREEN_HEIGHT);
			App->enemies->Disable();
		}


		if (current_animation != &downstairs)
		{
			downstairs.Reset();
			current_animation = &downstairs;
		}
		if (time_Counters[stairs] > 2 && time_Counters[stairs] < 3)
			App->fade->FadeToBlack(App->lvl2, App->secretareas, 0);
	}


	if(c1 == col && dead == false && App->fade->IsFading() == false)
	{

		/*App->particles->AddParticle(App->particles->explosion, position.x, position.y, COLLIDER_NONE, 150);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, COLLIDER_NONE, 220);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, COLLIDER_NONE, 670);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, COLLIDER_NONE, 480);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, COLLIDER_NONE, 350);*/

		/*dead = true;*/
	}
}