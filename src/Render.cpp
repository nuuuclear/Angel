#include <SDL3/SDL.h>

#include "Window.h"
#include "Log.h"

SDL_Renderer* renderer;
SDL_Surface framebuffer;

SDL_Surface* Angel_RendererInit(const char* window_title, size_t width, size_t height, SDL_WindowFlags windowFlags) {
	if (Angel_CreateWindow(window_title, width, height, windowFlags)) {

		framebuffer.pixels = Angel_GetFrameBuffer(&framebuffer.pitch);

		//framebuffer.width  = width;
		//framebuffer.height = height;

		SDL_DestroyWindowSurface(Angel_GetWindow()); // destroy the mysteriously already existing surface

		renderer = SDL_CreateGPURenderer(NULL, Angel_GetWindow());
	
		if (renderer == NULL) {
			Angel_PrintError("Failed to create renderer", SDL_GetError());
		}

		return &framebuffer;
	} else {
		Angel_PrintError("Failed to create window", "");
	}
	
	return NULL;
}

void Angel_RendererSetFixedSize(int w, int h) {
	SDL_SetRenderLogicalPresentation(renderer, h, w, SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);
}

void Angel_RendererFinish() {
	Angel_DestroyWindow();

	SDL_DestroyRenderer(renderer);
}

void Angel_RendererDraw() {
	Angel_Display();

	framebuffer.pixels = Angel_GetFrameBuffer(&framebuffer.pitch);
}

SDL_Renderer* Angel_GetRenderer() {
	return renderer;
}

