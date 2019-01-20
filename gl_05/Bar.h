#pragma once

#include "Node.h"
#include "Support.h"
#include "Cylinder.h"

class Bar : public engine::Node
{
public:
	Bar();
	~Bar();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);

private:
	Support supports[2];
};

