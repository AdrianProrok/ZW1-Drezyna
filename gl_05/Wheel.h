#pragma once

#include "Node.h"
#include "Cylinder.h"
#include "WheelSide.h"
#include "Screw.h"

class Wheel : public engine::Node
{
public:
	Wheel();
	~Wheel();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);

private:

	void generateScrews(int);
	WheelSide sides[2];
	std::vector<Screw> screws;
};

