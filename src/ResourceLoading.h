#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <string>

#include "Log.h"
#include "AssetManager.h"

#include "Sprite.h"
#include "Font.h"

bool Angel_MakeSprite(
	SDL_Renderer* renderer, AssetManager& assets, 
	std::string path, std::string handle, 
	int width, int height
);

bool Angel_MakeFont(
	AssetManager& assets, 
	std::string path, std::string key, 
	float ptsize
);