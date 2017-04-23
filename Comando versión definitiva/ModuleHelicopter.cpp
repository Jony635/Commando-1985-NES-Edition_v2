#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLvl1.h"
#include "ModuleWelcome.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Animation.h"
#include "ModuleHelicopter.h"

#include "ModuleLvl2.h"
#include "ModuleGameOver.h"
#include "ModulePlayer.h"

ModuleHelicopter::ModuleHelicopter()
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

	//joejump animation
	joejump.PushBack({ 94, 77, 15, 21 });
	joejump.speed = 0.08f;
	//joevoid  animation
	joevoid.PushBack({ 99, 25, 15, 21 });
	joevoid.speed = 0.08f;
	//joegoodbye  animation
	joegoodbye.PushBack({ 56, 73, 16, 26 });
	joegoodbye.PushBack({ 74, 73, 16, 26 });
	joegoodbye.speed = 0.04f;
	//joerun  animation
	joerun.PushBack({ 2, 49, 16, 22 });
	joerun.PushBack({ 20, 49, 16, 22 });
	joerun.speed = 0.08f;
}


ModuleHelicopter::~ModuleHelicopter()
{}

// Load assets
bool ModuleHelicopter::Start()
{
	LOG("Loading lvl1 scene");

	App->player->Disable();
	App->audio->Enable();

	App->audio->Play("Resources/Audio/Themes_SoundTrack/Area Intro.ogg",true);
	background = App->textures->Load("Resources/Screens/CommandoArea1.png");//foto del fondo
	graphics4 = App->textures->Load("Resources/Animations/Helicopter.png");
	graphics5 = App->textures->Load("Resources/Animations/Main Character Blue.png");
	positionhy = SCREEN_HEIGHT - 50;
	positionhx = (SCREEN_WIDTH / 2) - 80;
	positionjoey = 85 + 25;
	positionjoex = (SCREEN_WIDTH / 2) + 18;
	contanimh = 0;
	contanimj = 0;


	if (current_animationjoe != &joevoid)
	{
		joevoid.Reset();
		current_animationjoe = &joevoid;
	}

	//current_animationh = bigh;

	return true;

}

// UnLoad assets
bool ModuleHelicopter::CleanUp()
{
	App->audio->Stop();

	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->textures->Unload(graphics4);
	App->textures->Unload(graphics5);
	firstimelvl1 = true;

	//App->audio->Stop();
	return true;
}


update_status ModuleHelicopter::Update() {
	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -2880 + SCREEN_HEIGHT, NULL);


	contanimh += 0.02f;
	/*if (contanimh > 7) {
	contanimj += 0.1f;

	}*/
	// Calculate helicopter & joe position -----------------------------




	if (contanimh > 5 && contanimh < 6) {
		if (current_animationjoe != &joejump)
		{
			joejump.Reset();
			current_animationjoe = &joejump;
		}
	}

	else if (contanimh>6 && contanimh<7) {
		contanimj += 0.1f;

		positionjoex = ((SCREEN_WIDTH / 2) + 18) + (contanimj * 5.5);
		positionjoey = 85 + 25 + ((-30)*(contanimj)) + (6 * contanimj*contanimj);

		if (current_animationjoe != &joejump)
		{
			joejump.Reset();
			current_animationjoe = &joejump;
		}
	}

	if (contanimh>7 && contanimh<9) {

		if (current_animationjoe != &joegoodbye)
		{
			joegoodbye.Reset();
			current_animationjoe = &joegoodbye;
		}
	}
	if (contanimh>9 && contanimh<11.4) {

		positionjoex -= 0.45;
		positionjoey += 0.25;

		if (current_animationjoe != &joerun)
		{
			joerun.Reset();
			current_animationjoe = &joerun;
		}
	}



	//falta ponerlo que jonny mayude

	/* if (contanimh < 4) {
	music1 = true;
	cont++;
	}
	else if (contanimh > 4 && contanimh < 9) {
	music1 = false;
	music2 = true;
	cont2++;

	}
	else if (contanimh > 9 && contanimh < 11.5) {
	music2 = false;
	music3 = true;
	cont3++;

	}*/


	if (contanimh >0 && contanimh <0.01f) {
		Mix_HaltChannel(-1);
		App->audio->sounfeffect1 = nullptr;
	}
	if (contanimh < 4 && App->audio->sounfeffect1 == nullptr) {
	App->audio->PlaySound("Resources/Audio/Sound Effects/Helicopter.wav");
	
	}
	if (contanimh >4 && contanimh <4.02f) {
		Mix_HaltChannel(-1);
		App->audio->sounfeffect1 = nullptr;

	}
	if (contanimh > 4 && contanimh < 9 && App->audio->sounfeffect1 == nullptr) {
		App->audio->PlaySound("Resources/Audio/Sound Effects/Helicopter is going away.wav");
	}
	if (contanimh >8 && contanimh <8.02f) {
		Mix_HaltChannel(-1);
		App->audio->sounfeffect1 = nullptr;

	}
	if (contanimh > 8 && contanimh < 11.4 && App->audio->sounfeffect1 == nullptr) {
		App->audio->PlaySound("Resources/Audio/Sound Effects/helicopter is going MORE away.wav");
	}
	if (contanimh >11.4) {
		Mix_HaltChannel(-1);
		App->audio->sounfeffect1 = nullptr;

	}
	

	







	if (positionhy > 15.0f && contanimh < 4.50f) {
		if (current_animationh != &bigh)
		{
			bigh.Reset();
			current_animationh = &bigh;
		}

		positionhy -= 0.80f;
		//forward = false;
	}

	else if (contanimh > 4.5 && contanimh < 5) {
		if (current_animationh != &medh)
		{
			medh.Reset();
			current_animationh = &medh;
		}

		positionhy = 15 + 47;
		positionhx = (SCREEN_WIDTH / 2) - 80 + 24;

		/*forward = false;*/
	}

	else if (contanimh > 5 && contanimh < 7) {
		positionhx = (SCREEN_WIDTH / 2) - 80 + 18;


		if (current_animationh != &smallh)
		{
			smallh.Reset();
			current_animationh = &smallh;
		}

		//medium = false;

	}
	else if (contanimh > 7 && contanimh < 7.5) {
		//big = true;
		if (current_animationh != &medh)
		{
			medh.Reset();
			current_animationh = &medh;
		}

		//current_animationh = medh;

		positionhy = 15 + 47;
		positionhx = (SCREEN_WIDTH / 2) - 80 + 24;

	}
	else if (contanimh > 7.5 && contanimh < 8) {
		if (current_animationh != &bigh)
		{
			bigh.Reset();
			current_animationh = &bigh;
		}
		positionhy = 15;
		positionhx = (SCREEN_WIDTH / 2) - 80;

	}
	else if (contanimh > 8) {
		if (current_animationh != &bigh)
		{
			bigh.Reset();
			current_animationh = &bigh;
		}
		positionhy -= 1.0f;

	}






	//App->render->Blit(graphics4, positionh.x, (int)positionh.y, &(current_animationh.GetCurrentFrame())); // helicopter animation
	App->render->Blit(graphics4, positionhx, (int)positionhy, &(current_animationh->GetCurrentFrame())); // helicopter animation
	App->render->Blit(graphics5, positionjoex, positionjoey, &(current_animationjoe->GetCurrentFrame())); // joe animation


	if (contanimh > 11.5) {
		contanimh = 0;
		contanimj = 0;
		App->fade->FadeToBlack(this, App->lvl1, 0);
	}


	return UPDATE_CONTINUE;

}