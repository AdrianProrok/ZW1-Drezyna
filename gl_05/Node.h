#pragma once

#include <glm/mat4x4.hpp>
#include <list>

#include "Mesh.h"

class Node
{
public:
	Node() {}
	~Node() {}

	Node* parent; // Mo¿e nie trzeba rodzica nawet... macierz transformacji mo¿na dawaæ jako argument render()
	std::list<Node*> children;

	void render();
	void setMesh( Mesh* mesh );
	Mesh* getMesh();
private:
	glm::mat4 trans;
	Mesh mesh;

};