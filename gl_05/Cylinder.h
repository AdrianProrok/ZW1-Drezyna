#pragma once

#include "Mesh.h"

namespace engine
{
	class Cylinder : public Mesh
	{
	public:
		Cylinder(float, float, GLuint, glm::vec3, glm::vec3 = glm::vec3(1.0f, 1.0f, 1.0f), float = -1.0f);
		~Cylinder();
	private:
		void generateBase(float, float, GLuint, glm::vec3);
		void calculateNormals(int verts);

		std::vector<Vertex> verticesCopy;
	};
}
