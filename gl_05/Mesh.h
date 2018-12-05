#pragma once

#include <GL/glew.h>

// GLM
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

// STD
#include <vector>

#include "Material.h"

namespace engine
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec3 color;
		glm::vec2 texture_coords;
	};

	struct Face
	{
		GLuint vertex_index[3];
	};

	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		std::vector<Vertex> vertices;
		std::vector<Face> faces;
		Material* material;

		GLuint VBO, EBO, VAO;

		void init();
		void render();
	};
}