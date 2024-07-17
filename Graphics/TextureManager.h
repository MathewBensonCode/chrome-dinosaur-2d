#pragma once

#include <SDL_pixels.h>  // for SDL_Color
#include <SDL_rect.h>    // for SDL_Rect
#include <SDL_render.h>  // for SDL_Texture
#include <stddef.h>      // for size_t
#include <string>

#include "SDL_ttf.h"

class TextureManager {
public:
	static void drawText(SDL_Texture* texture, int x, int y, size_t w, size_t h);
	static SDL_Texture* loadTextTexture(std::string textureText, TTF_Font* font, SDL_Color textColor);
	
	static SDL_Texture* loadSpriteTexture(const char* pathToTexture);
	static void drawSprite(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};
