#include "Draisine.h"
#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

using namespace engine;

Draisine::Draisine()
{
}

Draisine::~Draisine()
{
}

void Draisine::generate()
{
	mesh = new RightRegularPrism(1.0f, 1.0f, 4, glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(2.0f, 1.0f,0.8f));

	/*mesh->vertices = {
		{{ 5.0f,  0.0f,  5.0f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  0.0f}},
		{{-5.0f,  0.0f,  5.0f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  0.0f}},
		{{-5.0f, -0.0f, -5.0f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  1.0f}},
		{{ 5.0f, -0.0f, -5.0f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  1.0f}},
	};

	mesh->faces = {
		{0, 1, 2 },
		{0, 2, 3}
	};*/

	mesh->init();
	/*Cube* cube = new Cube;
	cube->init();
	test.setMesh(cube);
	test.position = glm::vec3(1.5f, 1.5f, 0.0f);
	test.scale = glm::vec3(1.0f);

	addChild(&test);

	Cube* cube2 = new Cube;
	cube2->init();
	test2.setMesh(cube2);
	test2.position = glm::vec3(-1.5f, 0.5f, 0.0f);
	test2.scale = glm::vec3(0.5f);
	
	test.addChild(&test2);*/

	this->position.y -= 2;
}

void Draisine::update(float delta_time, glm::mat4 trans)
{
	// Aktualizowanie pozycji, obrotu, skali
	test.rotation.x += 45.0f * delta_time;
	if (rotation.x >= 360.0f)
		rotation.x -= 360.0f;

	Node::update(delta_time, trans);
}