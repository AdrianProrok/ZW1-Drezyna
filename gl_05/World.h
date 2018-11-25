#pragma once

#include "Scene.h"
#include "Draisine.h"

class World : public Scene
{

public:
	Draisine draisine;
	void init();
};