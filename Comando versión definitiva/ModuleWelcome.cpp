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
#include "ModuleHelicopter.h"
#include "ModuleEndLvl1.h"



ModuleWelcome::ModuleWelcome()
{
	// zero
	zero.x = 1;
	zero.y = 1;
	zero.w = 8;
	zero.h = 8;
	// one
	one.x = 9;
	one.y = 1;
	one.w = 8;
	one.h = 8;
	// two
	two.x = 18;
	two.y = 1;
	two.w = 8;
	two.h = 8;
	// three
	three.x = 29;
	three.y = 1;
	three.w = 8;
	three.h = 8;
	// four
	four.x = 39;
	four.y = 1;
	four.w = 8;
	four.h = 8;
	// five
	five.x = 49;
	five.y = 1;
	five.w = 8;
	five.h = 8;
	// six
	six.x = 59;
	six.y = 1;
	six.w = 8;
	six.h = 8;
	// seven
	seven.x = 68;
	seven.y = 1;
	seven.w = 8;
	seven.h = 8;
	// eight
	eight.x = 78;
	eight.y = 1;
	eight.w = 8;
	eight.h = 8;
	// nine
	nine.x = 88;
	nine.y = 1;
	nine.w = 8;
	nine.h = 8;
	//pone
	pone.x = 35;
	pone.y = 39;
	pone.w = 22;
	pone.h = 8;

	// redzero
	redzero.x = 1;
	redzero.y = 49;
	redzero.w = 8;
	redzero.h = 8;
	// redone
	redone.x = 9;
	redone.y = 49;
	redone.w = 8;
	redone.h = 8;
	// redtwo
	redtwo.x = 18;
	redtwo.y = 49;
	redtwo.w = 8;
	redtwo.h = 8;
	// redthree
	redthree.x = 29;
	redthree.y = 49;
	redthree.w = 8;
	redthree.h = 8;
	// redfour
	redfour.x = 39;
	redfour.y = 49;
	redfour.w = 8;
	redfour.h = 8;
	// redfive
	redfive.x = 49;
	redfive.y = 49;
	redfive.w = 8;
	redfive.h = 8;
	// redsix
	redsix.x = 59;
	redsix.y = 49;
	redsix.w = 8;
	redsix.h = 8;
	// redseven
	redseven.x = 68;
	redseven.y = 49;
	redseven.w = 8;
	redseven.h = 8;
	// redeight
	redeight.x = 78;
	redeight.y = 49;
	redeight.w = 8;
	redeight.h = 8;
	// rednine
	rednine.x = 88;
	rednine.y = 49;
	rednine.w = 8;
	rednine.h = 8;
	//highsc
	highsc.x = 2;
	highsc.y = 39;
	highsc.w = 32;
	highsc.h = 8;
}

ModuleWelcome::~ModuleWelcome()
{}

// Load assets
bool ModuleWelcome::Start()
{
	App->player->contlives = 4;
	App->textures->Enable();
	App->audio->Enable();
	App->input->Enable();
	App->audio->Play("Resources/Audio/Themes_SoundTrack/Title Theme.ogg",true);
	LOG("Loading welcome scene");
	bool ret = true;
	background = App->textures->Load("Resources/Screens/Commandowelcome.png");//foto del fondo
	App->render->camera.x = App->render->camera.y = 0;
	leters = App->textures->Load("Resources/Animations/Alphabet.png");//letras


	return ret;
}

