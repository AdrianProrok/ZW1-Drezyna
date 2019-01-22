#pragma once

#include "Cube.h"

namespace engine
{
	Cube::Cube(float size, glm::vec3 color) : Cylinder(size, size * static_cast<float>(sqrt(2) / 2.0f), 4, color)
	{

	}
	Cube::~Cube()
	{

	}
}