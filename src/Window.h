#pragma once

#include <string>
#include <SDL3/SDL.h>

bool Angel_CreateWindow(const char* window_title, size_t screen_width, size_t screen_height, SDL_WindowFlags windowFlags);
void Angel_DestroyWindow();
unsigned char* Angel_GetFrameBuffer(int *pitch);
void Angel_Display();
void Angel_HandleWindowResize(size_t width, size_t height);
SDL_Window* Angel_GetWindow();