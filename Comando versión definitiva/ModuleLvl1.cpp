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
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleHelicopter.h"
#include "Math.h"
#include "ModuleEndLvl1.h"




ModuleLvl1::ModuleLvl1()
{
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
	rednine.x = 2;
	rednine.y = 39;
	rednine.w = 32;
	rednine.h = 8;

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

	// handg
	handg.x = 7;
	handg.y = 28;
	handg.w = 10;
	handg.h = 12;
	// life
	life.x = 0;
	life.y = 0;
	life.w = 11;
	life.h = 15;
	

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
	cont = 0;
	intro = true;
	big = true;
	medium = false;
	small = false;
	contanimh = 0;
	forward = false;
	
	//App->input->Disable();
	background = App->textures->Load("Resources/Screens/CommandoArea1.png");//foto del fondo
	App->textures->Enable();
	App->player->Enable();
	App->render->camera.x = App->render->camera.y = 0;
	App->player->timeintro = 0;

	if (App->helicopter->firstimelvl1 == false) 
	{
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Commando (NES) Music - New Life Intro.ogg", false);

	}


		graphics = App->textures->Load("Resources/Animations/Ally soldier alone.png");
		graphics2 = App->textures->Load("Resources/Animations/Guard Enemy.png");
		graphics3 = App->textures->Load("Resources/Animations/handgranadesx4.png");
		graphics4= App->textures->Load("Resources/Animations/Alphabet.png");
		graphics5 = App->textures->Load("Resources/Animations/boosted handgranade.png");
		graphics6 = App->textures->Load("Resources/Animations/lives_counter.png");
		App->enemies->Enable();
		App->collision->Enable();
		App->particles->Enable();
		//App->player->timeintro = 0;


		// Colliders ---
		int i = 0;
		wall[i++] = App->collision->AddCollider({ 198, -(2880 - 2708 - SCREEN_HEIGHT), 54, 31 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 4, -(2880 - 2645 - SCREEN_HEIGHT), 36, 29 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 87, -(2880 - 2643 - SCREEN_HEIGHT), 23, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 135, -(2880 - 2595 - SCREEN_HEIGHT), 23, 21 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 151, -(2880 - 2579 - SCREEN_HEIGHT), 22, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 136, -(2880 - 2819 - SCREEN_HEIGHT), 21, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 152, -(2880 - 2803 - SCREEN_HEIGHT), 20, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 169, -(2880 - 2819 - SCREEN_HEIGHT), 19, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 25, -(2880 - 2772 - SCREEN_HEIGHT), 20, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 88, -(2880 - 2532 - SCREEN_HEIGHT), 21, 19 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 201, -(2880 - 2502 - SCREEN_HEIGHT), 55, 40 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 208, -(2880 - 2486 - SCREEN_HEIGHT), 48, 24 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 7, -(2880 - 2418 - SCREEN_HEIGHT), 23, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 23, -(2880 - 2402 - SCREEN_HEIGHT), 22, 21 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 161, -(2880 - 80 - SCREEN_HEIGHT), 60, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 37, -(2880 - 2418 - SCREEN_HEIGHT), 26, 23 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 165, -(2880 - 2595 - SCREEN_HEIGHT), 26, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 127, -(2880 - 2384 - SCREEN_HEIGHT), 62, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 86, -(2880 - 2338 - SCREEN_HEIGHT), 25, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 150, -(2880 - 2290 - SCREEN_HEIGHT), 25, 22 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 2262 - SCREEN_HEIGHT), 50, 57 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 38, -(2880 - 2283 - SCREEN_HEIGHT), 21, 27 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 41, -(2880 - 2269 - SCREEN_HEIGHT), 11, 19 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 214, -(2880 - 2226 - SCREEN_HEIGHT), 25, 24 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1989 - SCREEN_HEIGHT), 111, 58 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 103, -(2880 - 2009 - SCREEN_HEIGHT), 20, 30 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 101, -(2880 - 1995 - SCREEN_HEIGHT), 16, 26 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 209, -(2880 - 1926 - SCREEN_HEIGHT), 47, 55 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 198, -(2880 - 1946 - SCREEN_HEIGHT), 29, 29 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 206, -(2880 - 1933 - SCREEN_HEIGHT), 22, 16 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 78, -(2880 - 1863 - SCREEN_HEIGHT), 66, 56 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 70, -(2880 - 1882 - SCREEN_HEIGHT), 82, 28 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 212, -(2880 - 1751 - SCREEN_HEIGHT), 48, 55 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 199, -(2880 - 1768 - SCREEN_HEIGHT), 25, 33 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 203, -(2880 - 1758 - SCREEN_HEIGHT), 22, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1701 - SCREEN_HEIGHT), 47, 59 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 43, -(2880 - 1720 - SCREEN_HEIGHT), 14, 30 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 39, -(2880 - 1709 - SCREEN_HEIGHT), 12, 24 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 70, -(2880 - 1697 - SCREEN_HEIGHT), 25, 23 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 86, -(2880 - 1682 - SCREEN_HEIGHT), 25, 20 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 101, -(2880 - 1699 - SCREEN_HEIGHT), 26, 21 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 150, -(2880 - 1538 - SCREEN_HEIGHT), 25, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 22, -(2880 - 1539 - SCREEN_HEIGHT), 24, 21 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 85, -(2880 - 1474 - SCREEN_HEIGHT), 26, 22 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 191, -(2880 - 1472 - SCREEN_HEIGHT), 62, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1343 - SCREEN_HEIGHT), 98, 82 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 158, -(2880 - 1343 - SCREEN_HEIGHT), 98, 82 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1205 - SCREEN_HEIGHT), 30, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 50, -(2880 - 1141 - SCREEN_HEIGHT), 28, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 162, -(2880 - 1141 - SCREEN_HEIGHT), 28, 18 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 194, -(2880 - 1088 - SCREEN_HEIGHT), 57, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 34, -(2880 - 1061 - SCREEN_HEIGHT), 28, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 114, -(2880 - 1028 - SCREEN_HEIGHT), 26, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 1008 - SCREEN_HEIGHT), 57, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 178, -(2880 - 997 - SCREEN_HEIGHT), 26, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 162, -(2880 - 933 - SCREEN_HEIGHT), 26, 17 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 18, -(2880 - 853 - SCREEN_HEIGHT), 26, 17 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 114, -(2880 - 853 - SCREEN_HEIGHT), 27, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 210, -(2880 - 853 - SCREEN_HEIGHT), 26, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 221, -(2880 - 719 - SCREEN_HEIGHT), 35, 82 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 211, -(2880 - 729 - SCREEN_HEIGHT), 20, 68 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 66, -(2880 - 752 - SCREEN_HEIGHT), 54, 9 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 6, -(2880 - 738 - SCREEN_HEIGHT), 24, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 22, -(2880 - 722 - SCREEN_HEIGHT), 25, 20 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 37, -(2880 - 739 - SCREEN_HEIGHT), 26, 21 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 147, -(2880 - 672 - SCREEN_HEIGHT), 70, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 640 - SCREEN_HEIGHT), 57, 7 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 98, -(2880 - 576 - SCREEN_HEIGHT), 54, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 512 - SCREEN_HEIGHT), 70, 7 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 214, -(2880 - 389 - SCREEN_HEIGHT), 42, 76 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 421 - SCREEN_HEIGHT), 29, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 65, -(2880 - 373 - SCREEN_HEIGHT), 28, 18 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 131, -(2880 - 342 - SCREEN_HEIGHT), 25, 16 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 195, -(2880 - 309 - SCREEN_HEIGHT), 25, 17 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 132, -(2880 - 288 - SCREEN_HEIGHT), 54, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 159, -(2880 - SCREEN_HEIGHT), 97, 31 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - 117 - SCREEN_HEIGHT), 46, 123 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 214, -(2880 - 100 - SCREEN_HEIGHT), 42, 125 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 32, -(2880 - 80 - SCREEN_HEIGHT), 60, 8 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ 0, -(2880 - SCREEN_HEIGHT), 96, 31 }, COLLIDER_WALL);

		wall[i++] = App->collision->AddCollider({ -10, -(2880-2880-SCREEN_HEIGHT), SCREEN_WIDTH, 10 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ -10, -(2880 +10 - SCREEN_HEIGHT), SCREEN_WIDTH, 10 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ -10, -(2880  - SCREEN_HEIGHT), 10, 2880 }, COLLIDER_WALL);
		wall[i++] = App->collision->AddCollider({ SCREEN_WIDTH, -(2880 - SCREEN_HEIGHT), 10, 2880 }, COLLIDER_WALL);





		//Colliders Water

		i = 0;
		water[i++] = App->collision->AddCollider({ 0, -(2880 - 2476 - SCREEN_HEIGHT), 54, 45 }, COLLIDER_WATER);
		water[i++] = App->collision->AddCollider({ 43, -(2880 - 1260 - SCREEN_HEIGHT), 42, 26 }, COLLIDER_WATER);
		water[i++] = App->collision->AddCollider({ 171, -(2880 - 1214 - SCREEN_HEIGHT), 84, 76 }, COLLIDER_WATER);
		water[i++] = App->collision->AddCollider({ 0, -(2880 - 252 - SCREEN_HEIGHT), 87, 60 }, COLLIDER_WATER);


		//Enemies
		App->enemies->AddEnemy(ENEMY_TYPES::KNIFE, 66, -(2880 - 2600 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 93, -(2880 - 2491 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 93, -(2880 - 2491 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::KNIFE, 93, -(2880 - 2491 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 147, -(2880 - 2664 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 147, -(2880 - 2664 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 147, -(2880 - 2664 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 147, -(2880 - 2664 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 147, -(2880 - 2664 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 147, -(2880 - 2664 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 70, -(2880 - 2591 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 70, -(2880 - 2591 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 70, -(2880 - 2591 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 70, -(2880 - 2591 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 70, -(2880 - 2591 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 2490 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 2490 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 2490 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 2490 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 2490 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 142, -(2880 - 2344 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 142, -(2880 - 2344 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 142, -(2880 - 2344 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 142, -(2880 - 2344 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 142, -(2880 - 2344 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 142, -(2880 - 2344 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 94, -(2880 - 2214 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 94, -(2880 - 2214 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 94, -(2880 - 2214 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 94, -(2880 - 2214 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 94, -(2880 - 2214 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 114, -(2880 - 2103 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 114, -(2880 - 2103 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 114, -(2880 - 2103 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 114, -(2880 - 2103 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 114, -(2880 - 2103 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 116, -(2880 - 1955 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 116, -(2880 - 1955 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 116, -(2880 - 1955 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 116, -(2880 - 1955 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 116, -(2880 - 1955 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 96, -(2880 - 1791 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 96, -(2880 - 1791 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 96, -(2880 - 1791 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 96, -(2880 - 1791 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 96, -(2880 - 1791 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 98, -(2880 - 1597 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 98, -(2880 - 1597 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 98, -(2880 - 1597 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 98, -(2880 - 1597 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 98, -(2880 - 1597 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 103, -(2880 - 1218 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 103, -(2880 - 1218 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 103, -(2880 - 1218 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 103, -(2880 - 1218 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 103, -(2880 - 1218 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 115, -(2880 - 1104 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 115, -(2880 - 1104 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 115, -(2880 - 1104 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 115, -(2880 - 1104 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 115, -(2880 - 1104 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 82, -(2880 - 949 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 82, -(2880 - 949 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 82, -(2880 - 949 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 82, -(2880 - 949 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 82, -(2880 - 949 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 158, -(2880 - 785 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 158, -(2880 - 785 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 158, -(2880 - 785 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 158, -(2880 - 785 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 158, -(2880 - 785 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 92, -(2880 - 680 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 92, -(2880 - 680 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 92, -(2880 - 680 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 92, -(2880 - 680 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 92, -(2880 - 680 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 143, -(2880 - 530 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 143, -(2880 - 530 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 143, -(2880 - 530 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 143, -(2880 - 530 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 143, -(2880 - 530 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 406 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 406 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 406 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 406 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 136, -(2880 - 406 - SCREEN_HEIGHT));

		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 123, -(2880 - 120 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 123, -(2880 - 120 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 123, -(2880 - 120 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 123, -(2880 - 120 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 123, -(2880 - 120 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 123, -(2880 - 120 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 123, -(2880 - 120 - SCREEN_HEIGHT));





		App->enemies->AddEnemy(ENEMY_TYPES::BOSSLVL1, 75, -(2880 - 126 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, 34, -(2880 - 1675 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::CAPTURERGUARD, 66, -(2880 - 1675 - SCREEN_HEIGHT));

		/*App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 45, -(2880 - 2491 - 200 - 200 - 200 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 23, -(2880 - 2491 - 200 - 200 - 200 - 200 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 74, -(2880 - 2491 - 200 - 200 - 200 - 200 - 200 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 189, -(2880 - 2491 - 200 - 200 - 200 - 200 - 200 - 200 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 126, -(2880 - 2491 - 200 - 200 - 200 - 200 - 200 - 200 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 100, -(2880 - 2491-50 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 123, -(2880 - 2491 - 50 - 50 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 125, -(2880 - 2491 - 50 - 50 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 176, -(2880 - 2491+29 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 128, -(2880 - 2491 + 29 + 29 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 34, -(2880 - 2491 + 29 + 29 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 12, -(2880 - 2491 + 29 + 29 + 29 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 129, -(2880 - 2491 + 29 + 29 + 29 + 29 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 122, -(2880 - 2491 + 29 + 29 + 29 + 29 + 29 - SCREEN_HEIGHT));
		App->enemies->AddEnemy(ENEMY_TYPES::WHITEGUARD, 98, -(2880 - 2491 + 29 + 29 + 29 + 29 + 29 + 29 - SCREEN_HEIGHT));*/

		return true;
	
}

// UnLoad assets
bool ModuleLvl1::CleanUp()
{
	App->audio->Stop();
	App->player->Disable();
	App->collision->Disable();
	App->enemies->Disable();
	App->input->keyboard[App->input->kcounter] = KEY_UP;
	App->player->current_animation = &App->player->idle;
	//App->input->Disable();
	introlvl1 = false;
	App->helicopter->firstimelvl1 = false;
	LOG("Unloading lvl1 scene");

	App->textures->Unload(background);
	App->textures->Unload(graphics);

	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);
	App->textures->Unload(graphics4);
	App->textures->Unload(graphics5);
	App->textures->Unload(graphics6);

	App->textures->Disable();
	//App->audio->Stop();
	return true;
}

// Update: draw background
update_status ModuleLvl1::Update()
{
	//if (App->player->timeintro > 0 && introlvl1 == false && hfinished)
	//{
	//	introlvl1 = true;
	//	App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1, 2 Theme.ogg", true);
	//	//App->audio->Play("Resources/Audio/Themes_SoundTrack/Commando (NES) Music - New Life Intro.ogg", false);
	//}
	//if(App->player->timeintro == 3.8f)
	//	introlvl1 = false;

	if (App->player->timeintro > 3.8f && introlvl1==false && App->helicopter->firstimelvl1 == false)
	{
		introlvl1=true;
		App->audio->Stop();
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1, 2 Theme.ogg", true);
		App->input->Enable();

	}
	else if (App->player->timeintro > 0 && introlvl1 == false && App->helicopter->firstimelvl1 == true)
	{
		introlvl1 = true;
		App->audio->Stop();
		App->audio->Play("Resources/Audio/Themes_SoundTrack/Area 1, 2 Theme.ogg", true);
		App->input->Enable();
	}


	// Move camera forward -----------------------------
	int speed = 3;

	if (App->player->position.y == (135 - cont) && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->render->camera.y < ((2880 - SCREEN_HEIGHT)*SCREEN_SIZE) - speed) {
		cont++;
		App->render->camera.y += speed;
	}

	App->render->Blit(background, 0, -2880 + SCREEN_HEIGHT, NULL);


	App->render->Blit(graphics, 50, -(2880 - 1675 - SCREEN_HEIGHT), &(ally.GetCurrentFrame()), 1.0f); // ally animation
	App->render->Blit(graphics, 47, -(2880 - 765 - SCREEN_HEIGHT), &(ally2.GetCurrentFrame()), 1.0f); // ally2 animation
	App->render->Blit(graphics, 15, -(2880-765-SCREEN_HEIGHT), &(ally3.GetCurrentFrame()), 1.0f); // ally3 animation
	App->render->Blit(graphics3, 161, -(2880 - 2482 - SCREEN_HEIGHT), &(box.GetCurrentFrame()), 1.0f); // box animation
	App->render->Blit(graphics3, 32, -(2880 - 1958 - SCREEN_HEIGHT), &(box2.GetCurrentFrame()), 1.0f); // box2 animation
	App->render->Blit(graphics3, 25, -(2880 - 977 - SCREEN_HEIGHT), &(box3.GetCurrentFrame()), 1.0f); // box3 animation
	App->render->Blit(graphics3, 55, -(2880 - 718 - SCREEN_HEIGHT), &(box4.GetCurrentFrame()), 1.0f); // box4 animation
	App->render->Blit(graphics3, 2, -(2880 - 492 - SCREEN_HEIGHT), &(box5.GetCurrentFrame()), 1.0f); // box5 animation
	App->render->Blit(graphics3, 166, -(2880 - 258 - SCREEN_HEIGHT), &(box6.GetCurrentFrame()), 1.0f); // box6 animation


	if(App->player->sc[0]==0)
	App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y/3), &zero );// zero
	if (App->player->sc[1] == 0)
	App->render->Blit(graphics4, 16+9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero);// zero
	if (App->player->sc[2] == 0)
	App->render->Blit(graphics4, 16+18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero );// zero
	if (App->player->sc[3] == 0)
	App->render->Blit(graphics4, 16+27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero );// zero
	if (App->player->sc[4] == 0)
	App->render->Blit(graphics4, 16+36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero);// zero
	if (App->player->sc[5] == 0)
	App->render->Blit(graphics4, 16+45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero);// zero

	if (App->player->sc[0] == 1)
		App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[1] == 1)
		App->render->Blit(graphics4, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[2] == 1)
		App->render->Blit(graphics4, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[3] == 1)
		App->render->Blit(graphics4, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[4] == 1)
		App->render->Blit(graphics4, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one
	if (App->player->sc[5] == 1)
		App->render->Blit(graphics4, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one);// one

	if (App->player->sc[0] == 2)
		App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[1] == 2)
		App->render->Blit(graphics4, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[2] == 2)
		App->render->Blit(graphics4, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[3] == 2)
		App->render->Blit(graphics4, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[4] == 2)
		App->render->Blit(graphics4, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two
	if (App->player->sc[5] == 2)
		App->render->Blit(graphics4, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two);// two

	if (App->player->sc[0] == 3)
		App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[1] == 3)
		App->render->Blit(graphics4, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[2] == 3)
		App->render->Blit(graphics4, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[3] == 3)
		App->render->Blit(graphics4, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[4] == 3)
		App->render->Blit(graphics4, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three
	if (App->player->sc[5] == 3)
		App->render->Blit(graphics4, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three);// three

	if (App->player->sc[0] == 4)
		App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[1] == 4)
		App->render->Blit(graphics4, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[2] == 4)
		App->render->Blit(graphics4, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[3] == 4)
		App->render->Blit(graphics4, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[4] == 4)
		App->render->Blit(graphics4, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four
	if (App->player->sc[5] == 4)
		App->render->Blit(graphics4, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four);// four

	if (App->player->sc[0] == 5)
		App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[1] == 5)
		App->render->Blit(graphics4, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[2] == 5)
		App->render->Blit(graphics4, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[3] == 5)
		App->render->Blit(graphics4, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[4] == 5)
		App->render->Blit(graphics4, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five
	if (App->player->sc[5] == 5)
		App->render->Blit(graphics4, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &five);// five

	if (App->player->sc[0] == 6)
		App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[1] == 6)
		App->render->Blit(graphics4, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[2] == 6)
		App->render->Blit(graphics4, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[3] == 6)
		App->render->Blit(graphics4, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[4] == 6)
		App->render->Blit(graphics4, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five
	if (App->player->sc[5] == 6)
		App->render->Blit(graphics4, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &six);// five

	if (App->player->sc[0] == 7)
		App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[1] == 7)
		App->render->Blit(graphics4, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[2] == 7)
		App->render->Blit(graphics4, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[3] == 7)
		App->render->Blit(graphics4, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[4] == 7)
		App->render->Blit(graphics4, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five
	if (App->player->sc[5] == 7)
		App->render->Blit(graphics4, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &seven);// five

	if (App->player->sc[0] == 8)
		App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[1] == 8)
		App->render->Blit(graphics4, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[2] == 8)
		App->render->Blit(graphics4, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[3] == 8)
		App->render->Blit(graphics4, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[4] == 8)
		App->render->Blit(graphics4, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five
	if (App->player->sc[5] == 8)
		App->render->Blit(graphics4, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &eight);// five

	if (App->player->sc[0] == 9)
		App->render->Blit(graphics4, 16, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[1] == 9)
		App->render->Blit(graphics4, 16 + 9, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[2] == 9)
		App->render->Blit(graphics4, 16 + 18, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[3] == 9)
		App->render->Blit(graphics4, 16 + 27, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[4] == 9)
		App->render->Blit(graphics4, 16 + 36, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five
	if (App->player->sc[5] == 9)
		App->render->Blit(graphics4, 16 + 45, -(2880 - 2675 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &nine);// five

	App->render->Blit(graphics4, 119+13, -(2880 - 2860 - SCREEN_HEIGHT)+3 - (App->render->camera.y / 3), &zero); // zero
	App->render->Blit(graphics5, 119, -(2880 - 2860 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &handg); // handg
	App->render->Blit(graphics6, 16, -(2880 - 2860 - SCREEN_HEIGHT)-3 - (App->render->camera.y / 3), &life); // life

	if(App->player->contlives==4)
		App->render->Blit(graphics4, 16+13, -(2880 - 2860 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &four); // four
	else if (App->player->contlives == 3)
		App->render->Blit(graphics4, 16 + 13, -(2880 - 2860 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &three); // three
	else if (App->player->contlives == 2)
		App->render->Blit(graphics4, 16 + 13, -(2880 - 2860 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &two); // two
	else if (App->player->contlives == 1)
		App->render->Blit(graphics4, 16 + 13, -(2880 - 2860 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &one); // one
	else if (App->player->contlives == 0)
		App->render->Blit(graphics4, 16 + 13, -(2880 - 2860 - SCREEN_HEIGHT) - (App->render->camera.y / 3), &zero); // zero


	

	if (App->input->keyboard[SDL_SCANCODE_F2]) {

		App->fade->FadeToBlack(this, App->endlvl1, 0);

	}

	return UPDATE_CONTINUE;
}



