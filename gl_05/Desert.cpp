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
	mesh = new RightRegularPrism(0.0f, 1000.0f, 4, glm::vec3(0.761f, 0.698f, 0.502f));

	addChild(&draisine);
	draisine.generate();
	draisine.position = glm::vec3(0.0f, 2.0f, 15.0f);
	

	for (int i = 0; i < 500; ++i)
	{
		addChild(&planks[i]);
		planks[i].generate();
		planks[i].position = glm::vec3(500.0f - (float)2*i, 0.0f, 15.0f);
	}


	mesh->init();

	this->position.y -= 2;
}

void Desert::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}