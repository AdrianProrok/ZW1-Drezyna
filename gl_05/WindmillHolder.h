#pragma once
#include "Node.h"
#include "Cylinder.h"
#include "Vane.h"

class WindmillHolder : public engine::Node
{
public:
	WindmillHolder();
	~WindmillHolder();

	void generate();
	void generateVanes(int);
	virtual void update(float delta_time, glm::mat4 trans);

	std::vector<Vane> vanes;
};
