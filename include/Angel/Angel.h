#pragma once

#ifdef _WIN32
# define DLL_EXPORT_TYP __declspec(dllexport)
#else
# define DLL_EXPORT_TYP
#endif


// TODO: make this an actual interface rather than some includes...
#include "../src/Engine.h"
#include "../src/Log.h"
#include "../src/Window.h"
#include "../src/Render.h"
#include "../src/Input.h"
#include "../src/AssetManager.h"
#include "../src/Draw.h"
#include "../src/Camera.h"
#include "../src/Collider.h"
#include "../src/Tilemap.h"
#include "../src/Font.h"
#include "../src/Text.h"
#include "../src/RenderWrapper.h"
#include "../src/Background.h"
#include "../src/ResourceLoading.h"
#include "../src/Audio.h"