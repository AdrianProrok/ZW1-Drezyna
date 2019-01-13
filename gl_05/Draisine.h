#pragma once

#include "Node.h"
#include "RightRegularPrism.h"
#include "Wheel.h"
#include "Bar.h"
#include "LeverBase.h"
#include "Fence.h"
#include "FenceCover.h"
#include "LongConnector.h"
#include "ShortConnector.h"
#include "WindmillBase.h"

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
	Fence fences[4];
	FenceCover covers[4];
	LongConnector longC[2];
	ShortConnector shortC[2];
	WindmillBase millBase;
};