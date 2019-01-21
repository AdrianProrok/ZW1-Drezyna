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
	setMesh(new Cylinder(5.0f, 1.0f, 4, glm::vec3(0.0f, 0.5f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 10.0f), 0.5f));

	addChild(&leverCon);
	leverCon.generate();
	leverCon.position = glm::vec3(0.0f, 5.15f, -0.2f);
	mesh->loadTexture("leverBaseTopTexture.jpg");
	mesh->init();
}

void LeverBase::update(float delta_time, glm::mat4 trans)
{
	leverCon.rotation.y += leverCon.angle*delta_time;
	if (leverCon.rotation.y >= 30.0f)
		leverCon.angle = -30.0f;
	else if(leverCon.rotation.y <= -30.0f)
		leverCon.angle = 30.0f;
		
	Node::update(delta_time, trans);
}