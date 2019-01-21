#include "FenceCover.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

FenceCover::FenceCover()
{
}

FenceCover::~FenceCover()
{
}

void FenceCover::generate()
{
	setMesh(new Cylinder(0.6f, 0.6f, 64, glm::vec3(1.0f, 0.5f, 0.0f), glm::vec3(0.45f, 1.0f, 0.45f), glm::vec2(1.0f,1.0f), glm::vec2(1.0f, 1.0f),  0.1f));
	mesh->loadTexture("fenceTexture.jpg");
	mesh->init();
}

void FenceCover::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}