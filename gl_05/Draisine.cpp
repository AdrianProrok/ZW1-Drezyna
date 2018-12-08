#include "Draisine.h"
#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

Draisine::Draisine()
{
}

Draisine::~Draisine()
{
}

void Draisine::generate()
{
	mesh = new RightRegularPrism(1.0f, 5.0f, 4, glm::vec3(0.274f, 0.509f, 0.705f), glm::vec3(2.0f, 1.0f, 1.0f));

	for (Wheel& wheel : wheels)
	{
		addChild(&wheel);
		wheel.generate();
	}
	//FRONT LEFT
	wheels[0].position = glm::vec3(4.5f, 0.5f, 3.65f);
	//FRONT RIGHT
	wheels[1].position = glm::vec3(4.5f, 0.5f, -4.35);
	//BACK LEFT
	wheels[2].position = glm::vec3(-4.5f, 0.5f, 3.65f);
	//BACK RIGHT
	wheels[3].position = glm::vec3(-4.5f, 0.5f, -4.35f);
		
	mesh->init();
}

void Draisine::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}