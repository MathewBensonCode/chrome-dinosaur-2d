#pragma once

#include "Game.h"

class TextureManager {
public:
	static void setColor(SDL_Texture* texture, Uint8 red, Uint8 green, Uint8 blue);
	static void drawText(SDL_Texture* texture, int x, int y, int w, int h);
	static SDL_Texture* loadTextTexture(std::string textureText, TTF_Font* font, SDL_Color textColor);
	static void getTextureWidthHeight(SDL_Texture* texture, int* width, int* height);
	
	static SDL_Texture* loadSpriteTexture(const char* pathToTexture);
	static void drawSprite(const char* pathToTexture, SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};