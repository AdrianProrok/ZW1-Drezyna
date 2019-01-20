#pragma once

#include "Cube.h"

namespace engine
{
	Cube::Cube(float size, glm::vec3 color) : RightRegularPrism(size, size * sqrt(2) / 2, 4, color)
	{

	}
	Cube::~Cube()
	{

	}
}