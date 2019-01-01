#pragma once
#include "Node.h"
#include "RightRegularPrism.h"

class Fence : public engine::Node
{
public:
	Fence();
	~Fence();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};