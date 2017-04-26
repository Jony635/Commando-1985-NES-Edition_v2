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
#include "Animation.h"



ModuleEndLvl1::ModuleEndLvl1()
{
	//guy animation
	guy.PushBack({ 1, 0, 36, 64 });
	guy.PushBack({ 37, 0, 36, 64 });
	guy.PushBack({ 73, 0, 36, 64 });
	guy.PushBack({ 1, 0, 36, 64 });
	guy.PushBack({ 37, 0, 36, 64 });
	guy.PushBack({ 73, 0, 36, 64 });
	guy.PushBack({ 1, 0, 36, 64 });
	guy.PushBack({ 37, 0, 36, 64 });
	guy.PushBack({ 73, 0, 36, 64 });
	guy.PushBack({ 1, 0, 36, 64 });
	guy.PushBack({ 37, 0, 36, 64 });
	guy.loop = false;
	guy.speed = 0.02f;

	//A
	a.x = 1;
	a.y = 11;
	a.w = 8;
	a.h = 8;
	//B
	b.x = 19;
	b.y = 11;
	b.w = 8;
	b.h = 8;
	//C
	c.x = 28;
	c.y = 11;
	c.w = 8;
	c.h = 8;
	//D
	d.x = 39;
	d.y = 11;
	d.w = 8;
	d.h = 8;
	//E
	e.x = 56;
	e.y = 11;
	e.w = 8;
	e.h = 8;
	//F
	f.x = 67;
	f.y = 11;
	f.w = 8;
	f.h = 8;
	//G
	g.x = 77;
	g.y = 11;
	g.w = 8;
	g.h = 8;
	//H
	h.x = 88;
	h.y = 11;
	h.w = 8;
	h.h = 8;
	//I
	i.x = 10;
	i.y = 20;
	i.w = 8;
	i.h = 8;
	//L
	l.x = 49;
	l.y = 20;
	l.w = 7;
	l.h = 8;
	//K
	k.x = 39;
	k.y = 20;
	k.w = 8;
	k.h = 8;
	//M
	m.x = 58;
	m.y = 20;
	m.w = 8;
	m.h = 8;
	//N
	n.x = 68;
	n.y = 20;
	n.w = 8;
	n.h = 8;
	//O
	o.x = 78;
	o.y = 20;
	o.w = 8;
	o.h = 8;
	//P
	p.x = 87;
	p.y = 20;
	p.w = 8;
	p.h = 8;
	//R
	r.x = 1;
	r.y = 29;
	r.w = 8;
	r.h = 8;
	//S
	s.x = 11;
	s.y = 29;
	s.w = 8;
	s.h = 8;
	//T
	t.x = 20;
	t.y = 29;
	t.w = 7;
	t.h = 8;
	//U
	u.x = 29;
	u.y = 29;
	u.w = 8;
	u.h = 8;
	//W
	w.x = 49;
	w.y = 29;
	w.w = 8;
	w.h = 8;



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

ModuleEndLvl1::~ModuleEndLvl1()
{}

// Load assets
bool ModuleEndLvl1::Start()
{
	time = 0;
	//App->input->Enable();//pa ahora hacer skape
	App->textures->Enable();
	App->audio->Enable();
	App->player->Disable();
	App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 2 Presentation.ogg", false);
	leters = App->textures->Load("Resources/Animations/Alphabet.png");//letras
	animation = App->textures->Load("Resources/Animations/Animation_end_mission1.png");//letras

	LOG("Loading endlvl scene");
	bool ret = true;
	App->render->camera.x = App->render->camera.y = 0;


	return ret;
}

// UnLoad assets
bool ModuleEndLvl1::CleanUp()
{
	//App->audio->Disable();
	App->audio->Stop();

	App->textures->Unload(leters);

	return true;
}

// Update: draw background
update_status ModuleEndLvl1::Update()
{

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






	time += 0.02f;



	// Draw everything --------------------------------------
	App->render->Blit(animation, 104, 105, &(guy.GetCurrentFrame()), 1.0f); // guy animation


	if (time>1)
		App->render->Blit(leters, 32, 40, &b);
	if (time > 1.2)
		App->render->Blit(leters, 40, 40, &r);
	if (time > 1.4)
		App->render->Blit(leters, 48, 40, &o);
	if (time > 1.6)
		App->render->Blit(leters, 56, 40, &k);
	if (time > 1.8)
		App->render->Blit(leters, 64, 40, &e);

	if (time > 2)
		App->render->Blit(leters, 81, 40, &t);
	if (time > 2.2)
		App->render->Blit(leters, 88, 40, &h);
	if (time > 2.4)
		App->render->Blit(leters, 96, 40, &e);

	if (time>2.6)
		App->render->Blit(leters, 112, 40, &one);
	if (time > 2.8)
		App->render->Blit(leters, 120, 40, &s);
	if (time > 3)
		App->render->Blit(leters, 128, 40, &t);


	if (time > 3.2)
		App->render->Blit(leters, 144, 40, &a);
	if (time > 3.4)
		App->render->Blit(leters, 152, 40, &r);
	if (time > 3.6)
		App->render->Blit(leters, 160, 40, &e);
	if (time > 3.8)
		App->render->Blit(leters, 168, 40, &a);

	if (time>4)
		App->render->Blit(leters, 32, 56, &n);
	if (time > 4.2)
		App->render->Blit(leters, 40, 56, &o);
	if (time > 4.4)
		App->render->Blit(leters, 48, 56, &w);

	if (time>4.6)
		App->render->Blit(leters, 64, 56, &r);
	if (time > 4.8)
		App->render->Blit(leters, 72, 56, &u);
	if (time > 5)
		App->render->Blit(leters, 80, 56, &s);
	if (time > 5.2)
		App->render->Blit(leters, 88, 56, &h);

	if (time > 5.4)
		App->render->Blit(leters, 105, 56, &t);
	if (time > 5.6)
		App->render->Blit(leters, 112, 56, &o);

	if (time > 5.8)
		App->render->Blit(leters, 129, 56, &t);
	if (time > 6)
		App->render->Blit(leters, 136, 56, &h);
	if (time > 6.2)
		App->render->Blit(leters, 143, 56, &e);

	if (time>6.4)
		App->render->Blit(leters, 160, 56, &two);
	if (time > 6.6)
		App->render->Blit(leters, 168, 56, &n);
	if (time > 6.8)
		App->render->Blit(leters, 176, 56, &d);

	if (time > 7)
		App->render->Blit(leters, 192, 56, &a);
	if (time > 7.2)
		App->render->Blit(leters, 200, 56, &r);
	if (time > 7.4)
		App->render->Blit(leters, 208, 56, &e);
	if (time > 7.6)
		App->render->Blit(leters, 216, 56, &a);

	if (time>12) {

		App->fade->FadeToBlack(this, App->welcome, 0);
	}

	return UPDATE_CONTINUE;
}