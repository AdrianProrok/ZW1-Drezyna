#pragma once

#include "Mesh.h"

namespace engine
{
	class Cylinder : public Mesh
	{
	public:
		Cylinder(float, float, GLuint, glm::vec3, glm::vec3 = glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2 = glm::vec2(1.0f, 1.0f), glm::vec2 = glm::vec2(1.0f, 1.0f),  float = -1.0f);
		~Cylinder();
	private:
		void generateBase(float, float, GLuint, glm::vec3);
		void calculateNormals(int verts);
		void scaleBaseTexture(glm::vec2, GLuint);
		void scaleSideTexture(glm::vec2, GLuint);

		std::vector<Vertex> verticesCopy;
	};
}
