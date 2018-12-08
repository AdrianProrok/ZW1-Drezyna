#include "Wheel.h"
#include "Mesh.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

Wheel::Wheel()
{
}


Wheel::~Wheel()
{
}

void Wheel::generate()
{
	mesh = new RightRegularPrism(0.7f, 1.35f, 64, glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 rotation(1.0f);
	rotation = glm::rotate(rotation, glm::radians(90.0f), glm::vec3(1, 0, 0));

	for (WheelSide& wheelSide : sides)
	{
		addChild(&wheelSide);
		wheelSide.generate();
	}

	sides[0].position = glm::vec3(0.0f, 0.0f, 0.7f);
	sides[1].position = glm::vec3(0.0f, 0.0f, -0.112f);

	for (Vertex& vertex : mesh->vertices)
	{
		glm::vec4 temp = glm::vec4(vertex.position, 1.0f);
		vertex.position = glm::vec3(rotation * temp);
	}

	mesh->init();
}

void Wheel::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}