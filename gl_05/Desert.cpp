#include "Desert.h"
#include "Cylinder.h"
#include "Mesh.h"
#include "Scene.h"
#include "Lamp.h"
#include "Plank.h"
#include <iostream>
using namespace engine;

Desert::Desert()
{
}


Desert::~Desert()
{
}

void Desert::generate()
{
	setMesh(new Cylinder(1.0f, 2000.0f, 4, glm::vec3(0.761f, 0.698f, 0.502f), glm::vec3(1,1,1), glm::vec2(400,400)));

	lights[0].color = { 1.0f, 1.0f, 1.0f };
	lights[0].intensity = 45000000.0f;
	lights[0].position = { -5000.0f, 5000.0f, 250.0f };
	addChild(&lights[0]);
	lights[0].generate();
	getScene()->addLight(&lights[0]);
	

	addChild(&draisine);
	draisine.generate();
	draisine.position = glm::vec3(0.0f, 1.5f + 1.0f, 0.0f);
	
	addChild(&planks[0]);
	planks[0].generate();	
	planks[0].position = glm::vec3(352.0f, 1.0f, 0.0f);
	
	for (int i = 1; i < 177; ++i)
	{
		addChild(&planks[i]);
		planks[i].setMesh(planks[0].getMesh());
		planks[i].position = glm::vec3(352.0f - (float)4*i, 1.0f, 0.0f);
	}

	addChild(&rails[0]);
	addChild(&rails[1]);
	rails[0].generate();
	rails[1].setMesh(rails[0].getMesh());
	rails[0].position = glm::vec3(0.0f, 0.14f + 1.0f, 4.0f);
	rails[1].position = glm::vec3(0.0f, 0.14f + 1.0f, -4.0f);
	
	mesh->loadTexture("desertTexture.png");
	mesh->init();

	addChild(&lamps[0]);
	lamps[0].generate(nullptr);
	lamps[0].position = glm::vec3(352.0f, 1.0f, 7.0f);

	for (int i = 1; i < 25; ++i)
	{
		addChild(&lamps[i]);
		lamps[i].generate(lamps[0].getMesh());
		lamps[i].position = glm::vec3(352.0f - (float)28.8 * i, 1.0f, 7.0f);
	}

	for (int i = 25; i < 50; ++i)
	{
		addChild(&lamps[i]);
		lamps[i].generate(lamps[0].getMesh());
		lamps[i].position = glm::vec3(352.0f - (float)28.8 * (i-25), 1.0f, -7.0f);
	}
}

void Desert::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}