#pragma once

#include <GL/glew.h>

// GLM
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

// STD
#include <vector>

#include "Material.h"

struct Vertex
{
	GLfloat position[3];
	GLfloat normal[3];
	GLfloat color[3];
	GLfloat texture_coords[2];
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