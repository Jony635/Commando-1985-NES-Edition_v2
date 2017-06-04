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
#include "ModuleWelcome.h"
#include "ModulePowerUp.h"

#include<stdio.h>


ModulePlayer::ModulePlayer()
{
	//bridge lvl2
	bridgelvl2.x = 0;
	bridgelvl2.y = 0;
	bridgelvl2.w = 256;
	bridgelvl2.h = 96;

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

	//throwing
	throwing.PushBack({ 75, 47, 16, 24 });
	throwing.PushBack({ 92, 47, 16, 24 });
	throwing.loop = false;
	throwing.speed = 0.08f;

	//throwing_godmode
	throwing_godmode.PushBack({ 75, 47, 16, 24 });
	throwing_godmode.PushBack({ 171, 161, 16, 24 });
	throwing_godmode.PushBack({ 216, 0, 16, 24 });
	throwing_godmode.PushBack({ 75, 47, 16, 24 });
	throwing_godmode.PushBack({ 27, 214, 16, 24 });
	throwing_godmode.PushBack({ 189, 161, 16, 24 });
	throwing_godmode.PushBack({ 233, 2, 16, 24 });
	throwing_godmode.PushBack({ 44, 214, 16, 24 });
	throwing_godmode.loop = false;
	throwing_godmode.speed = 0.16f;

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

	// move upgodmode
	upgodmode.PushBack({ 28, 1, 11, 22 });
	upgodmode.PushBack({ 191, 110, 11, 22 });
	upgodmode.PushBack({ 157, 2, 11, 22 });
	upgodmode.PushBack({ 47, 108, 11, 22 });
	upgodmode.PushBack({ 40, 2, 11, 22 });
	upgodmode.PushBack({ 178, 111, 11, 22 });
	upgodmode.PushBack({ 145, 3, 11, 22 });
	upgodmode.PushBack({ 34, 109, 11, 22 });
	upgodmode.speed = 0.4f;

	// Move down
	down.PushBack({ 14, 0, 13, 23 });
	down.PushBack({ 0, 0, 13, 23 });
	down.speed = 0.1f;

	// Move downgodmode
	downgodmode.PushBack({ 14, 0, 13, 23 });
	downgodmode.PushBack({ 132, 109, 13, 23 });
	downgodmode.PushBack({ 131, 1, 13, 23 });
	downgodmode.PushBack({ 19, 107, 13, 23 });
	downgodmode.PushBack({ 0, 0, 13, 23 });
	downgodmode.PushBack({ 118, 109, 13, 23 });
	downgodmode.PushBack({ 117, 1, 13, 23 });
	downgodmode.PushBack({ 4, 107, 13, 23 });
	downgodmode.speed = 0.4f;

	// Move left
	left.PushBack({ 2, 49, 16, 22 });
	left.PushBack({ 20, 49, 16, 22 });
	left.speed = 0.1f;

	// Move leftgodmode
	leftgodmode.PushBack({ 2, 49, 16, 22 });
	leftgodmode.PushBack({ 136, 136, 16, 22 });
	leftgodmode.PushBack({ 134, 26, 16, 22 });
	leftgodmode.PushBack({ 60, 108, 16, 22 });
	leftgodmode.PushBack({ 20, 49, 16, 22 });
	leftgodmode.PushBack({ 119, 136, 16, 22 });
	leftgodmode.PushBack({ 117, 26, 16, 22 });
	leftgodmode.PushBack({ 4, 132, 16, 22 });
	leftgodmode.speed = 0.4f;

	// Move right
	right.PushBack({ 56, 49, 16, 22 });
	right.PushBack({ 38, 49, 16, 22 });
	right.speed = 0.1f;

	// Move rightgodmode
	rightgodmode.PushBack({ 56, 49, 16, 22 });
	rightgodmode.PushBack({ 219, 136, 16, 22 });
	rightgodmode.PushBack({ 202, 28, 16, 22 });
	rightgodmode.PushBack({ 78, 108, 16, 22 });
	rightgodmode.PushBack({ 38, 49, 16, 22 });
	rightgodmode.PushBack({ 117, 219, 16, 22 });
	rightgodmode.PushBack({ 219, 28, 16, 22 });
	rightgodmode.PushBack({ 87, 132, 16, 22 });
	rightgodmode.speed = 0.4f;

	// Move ur
	ur.PushBack({ 51, 25, 16, 22 });
	ur.PushBack({ 34, 25, 16, 22 });
	ur.speed = 0.1f;

	// Move urgodmode
	urgodmode.PushBack({ 51, 25, 16, 22 });
	urgodmode.PushBack({ 184, 136, 16, 22 });
	urgodmode.PushBack({ 166, 53, 16, 22 });
	urgodmode.PushBack({ 37, 162, 16, 22 });
	urgodmode.PushBack({ 34, 25, 16, 22 });
	urgodmode.PushBack({ 201, 136, 16, 22 });
	urgodmode.PushBack({ 183, 53, 16, 22 });
	urgodmode.PushBack({ 54, 162, 16, 22 });
	urgodmode.speed = 0.4f;


	// Move ul
	ul.PushBack({ 1, 25, 14, 22 });
	ul.PushBack({ 16, 25, 16, 22 });
	ul.speed = 0.1f;

	// Move ulgodmode
	ulgodmode.PushBack({ 1, 25, 14, 22 });
	ulgodmode.PushBack({ 170, 136, 14, 22 });
	ulgodmode.PushBack({ 135, 53, 14, 22 });
	ulgodmode.PushBack({ 22, 162, 14, 22 });
	ulgodmode.PushBack({ 16, 25, 16, 22 });
	ulgodmode.PushBack({ 153, 136, 16, 22 });
	ulgodmode.PushBack({ 118, 53, 16, 22 });
	ulgodmode.PushBack({ 5, 162, 16, 22 });
	ulgodmode.speed = 0.4f;

	// Move dr
	dr.PushBack({ 85, 1, 15, 22 });
	dr.PushBack({ 101, 1, 15, 22 });
	dr.speed = 0.1f;

	// Move drgodmode
	drgodmode.PushBack({ 85, 1, 15, 22 });
	drgodmode.PushBack({ 204, 110, 15, 22 });
	drgodmode.PushBack({ 185, 2, 15, 22 });
	drgodmode.PushBack({ 54, 132, 15, 22 });
	drgodmode.PushBack({ 101, 1, 15, 22 });
	drgodmode.PushBack({ 220, 110, 15, 22 });
	drgodmode.PushBack({ 201, 2, 15, 22 });
	drgodmode.PushBack({ 70, 132, 15, 22 });
	drgodmode.speed = 0.4f;

	// Move dl
	dl.PushBack({ 69, 1, 15, 22 });
	dl.PushBack({ 53, 1, 15, 22 });
	dl.speed = 0.1f;

	// Move dlgodmode
	dlgodmode.PushBack({ 69, 1, 15, 22 });
	dlgodmode.PushBack({ 162, 110, 15, 22 });
	dlgodmode.PushBack({ 151, 53, 15, 22 });
	dlgodmode.PushBack({ 38, 132, 15, 22 });
	dlgodmode.PushBack({ 53, 1, 15, 22 });
	dlgodmode.PushBack({ 146, 110, 15, 22 });
	dlgodmode.PushBack({ 169, 2, 15, 22 });
	dlgodmode.PushBack({ 22, 132, 15, 22 });
	dlgodmode.speed = 0.4f;

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
	move = true;
	if (!App->welcome->IsEnabled())
	respawn = true;
	playsounddead = true;
	playsounddie = true;
	if(!App->welcome->IsEnabled())
	playsoundresp = true;
	winsound = true;
	endaudio = true;
	current_animation = &up;
	if(graphics==nullptr)
	graphics = App->textures->Load("Resources/Animations/Main Character Blue.png");
	if (byebye == nullptr)
	byebye = App->textures->Load("Resources/Screens/byebye.png");
	if (ui_stuff == nullptr)
	ui_stuff = App->textures->Load("Resources/ui/ui_stuff.png");
	if (graphparticles == nullptr)
	graphparticles = App->textures->Load("Resources/Sprites/Shoots and Explosions/Shoots_and_explosions.png");
	if(bridge==nullptr)
	bridge = App->textures->Load("Resources/Screens/bridgelvl2.png");//puente
	if (bunkers == nullptr)
	bunkers = App->textures->Load("Resources/Screens/bunkers.png");
	if (room1 == nullptr)
	room1 = App->textures->Load("Resources/Screens/sa1-walls.png");
	if(room4==nullptr)
	room4 = App->textures->Load("Resources/Screens/sa4-walls.png");
	if (room5 == nullptr)
	room5 = App->textures->Load("Resources/Screens/sa5-walls.png");
	if(room6==nullptr)
	room6 = App->textures->Load("Resources/Screens/sa6-walls.png");
	position.x = (SCREEN_WIDTH / 2) - 7;
	position.y = 140;
	if (col == nullptr && !		App->welcome->IsEnabled())
	col = App->collision->AddCollider({position.x, position.y, 16, 20}, COLLIDER_PLAYER, this);
	if(font_score==-1)
	font_score = App->fonts->Load("Resources/ui/Alphabet.png", "0123456789abcdefghiklmnoprstuvwxyq<HIGH=!'·$%&/()-.€@ASD_GHJ", 6);


	//An Example of Starting one timer:

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");


	App->textures->Unload(graphics);
	graphics = nullptr;
	App->textures->Unload(ui_stuff);
	ui_stuff = nullptr;
	App->textures->Unload(graphparticles);
	graphparticles = nullptr;
	App->textures->Unload(bridge);
	bridge = nullptr;
	App->textures->Unload(bunkers);
	bunkers = nullptr;
	App->textures->Unload(room1);
	room1 = nullptr;
	App->textures->Unload(room4);
	room4 = nullptr;
	App->textures->Unload(room5);
	room5 = nullptr;
	App->textures->Unload(room6);
	room6 = nullptr;
	App->textures->Unload(byebye);
	byebye = nullptr;
	App->collision->EraseCollider(col);
	col = nullptr;
	App->fonts->UnLoad(font_score);
	font_score = -1;
	
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
update_status ModulePlayer::Update() {

	//win
	if (App->render->camera.y < -(2880 - 100 - SCREEN_HEIGHT) && App->enemies->Enemies_Alive() == 0) {
		win = true;
	}
	if (win) {
		time_Counters[COUNTERS::bye] += 0.02;
		move = false;
		App->collision->Disable();
		App->powerup->Disable();
		App->enemies->Disable();
		if (winsound) {
			winsound = false;
			App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1 Cleared.ogg", false);
		}
		

		if (position.x > 120) {
			if (current_animation != &left)
			{
				left.Reset();
				current_animation = &left;
			}
			position.x--;
		}
		if (position.x < 120) {
			if (current_animation != &right)
			{
				right.Reset();
				current_animation = &right;
			}
			position.x++;
		}
		if (position.x == 120) {
			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;
			}
			

			if (position.y > -(2880 + 50 - SCREEN_HEIGHT)) {
				position.y--;

			}

		}
		if (position.y == -(2880 + 50 - SCREEN_HEIGHT)) {
			if (endaudio) {
				App->audio->Play("Resources/Audio/Themes_SoundTrack/Commando (NES) Music - Ending Theme.ogg", false);
				endaudio = false;
			}
			App->render->Blit(byebye, 0, -(2880 - SCREEN_HEIGHT), nullptr);
			App->render->camera.y = -(2880 - SCREEN_HEIGHT);
			if (time_Counters[bye] > 40) {
				App->fade->FadeToBlack(App->lvl2, App->welcome, 1);
			}
		}
	}
	//shortgodmode
	if (shortgodmode) {
		time_Counters[COUNTERS::shortgodmode_counter] += 0.02;
		if (time_Counters[COUNTERS::shortgodmode_counter] < 10.0f) {
			godmode = true;
		}
		else {
			shortgodmode = false;
			godmode = false;
		}
	}

	//HIGHSCORE
	if (score > highscore) {
		highscore = score;
		if (soundhighscore&&score > 20000) {
			App->audio->PlaySound("Resources/Audio/Sound Effects/Got 20k.wav");
			soundhighscore = false;
		}
	}

	if (dead)
	{
		for (int i = 0; i < PowerUp_Types::MAX_POWERUP_TYPE; ++i)
		{
			PlayerPowerUps[i] = false;
		}
	}
	//RESPAWN
	if (respawn && !App->secretareas->IsEnabled() && !App->welcome->IsEnabled()) {
		time_Counters[respawn] += 0.02f;
		move = false;
		App->enemies->Disable();
		if (playsoundresp) {
			App->audio->Play("Resources/Audio/Themes_SoundTrack/Commando (NES) Music - New Life Intro.ogg", false);
			playsoundresp = false;
		}
		if (time_Counters[respawn] > 3.8) {
			move = true;
			App->enemies->Enable();
			respawn = false;
			App->lvl2->playsoundlvl2 = true;
		}
	}


	//Win, die and lose one live
	if (!win && !dead && !App->welcome->IsEnabled() && !App->fade->IsFading())
	{
		if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_IDLE &&
			App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN)
		{
			position.x = (SCREEN_WIDTH / 2) - 7;
			position.y = -(2880 - SCREEN_HEIGHT - 140);
			App->render->camera.y = -(2880 - SCREEN_HEIGHT);
			App->enemies->Disable();
			App->particles->Disable();
			win = true;
		}

		if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_IDLE &&
			App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)
		{
			live_counter = 1;
			dead = true;
		}

		if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_IDLE &&
			App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN)
		{
			dead = true;
		}
	}



	//Changing rooms automatically
	if (!win && !dead && !App->welcome->IsEnabled() && !App->fade->IsFading())
	{
		if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_IDLE &&
			App->input->keyboard[SDL_SCANCODE_F6] == KEY_DOWN)
		{
			if (App->secretareas->IsEnabled())
				App->fade->FadeToBlack(App->secretareas, App->secretareas, 2, SECRETROOM::ROOM1);
			else if (App->lvl2->IsEnabled())
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 2, SECRETROOM::ROOM1);
		}

		if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_IDLE &&
			App->input->keyboard[SDL_SCANCODE_F7] == KEY_DOWN)
		{
			if (App->secretareas->IsEnabled())
				App->fade->FadeToBlack(App->secretareas, App->secretareas, 2, SECRETROOM::ROOM2);
			else if (App->lvl2->IsEnabled())
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 2, SECRETROOM::ROOM2);
		}

		if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_IDLE &&
			App->input->keyboard[SDL_SCANCODE_F8] == KEY_DOWN)
		{
			if (App->secretareas->IsEnabled())
				App->fade->FadeToBlack(App->secretareas, App->secretareas, 2, SECRETROOM::ROOM3);
			else if (App->lvl2->IsEnabled())
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 2, SECRETROOM::ROOM3);
		}

		if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_IDLE &&
			App->input->keyboard[SDL_SCANCODE_F9] == KEY_DOWN)
		{
			if (App->secretareas->IsEnabled())
				App->fade->FadeToBlack(App->secretareas, App->secretareas, 2, SECRETROOM::ROOM4);
			else if (App->lvl2->IsEnabled())
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 2, SECRETROOM::ROOM4);
		}

		if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_IDLE &&
			App->input->keyboard[SDL_SCANCODE_F10] == KEY_DOWN)
		{
			if (App->secretareas->IsEnabled())
				App->fade->FadeToBlack(App->secretareas, App->secretareas, 2, SECRETROOM::ROOM5);
			else if (App->lvl2->IsEnabled())
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 2, SECRETROOM::ROOM5);
		}

		if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_IDLE &&
			App->input->keyboard[SDL_SCANCODE_F11] == KEY_DOWN)
		{
			if (App->secretareas->IsEnabled())
				App->fade->FadeToBlack(App->secretareas, App->secretareas, 2, SECRETROOM::ROOM6);
			else if (App->lvl2->IsEnabled())
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 2, SECRETROOM::ROOM6);
		}
	}
	

	//Debug for power ups
	if (!win && !dead && !App->welcome->IsEnabled() && !App->fade->IsFading())
	{
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		{
			App->powerup->AddPowerUp(PowerUp_Types::GRENADEx4, position.x, position.y - 20);
		}
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN)
		{
			App->powerup->AddPowerUp(PowerUp_Types::GRENADEx5, position.x, position.y - 20);
		}
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)
		{
			App->powerup->AddPowerUp(PowerUp_Types::GASOLINE, position.x, position.y - 20);
		}
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN)
		{
			App->powerup->AddPowerUp(PowerUp_Types::BAG, position.x, position.y - 20);
		}
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F5] == KEY_DOWN)
		{
			App->powerup->AddPowerUp(PowerUp_Types::BINOCULAR, position.x, position.y - 20);
		}
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F6] == KEY_DOWN)
		{
			App->powerup->AddPowerUp(PowerUp_Types::BULLETPROOF_VEST, position.x, position.y - 20);
		}
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F7] == KEY_DOWN)
		{
			App->powerup->AddPowerUp(PowerUp_Types::MEDAL, position.x, position.y - 20);
		}
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F8] == KEY_DOWN)
		{
			App->powerup->AddPowerUp(PowerUp_Types::MEDAL_OF_HONOR, position.x, position.y - 20);
		}
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F9] == KEY_DOWN)
		{
			PlayerPowerUps[MEGA_SHOOT] = true;
		}
		if ((App->input->keyboard[SDL_SCANCODE_LALT] == KEY_DOWN || App->input->keyboard[SDL_SCANCODE_LALT] == KEY_REPEAT) &&
			App->input->keyboard[SDL_SCANCODE_F10] == KEY_DOWN)
		{
			PlayerPowerUps[HANDGRANADE] = true;
		}
	}
	


	//counters
	if (current_animation == &upstairs || current_animation == &downstairs)
		time_Counters[stairs] += 0.02;

	int speed = 1;

	//Grenades
	if (granade_counter > 0 &&
		(App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN || App->input->buttons[SDL_CONTROLLER_BUTTON_Y] == KEY_STATE::KEY_DOWN))
	{
		if (godmode) {
			if (current_animation != &throwing_godmode)
			{
				throwing_godmode.Reset();
				current_animation = &throwing_godmode;
			}

		}
		else {
			if (current_animation != &throwing)
			{
				throwing.Reset();
				current_animation = &throwing;
			}

		}

		granade_counter--;
		App->particles->grenade.speed.y = -2;
		App->particles->grenade.speed.x = 0;
		App->particles->grenade.life = 750;
		App->particles->AddParticle(App->particles->grenade, position.x + (col->rect.w / 2), position.y, COLLIDER_PLAYER_GRENADE);
	}

	if (current_animation == &throwing_godmode && current_animation->Finished()) {
		if (current_animation != &upgodmode)
		{
			upgodmode.Reset();
			current_animation = &upgodmode;
		}
	}

	if (current_animation == &throwing && current_animation->Finished()) {
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	//Shoots
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->buttons[SDL_CONTROLLER_BUTTON_X] == KEY_STATE::KEY_DOWN)
		if (current_animation == &up || current_animation == &upgodmode)
		{
			if (!PlayerPowerUps[PowerUp_Types::MEGA_SHOOT])
			{

				App->particles->bullet.speed.y = -5;
				App->particles->bullet.speed.x = 0;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->bullet.life = 300;
				else
					App->particles->bullet.life = 600;
				App->particles->AddParticle(App->particles->bullet, position.x + (col->rect.w / 2), position.y, COLLIDER_PLAYER_SHOT);
			}
			else
			{
				App->particles->mega_bullet.speed.y = -5;
				App->particles->mega_bullet.speed.x = 0;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->mega_bullet.life = 300;
				else
					App->particles->mega_bullet.life = 600;
				App->particles->AddParticle(App->particles->mega_bullet, position.x + (col->rect.w / 2), position.y, COLLIDER_PLAYER_SHOT);
			}
		}
		else if (current_animation == &down || current_animation == &downgodmode)
		{
			if (!PlayerPowerUps[PowerUp_Types::MEGA_SHOOT])
			{
				App->particles->bullet.speed.x = 0;
				App->particles->bullet.speed.y = 5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->bullet.life = 300;
				else
					App->particles->bullet.life = 600;
				App->particles->AddParticle(App->particles->bullet, position.x, position.y + 20, COLLIDER_PLAYER_SHOT);
			}
			else
			{
				App->particles->mega_bullet.speed.x = 0;
				App->particles->mega_bullet.speed.y = 5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->mega_bullet.life = 300;
				else
					App->particles->mega_bullet.life = 600;
				App->particles->AddParticle(App->particles->mega_bullet, position.x, position.y + 20, COLLIDER_PLAYER_SHOT);
			}

		}
		else if (current_animation == &right || current_animation == &rightgodmode)
		{

			if (!PlayerPowerUps[PowerUp_Types::MEGA_SHOOT])
			{
				App->particles->bullet.speed.y = 0;
				App->particles->bullet.speed.x = 5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->bullet.life = 300;
				else
					App->particles->bullet.life = 600;
				App->particles->AddParticle(App->particles->bullet, (position.x + col->rect.w), position.y + 5, COLLIDER_PLAYER_SHOT);
			}
			else
			{
				App->particles->mega_bullet.speed.y = 0;
				App->particles->mega_bullet.speed.x = 5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->mega_bullet.life = 300;
				else
					App->particles->mega_bullet.life = 600;
				App->particles->AddParticle(App->particles->mega_bullet, (position.x + col->rect.w), position.y + 5, COLLIDER_PLAYER_SHOT);
			}

		}
		else if (current_animation == &left || current_animation == &leftgodmode)
		{
			if (!PlayerPowerUps[PowerUp_Types::MEGA_SHOOT])
			{
				App->particles->bullet.speed.y = 0;
				App->particles->bullet.speed.x = -5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->bullet.life = 300;
				else
					App->particles->bullet.life = 600;
				App->particles->AddParticle(App->particles->bullet, position.x, position.y + 5, COLLIDER_PLAYER_SHOT);
			}
			else
			{
				App->particles->mega_bullet.speed.y = 0;
				App->particles->mega_bullet.speed.x = -5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->mega_bullet.life = 300;
				else
					App->particles->mega_bullet.life = 600;
				App->particles->AddParticle(App->particles->mega_bullet, position.x, position.y + 5, COLLIDER_PLAYER_SHOT);
			}

		}
		else if (current_animation == &ur || current_animation == &urgodmode)
		{

			if (!PlayerPowerUps[PowerUp_Types::MEGA_SHOOT])
			{
				App->particles->bullet.speed.x = 5;
				App->particles->bullet.speed.y = -5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->bullet.life = 300;
				else
					App->particles->bullet.life = 600;
				App->particles->AddParticle(App->particles->bullet, position.x + col->rect.w, position.y, COLLIDER_PLAYER_SHOT);
			}
			else
			{
				App->particles->mega_bullet.speed.x = 5;
				App->particles->mega_bullet.speed.y = -5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->mega_bullet.life = 300;
				else
					App->particles->mega_bullet.life = 600;
				App->particles->AddParticle(App->particles->mega_bullet, position.x + col->rect.w, position.y, COLLIDER_PLAYER_SHOT);
			}

		}
		else if (current_animation == &ul || current_animation == &ulgodmode)
		{

			if (!PlayerPowerUps[PowerUp_Types::MEGA_SHOOT])
			{
				App->particles->bullet.speed.x = -5;
				App->particles->bullet.speed.y = -5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->bullet.life = 300;
				else
					App->particles->bullet.life = 600;
				App->particles->AddParticle(App->particles->bullet, position.x, position.y, COLLIDER_PLAYER_SHOT);
			}
			else
			{
				App->particles->mega_bullet.speed.x = -5;
				App->particles->mega_bullet.speed.y = -5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->mega_bullet.life = 300;
				else
					App->particles->mega_bullet.life = 600;
				App->particles->AddParticle(App->particles->mega_bullet, position.x, position.y, COLLIDER_PLAYER_SHOT);
			}

		}
		else if (current_animation == &dr || current_animation == &drgodmode)
		{
			if (!PlayerPowerUps[PowerUp_Types::MEGA_SHOOT])
			{
				App->particles->bullet.speed.x = 5;
				App->particles->bullet.speed.y = 5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->bullet.life = 300;
				else
					App->particles->bullet.life = 600;
				App->particles->AddParticle(App->particles->bullet, position.x + col->rect.w, position.y + col->rect.h, COLLIDER_PLAYER_SHOT);
			}
			else
			{
				App->particles->mega_bullet.speed.x = 5;
				App->particles->mega_bullet.speed.y = 5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->mega_bullet.life = 300;
				else
					App->particles->mega_bullet.life = 600;
				App->particles->AddParticle(App->particles->mega_bullet, position.x + col->rect.w, position.y + col->rect.h, COLLIDER_PLAYER_SHOT);
			}

		}
		else if (current_animation == &dl || current_animation == &dlgodmode)
		{

			if (!PlayerPowerUps[PowerUp_Types::MEGA_SHOOT])
			{
				App->particles->bullet.speed.x = -5;
				App->particles->bullet.speed.y = 5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->bullet.life = 300;
				else
					App->particles->bullet.life = 600;
				App->particles->AddParticle(App->particles->bullet, position.x, position.y + col->rect.h, COLLIDER_PLAYER_SHOT);
			}
			else
			{
				App->particles->mega_bullet.speed.x = -5;
				App->particles->mega_bullet.speed.y = 5;
				if (!PlayerPowerUps[PowerUp_Types::BINOCULAR])
					App->particles->mega_bullet.life = 300;
				else
					App->particles->mega_bullet.life = 600;

				App->particles->AddParticle(App->particles->mega_bullet, position.x, position.y + col->rect.h, COLLIDER_PLAYER_SHOT);
			}

		}

	if (current_animation != &downstairs&&current_animation != &upstairs&& move && !dead) {

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
			if (godmode) {
				if (current_animation != &leftgodmode)
				{
					leftgodmode.Reset();
					current_animation = &leftgodmode;
				}
			}
			else {
				if (current_animation != &left)
				{
					left.Reset();
					current_animation = &left;
				}
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
			if (godmode) {
				if (current_animation != &rightgodmode)
				{
					rightgodmode.Reset();
					current_animation = &rightgodmode;
				}
			}
			else {
				if (current_animation != &right)
				{
					right.Reset();
					current_animation = &right;
				}
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
			if (godmode) {
				if (current_animation != &downgodmode)
				{
					downgodmode.Reset();
					current_animation = &downgodmode;
				}
			}
			else {
				if (current_animation != &down)
				{
					down.Reset();
					current_animation = &down;
				}
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
			if (godmode) {
				if (current_animation != &upgodmode)
				{
					upgodmode.Reset();
					current_animation = &upgodmode;
				}
			}
			else {
				if (current_animation != &up)
				{
					up.Reset();
					current_animation = &up;

				}
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
			if (godmode) {
				if (current_animation != &urgodmode)
				{
					urgodmode.Reset();
					current_animation = &urgodmode;
				}
			}
			else {
				if (current_animation != &ur)
				{
					ur.Reset();
					current_animation = &ur;
				}
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
			if (godmode) {
				if (current_animation != &ulgodmode)
				{
					ulgodmode.Reset();
					current_animation = &ulgodmode;
				}
			}
			else {
				if (current_animation != &ul)
				{
					ul.Reset();
					current_animation = &ul;
				}
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
			if (godmode) {
				if (current_animation != &drgodmode)
				{
					drgodmode.Reset();
					current_animation = &drgodmode;
				}
			}
			else {
				if (current_animation != &dr)
				{
					dr.Reset();
					current_animation = &dr;
				}
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
			if (godmode) {
				if (current_animation != &dlgodmode)
				{
					dlgodmode.Reset();
					current_animation = &dlgodmode;
				}
			}
			else {
				if (current_animation != &dl)
				{
					dl.Reset();
					current_animation = &dl;
				}
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
	if(col!=nullptr)
	col->SetPos(position.x, position.y);

	// Draw everything --------------------------------------
	if (dead == false && !App->welcome->IsEnabled())
	{
		if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
			&&App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
			&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
			&& (App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_IDLE
				&&App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_IDLE
				&& App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_IDLE)
			&& current_animation != &upstairs
			&& current_animation != &downstairs
			&& current_animation != &throwing
			&& current_animation != &throwing_godmode && !win)
		{
			if (godmode) {

				if (current_animation == &up)
					current_animation = &upgodmode;
				else if (current_animation == &down)
					current_animation = &downgodmode;
				else if (current_animation == &right)
					current_animation = &rightgodmode;
				else if (current_animation == &left)
					current_animation = &leftgodmode;
				else if (current_animation == &ul)
					current_animation = &ulgodmode;
				else if (current_animation == &ur)
					current_animation = &urgodmode;
				else if (current_animation == &dl)
					current_animation = &dlgodmode;
				else if (current_animation == &dr)
					current_animation = &drgodmode;



				time_Counters[COUNTERS::godidle] += 0.03f;

				if (time_Counters[COUNTERS::godidle] < 0.2f)
					App->render->Blit(graphics, position.x, position.y, &(current_animation->frames[0]));
				else if (time_Counters[COUNTERS::godidle] > 0.2f &&time_Counters[COUNTERS::godidle] < 0.4f)
					App->render->Blit(graphics, position.x, position.y, &(current_animation->frames[1]));
				else if (time_Counters[COUNTERS::godidle] > 0.4f &&time_Counters[COUNTERS::godidle] < 0.6f)
					App->render->Blit(graphics, position.x, position.y, &(current_animation->frames[2]));
				else if (time_Counters[COUNTERS::godidle] > 0.6f &&time_Counters[COUNTERS::godidle] < 0.8f)
					App->render->Blit(graphics, position.x, position.y, &(current_animation->frames[3]));
				else
					time_Counters[COUNTERS::godidle] = 0;


			}
			else {
				App->render->Blit(graphics, position.x, position.y, &(current_animation->frames[0]));
			}
		}
		else
		{
			App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
		}
		if (App->lvl2->IsEnabled())
		{
			App->render->Blit(bridge, 0, -(2880 - 1344 - SCREEN_HEIGHT), &bridgelvl2);
			App->render->Blit(bunkers, 0, -(2880 - SCREEN_HEIGHT), NULL);
		}
		else if (App->secretareas->IsEnabled())
		{
			switch (App->secretareas->actual_room)
			{
			case ROOM1:
				App->render->Blit(room1, 0, 0, NULL);
				break;
			case ROOM4:
				App->render->Blit(room4, 0, -(448 - SCREEN_HEIGHT), NULL);
				break;
			case ROOM5:
				App->render->Blit(room5, 0, -(448 - SCREEN_HEIGHT), NULL);
				break;
			case ROOM6:
				App->render->Blit(room6, 0, -(448 - SCREEN_HEIGHT), NULL);
				break;
			}
		}
	}
	else if (dead == true && !App->welcome->IsEnabled() && !win) {
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
		time_Counters[Player_Die] += 0.02;
		move = false;
		if (current_animation != &die_w) {
			if (current_animation != &die)
			{
				die.Reset();
				current_animation = &die;
			}
		}
		if (playsounddie) {
			live_counter--;
			granade_counter = 5;
			App->audio->Play("Resources/Audio/Themes_SoundTrack/Life Lost.ogg", false);
			playsounddie = false;
		}
		if (time_Counters[Player_Die] > 3 && live_counter > 0) {
			if (App->lvl2->IsEnabled())
				App->fade->FadeToBlack(App->lvl2, App->lvl2, 1);
			if (App->secretareas->IsEnabled())
				App->fade->FadeToBlack(App->secretareas, App->lvl2, 1);
		}
		else if (time_Counters[Player_Die] > 3 && live_counter == 0) {
			if (playsounddead) {
				granade_counter = 5;
				App->audio->Play("Resources/Audio/Themes_SoundTrack/Commando (NES) Music - Game Over.ogg", false);
				playsounddead = false;
			}
			if (time_Counters[Player_Die] > 9) {
				if (App->lvl2->IsEnabled())
					App->fade->FadeToBlack(App->lvl2, App->welcome, 1);
				if (App->secretareas->IsEnabled())
					App->fade->FadeToBlack(App->secretareas, App->welcome, 1);



			}
		}
	}
	if (!App->welcome->IsEnabled()&&!win) {
		// Draw UI (score) --------------------------------------
		sprintf(score_text, "%06d", score);
		sprintf(lives_text, "%01d", live_counter);
		sprintf(grenades_text, "%02d", granade_counter);

		App->fonts->BlitText(16, 16, font_score, score_text);
		App->render->Blit(ui_stuff, 18, 209, &lives, false);
		App->render->Blit(ui_stuff, 123, 212, &granade, false);
		App->fonts->BlitText(32, 215, font_score, lives_text);
		App->fonts->BlitText(136, 215, font_score, grenades_text);
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

	if (!godmode &&c2->enemytype != ENEMY_TYPES::RUNNER && (c1->type == COLLIDER_PLAYER && (c2->type == COLLIDER_ENEMY || c2->type == COLLIDER_ENEMY_GRENADE_EXPL || c2->type == COLLIDER_ENEMY_SHOT)) && dead == false/* && !godmode*/) {
		dead = true;
	}

	//If it collides with the water

	if (!godmode  && (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_WATER) && !dead) {
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
			dead = true;
		}
	}
	
	if (c2->type == COLLIDER_UPSTAIRS&&dead == false) {
		if (App->secretareas->actual_room == ROOM3&&App->secretareas->ystair == &App->secretareas->yellowstair) {
		if (current_animation != &upstairs)
		{
			upstairs.Reset();
			current_animation = &upstairs;
		}

		if (time_Counters[stairs]>3 && time_Counters[stairs]<4)
			App->fade->FadeToBlack(App->secretareas, App->lvl2, 0);
		}
		else if (App->secretareas->actual_room != ROOM3) {
			if (current_animation != &upstairs)
			{
				upstairs.Reset();
				current_animation = &upstairs;
			}

			if (time_Counters[stairs] > 3 && time_Counters[stairs] < 4)
				App->fade->FadeToBlack(App->secretareas, App->lvl2, 0);

		}
	}

	if (c2->type == COLLIDER_DOWNSTAIRS&&dead == false) {
		if (position.y > -(2880 - 2500 - SCREEN_HEIGHT) && App->lvl2->current_stair1_animation == &App->lvl2->stair) {
			App->particles->Disable();
			App->secretareas->actual_room = SECRETROOM::ROOM1;
			App->player->position.x = 234;
			App->player->position.y = -(2880 - 2632 - SCREEN_HEIGHT);
			App->enemies->Disable();
			if (current_animation != &downstairs)
			{
				downstairs.Reset();
				current_animation = &downstairs;
			}
			if (time_Counters[stairs] > 2 && time_Counters[stairs] < 3)
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 0);

		}
		else if (position.y < -(2880 - 2500 - SCREEN_HEIGHT) && position.y > -(2880 - 1540 - SCREEN_HEIGHT) && App->lvl2->current_stair2_animation == &App->lvl2->stair) {
			App->particles->Disable();
			App->secretareas->actual_room = SECRETROOM::ROOM2;
			App->player->position.x = 120;
			App->player->position.y = -(2880 - 1544 - SCREEN_HEIGHT);
			App->enemies->Disable();
			if (current_animation != &downstairs)
			{
				downstairs.Reset();
				current_animation = &downstairs;
			}
			if (time_Counters[stairs] > 2 && time_Counters[stairs] < 3)
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 0);
		}
		else if (position.y < -(2880 - 1540 - SCREEN_HEIGHT) && position.y > -(2880 - 1200 - SCREEN_HEIGHT) && App->lvl2->current_stair3_animation == &App->lvl2->stair) {
			App->particles->Disable();
			App->secretareas->actual_room = SECRETROOM::ROOM3;
			App->player->position.x = 208;
			App->player->position.y = -(2880 - 1424 - SCREEN_HEIGHT);
			App->enemies->Disable();
			if (current_animation != &downstairs)
			{
				downstairs.Reset();
				current_animation = &downstairs;
			}
			if (time_Counters[stairs] > 2 && time_Counters[stairs] < 3)
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 0);

		}
		else if (position.y < -(2880 - 1200 - SCREEN_HEIGHT) && position.y > -(2880 - 1000 - SCREEN_HEIGHT) && App->lvl2->current_stair4_animation == &App->lvl2->stair) {
			App->particles->Disable();
			App->secretareas->actual_room = SECRETROOM::ROOM4;
			App->player->position.x = 96;
			App->player->position.y = -(2880 - 1065 - SCREEN_HEIGHT);
			App->enemies->Disable();
			if (current_animation != &downstairs)
			{
				downstairs.Reset();
				current_animation = &downstairs;
			}
			if (time_Counters[stairs] > 2 && time_Counters[stairs] < 3)
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 0);
		}
		else if (position.y < -(2880 - 1000 - SCREEN_HEIGHT) && position.y > -(2880 - 600 - SCREEN_HEIGHT) && App->lvl2->current_stair5_animation == &App->lvl2->stair) {
			App->particles->Disable();
			App->secretareas->actual_room = SECRETROOM::ROOM5;
			App->player->position.x = 80;
			App->player->position.y = -(2880 - 743 - SCREEN_HEIGHT);
			App->enemies->Disable();
			if (current_animation != &downstairs)
			{
				downstairs.Reset();
				current_animation = &downstairs;
			}
			if (time_Counters[stairs] > 2 && time_Counters[stairs] < 3)
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 0);
		}
		else if (position.y < -(2880 - 600 - SCREEN_HEIGHT) && position.y > -(2880 - SCREEN_HEIGHT) && App->lvl2->current_stair6_animation == &App->lvl2->stair) {
			App->particles->Disable();
			App->secretareas->actual_room = SECRETROOM::ROOM6;
			App->player->position.x = 120;
			App->player->position.y = -(2880 - 528 - SCREEN_HEIGHT);
			App->enemies->Disable();
			if (current_animation != &downstairs)
			{
				downstairs.Reset();
				current_animation = &downstairs;
			}
			if (time_Counters[stairs] > 2 && time_Counters[stairs] < 3)
				App->fade->FadeToBlack(App->lvl2, App->secretareas, 0);
		}
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