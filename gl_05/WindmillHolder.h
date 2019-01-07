#pragma once
#include "Node.h"
#include "RightRegularPrism.h"
//#include "WindmillVane.h"

class WindmillHolder : public engine::Node
{
public:
	WindmillHolder();
	~WindmillHolder();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);

	//WindmillVane vanes[5];
};
