#pragma once

#include "Mesh.h"

namespace engine
{
	class RightRegularPrism : public Mesh
	{
	public:
		RightRegularPrism(float, float, GLuint, glm::vec3, glm::vec3 = glm::vec3(1.0f, 1.0f, 1.0f), float = -1.0f);
		~RightRegularPrism();
	private:
		void generateBase(float, float, GLuint, glm::vec3);
		void calculateNormals();
	};
}
