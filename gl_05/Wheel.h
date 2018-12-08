#pragma once

#include "Node.h"
#include "RightRegularPrism.h"
#include "WheelSide.h"

class Wheel : public engine::Node
{
public:
	Wheel();
	~Wheel();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);

private:
	WheelSide sides[2];
};

