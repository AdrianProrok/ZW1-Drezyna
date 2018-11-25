#pragma once

#include <GL/glew.h>

#include <glm/mat4x4.hpp>
#include <list>

class Scene;
class Mesh;

class Node
{
public:
	Node();
	~Node();

	Node* parent; // Mo¿e nie trzeba rodzica nawet... macierz transformacji mo¿na dawaæ jako argument render()
	std::list<Node*> children;

	void render();
protected:
	glm::mat4 trans;
	Mesh* mesh;

	Scene* scene;

	void setMesh(Mesh* mesh);
	Mesh* getMesh();
};