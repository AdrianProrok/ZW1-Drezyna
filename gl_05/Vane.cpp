#include "Vane.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

Vane::Vane()
{
}

Vane::~Vane()
{
}

void Vane::generate()
{
	setMesh(new Cylinder(0.1f, 1.0f, 3, glm::vec3(0.5f, 0.2f, 0.5f), glm::vec3(1.175f, 1.0f, 0.3f)));
	mesh->loadTexture("vaneTexture.jpg");
	mesh->init();
}

void Vane::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}