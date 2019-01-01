#include "RightRegularPrism.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace engine
{
	RightRegularPrism::RightRegularPrism(float height, float radius, GLuint verts, glm::vec3 color, glm::vec3 scale, float secondRadius)
	{
		if (secondRadius == -1.0f) {
			secondRadius = radius;
		}
		generateBase(0, radius, verts, color);
		generateBase(height, secondRadius, verts, color);

		for (GLuint i = 1; i < verts; ++i)
		{
			//dolna podstawa
			faces.push_back({0, i+1, i});
			//gorna podstawa
			faces.push_back({verts+1, i+verts+1, i+verts+2});
			//boki
			faces.push_back({i, i+verts+2, i+verts+1});
			faces.push_back({i, i+1, i+verts+2});
		}
		//ostatni vert dolnej podstawy z pierwszym
		faces.push_back({0, 1, verts});
		//ostatni vert gornej podstawy z pierwszym
		faces.push_back({verts+1, 2*verts+1, verts+2});
		//ostatnia scianka boczna
		faces.push_back({verts, verts+2, 2*verts+1});
		faces.push_back({ verts, 1, verts + 2 });

		//obracamy figure o 45 stopni, uzywane przy generacji prostopadloscianow, aby mozna je bylo odrazu skalowac
		glm::mat4 rotation(1.0f);
		rotation = glm::rotate(rotation, glm::radians(45.0f), glm::vec3(0, 1, 0));

		for (Vertex& vertex : vertices)
		{
			glm::vec4 temp = glm::vec4(vertex.position, 1.0f);
			vertex.position = glm::vec3(rotation * temp);
		}

		this->scale(scale);
		calculateNormals();
	}

	void RightRegularPrism::generateBase(float height, float radius, GLuint verts, glm::vec3 color)
	{
		glm::mat4 rotation(1.0f);

		Vertex zeroV = { { 0.0f,  height, 0.0f}, glm::vec3(0.0f), color, {0.0f, 0.0f} };
		Vertex firstV = { { 0.0f, height, radius}, glm::vec3(0.0f), color, {0.0f, 0.0f} };

		vertices.push_back(zeroV);
		vertices.push_back(firstV);

		rotation = glm::rotate(rotation, glm::radians(360.0f / (float)verts), glm::vec3(0, 1, 0));

		glm::vec4 temp = glm::vec4(firstV.position, 1.0f);

		for (GLuint i = 0; i < verts - 1; ++i)
		{
			temp = temp * rotation;
			Vertex newVert = { glm::vec3(temp), glm::vec3(0.0f), color, {0.0f, 0.0f} };
			vertices.push_back(newVert);
		}
	}

	void RightRegularPrism::calculateNormals()
	{
		for (Face& face : faces)
		{
			glm::vec3 edge1 = vertices[face.vertex_index[2]].position - vertices[face.vertex_index[0]].position;
			glm::vec3 edge2 = vertices[face.vertex_index[1]].position - vertices[face.vertex_index[0]].position;
			glm::vec3 normal = normalize(glm::cross(edge1, edge2));

			vertices[face.vertex_index[0]].normal += normal;
			vertices[face.vertex_index[1]].normal += normal;
			vertices[face.vertex_index[2]].normal += normal;
		}

		for (Vertex& vertex : vertices)
			vertex.normal = normalize(vertex.normal);
	}

	RightRegularPrism::~RightRegularPrism()
	{
	}
}