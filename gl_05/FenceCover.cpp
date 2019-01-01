#include "FenceCover.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

FenceCover::FenceCover()
{
}

FenceCover::~FenceCover()
{
}

void FenceCover::generate()
{
	mesh = new RightRegularPrism(0.6f, 0.6f, 64, glm::vec3(1.0f, 0.5f, 0.0f), glm::vec3(0.45f, 1.0f, 0.45f), 0.1f);
	mesh->init();
}

void FenceCover::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}