// UnLoad assets
bool ModuleWelcome::CleanUp()
{
	//App->audio->Disable();
	App->audio->Stop();
	App->textures->Unload(leters);

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleWelcome::Update()
{
	



	// Draw everything --------------------------------------
	App->render->Blit(background, 0,  0, NULL);
	App->render->Blit(leters, 114, -(2880 - 2667 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &highsc);// hsc
	App->render->Blit(leters, 18, -(2880 - 2667 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &pone);// pone

	if (App->player->hs[0] == 0)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redzero);// red
	if (App->player->hs[1] == 0)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redzero);// red
	if (App->player->hs[2] == 0)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redzero);// red
	if (App->player->hs[3] == 0)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redzero);// red
	if (App->player->hs[4] == 0)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redzero);// red
	if (App->player->hs[5] == 0)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redzero);// red

	if (App->player->hs[0] == 1)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redone);// red
	if (App->player->hs[1] == 1)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redone);// red
	if (App->player->hs[2] == 1)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redone);// red
	if (App->player->hs[3] == 1)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redone);// red
	if (App->player->hs[4] == 1)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redone);// red
	if (App->player->hs[5] == 1)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redone);// red

	if (App->player->hs[0] == 2)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redtwo);// red
	if (App->player->hs[1] == 2)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redtwo);// red
	if (App->player->hs[2] == 2)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redtwo);// red
	if (App->player->hs[3] == 2)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redtwo);// red
	if (App->player->hs[4] == 2)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redtwo);// red
	if (App->player->hs[5] == 2)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redtwo);// red

	if (App->player->hs[0] == 3)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redthree);// red
	if (App->player->hs[1] == 3)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redthree);// red
	if (App->player->hs[2] == 3)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redthree);// red
	if (App->player->hs[3] == 3)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redthree);// red
	if (App->player->hs[4] == 3)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redthree);// red
	if (App->player->hs[5] == 3)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redthree);// red

	if (App->player->hs[0] == 4)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfour);// red
	if (App->player->hs[1] == 4)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfour);// red
	if (App->player->hs[2] == 4)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfour);// red
	if (App->player->hs[3] == 4)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfour);// red
	if (App->player->hs[4] == 4)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfour);// red
	if (App->player->hs[5] == 4)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfour);// red

	if (App->player->hs[0] == 5)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfive);// red
	if (App->player->hs[1] == 5)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfive);// red
	if (App->player->hs[2] == 5)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfive);// red
	if (App->player->hs[3] == 5)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfive);// red
	if (App->player->hs[4] == 5)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfive);// red
	if (App->player->hs[5] == 5)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redfive);// red

	if (App->player->hs[0] == 6)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redsix);// red
	if (App->player->hs[1] == 6)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redsix);// red
	if (App->player->hs[2] == 6)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redsix);// red
	if (App->player->hs[3] == 6)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redsix);// red
	if (App->player->hs[4] == 6)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redsix);// red
	if (App->player->hs[5] == 6)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redsix);// red

	if (App->player->hs[0] == 7)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redseven);// red
	if (App->player->hs[1] == 7)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redseven);// red
	if (App->player->hs[2] == 7)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redseven);// red
	if (App->player->hs[3] == 7)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redseven);// red
	if (App->player->hs[4] == 7)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redseven);// red
	if (App->player->hs[5] == 7)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redseven);// red

	if (App->player->hs[0] == 8)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redeight);// red
	if (App->player->hs[1] == 8)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redeight);// red
	if (App->player->hs[2] == 8)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redeight);// red
	if (App->player->hs[3] == 8)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redeight);// red
	if (App->player->hs[4] == 8)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redeight);// red
	if (App->player->hs[5] == 8)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &redeight);// red

	if (App->player->hs[0] == 9)
		App->render->Blit(leters, 104, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &rednine);// red
	if (App->player->hs[1] == 9)
		App->render->Blit(leters, 104 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &rednine);// red
	if (App->player->hs[2] == 9)
		App->render->Blit(leters, 104 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &rednine);// red
	if (App->player->hs[3] == 9)
		App->render->Blit(leters, 104 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &rednine);// red
	if (App->player->hs[4] == 9)
		App->render->Blit(leters, 104 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &rednine);// red
	if (App->player->hs[5] == 9)
		App->render->Blit(leters, 104 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &rednine);// red

	if (App->player->sc[0] == 0)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero);// zero
	if (App->player->sc[1] == 0)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero);// zero
	if (App->player->sc[2] == 0)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero);// zero
	if (App->player->sc[3] == 0)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero);// zero
	if (App->player->sc[4] == 0)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero);// zero
	if (App->player->sc[5] == 0)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero);// zero

	if (App->player->sc[0] == 1)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[1] == 1)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[2] == 1)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[3] == 1)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[4] == 1)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[5] == 1)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one

	if (App->player->sc[0] == 2)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[1] == 2)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[2] == 2)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[3] == 2)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[4] == 2)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[5] == 2)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two

	if (App->player->sc[0] == 3)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[1] == 3)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[2] == 3)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[3] == 3)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[4] == 3)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[5] == 3)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three

	if (App->player->sc[0] == 4)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[1] == 4)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[2] == 4)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[3] == 4)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[4] == 4)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[5] == 4)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four

	if (App->player->sc[0] == 5)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[1] == 5)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[2] == 5)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[3] == 5)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[4] == 5)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[5] == 5)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five

	if (App->player->sc[0] == 6)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[1] == 6)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[2] == 6)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[3] == 6)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[4] == 6)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[5] == 6)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five

	if (App->player->sc[0] == 7)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[1] == 7)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[2] == 7)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[3] == 7)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[4] == 7)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[5] == 7)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five

	if (App->player->sc[0] == 8)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[1] == 8)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[2] == 8)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[3] == 8)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[4] == 8)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[5] == 8)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five

	if (App->player->sc[0] == 9)
		App->render->Blit(leters, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[1] == 9)
		App->render->Blit(leters, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[2] == 9)
		App->render->Blit(leters, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[3] == 9)
		App->render->Blit(leters, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[4] == 9)
		App->render->Blit(leters, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[5] == 9)
		App->render->Blit(leters, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five

	if (App->input->keyboard[SDL_SCANCODE_RETURN]) {

		App->fade->FadeToBlack(this, App->helicopter, 0);
	}

	return UPDATE_CONTINUE;
}