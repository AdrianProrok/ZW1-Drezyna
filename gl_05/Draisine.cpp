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
	setMesh(new Cylinder(1.0f, 5.0f, 4, glm::vec3(0.274f, 0.509f, 0.705f), glm::vec3(2.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec2(4.0f, 0.5f)));
	//Wheels
	for (Wheel& wheel : wheels)
	{
		addChild(&wheel);
		wheel.generate();
	}
	//FRONT LEFT
	wheels[0].position = glm::vec3(4.5f, 0.5f, 3.65f);
	wheels[0].rotation.x = 90.0f;
	//BACK LEFT
	wheels[1].position = glm::vec3(-4.5f, 0.5f, 3.65f);
	wheels[1].rotation.x = 90.0f;
	//FRONT RIGHT
	wheels[2].position = glm::vec3(4.5f, 0.5f, -3.65f);
	wheels[2].rotation.x = -90.0f;
	//BACK RIGHT
	wheels[3].position = glm::vec3(-4.5f, 0.5f, -3.65f);
	wheels[3].rotation.x = -90.0f;

	//Bars
	for (Bar& bar : bars)
	{
		addChild(&bar);
		bar.generate();
	}
	bars[0].position = glm::vec3(0.0f, 0.0f, 4.839f);
	bars[1].position = glm::vec3(0.0f, 0.0f, -4.839f);
	bars[0].rotation.x = -90.0f;
	bars[1].rotation.x = 90.0f;

	addChild(&base);
	base.generate();
	base.position = glm::vec3(0.0f, 1.0f, 0.0f);
	//Fence
	for (Fence& fence : fences)
	{
		addChild(&fence);
		fence.generate();
	}

	fences[0].position = glm::vec3( 6.8f, 1.0f,  3.3f);
	fences[1].position = glm::vec3(-6.8f, 1.0f, -3.3f);
	fences[2].position = glm::vec3( 6.8f, 1.0f, -3.3f);
	fences[3].position = glm::vec3(-6.8f, 1.0f,  3.3f);

	for (FenceCover& cover : covers)
	{
		addChild(&cover);
		cover.generate();
	}

	covers[0].position = glm::vec3(6.8f, 3.0f, 3.3f);
	covers[1].position = glm::vec3(-6.8f, 3.0f, -3.3f);
	covers[2].position = glm::vec3(6.8f, 3.0f, -3.3f);
	covers[3].position = glm::vec3(-6.8f, 3.0f, 3.3f);

	for (LongConnector& c : longC)
	{
		addChild(&c);
		c.generate();
	}
	longC[0].position = glm::vec3(-6.8f, 2.5f, 3.3f);
	longC[1].position = glm::vec3(-6.8f, 2.5f, -3.3f);

	for (ShortConnector& c : shortC)
	{
		addChild(&c);
		c.generate();
	}
	shortC[0].position = glm::vec3(6.8f, 2.5f, -3.3f);
	shortC[1].position = glm::vec3(-6.8f, 2.5f, -3.3f);

	//WindMill

	addChild(&millBase);
	millBase.generate();
	millBase.position = glm::vec3(-6.13f, 0.3f, 0.0f);

	mesh->init();
	//mesh->loadTexture("checkerboard.png");
}

void Draisine::update(float delta_time, glm::mat4 trans)
{
	for (int i = 0; i < 2; ++i)
	{
		wheels[i].rotation.y += 45.0f*delta_time;
		if (wheels[i].rotation.y >= 360.0f) wheels[i].rotation.y -= 360.0f;

		wheels[i + 2].rotation.y -= 45.0f*delta_time;
		if (wheels[i + 2].rotation.y <= 0.0f) wheels[i + 2].rotation.y += 360.0f;

		bars[i].position.x = -1.0f*sin(glm::radians(wheels[i].rotation.y));
		bars[i].position.y = 0.5f + 1.0f*cos(glm::radians(wheels[i].rotation.y));
	}
	
	Node::update(delta_time, trans);
}