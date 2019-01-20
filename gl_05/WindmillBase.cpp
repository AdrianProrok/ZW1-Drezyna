#include "WindmillBase.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

WindmillBase::WindmillBase()
{
}

WindmillBase::~WindmillBase()
{
}

void WindmillBase::generate()
{
	mesh = new Cylinder(4.0f, 1.0f, 4, glm::vec3(0.7f, 0.2f, 0.345f), glm::vec3(0.52f, 1.0f, 2.0f));

	addChild(&holder);
	holder.generate();
	holder.position = glm::vec3(-0.35f, 3.0f, 0.0f);

	mesh->init();
}

void WindmillBase::update(float delta_time, glm::mat4 trans)
{
	holder.rotation.x += 45.0f*delta_time;
	if (holder.rotation.x >= 360.0f) holder.rotation.x -= 360.0f;
	Node::update(delta_time, trans);
}