#include "LeverBase.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

LeverBase::LeverBase()
{
}

LeverBase::~LeverBase()
{
}

void LeverBase::generate()
{
	mesh = new RightRegularPrism(5.0f, 1.0f, 4, glm::vec3(0.0f, 0.5f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.5f);

	addChild(&lever);
	lever.generate();
	lever.position = glm::vec3(0.0f, 5.0f, 0.0f);

	mesh->init();
}

void LeverBase::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}