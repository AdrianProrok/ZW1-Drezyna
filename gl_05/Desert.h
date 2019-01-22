#pragma once

#include "Node.h"
#include "Draisine.h"
#include "Plank.h"
#include "Rail.h"
#include "Light.h"
#include "Lamp.h"

class Desert : public engine::Node
{
public:
	Desert();
	~Desert();
	
	void generate();
	virtual void update(float delta_time, glm::mat4 trans);

private:
	Draisine draisine;
    
	std::vector<Plank> planks;

	std::vector<Lamp> lamps;

	Rail rails[2];

	engine::Light light;

	void setSun(glm::vec3 color, float intens, glm::vec3 position);
	void generateRailroadTrack(float length, float space);
	void generateLamps(unsigned int count, float spacing);
};

