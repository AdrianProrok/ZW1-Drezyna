#pragma once

#include "Node.h"
#include "Cylinder.h"

class Rail : public engine::Node
{
public:
	Rail();
	~Rail();

	void generate(float length);
	virtual void update(float delta_time, glm::mat4 trans);
};

