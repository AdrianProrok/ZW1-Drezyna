#pragma once

#include "Node.h"
#include "RightRegularPrism.h"
#include "Wheel.h"
#include "Bar.h"
#include "LeverBase.h"

class Draisine : public engine::Node
{
public:
	Draisine();
	~Draisine();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
private:
	Wheel wheels[4];
	Bar bars[2];
	LeverBase base;
	//Fence fences[20];
};