#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLvl1.h"
#include "ModuleWelcome.h"
#include "ModuleLvl2.h"
#include "ModuleGameOver.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "Animation.h"
#include "ModuleCollision.h"




ModuleLvl2::ModuleLvl2()
{
	//enemyally animation
	enemyally.PushBack({ 17, 0, 16, 22 });
	enemyally.PushBack({ 0, 0, 16, 22 });
	enemyally.PushBack({ 34, 0, 16, 22 });
	enemyally.PushBack({ 0, 0, 16, 22 });
	enemyally.speed = 0.08f;

	//enemydie animation
	enemydie.PushBack({ 2, 68, 16, 26 });
	enemydie.PushBack({ 20, 68, 16, 26 });
	enemydie.PushBack({ 36, 68, 16, 26 });
	enemydie.PushBack({ 51, 68, 16, 26 });
	enemydie.loop = false;
	enemydie.speed = 0.07f;
}

ModuleLvl2::~ModuleLvl2()
{}

// Load assets
bool ModuleLvl2::Start()
{
	enemydie_indicator = false;
	enemydie.Reset();

	LOG("Loading space scene");
	App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1, 2 Theme.ogg");

	background = App->textures->Load("Resources/Screens/CommandoArea2.png");//foto del fondo
	graphics = App->textures->Load("Resources/Animations/Guard Enemy.png");
	graphics2 = App->textures->Load("Resources/Animations/Common enemy.png");

	App->render->camera.x = App->render->camera.y = 0;
	App->player->Enable();
	App->collision->Enable();

	// Colliders ---
	enemy=App->collision->AddCollider({ SCREEN_WIDTH/2, -(2880 - 2700 - SCREEN_HEIGHT), 16, 22 }, COLLIDER_ENEMY);

	return true;
}

// UnLoad assets
bool ModuleLvl2::CleanUp()
{
	App->audio->Stop();

	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->collision->Disable();


	return true;
}

// Update: draw background
update_status ModuleLvl2::Update()
{
	// Move camera forward -----------------------------
	int speed = 3;

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT&&App->render->camera.y<((2880 - SCREEN_HEIGHT)*SCREEN_SIZE) - speed)
		App->render->camera.y += speed;

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->render->camera.y != 0)
		App->render->camera.y -= speed;


	
	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -2880 + SCREEN_HEIGHT, NULL);

	if(!enemydie_indicator)
	App->render->Blit(graphics,SCREEN_WIDTH/2, -(2880 - 2700 - SCREEN_HEIGHT), &(enemyally.GetCurrentFrame()), 1.0f);

	if (enemydie_indicator)
	App->render->Blit(graphics2, SCREEN_WIDTH / 2, -(2880 - 2700 - SCREEN_HEIGHT), &(enemydie.GetCurrentFrame()), 1.0f);


	if (App->input->keyboard[SDL_SCANCODE_1]) {

		App->fade->FadeToBlack(this, App->gameover, 1);
	}

	return UPDATE_CONTINUE;
}