#pragma once
#include "Node.h"
#include "Cylinder.h"

class Plank : public engine::Node
{
public:
	Plank();
	~Plank();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};

