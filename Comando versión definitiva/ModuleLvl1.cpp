#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLvl1.h"
#include "ModuleWelcome.h"
#include "ModuleLvl2.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"




ModuleLvl1::ModuleLvl1()
{
	
	//Helicopter big animation
	bigh.PushBack({ 10, 15, 160, 139 });
	bigh.PushBack({ 16, 187, 160, 139 });
	bigh.PushBack({ 14, 330, 160, 139 });
	bigh.PushBack({ 17, 472, 160, 139 });
	bigh.PushBack({ 26, 619, 160, 139 });
	bigh.PushBack({ 27, 761, 160, 139 });
	bigh.PushBack({ 41, 907, 160, 139 });
	bigh.speed = 0.8f;
	//Helicopter med animation
	medh.PushBack({ 256, 54, 112, 92 });
	medh.PushBack({ 264, 204, 112, 92 });
	medh.PushBack({ 262, 341, 112, 92 });
	medh.PushBack({ 264, 497, 112, 92 });
	medh.PushBack({ 262, 663, 112, 92 });
	medh.PushBack({ 261, 809, 112, 92 });
	medh.PushBack({ 260, 945, 112, 92 });
	medh.speed = 0.8f;
	//Helicopter small animation
	smallh.PushBack({ 454, 51, 126, 90 });
	smallh.PushBack({ 458, 206, 126, 90 });
	smallh.PushBack({ 459, 361, 126, 90 });
	smallh.PushBack({ 459, 503, 126, 90 });
	smallh.PushBack({ 452, 661, 126, 90 });
	smallh.PushBack({ 451, 815, 126, 90 });
	smallh.PushBack({ 462, 954, 126, 90 });
	smallh.speed = 0.8f;

	//ally animation
	ally.PushBack({ 0, 0, 16, 22 });
	ally.PushBack({ 17, 0, 16, 22 });
	ally.speed = 0.08f;
	//ally2 animation
	ally2.PushBack({ 0, 0, 16, 22 });
	ally2.PushBack({ 17, 0, 16, 22 });
	ally2.speed = 0.08f;
	//ally3 animation
	ally3.PushBack({ 0, 0, 16, 22 });
	ally3.PushBack({ 17, 0, 16, 22 });
	ally3.speed = 0.08f;

	//enemyally animation
	enemyally.PushBack({ 17, 0, 16, 22 });
	enemyally.PushBack({ 0, 0, 16, 22 });
	enemyally.PushBack({ 34, 0, 16, 22 });
	enemyally.PushBack({ 0, 0, 16, 22 });
	enemyally.speed = 0.08f;
		//enemyally2 animation
	enemyally2.PushBack({ 17, 0, 16, 22 });
	enemyally2.PushBack({ 0, 0, 16, 22 });
	enemyally2.PushBack({ 34, 0, 16, 22 });
	enemyally2.PushBack({ 0, 0, 16, 22 });
	enemyally2.speed = 0.08f;

	//box animation
	box.PushBack({ 27, 18, 23, 15 });
	box.PushBack({ 27, 1, 23, 15 });
	box.PushBack({ 1, 18, 23, 15 });
	box.PushBack({ 1, 1, 23, 15 });
	box.speed = 0.08f;
	//box2 animation
	box2.PushBack({ 27, 18, 23, 15 });
	box2.PushBack({ 27, 1, 23, 15 });
	box2.PushBack({ 1, 18, 23, 15 });
	box2.PushBack({ 1, 1, 23, 15 });
	box2.speed = 0.08f;
	//box3 animation
	box3.PushBack({ 27, 18, 23, 15 });
	box3.PushBack({ 27, 1, 23, 15 });
	box3.PushBack({ 1, 18, 23, 15 });
	box3.PushBack({ 1, 1, 23, 15 });
	box3.speed = 0.08f;
	//box4 animation
	box4.PushBack({ 27, 18, 23, 15 });
	box4.PushBack({ 27, 1, 23, 15 });
	box4.PushBack({ 1, 18, 23, 15 });
	box4.PushBack({ 1, 1, 23, 15 });
	box4.speed = 0.08f;
	//box5 animation
	box5.PushBack({ 27, 18, 23, 15 });
	box5.PushBack({ 27, 1, 23, 15 });
	box5.PushBack({ 1, 18, 23, 15 });
	box5.PushBack({ 1, 1, 23, 15 });
	box5.speed = 0.08f;
	//box6 animation
	box6.PushBack({ 27, 18, 23, 15 });
	box6.PushBack({ 27, 1, 23, 15 });
	box6.PushBack({ 1, 18, 23, 15 });
	box6.PushBack({ 1, 1, 23, 15 });
	box6.speed = 0.08f;
}


ModuleLvl1::~ModuleLvl1()
{}

