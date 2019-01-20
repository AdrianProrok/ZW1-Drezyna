#include "Desert.h"
#include "Cylinder.h"
#include "Mesh.h"
#include "Scene.h"

using namespace engine;

Desert::Desert()
{
}


Desert::~Desert()
{
}

void Desert::generate()
{
	mesh = new Cylinder(1.0f, 1000.0f, 4, glm::vec3(0.761f, 0.698f, 0.502f)); //glm::vec3(1.0f, 1.0f, 0.2f));

	addChild(&draisine);
	draisine.generate();
	draisine.position = glm::vec3(0.0f, 1.5f + 1.0f, 0.0f);
	
	planks[0].generate();
	addChild(&planks[0]);
	planks[0].position = glm::vec3(200.0f, 1.0f, 0.0f);
	for (int i = 1; i < 100; ++i)
	{
		addChild(&planks[i]);
		planks[i].setMesh(planks[0].getMesh());
		planks[i].position = glm::vec3(200.0f - (float)4*i, 1.0f, 0.0f);
	}

	addChild(&rails[0]);
	addChild(&rails[1]);
	rails[0].generate();
	rails[1].setMesh(rails[0].getMesh());
	rails[0].position = glm::vec3(0.0f, 0.14f + 1.0f, 4.0f);
	rails[1].position = glm::vec3(0.0f, 0.14f + 1.0f, -4.0f);
	
	mesh->loadTexture("desertTexture.jpg");
	mesh->init();

	//this->position.y -= 2.0;

	lights[0].color = { 1.0f, 1.0f, 1.0f };
	lights[0].intensity = 10000000.0f;
	lights[0].position = { -2000.0f, 2000.0f, 250.0f };
	lights[0].setScene(getScene());
	lights[0].generate();
	getScene()->addLight(&lights[0]);

	lights[1].color = { 1.0f, 0.0f, 0.0f };
	lights[1].intensity = 100.0f;
	lights[1].position = { 15.0f, 2.0f, 0.0f };
	lights[1].setScene(getScene());
	lights[1].generate();
	getScene()->addLight(&lights[1]);

	lights[2].color = { 0.0f, 1.0f, 0.0f };
	lights[2].intensity = 100.0f;
	lights[2].position = { 15.0f, 2.0f, 6.0f };
	lights[2].setScene(getScene());
	lights[2].generate();
	getScene()->addLight(&lights[2]);

	lights[3].color = { 0.0f, 0.0f, 1.0f };
	lights[3].intensity = 100.0f;
	lights[3].position = { 18.0f, 2.0f, 3.0f };
	lights[3].setScene(getScene());
	lights[3].generate();
	getScene()->addLight(&lights[3]);

	addChild(&lights[0]);
	addChild(&lights[1]);
	addChild(&lights[2]);
	addChild(&lights[3]);
}

void Desert::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}