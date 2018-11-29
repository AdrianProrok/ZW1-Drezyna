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
	mesh = new Mesh();

	// Set up vertex data 

	mesh->vertices = {
		{{ 0.25f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  0.0f}},
		{{-0.75f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  0.0f}},
		{{-0.25f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  1.0f}},
		{{ 0.75f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  1.0f}},
											    									
		{{-0.25f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  0.0f}},
		{{-0.75f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  1.0f}},
		{{ 0.25f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  1.0f}},
		{{ 0.75f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  0.0f}},
											    					   				
		{{-0.25f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  0.0f}},
		{{-0.25f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  1.0f}},
		{{ 0.75f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  1.0f}},
		{{ 0.75f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  0.0f}},
											    					   				
		{{-0.75f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  0.0f}},
		{{-0.75f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  1.0f}},
		{{ 0.25f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  1.0f}},
		{{ 0.25f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  0.0f}},
											    					   				
		{{-0.25f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  0.0f}},
		{{-0.75f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  1.0f}},
		{{-0.25f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f,  0.0f}},
		{{-0.75f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {1.0f,  1.0f}},
											    					   				
		{{ 0.75f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  0.0f}},
		{{ 0.75f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {0.0f,  0.0f}},
		{{ 0.25f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f,  1.0f}},
		{{ 0.25f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  1.0f}}
	};

	mesh->faces = {
		{0, 1, 2 },
		{0, 2, 3},
		{4, 5, 6},
		{4, 6, 7},
		{8, 9, 10},
		{8, 10, 11},
		{12, 13, 14},
		{12, 14, 15},
		{16, 17, 18},
		{18, 17, 19},
		{20, 21, 22},
		{20, 22, 23}
	};

	mesh->init();
	Cube* cube = new Cube;
	cube->init();
	test.setMesh(cube);
	test.position = glm::vec3(1.0f, 0.0f, 0.0f);
	test.scale = glm::vec3(0.5f);

	addChild(&test);
	//children.push_back(&test);
}

void Draisine::update(float delta_time, glm::mat4 trans)
{
	// Aktualizowanie pozycji, obrotu, skali
	rotation.x += 45.0f * delta_time;
	if (rotation.x >= 360.0f)
		rotation.x -= 360.0f;

	Node::update(delta_time, trans);
}