#pragma once
#include "Node.h"
#include "RightRegularPrism.h"

class Vane : public engine::Node
{
public:
	Vane();
	~Vane();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};
