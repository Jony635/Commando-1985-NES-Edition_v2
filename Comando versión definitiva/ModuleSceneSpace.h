#pragma once
#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct Collider;

class ModuleSceneSpace : public Module
{
public:
	ModuleSceneSpace(Application* app, bool start_enabled = true);
	~ModuleSceneSpace();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* background;
	SDL_Texture* stars;
};