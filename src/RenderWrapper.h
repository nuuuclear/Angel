#pragma once

#include "Engine.h"

#include <SDL3/SDL.h>

bool Angel_StartRenderer(const char* title, int width, int height, SDL_WindowFlags windowFlags);
void Angel_EndRenderer();