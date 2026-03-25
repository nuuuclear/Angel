#pragma once

#include "Sound.h"

#include <SDL3/SDL.h>
#include <miniaudio.h>

bool Angel_AudioInit();
bool Angel_AudioStart();
void Angel_AudioEnd();

// audio objects
ANG_Sound* Angel_MakeSound();
void Angel_DestroySound();

void Angel_PutSound(const char* path);

void Angel_PlaySound();
void Angel_StopSound();
void Angel_ResetSound();

void Angel_SoundSetFreq();
void Angel_SoundSetVol();
void Angel_SoundSetPan();
void Angel_SoundSetAutomation();

void Angel_SoundSetCallback();