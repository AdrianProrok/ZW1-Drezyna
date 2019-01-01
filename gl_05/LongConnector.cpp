#include "LongConnector.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

LongConnector::LongConnector()
{
}

LongConnector::~LongConnector()
{
}

void LongConnector::generate()
{
	mesh = new RightRegularPrism(13.6f, 0.5f, 64, glm::vec3(1.0f, 0.5f, 0.0f), glm::vec3(0.45f, 1.0f, 0.45f));
	mesh->init();
}

void LongConnector::update(float delta_time, glm::mat4 trans)
{
	(*this).rotation.z = -90.0f;
	Node::update(delta_time, trans);
}