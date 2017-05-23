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