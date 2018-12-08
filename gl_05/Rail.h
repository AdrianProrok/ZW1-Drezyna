#pragma once

#include "Node.h"
#include "RightRegularPrism.h"

class Rail : public engine::Node
{
public:
	Rail();
	~Rail();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};

