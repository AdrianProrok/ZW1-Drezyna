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
	//BACK LEFT
	wheels[1].position = glm::vec3(-4.5f, 0.5f, 3.65f);
	//FRONT RIGHT
	wheels[2].position = glm::vec3(4.5f, 0.5f, -3.65f);
	//BACK RIGHT
	wheels[3].position = glm::vec3(-4.5f, 0.5f, -3.65f);

	for (Bar& bar : bars)
	{
		addChild(&bar);
		bar.generate();
	}
	bars[0].position = glm::vec3(0.0f, 1.5f, 4.462f);
	bars[1].position = glm::vec3(0.0f, 1.5f, -4.612f);

	addChild(&base);
	base.generate();
	base.position = glm::vec3(0.0f, 1.0f, 0.0f);
		
	mesh->init();
}

void Draisine::update(float delta_time, glm::mat4 trans)
{
	for (int i = 0; i < 2; ++i)
	{
		wheels[i].rotation.x = 90.0f;
		wheels[i+2].rotation.x = -90.0f;

		bars[i].rotation.x = 90.0f;

		wheels[i].rotation.y += 45.0f*delta_time;
		if (wheels[i].rotation.y >= 360.0f) rotation.y -= 360.0f;

		wheels[i + 2].rotation.y -= 45.0f*delta_time;
		if (wheels[i + 2].rotation.y <= 0.0f) rotation.y += 360.0f;

		bars[i].position.x = -1.0f*sin(glm::radians(wheels[i].rotation.y));
		bars[i].position.y = 0.5f + 1.0f*cos(glm::radians(wheels[i].rotation.y));
	}
	
	Node::update(delta_time, trans);
}