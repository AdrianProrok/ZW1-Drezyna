#pragma once
#include "Node.h"
#include "Cylinder.h"
#include "WindmillHolder.h"

class WindmillBase : public engine::Node
{
public:
	WindmillBase();
	~WindmillBase();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);

	WindmillHolder holder;
};

