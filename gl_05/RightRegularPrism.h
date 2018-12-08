#pragma once

#include "Mesh.h"

namespace engine
{
	class RightRegularPrism : public Mesh
	{
	public:
		RightRegularPrism(float height, float radius, GLuint verts, glm::vec3 color);
		~RightRegularPrism();
	private:
		void generateBase(float height, float radius, GLuint verts, glm::vec3 color);
	};
}
