#include "Draw.h"

void Angel_DrawClear() {
	SDL_RenderClear(Angel_GetRenderer());
}

void Angel_DrawPresent() {
	SDL_RenderPresent(Angel_GetRenderer());
}