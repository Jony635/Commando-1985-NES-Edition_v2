#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"

#include<string.h>

// Constructor
ModuleFonts::ModuleFonts() : Module()
{}

// Destructor
ModuleFonts::~ModuleFonts()
{}

// Load new texture from file path
int ModuleFonts::Load(const char* texture_path, const char* characters, uint rows)
{
	int id = -1;

	if(texture_path == nullptr || characters == nullptr || rows == 0)
	{
		LOG("Could not load font");
		return id;
	}

	SDL_Texture* tex = App->textures->Load(texture_path);

	if(tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
	{
		LOG("Could not load font at %s with characters '%s'", texture_path, characters);
		return id;
	}

	id = 0;
	for(; id < MAX_FONTS; ++id)
		if(fonts[id].graphic == nullptr)
			break;

	if(id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", texture_path, MAX_FONTS);
		return id;
	}

	App->textures->GetSize(tex, fonts[id].wtex, fonts[id].htex);

	fonts[id].graphic = tex; // graphic: pointer to the texture
	fonts[id].rows = rows; // rows: rows of characters in the texture
	fonts[id].len = strlen(characters); // len: length of the table

	// TODO 1: Finish storing font data

	for (int i = 0; characters[i] != '\0'; i++)
	{
		fonts[id].table[i] = characters[i];
		if (characters[i + 1] == '\0') {
			fonts[id].table[i + 1] = '\0';
		}
	}
	fonts[id].row_chars = fonts[id].len / rows;// row_chars: amount of chars per row of the texture
	fonts[id].char_w = fonts[id].wtex / fonts[id].row_chars;// char_w: width of each character
	fonts[id].char_h = fonts[id].htex / rows;// char_h: height of each character
	
	LOG("Successfully loaded BMP font from %s", texture_path);

	return id;
}

void ModuleFonts::UnLoad(int font_id)
{
	if(font_id >= 0 && font_id < MAX_FONTS && fonts[font_id].graphic != nullptr)
	{
		App->textures->Unload(fonts[font_id].graphic);
		fonts[font_id].graphic = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}

// Render text using a bitmap font
void ModuleFonts::BlitText(int x, int y, int font_id, const char* text) const
{
	if(text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].graphic == nullptr)
	{
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	const Font* font = &fonts[font_id];
	SDL_Rect rect;
	uint len = strlen(text);
	rect.x = 0;
	rect.y = 0;
	rect.w = font->char_w;
	rect.h = font->char_h;
	SDL_Rect* rectp = &rect;
	for(uint i = 0; i < len; ++i)
	{
		rect.x = 0;
		rect.y = 0;
		for (uint j = 0; j < font->len; j++)
		{
			if (j%font->row_chars == 0 && j != 0) {
				rect.x = 0;
				rect.y += font->char_h;
			}
			if (text[i] == font->table[j]) {
				App->render->Blit(font->graphic, x, y, rectp, 1, false);
				x += font->char_w;
				break;
			}
			rect.x += font->char_w;

		}
	}
}
