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
	mesh = new RightRegularPrism(1.0f, 500.0f, 4, glm::vec3(0.761f, 0.698f, 0.502f), glm::vec3(1.0f, 1.0f, 0.2f));

	addChild(&draisine);
	draisine.generate();
	draisine.position = glm::vec3(0.0f, 1.5f + 1.0f, 0.0f);
	
	for (int i = 0; i < 100; ++i)
	{
		addChild(&planks[i]);
		planks[i].generate();
		planks[i].position = glm::vec3(200.0f - (float)4*i, 1.0f, 0.0f);
	}

	for (int i = 0; i < 2; ++i)
	{
		addChild(&rails[i]);
		rails[i].generate();
		rails[i].position = glm::vec3(0.0f, 0.14f + 1.0f, 4.0f - 8.0f*i);
	}

	mesh->init();

	this->position.y -= 2.0;
}

void Desert::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}