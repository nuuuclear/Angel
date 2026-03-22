#pragma once

SDL_Surface* Angel_RendererInit(const char* window_title, size_t width, size_t height, SDL_WindowFlags windowFlags);
void Angel_RendererSetFixedSize(int w, int h);
void Angel_RendererFinish();
void Angel_RendererDraw();
SDL_Renderer* Angel_GetRenderer();