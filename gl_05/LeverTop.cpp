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
	setMesh(new Cylinder(0.2f, 0.5f, 4, glm::vec3(0.8f, 0.2f, 1.0f), glm::vec3(9.0f, 1.0f, 1.0f), glm::vec2(2.5f, 2.0f), glm::vec2(1.0f, 1.0f), 0.5f));
	
	(*this).rotation.x = -90.0f;

	for (LeverHandle& h : handles)
	{
		addChild(&h);
		h.generate();
	}
	handles[0].position = glm::vec3( 3.3f, 0.0f, 0.0f);
	handles[1].position = glm::vec3(-3.3f, 0.0f, 0.0f);
	mesh->loadTexture("leverBaseTopTexture.jpg");
	mesh->init();
}

void LeverTop::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}