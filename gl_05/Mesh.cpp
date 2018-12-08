#include "Mesh.h"

#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace engine
{
	Mesh::Mesh()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		material = nullptr;
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void Mesh::init()
	{
		// ZAK£ADAMY, ¯E MAMY USTAWIONE "vertices" ORAZ "faces"

		glBindVertexArray(VAO);

		// Bufor z wierzcho³kami
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		// &vertices[0] - wskaŸnik na pocz¹tek vector, vector gwarantuje, ¿e elementy s¹ ustawione pokolei
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

		// Bufor z œciankami
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, faces.size() * sizeof(Face), &faces[0], GL_STATIC_DRAW);

		// Informacje o wspó³rzêdnych wierzcho³ka
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

		// Informacje o normalnych
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(glm::vec3)));

		// Informacje o kolorze wierzcho³ka
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(2 * sizeof(glm::vec3)));

		// Wspó³rzêdne tekstury wierzcho³ka
		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(glm::vec3)));

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void Mesh::render()
	{
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, faces.size() * 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	void Mesh::scale(glm::vec3 scale)
	{
		glm::mat4 mat_scale = glm::mat4(1.0f);
		mat_scale = glm::scale(mat_scale, scale);

		for (Vertex& vertex : vertices)
		{
			glm::vec4 temp = glm::vec4(vertex.position, 1.0f);
			vertex.position = glm::vec3(mat_scale * temp);
		}
	}
}