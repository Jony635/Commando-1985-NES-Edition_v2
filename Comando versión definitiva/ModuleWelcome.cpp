#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWelcome.h"
#include "ModuleLvl2.h"


ModuleWelcome::ModuleWelcome() {}

ModuleWelcome::~ModuleWelcome() {}

bool ModuleWelcome::Start() {

	LOG("Loading Welcome scene");
	
	//Textures
	Area2Option = App->textures->Load("Resources/Screens/Intro_Screen1.png");//foto del fondo
	ExitOption= App->textures->Load("Resources/Screens/Intro_Screen2.png");//foto del fondo
	//Enables and Disables
	App->textures->Enable();

	Menu_Options = MENU::Lvl2;
	//Cameras positions
	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

update_status ModuleWelcome::Update() {

	if (App->input->keyboard[SDL_SCANCODE_S]==KEY_DOWN||
		App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_DOWN]==KEY_DOWN)
	{
		if (Menu_Options == MENU::Lvl2)
			Menu_Options = MENU::exit;
		else if(Menu_Options == MENU::exit)
			Menu_Options = MENU::Lvl2;
	}
	if (App->input->keyboard[SDL_SCANCODE_W]==KEY_DOWN ||
		App->input->buttons[SDL_CONTROLLER_BUTTON_DPAD_UP]==KEY_DOWN)
	{
		if (Menu_Options == MENU::Lvl2)
			Menu_Options = MENU::exit;
		else if (Menu_Options == MENU::exit)
			Menu_Options = MENU::Lvl2;
	}

	//Render Map
	if(Menu_Options==MENU::Lvl2)
	App->render->Blit(Area2Option, 0,  0, NULL);
	if(Menu_Options == MENU::exit)
	App->render->Blit(ExitOption, 0,  0, NULL);

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

	LOG("Unloading lvl1 scene");

	//Disables
	App->textures->Disable();


	//Unload textures
	App->textures->Unload(ExitOption);
	App->textures->Unload(Area2Option);

	return true;
}

