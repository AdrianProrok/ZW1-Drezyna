#pragma once
#include "Node.h"
#include "RightRegularPrism.h"

class ShortConnector : public engine::Node
{
public:
	ShortConnector();
	~ShortConnector();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};
