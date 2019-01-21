#include "LeverHandle.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Scene.h"

using namespace engine;

LeverHandle::LeverHandle()
{
}

LeverHandle::~LeverHandle()
{
}

void LeverHandle::generate()
{
	setMesh(new Cylinder(0.2f, 1.0f, 4, glm::vec3(0.0f, 0.5f, 1.0f), glm::vec3(0.25f, 1.5f, 1.7f), glm::vec2(1.0f, 2.0f), glm::vec2(5.0f, 1.0f), 1.0f));
	mesh->loadTexture("leverConnHandleTexture.jpg");
	mesh->init();

	/*light.color = { 0.0f, 1.0f, 0.0f };
	light.intensity = 100.0f;
	light.position = { 15.0f, 2.0f, 0.0f };
	light.setScene(getScene());
	light.generate();
	getScene()->addLight(&light);

	addChild(&light);*/
}

void LeverHandle::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}