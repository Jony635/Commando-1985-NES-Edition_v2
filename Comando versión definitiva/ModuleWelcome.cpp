#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWelcome.h"
#include "ModuleLvl2.h"
#include "ModuleAudio.h"
#include "ModuleSecretAreas.h"
#include "ModulePlayer.h"
#include "ModuleFonts.h"

#include <stdio.h>


ModuleWelcome::ModuleWelcome() {}

ModuleWelcome::~ModuleWelcome() {}

bool ModuleWelcome::Start() {

	LOG("Loading Welcome scene");

	App->secretareas->hgcounter = App->secretareas->mgcounter = 0;
	App->player->live_counter = 4;
	App->player->granade_counter = 5;
	App->secretareas->actual_room = ROOM1;
	App->lvl2->checkpointpassed = false;
	App->player->soundhighscore = true;
	App->player->win = false;
	App->secretareas->playdorosound = true;


	for (int i = 0; i < StartTypes::MAX_TYPES; i++)
	{
		App->start_types_arr[i] = false;
	}
	for (int i = 0; i < pu_taken_lvl2::MAXIM_TYPES; i++)
	{
		App->powerups_taken[i] = false;
	}


	//fonts
	font_high_score = App->fonts->Load("Resources/ui/Alphabetred.png", "0123456789abcdefghiklmnoprstuvwxyq<HIGH=!'�$%&/()-.�@ASD_GHJ", 6);
	font_welcome_score = App->fonts->Load("Resources/ui/Alphabetwhite.png", "0123456789abcdefghiklmnoprstuvwxyq<HIGH=!'�$%&/()-.�@ASD_GHJ", 6);



	//Textures
	Area2Option = App->textures->Load("Resources/Screens/Intro_Screen1.png");//foto del fondo
	ExitOption= App->textures->Load("Resources/Screens/Intro_Screen2.png");//foto del fondo
	//Enables and Disables
	App->player->Enable();
	App->textures->Enable();
	App->audio->Enable();
	Menu_Options = MENU::Lvl2;
	//Cameras positions
	App->render->camera.x = App->render->camera.y = 0;
	App->audio->Play("Resources/Audio/Themes_SoundTrack/Title Theme.ogg", true);
	//init stairs
	App->lvl2->current_stair1_animation = &App->lvl2->stairinv;
	App->lvl2->current_stair2_animation = &App->lvl2->stairinv;
	App->lvl2->current_stair3_animation = &App->lvl2->stairinv;
	App->lvl2->current_stair4_animation = &App->lvl2->stairinv;
	App->lvl2->current_stair5_animation = &App->lvl2->stairinv;
	App->lvl2->current_stair6_animation = &App->lvl2->stairinv;
	//restart things
	App->secretareas->gateopened = false;
	App->secretareas->swallposition.x = 33;
	App->secretareas->swallposition.y = 216;
	return true;
}

update_status ModuleWelcome::Update() {


	if (!App->fade->IsFading())
	{
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_DOWN ||
			App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_DOWN)
		{
			if (Menu_Options == MENU::Lvl2)
				Menu_Options = MENU::exit;
			else if (Menu_Options == MENU::exit)
				Menu_Options = MENU::Lvl2;
		}
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_DOWN ||
			App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_DOWN)
		{
			if (Menu_Options == MENU::Lvl2)
				Menu_Options = MENU::exit;
			else if (Menu_Options == MENU::exit)
				Menu_Options = MENU::Lvl2;
		}
	}
	//Render Map
	if(Menu_Options==MENU::Lvl2)
	App->render->Blit(Area2Option, 0,  0, NULL);
	if(Menu_Options == MENU::exit)
	App->render->Blit(ExitOption, 0,  0, NULL);

	//render scores
	sprintf(App->player->score_text, "%06d", App->player->score);
	sprintf(one_up_text, "%s", "up");
	sprintf(high_text, "%s", "high");
	sprintf(App->player->high_score_text, "%06d", App->player->highscore);

	App->fonts->BlitText(16, 16, font_welcome_score, App->player->score_text);
	App->fonts->BlitText(24, 8, font_welcome_score, one_up_text);
	App->fonts->BlitText(16, 8, font_welcome_score, "1");
	App->fonts->BlitText(104, 16, font_high_score, App->player->high_score_text);
	App->fonts->BlitText(112, 8, font_high_score, high_text);

	//Fade to black to next lvl
	if ((App->input->keyboard[SDL_SCANCODE_RETURN] || App->input->buttons[SDL_CONTROLLER_BUTTON_A]==KEY_DOWN)&& Menu_Options==MENU::Lvl2) {
		App->fade->FadeToBlack(this, App->lvl2, 2);
		
	}
	else if ((App->input->keyboard[SDL_SCANCODE_RETURN] || App->input->buttons[SDL_CONTROLLER_BUTTON_A] == KEY_DOWN) && Menu_Options == MENU::exit)
	{
		return UPDATE_STOP;
	}

	return UPDATE_CONTINUE;

}

bool ModuleWelcome::CleanUp() {

	LOG("Unloading welcome scene");

	//Unload textures
	App->textures->Unload(ExitOption);
	ExitOption = nullptr;
	App->textures->Unload(Area2Option);
	Area2Option = nullptr;

	App->fonts->UnLoad(font_high_score);
	font_high_score = -1;
	App->fonts->UnLoad(font_welcome_score);
	font_welcome_score = -1;

	App->player->score = 0;

	//Disables
	App->textures->Disable();
	App->audio->Disable();
	App->player->Disable();

	

	return true;
}

