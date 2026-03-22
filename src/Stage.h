#pragma once

#include "Entity.h"

#include <vector>

typedef Background;

class Stage {
public:
	Stage();
	~Stage();

	void Step();
	void Draw();
private:
	Background	backgroundLayers[16];
	Tilemap		basetiles;
	collidermap collider;

	std::vector<Entity*> actors;
	
};