#include "Fence.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

Fence::Fence()
{
}

Fence::~Fence()
{
}

void Fence::generate()
{
	setMesh(new Cylinder(2.0f, 0.5f , 64, glm::vec3(1.0f, 0.5f, 0.0f), glm::vec3(0.45f, 1.0f, 0.45f)));
	//mesh->loadTexture("fenceTexture.jpg");
	mesh->init();
}

void Fence::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}