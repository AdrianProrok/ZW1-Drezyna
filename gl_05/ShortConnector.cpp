#include "ShortConnector.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

ShortConnector::ShortConnector()
{
}

ShortConnector::~ShortConnector()
{
}

void ShortConnector::generate()
{
	mesh = new RightRegularPrism(6.6f, 0.5f, 64, glm::vec3(1.0f, 0.5f, 0.0f), glm::vec3(0.45f, 1.0f, 0.45f));
	mesh->init();
}

void ShortConnector::update(float delta_time, glm::mat4 trans)
{
	this->rotation.x = 90.0f;
	Node::update(delta_time, trans);
}