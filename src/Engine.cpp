#include "Engine.h"

#include <SDL3/SDL.h>

#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_ttf/SDL_textengine.h>

#include "Log.h"

static unsigned char* cursor_surface_pixels;
static SDL_Surface*   cursor_surface;
static SDL_Cursor*    cursor;

bool Angel_Init() {
	if (SDL_Init(SDL_INIT_EVENTS) == false) {
		Angel_PrintError("Could not intialize SDL: ", SDL_GetError());

		SDL_Quit();
		return false;
	}

	if (SDL_InitSubSystem(SDL_INIT_VIDEO) == false) {
		Angel_PrintError("Could not intialize SDL video subsystem: ", SDL_GetError());

		SDL_Quit();
		return false;
	}

	if (TTF_Init() == false) {
		Angel_PrintError("Could not intialize TTF: ", SDL_GetError());

		TTF_Quit();
		SDL_Quit();
		return false;
	}

	return true;
}

void Angel_Finish() {
	TTF_Quit();
	SDL_Quit();
}

unsigned long Angel_GetTicks() {
	return SDL_GetTicks();
}

unsigned long Angel_CountFPS() {
	unsigned long now;
	static bool first = true;
	static unsigned long max_count;
	static unsigned long count;
	static unsigned long wait;

	if (first) {
		wait = Angel_GetTicks();
		first = false;
	}

	now = Angel_GetTicks();
	count++;

	if (wait + 1000 <= now) {
		wait += 1000;
		max_count = count;
		count = 0;
	}

	return max_count;
}

void Angel_Delay(uint32_t ticks) {
	SDL_Delay(ticks);
}