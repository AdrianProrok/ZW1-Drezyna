#pragma once
#include "Node.h"
#include "LeverHandle.h"
#include "RightRegularPrism.h"

class LeverTop : public engine::Node
{
public:
	LeverTop();
	~LeverTop();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);

	LeverHandle handles[2];
};
