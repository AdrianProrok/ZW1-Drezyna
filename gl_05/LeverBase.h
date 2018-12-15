#pragma once
#include "Node.h"
#include "RightRegularPrism.h"

class LeverBase : public engine::Node
{
public:
	LeverBase();
	~LeverBase();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};