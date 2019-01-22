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
	setMesh(new Cylinder(0.72f, 0.2f, 64, glm::vec3(0.325f, 1.0f, 0.63f)));

	for (Vane& v : vanes)
	{
		addChild(&v);
		v.generate();
	}

	generateVanes(5);
	mesh->loadTexture("windmillTexture.jpg");
	mesh->init();

	this->rotation.z = 90.0f;
}

void WindmillHolder::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}

void WindmillHolder::generateVanes(int numberOfVanes)
{
	for (int i=0; i<numberOfVanes; i++)
		vanes.push_back(Vane());

	glm::mat4 rotation(1.0f);
	rotation = glm::rotate(rotation, glm::radians(360.0f / (float)numberOfVanes), glm::vec3(0, 1, 0));

	vanes[0].position = glm::vec3(0.925f, 0.6f, -0.06f);
	glm::vec4 temp = glm::vec4(vanes[0].position, 1.0f);

	for (int i=1; i< numberOfVanes; i++)
	{
		temp = temp * rotation;
		vanes[i].position = glm::vec3(temp);
		vanes[i].rotation.y = (-360.0f/float(numberOfVanes)) * i;
	}

	addChild(&vanes[0]);
	vanes[0].generate();
	for (int i=1; i<numberOfVanes; i++)
	{
		addChild(&vanes[i]);
		vanes[i].setMesh(vanes[0].getMesh());
	}
}