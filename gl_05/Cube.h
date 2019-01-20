#pragma once

#include "Mesh.h"
#include "RightRegularPrism.h"

namespace engine 
{
	class Cube : public RightRegularPrism
	{
	public:
		Cube(float size, glm::vec3 color);
		~Cube();
	};
}