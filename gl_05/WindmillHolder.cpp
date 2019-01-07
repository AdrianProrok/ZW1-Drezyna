#include "WindmillHolder.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

WindmillHolder::WindmillHolder()
{
}

WindmillHolder::~WindmillHolder()
{
}

void WindmillHolder::generate()
{
	mesh = new RightRegularPrism(0.9f, 0.2f, 64, glm::vec3(0.325f, 0.9f, 0.63f));

	/*for (WindmillVane& v : vanes)
	{
		addChild(&v);
		v.generate();
	}

	vanes[0].position = glm::vec3(6.8f, 1.0f, 3.3f);
	vanes[1].position = glm::vec3(-6.8f, 1.0f, -3.3f);
	vanes[2].position = glm::vec3(6.8f, 1.0f, -3.3f);
	vanes[3].position = glm::vec3(-6.8f, 1.0f, 3.3f);*/

	mesh->init();
}

void WindmillHolder::update(float delta_time, glm::mat4 trans)
{
	this->rotation.z = 90.0f;
	Node::update(delta_time, trans);
}