#pragma once
#include "Node.h"
#include "RightRegularPrism.h"
#include "LeverTop.h"

class LeverConnector : public engine::Node
{
public:
	LeverConnector();
	~LeverConnector();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);

	LeverTop lever;
};
