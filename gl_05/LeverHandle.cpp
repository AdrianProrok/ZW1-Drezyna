#include "LeverHandle.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

LeverHandle::LeverHandle()
{
}

LeverHandle::~LeverHandle()
{
}

void LeverHandle::generate()
{
	mesh = new RightRegularPrism(0.2f, 1.0f, 4, glm::vec3(0.0f, 0.5f, 1.0f), glm::vec3(0.25f, 1.5f, 1.7f), 1.0f);
	mesh->init();
}

void LeverHandle::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}