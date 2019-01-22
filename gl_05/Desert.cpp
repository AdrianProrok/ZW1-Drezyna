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
	mesh->loadTexture("desertTexture.png");
	mesh->init();

	setSun({ 1.0f, 1.0f, 1.0f }, 45000000.0f, { -5000.0f, 5000.0f, 250.0f });
	
	addChild(&draisine);
	draisine.generate();
	draisine.position = glm::vec3(0.0f, 1.5f + 1.0f, 0.0f);
	
	generateRailroadTrack(700.0f, 4.0f);
	
	generateLamps(50, 28.8f);
}

void Desert::setSun(glm::vec3 color, float intens, glm::vec3 position)
{
	light.color = color;
	light.intensity = intens;
	light.position = position;
	addChild(&light);
	light.generate();
	getScene()->addLight(&light);
}

void Desert::generateRailroadTrack(float length, float space)
{
	planks.clear();
	planks.resize(static_cast<unsigned int>(length/space));
	
	if (planks.size() == 0)
		return;

	addChild(&planks[0]);
	planks[0].generate();
	planks[0].position = glm::vec3(length/2.0f, 1.0f, 0.0f);

	for (unsigned int i = 1; i < planks.size(); ++i)
	{
		addChild(&planks[i]);
		planks[i].setMesh(planks[0].getMesh());
		planks[i].position = glm::vec3(length/2.0f - (float)space * i, 1.0f, 0.0f);
	}

	addChild(&rails[0]);
	addChild(&rails[1]);
	rails[0].generate(length);
	rails[1].setMesh(rails[0].getMesh());
	rails[0].position = glm::vec3(space/2.0f, 0.14f + 1.0f, 4.0f);
	rails[1].position = glm::vec3(space/2.0f, 0.14f + 1.0f, -4.0f);
}

void Desert::generateLamps(unsigned int count, float spacing)
{
	float start_position = (count * spacing)/4.0f - spacing / 2.0f;

	lamps.clear();
	lamps.resize(count);

	if (lamps.size() == 0)
		return;

	addChild(&lamps[0]);
	lamps[0].generate(nullptr);
	lamps[0].position = glm::vec3(start_position, 1.0f, 7.0f);

	for (unsigned int i = 1; i < lamps.size()/2; ++i)
	{
		addChild(&lamps[i]);
		lamps[i].generate(lamps[0].getMesh());
		lamps[i].position = glm::vec3(start_position - (float)spacing * i, 1.0f, 7.0f);
	}

	for (unsigned int i = lamps.size()/2; i < lamps.size(); ++i)
	{
		addChild(&lamps[i]);
		lamps[i].generate(lamps[0].getMesh());
		lamps[i].position = glm::vec3(start_position - (float)spacing * (i - lamps.size()/2), 1.0f, -7.0f);
	}
}

void Desert::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}