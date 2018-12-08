#pragma once

#include "Scene.h"
#include "Desert.h"

class World : public engine::Scene
{

public:
	World();
	~World();
	void init(float aspect_ratio);
	void render();
	virtual void update(float delta_time, const Input& input);
private:
	Desert desert;

};