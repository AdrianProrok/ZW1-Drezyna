#pragma once
#include "Node.h"
#include "Cylinder.h"

class FenceCover : public engine::Node
{
public:
	FenceCover();
	~FenceCover();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};
