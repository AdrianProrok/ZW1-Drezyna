#include "LeverTop.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

LeverTop::LeverTop()
{
}

LeverTop::~LeverTop()
{
}

void LeverTop::generate()
{
	mesh = new RightRegularPrism(0.2f, 0.5f, 4, glm::vec3(0.0f, 0.5f, 1.0f), glm::vec3(9.0f, 1.0f, 1.0f), 0.5f);

	for (LeverHandle& h : handles)
	{
		addChild(&h);
		h.generate();
	}
	handles[0].position = glm::vec3( 3.3f, 0.0f, 0.0f);
	handles[1].position = glm::vec3(-3.3f, 0.0f, 0.0f);
	mesh->init();
}

void LeverTop::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}