#include "Screw.h"
#include "Mesh.h"

using namespace engine;

Screw::Screw()
{
}


Screw::~Screw()
{
}

void Screw::generate()
{
	mesh = new RightRegularPrism(0.175f, 0.1f, 8, glm::vec3(0.0f, 1.0f, 0.0f));
	mesh->init();
}

void Screw::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}