#pragma once

#include "Mesh.h"
#include "Cylinder.h"

namespace engine 
{
	class Cube : public Cylinder
	{
	public:
		Cube(float size, glm::vec3 color);
		~Cube();
	};
}