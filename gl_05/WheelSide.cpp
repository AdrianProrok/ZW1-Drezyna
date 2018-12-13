#include "WheelSide.h"
#include "Mesh.h"

using namespace engine;

WheelSide::WheelSide()
{
}


WheelSide::~WheelSide()
{
}


void WheelSide::generate()
{
	mesh = new RightRegularPrism(0.112f, 1.475f, 64, glm::vec3(0.98f, 0.52f, 0.35f));
	mesh->init();
}

void WheelSide::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}