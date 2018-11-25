#pragma once

// GLM
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

// STD
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texture_coords;
};

struct Face
{
	unsigned int vertex_index[3];
};

class Mesh
{
	std::vector<Vertex> vertices;
	std::vector<Face> faces;
	// Indeks materia³u?
};