// Load assets
bool ModuleLvl1::Start()
{
		LOG("Loading lvl1 scene");
		intro = true;
		if (intro) 
		{
			App->audio->PlaySound("Resources/Audio/Sound Effects/Helicopter.wav");
			App->audio->Play("Resources/Audio/Themes_SoundTrack/Area Intro.ogg");
			background = App->textures->Load("Resources/Screens/CommandoArea1.png");//foto del fondo
			graphics4 = App->textures->Load("Resources/Animations/Helicopter.png");
			current_animation = bigh;
			positionh.y = SCREEN_HEIGHT;
			positionh.x = (SCREEN_WIDTH / 2) - 80;
			//App->textures->Unload(graphics4);

			intro = false;
		}
		else {





			App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1, 2 Theme.ogg");
			graphics = App->textures->Load("Resources/Animations/Ally soldier alone.png");
			graphics2 = App->textures->Load("Resources/Animations/Guard Enemy.png");
			graphics3 = App->textures->Load("Resources/Animations/handgranadesx4.png");
			App->render->camera.x = App->render->camera.y = 0;
			App->player->Enable();
			App->collision->Enable();

			// Colliders ---
			wall1 = App->collision->AddCollider({ 193, -(2880 - 2706 - SCREEN_HEIGHT), 63, 46 }, COLLIDER_WALL);
		}
	return true;
}

// UnLoad assets
bool ModuleLvl1::CleanUp()
{
	App->audio->Stop();
	App->player->Disable();
	App->collision->Disable();

	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->textures->Unload(graphics);

	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);
	App->textures->Unload(graphics4);
	App->audio->CleanUp();
	
	//App->audio->Stop();
	return true;
}

// Update: draw background
update_status ModuleLvl1::Update()
{



	// Move camera forward -----------------------------
	int speed = 3;

	if (App->player->position.y == (135 - cont) && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->render->camera.y < ((2880 - SCREEN_HEIGHT)*SCREEN_SIZE) - speed) {
		cont++;
		App->render->camera.y += speed;
	}



	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -2880 + SCREEN_HEIGHT, NULL);

	

	// Calculate helicopter Y position -----------------------------
	if (positionh.y != 5.0f && big==true) {
		positionh.y -= 0.001f;
		//forward = false;
	}

	else if (positionh.y == 5) {
		//forward = true;
		big = false;
		medium = true;
		current_animation = medh;
		positionh.y = 5 + 47;
		positionh.x = (SCREEN_WIDTH / 2) - 80 + 24;

		/*forward = false;*/
	}

	if (medium) {
		current_animation = smallh;

	}
	
	


	App->render->Blit(graphics4, positionh.x, positionh.y, &(current_animation.GetCurrentFrame()), 1.0f); // helicopter animation



	App->render->Blit(graphics, 50, -(2880 - 1675 - SCREEN_HEIGHT), &(ally.GetCurrentFrame()), 1.0f); // ally animation
	App->render->Blit(graphics, 47, -(2880 - 765 - SCREEN_HEIGHT), &(ally2.GetCurrentFrame()), 1.0f); // ally2 animation
	App->render->Blit(graphics, 15, -(2880-765-SCREEN_HEIGHT), &(ally3.GetCurrentFrame()), 1.0f); // ally3 animation
	App->render->Blit(graphics2, 34, -(2880 - 1675 - SCREEN_HEIGHT), &(enemyally.GetCurrentFrame()), 1.0f); // enemyally animation
	App->render->Blit(graphics2, 66, -(2880 - 1675 - SCREEN_HEIGHT), &(enemyally2.GetCurrentFrame()), 1.0f); // enemyally2 animation
	App->render->Blit(graphics3, 161, -(2880 - 2482 - SCREEN_HEIGHT), &(box.GetCurrentFrame()), 1.0f); // box animation
	App->render->Blit(graphics3, 32, -(2880 - 1958 - SCREEN_HEIGHT), &(box2.GetCurrentFrame()), 1.0f); // box2 animation
	App->render->Blit(graphics3, 25, -(2880 - 977 - SCREEN_HEIGHT), &(box3.GetCurrentFrame()), 1.0f); // box3 animation
	App->render->Blit(graphics3, 55, -(2880 - 718 - SCREEN_HEIGHT), &(box4.GetCurrentFrame()), 1.0f); // box4 animation
	App->render->Blit(graphics3, 2, -(2880 - 492 - SCREEN_HEIGHT), &(box5.GetCurrentFrame()), 1.0f); // box5 animation
	App->render->Blit(graphics3, 166, -(2880 - 258 - SCREEN_HEIGHT), &(box6.GetCurrentFrame()), 1.0f); // box6 animation




	if (App->input->keyboard[SDL_SCANCODE_1]) {

		App->fade->FadeToBlack(this, App->lvl2, 1);

	}

	return UPDATE_CONTINUE;
}