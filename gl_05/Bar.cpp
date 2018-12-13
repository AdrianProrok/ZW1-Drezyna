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
	mesh = new RightRegularPrism(0.15f, 1.0f, 4, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(6.375f, 1.0f, 0.325f));
	mesh->init();
}

void Bar::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}