#pragma once

#include <string>

bool Angel_Init(void);
void Angel_Finish();
unsigned long Angel_GetTicks();
unsigned long Angel_CountFPS();
void Angel_Delay(uint32_t ticks);