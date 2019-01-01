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
	//Wheels
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
	//Bars
	for (Bar& bar : bars)
	{
		addChild(&bar);
		bar.generate();
	}
	bars[0].position = glm::vec3(0.0f, 1.5f, 4.462f);
	bars[1].position = glm::vec3(0.0f, 1.5f, -4.612f);
	//LeverBase
	addChild(&base);
	base.generate();
	base.position = glm::vec3(0.0f, 1.0f, 0.0f);
	//Fence
	for (Fence& fence : fences)
	{
		addChild(&fence);
		fence.generate();
	}
	/*int amountInRowX = 11;
	int amountInRowY = 5;
	for (int i = 0; i < amountInRowX; i++) {
		fences[i].position = glm::vec3(6.8f - 1.36f*i, 1.0f, 3.3f);
		fences[i+ amountInRowX].position = glm::vec3(6.8f - 1.36f*i, 1.0f, -3.3f);
	}
	for (int i = amountInRowX; i < amountInRowY+amountInRowX; i++) {
		fences[i + amountInRowX].position = glm::vec3(6.8f, 1.0f, 2.2f - 1.1f*(i - amountInRowX));
		fences[i + amountInRowX + amountInRowY].position = glm::vec3(-6.8f, 1.0f, 2.2f-1.1f*(i-amountInRowX));
	} */
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