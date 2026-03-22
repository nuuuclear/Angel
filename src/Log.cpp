#include "log.h"

#include <SDL3/SDL.h>

void Angel_PrintError(const char* title, const char* error) {
	std::string errmsg = std::string(title) + error;
	SDL_Log(errmsg.c_str());
}