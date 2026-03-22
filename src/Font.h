#pragma once

#include <SDL3_ttf/SDL_ttf.h>

class Font {
public:
	void Load_FromTTF(TTF_Font* fontdata);
	void Load_FromMemory(const char data);

	void Destroy();

	void SetSize(float s);

	TTF_Font* Get();
private:
	TTF_Font* font = nullptr;
};
