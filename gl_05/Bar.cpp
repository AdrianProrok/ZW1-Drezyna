#include "Bar.h"
#include "Mesh.h"

using namespace engine;

Bar::Bar()
{
}


Bar::~Bar()
{
}

void Bar::generate()
{
	mesh = new Cylinder(0.15f, 1.0f, 4, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(6.675f, 1.0f, 0.325f));

	for (Support& support: supports)
	{
		addChild(&support);
		support.generate();
	}

	supports[0].position = glm::vec3(4.5f, 0.15f, 0.0f);
	supports[1].position = glm::vec3(-4.5f, 0.15f, 0.0f);


	mesh->init();
}

void Bar::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}