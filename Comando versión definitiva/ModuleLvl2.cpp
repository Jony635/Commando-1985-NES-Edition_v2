#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleLvl2.h"


ModuleLvl2::ModuleLvl2(){}

ModuleLvl2::~ModuleLvl2(){}

bool ModuleLvl2::Start() {

	LOG("Loading lvl1 scene");

	//Textures
	background = App->textures->Load("Resources/Screens/CommandoArea2.png");//foto del fondo

	//Enables & Disables
	App->textures->Enable();

	//Caeras positions
	App->render->camera.x = App->render->camera.y = 0;

	return true;
}

update_status ModuleLvl2::Update(){

	//Render Map
	App->render->Blit(background, 0, -2880 + SCREEN_HEIGHT, NULL);

	////Fade to black to next lvl
	//if (App->input->keyboard[SDL_SCANCODE_F2]) {
	//	App->fade->FadeToBlack(this, App->endlvl2, 0);
	//}

	return UPDATE_CONTINUE;

}

bool ModuleLvl2::CleanUp(){

	LOG("Unloading lvl1 scene");

	//Disables
	App->textures->Disable();


	//Unload textures
	App->textures->Unload(background);

	return true;
}

