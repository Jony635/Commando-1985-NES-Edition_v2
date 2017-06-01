#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 15

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleEnemies;
class ModuleFonts;
class Module;
class ModuleWelcome;
class ModuleLvl2;
class ModuleAudio;
class ModulePowerUp;
class ModuleSecretAreas;

enum StartTypes {
	lvl2,
	room1,
	room2,
	room4,
	room5,
	MAX_TYPES
};

enum pu_taken_lvl2 {
	granade1,
	binocular,
	godmode,
	granade2,
	granade3,
	granade4,
	ally1,
	ally2,
	MAXIM_TYPES
};

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleWelcome* welcome;
	ModuleLvl2* lvl2;
	ModuleSecretAreas* secretareas;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleFonts* fonts;
	ModuleAudio* audio;
	ModulePowerUp* powerup;
	bool stop_music;
	bool start_types_arr[StartTypes::MAX_TYPES] = { false,false, false, false, false };
	bool powerups_taken[pu_taken_lvl2::MAXIM_TYPES] = { false,false, false, false, false, false, false };

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__