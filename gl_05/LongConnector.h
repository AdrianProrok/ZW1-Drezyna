#pragma once
#include "Node.h"
#include "Cylinder.h"

class LongConnector : public engine::Node
{
public:
	LongConnector();
	~LongConnector();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};
