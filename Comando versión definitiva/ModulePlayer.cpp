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

#include<stdio.h>

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	//bridge lvl1
	bridgelvl2.x = 0;
	bridgelvl2.y = 0;
	bridgelvl2.w = 256;
	bridgelvl2.h = 95;


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
	position.x = (SCREEN_WIDTH / 2) - 7;
	position.y = 140;
	score = 0;
	live_counter = 4;
	granade_counter = 0;
	col = App->collision->AddCollider({position.x, position.y, 32, 16}, COLLIDER_PLAYER, this);
	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	font_score = App->fonts->Load("Resources/ui/Alphabet.png", "0123456789abcdefghiklmnoprstuvwxyq<HIGH=!'·$%&/()-.€@ASD_GHJ", 6);
	// TODO 4: Try loading "rtype_font3.png" that has two rows to test if all calculations are correct

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->textures->Unload(ui_stuff);
	App->collision->EraseCollider(col);
	App->fonts->UnLoad(font_score);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{

	int speed = 1;

	//DEFAULT ANIMATION
	if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
		&&App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
		|| (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
			&&App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		|| (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
			&&App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
		|| (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT
			&&App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE))
	{
		/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
		{
		App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
		App->particles->bullet.speed.y = -5;
		App->particles->bullet.speed.x = 0;
		App->particles->bullet.life = 300;
		App->particles->AddParticle(App->particles->bullet, position.x + (p->rect.w / 2), position.y, COLLIDER_PLAYER_SHOT);
		}*/
	}


	//LEFT
	if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT &&position.x > 0
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE)
		|| (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE))
	{
		if (colleft == false) {
			position.x -= speed;
			/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
			{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
			App->particles->bullet.speed.y = 0;
			App->particles->bullet.speed.x = -5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x, position.y + 5, COLLIDER_PLAYER_SHOT);
			}*/
		}

		if (current_animation != &left)
		{
			left.Reset();
			current_animation = &left;
		}
	}

	//RIGHT
	if ((App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT &&position.x < SCREEN_WIDTH - 16
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE)
		|| (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < SCREEN_WIDTH - 16
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE))
	{
		if (colright == false) {
			position.x += speed;
			/*	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
			{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
			App->particles->bullet.speed.y = 0;
			App->particles->bullet.speed.x = 5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, (position.x + p->rect.w), position.y + 5, COLLIDER_PLAYER_SHOT);
			}*/
		}

		if (current_animation != &right)
		{
			right.Reset();
			current_animation = &right;
		}
	}


	//DOWN
	if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT &&position.y < SCREEN_HEIGHT - 22
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
		)
		|| (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && position.y < SCREEN_HEIGHT - 22
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE))
	{
		if (coldown == false && position.y<App->render->camera.y + SCREEN_HEIGHT - 22) {
			position.y += speed;
			/*	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
			{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
			App->particles->bullet.speed.x = 0;
			App->particles->bullet.speed.y = 5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x, position.y + 20, COLLIDER_PLAYER_SHOT);
			}*/
		}

		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}


	//UP
	if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		|| (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && position.y > -2880 + SCREEN_HEIGHT
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 0
			&& App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
	{
		if (colup == false) {
			position.y -= speed;
			/*	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
			{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
			App->particles->bullet.speed.x = 0;
			App->particles->bullet.speed.y = -5;
			App->particles->bullet.life =300;
			App->particles->AddParticle(App->particles->bullet, position.x + (p->rect.w / 2), position.y, COLLIDER_PLAYER_SHOT);
			}*/
		}

		//App->render->camera.y += speed;

		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;

		}
	}

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
			/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
			{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
			App->particles->bullet.speed.x = 5;
			App->particles->bullet.speed.y = -5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x + p->rect.w, position.y, COLLIDER_PLAYER_SHOT);
			}*/
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
			/*	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
			{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
			App->particles->bullet.speed.x = -5;
			App->particles->bullet.speed.y = -5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x, position.y, COLLIDER_PLAYER_SHOT);
			}*/
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
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
	{
		if (blockDR == false)
		{
			if (colright == false)
				position.x += speed;
			if (coldown == false && position.y<App->render->camera.y + SCREEN_HEIGHT - 22)
				position.y += speed;
			/*	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
			{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
			App->particles->bullet.speed.x = 5;
			App->particles->bullet.speed.y = 5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x + p->rect.w, position.y + p->rect.h, COLLIDER_PLAYER_SHOT);
			}*/
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
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
	{
		if (blockDL == false)
		{
			if (colleft == false)
				position.x -= speed;
			if (coldown == false && position.y<App->render->camera.y + SCREEN_HEIGHT - 22)
				position.y += speed;
			/*	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
			{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Shoot.wav");
			App->particles->bullet.speed.x = -5;
			App->particles->bullet.speed.y = 5;
			App->particles->bullet.life = 300;
			App->particles->AddParticle(App->particles->bullet, position.x, position.y + p->rect.h, COLLIDER_PLAYER_SHOT);
			}*/
		}

		if (current_animation != &dl)
		{
			dl.Reset();
			current_animation = &dl;
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


	if(App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);
	}

	if(App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
	   && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)

	col->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	if (dead == false) {
		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&&App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE))
			App->render->Blit(graphics, position.x, position.y, &(current_animation->frames[0]));
		else
			App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	}
	// Draw UI (score) --------------------------------------
	sprintf(score_text,"%06d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(16, 9, font_score, score_text);
	App->render->Blit(ui_stuff, 18, 209, &lives, false);
	App->render->Blit(ui_stuff, 123, 212, &granade, false);
	//App->fonts->BlitText(32, 215, font_score, live_counter);
	//App->fonts->BlitText(136, 215, font_score, granade_counter);

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if(c1 == col && dead == false && App->fade->IsFading() == false)
	{

		App->particles->AddParticle(App->particles->explosion, position.x, position.y, COLLIDER_NONE, 150);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, COLLIDER_NONE, 220);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, COLLIDER_NONE, 670);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, COLLIDER_NONE, 480);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, COLLIDER_NONE, 350);

		dead = true;
	}
}