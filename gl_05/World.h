#pragma once

#include "Scene.h"
#include "Draisine.h"

class World : public engine::Scene
{

public:
	World();
	~World();
	Draisine draisine;
	void init(float aspect_ratio);
	void render();
	virtual void update(float delta_time, const Input& input);

};