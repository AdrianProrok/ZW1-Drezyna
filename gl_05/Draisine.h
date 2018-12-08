#pragma once

#include "Node.h"
#include "Cube.h"
#include "RightRegularPrism.h"

class Draisine : public engine::Node
{
public:
	Draisine();
	~Draisine();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
private:
	engine::Node test;
	engine::Node test2;
};