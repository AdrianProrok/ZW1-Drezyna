#pragma once
#include "Node.h"
#include "Cylinder.h"

class Screw : public engine::Node
{
public:
	Screw();
	~Screw();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};

