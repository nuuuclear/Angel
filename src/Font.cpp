#include "Font.h"
#include "Log.h"

void Font::Load_FromTTF(TTF_Font* fontdata) {
	font = fontdata;

	if (font == NULL) {
		Angel_PrintError("Failed to open font: ", SDL_GetError());
	}
}

void Font::Load_FromMemory(const char data) {

}

void Font::Destroy() {
	TTF_CloseFont(font);
}

TTF_Font* Font::Get() {
	return font;
}

void Font::SetSize(float s) {
	TTF_SetFontSize(font, s);
}
