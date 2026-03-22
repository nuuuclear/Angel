#include "Draw.h"

static SDL_Surface* framebuffer;
// static SDL_Surface* surf[SURFACE_MAX_ID];

//static font *drawFont

bool Angel_StartRenderer(const char *title, int width, int height, SDL_WindowFlags windowFlags) {
	framebuffer = Angel_RendererInit(title, width, height, windowFlags);

	if (framebuffer == NULL) return false;

	return true;
}

void Angel_EndRenderer() {
	framebuffer = NULL;
	Angel_RendererFinish();

	// memset(surface_meta, 0, sizeof(surface_meta));
}