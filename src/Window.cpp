#include "Window.h"

#include "Log.h"

SDL_Window* window;

static SDL_Surface* window_surface;
static SDL_Surface* framebuffer;

bool Angel_CreateWindow(const char *window_title, size_t screen_width, size_t screen_height, SDL_WindowFlags windowFlags) {
	window = SDL_CreateWindow(window_title, screen_width, screen_height, windowFlags);

	if (window != NULL) {
		SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

		window_surface = SDL_GetWindowSurface(window);

		if (window_surface != NULL) {
			framebuffer = SDL_ConvertSurface(window_surface, SDL_PIXELFORMAT_RGB24);

			if (framebuffer != NULL) {
				SDL_LockSurface(framebuffer);

				return true;
			} else {
				Angel_PrintError("Couldn't make framebuffer surface: ", SDL_GetError());
				SDL_DestroyWindow(window);
			}
		} else {
			Angel_PrintError("Couldn't make window surface: ", SDL_GetError());
		}
	} else {
		Angel_PrintError("Couldn't make window: ", SDL_GetError());
	}

	return false;
}

void Angel_DestroyWindow() {
	SDL_DestroySurface(framebuffer);
	SDL_DestroyWindow(window);
}

unsigned char* Angel_GetFrameBuffer(int *pitch) {
	*pitch = framebuffer->pitch;

	return (unsigned char*)framebuffer->pixels;
}

void Angel_Display() {
	SDL_UnlockSurface(framebuffer);
	if (SDL_BlitSurface(framebuffer, NULL, window_surface, NULL) < 0)
		Angel_PrintError("Couldn't blit framebuffer to window: ", SDL_GetError());

	SDL_LockSurface(framebuffer);

	if (SDL_UpdateWindowSurface(window) < 0)
		Angel_PrintError("Couldn't copy window surface to screen: ", SDL_GetError());
}

void Angel_HandleWindowResize(size_t width, size_t height) {
	window_surface = SDL_GetWindowSurface(window);

	if (window_surface == NULL)
		Angel_PrintError("Couldn't get the window's surface: ", SDL_GetError());
}

// getters
SDL_Window* Angel_GetWindow() {
	return window;
}