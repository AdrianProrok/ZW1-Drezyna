#include "Desert.h"
#include "RightRegularPrism.h"
#include "Mesh.h"

using namespace engine;

Desert::Desert()
{
}


Desert::~Desert()
{
}

void Desert::generate()
{
	mesh = new RightRegularPrism(0.0f, 100.0f, 4, glm::vec3(0.761f, 0.698f, 0.502f), glm::vec3(10.0f, 0.0f, 10.0f));
	mesh->init();

	draisine.generate();
	draisine.position = glm::vec3(0.0f, 2.0f, 15.0f);

	addChild(&draisine);

	this->position.y -= 2;
}

void Desert::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}