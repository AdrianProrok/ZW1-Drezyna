#include "Support.h"
#include "Mesh.h"

using namespace engine;

Support::Support()
{
}


Support::~Support()
{
}

void Support::generate()
{
	mesh = new Cylinder(0.227f, 0.227f, 64, glm::vec3(0.0f, 1.0f, 1.0f));
	mesh->loadTexture("barTexture.jpg");
	mesh->init();
}

void Support::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}