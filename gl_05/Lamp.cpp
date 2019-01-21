#include "Lamp.h"
#include "Mesh.h"
#include "Cube.h"
#include "Scene.h"

using namespace engine;

Lamp::Lamp()
{
}


Lamp::~Lamp()
{
}

void Lamp::generate(Mesh* mesh)
{
	if (mesh == nullptr) {
		setMesh(new Cube(0.5f, glm::vec3(0.2, 0.2, 0.2)));
		getMesh()->scale(glm::vec3(1, 6, 1));
	}
	else {
		setMesh(mesh);
		mesh->init();
	}

	light.color = { 1.0f, 1.0f, 1.0f };
	light.intensity = 7.5f;
	light.position = { 0.0f, 3.0f, 0.0f };
	addChild(&light);
	light.generate();
	getScene()->addLight(&light);
}

void Lamp::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}