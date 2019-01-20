#pragma once
#include "Node.h"
#include "Cylinder.h"

class WheelSide : public engine::Node
{
public:
	WheelSide();
	~WheelSide();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};

