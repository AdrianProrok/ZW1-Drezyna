#pragma once
#include "Node.h"
#include "Cylinder.h"

class Support : public engine::Node
{
public:
	Support();
	~Support();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
};

