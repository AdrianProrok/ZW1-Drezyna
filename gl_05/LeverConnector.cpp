#include "LeverConnector.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

LeverConnector::LeverConnector()
{
	this->angle = 30.0f;
}

LeverConnector::~LeverConnector()
{
}

void LeverConnector::generate()
{
	mesh = new RightRegularPrism(0.4f, 0.3f, 64, glm::vec3(0.2f, 0.5f, 0.7f));

	addChild(&lever);
	lever.generate();
	lever.position = glm::vec3(0.0f, 0.2f, -0.15f);

	mesh->init();
}

void LeverConnector::update(float delta_time, glm::mat4 trans)
{
	this->rotation.x = 90.0f;
	Node::update(delta_time, trans);
}