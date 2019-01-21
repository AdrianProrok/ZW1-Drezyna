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
	setMesh(new Cylinder(6.6f, 0.5f, 64, glm::vec3(1.0f, 0.5f, 0.0f), glm::vec3(0.45f, 1.0f, 0.45f), glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 10.0f)));
	mesh->loadTexture("fenceTexture.jpg");
	mesh->init();
	this->rotation.x = 90.0f;
}

void ShortConnector::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}