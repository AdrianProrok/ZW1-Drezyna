#include "WheelSide.h"
#include "Mesh.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

WheelSide::WheelSide()
{
}


WheelSide::~WheelSide()
{
}


void WheelSide::generate()
{
	mesh = new RightRegularPrism(0.112f, 1.65f, 64, glm::vec3(0.98f, 0.52f, 0.35f));

	glm::mat4 rotation(1.0f);
	rotation = glm::rotate(rotation, glm::radians(90.0f), glm::vec3(1, 0, 0));

	for (Vertex& vertex : mesh->vertices)
	{
		glm::vec4 temp = glm::vec4(vertex.position, 1.0f);
		vertex.position = glm::vec3(rotation * temp);
	}
	mesh->init();
}

void WheelSide::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}