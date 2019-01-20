#pragma once
#include "Node.h"
#include "Cylinder.h"
#include "Light.h"

class LeverHandle : public engine::Node
{
public:
	LeverHandle();
	~LeverHandle();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};
