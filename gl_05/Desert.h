#pragma once

#include "Node.h"
#include "Draisine.h"
#include "Plank.h"
#include "Rail.h"
#include "Light.h"

class Desert : public engine::Node
{
public:
	Desert();
	~Desert();
	
	void generate();
	virtual void update(float delta_time, glm::mat4 trans);

private:
	Draisine draisine;
    Plank planks[177];
	Rail rails[2];

	engine::Light lights[4];
};

