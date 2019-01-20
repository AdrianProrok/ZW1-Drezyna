#include "Cylinder.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace engine
{
	Cylinder::Cylinder(float height, float radius, GLuint verts, glm::vec3 color, glm::vec3 scale, float secondRadius)
	{
		if (secondRadius == -1.0f) {
			secondRadius = radius;
		}
		generateBase(0, radius, verts, color);
		generateBase(height, secondRadius, verts, color);

		vertices.insert(vertices.end(), verticesCopy.begin(), verticesCopy.end());

		for (GLuint i = 1; i < verts; ++i)
		{
			//dolna podstawa
			faces.push_back({ 0, i + 1, i });
			//gorna podstawa
			faces.push_back({ verts + 1, i + verts + 1, i + verts + 2 });
			//boki
			faces.push_back({ i + 2 * verts + 1, i + 3 * verts + 3, i + 3 * verts + 2 });
			faces.push_back({ i + 2 * verts + 1, i + 2 + 2 * verts, i + 3 * verts + 3 });
		}
		//ostatni vert dolnej podstawy z pierwszym
		faces.push_back({ 0, 1, verts });
		//ostatni vert gornej podstawy z pierwszym
		faces.push_back({ verts + 1, 2 * verts + 1, verts + 2 });
		//ostatnia scianka boczna
		faces.push_back({ 3 * verts + 1, 4 * verts + 3, 4 * verts + 2 });
		faces.push_back({ 3 * verts + 1, 3 * verts + 2, 4 * verts + 3 });

		this->scale(scale);
		calculateNormals(verts);
	}

	void Cylinder::generateBase(float height, float radius, GLuint verts, glm::vec3 color)
	{
		float uPos = height == 0 ? 0.25f : 0.75f;
		float vPos = 0.75f;

		glm::mat4 rotation(1.0f);

		Vertex zeroV = { { 0.0f,  height, 0.0f}, glm::vec3(0.0f), color, {uPos, vPos} };
		Vertex firstV = { { 0.0f, height, radius}, glm::vec3(0.0f), color, glm::vec2(0.0f) };

		glm::mat4 vertRotation(1.0f);
		vertRotation = glm::rotate(vertRotation, glm::radians(45.0f), glm::vec3(0, 1, 0));

		glm::vec4 temp = glm::vec4(zeroV.position, 1.0f);
		zeroV.position = glm::vec3(vertRotation * temp);
		temp = glm::vec4(firstV.position, 1.0f);
		firstV.position = glm::vec3(vertRotation * temp);
		firstV.texture_coords = { uPos + firstV.position.x / (radius * 4), vPos + firstV.position.z / (radius * 4) };
		
		vertices.push_back(zeroV);
		vertices.push_back(firstV);

		firstV.texture_coords = { 0.0f, uPos - 0.25f };
		verticesCopy.push_back(firstV);

		rotation = glm::rotate(rotation, glm::radians(360.0f / (float)verts), glm::vec3(0, 1, 0));

		temp = glm::vec4(firstV.position, 1.0f);

		for (GLuint i = 0; i < verts - 1; ++i)
		{
			temp = temp * rotation;

			Vertex newVert = { glm::vec3(temp), glm::vec3(0.0f), color, {uPos + temp.x / (radius * 4), vPos + temp.z / (radius * 4)} };
			vertices.push_back(newVert);

			newVert.texture_coords = { (i + 1)* 1.0f / verts , uPos - 0.25f };
			verticesCopy.push_back(newVert);
		}

		firstV.texture_coords = { 1.0f, uPos - 0.25f };
		verticesCopy.push_back(firstV);
	}

	void Cylinder::calculateNormals(int verts)
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

		glm::vec3 tempNormal = vertices[3 * verts + 2].normal;
		vertices[3 * verts + 2].normal += vertices[2 * verts + 2].normal;
		vertices[2 * verts + 2].normal += tempNormal;

		tempNormal = vertices[4 * verts + 3].normal;
		vertices[4 * verts + 3].normal += vertices[3 * verts + 3].normal;
		vertices[3 * verts + 3].normal += tempNormal;

		for (int i = 0; i < verts+1; ++i)
		{
			glm::vec3 tempNormal = vertices[i + 2 * verts + 2].normal;
			vertices[i + 2 * verts + 2].normal += vertices[i + 3 * verts + 3].normal;
			vertices[i + 3 * verts + 3].normal += tempNormal;
		}

		for (Vertex& vertex : vertices)
			vertex.normal = normalize(vertex.normal);
	}

	Cylinder::~Cylinder()
	{
	}
}