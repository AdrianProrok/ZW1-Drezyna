#include "Plank.h"
#include "Mesh.h"

using namespace engine;

Plank::Plank()
{
}


Plank::~Plank()
{
}

void Plank::generate()
{
	mesh = new Cylinder(0.125f, 0.5f, 4, glm::vec3(0.651f, 0.502f, 0.392f), glm::vec3(2.0f, 1.0f, 14.0f));
	mesh->init();
}

void Plank::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}