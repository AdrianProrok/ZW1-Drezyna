#include "Wheel.h"
#include "Mesh.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

Wheel::Wheel()
{
}


Wheel::~Wheel()
{
}

void Wheel::generate()
{
	setMesh(new Cylinder(0.7f, 1.35f, 64, glm::vec3(1.0f, 0.0f, 0.0f)));

	for (WheelSide& wheelSide : sides)
		addChild(&wheelSide);

	sides[0].generate();
	sides[1].setMesh(sides[0].getMesh());
	sides[0].position = glm::vec3(0.0f, -0.112f, 0.0f);
	sides[1].position = glm::vec3(0.0f, 0.7f, 0.0f);

	generateScrews(5);

	mesh->loadTexture("wheelsTexture.jpg");
	mesh->init();
}

void Wheel::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}


void Wheel::generateScrews(int numberOfScrews)
{
	for (int i = 0; i < numberOfScrews; ++i)
		screws.push_back(Screw());

	if (numberOfScrews == 1)
	{
		screws[0].position = glm::vec3(0.0f, 0.7f, 0.0f);
	}
	else
	{
		glm::mat4 rotation(1.0f);
		rotation = glm::rotate(rotation, glm::radians(360.0f / (float)numberOfScrews), glm::vec3(0, 1, 0));

		screws[0].position = glm::vec3(0.45f, 0.7f, 0.0f);
		glm::vec4 temp = glm::vec4(screws[0].position, 1.0f);

		for (int i = 1; i < numberOfScrews; ++i)
		{
			temp = temp * rotation;
			screws[i].position = glm::vec3(temp);
		}
	}

	addChild(&screws[0]);
	screws[0].generate();
	for (int i = 1; i < numberOfScrews; ++i)
	{
		addChild(&screws[i]);
		screws[i].setMesh(screws[0].getMesh());
	}
}