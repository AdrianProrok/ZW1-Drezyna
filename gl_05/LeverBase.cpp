#include "LeverBase.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

LeverBase::LeverBase()
{
}

LeverBase::~LeverBase()
{
}

void LeverBase::generate()
{
	//bedzie dodana zmienna kolor i texture, bo uzywamy duzo razy tego samego
	/*mesh->vertices = {
		{{-1.0f, 1.0f,  1.0f}, {1.0f, 1.0f,  1.0f}, {0.0f, 0.5f, 1.0f}, {0.0f, 0.0f}},
		{{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f,  1.0f}, {0.0f, 0.5f, 1.0f}, {0.0f, 0.0f}},
		{{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f,  1.0f}, {0.0f, 0.5f, 1.0f}, {0.0f, 0.0f}},
		{{ 1.0f, 1.0f,  1.0f}, {1.0f, 1.0f,  1.0f}, {0.0f, 0.5f, 1.0f}, {0.0f, 0.0f}},
		{{-0.5f, 1.0f,  0.5f}, {1.0f, 1.0f,  1.0f}, {0.0f, 0.5f, 1.0f}, {0.0f, 0.0f}},
		{{-0.5f, 1.0f, -0.5f}, {1.0f, 1.0f,  1.0f}, {0.0f, 0.5f, 1.0f}, {0.0f, 0.0f}},
		{{-0.5f, 1.0f, -0.5f}, {1.0f, 1.0f,  1.0f}, {0.0f, 0.5f, 1.0f}, {0.0f, 0.0f}},
		{{ 0.5f, 1.0f,  0.5f}, {1.0f, 1.0f,  1.0f}, {0.0f, 0.5f, 1.0f}, {0.0f, 0.0f}},
	};

	mesh->faces = {
		{0, 1, 2},
		{0, 2, 3},
		{7,4,2},
		{7,2,1},
		{3,2,4},
		{3,4,5},
		{5,4,7},
		{5,7,6},
		{6,7,1},
		{6,1,0},
		{0,3,5},
		{0,5,6}
	};*/
	mesh = new RightRegularPrism(5.0f, 1.0f, 4, glm::vec3(0.0f, 0.5f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.5f);

	mesh->init();
}

void LeverBase::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}