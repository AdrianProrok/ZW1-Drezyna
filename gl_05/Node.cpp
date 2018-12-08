#include "Node.h"
#include "Mesh.h"
#include "Scene.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

namespace engine
{
	Node::Node()
	{
		mesh = nullptr;
		scene = nullptr;
		parent = nullptr;

		position = glm::vec3(0.0f, 0.0f, 0.0f);
		rotation = glm::vec3(0.0f, 0.0f, 0.0f);
		scale = glm::vec3(1.0f, 1.0f, 1.0f);
	}

	Node::~Node()
	{
		if(mesh)
			delete mesh; // Do przemyœlenia, bo bêdzie problem jak mesh s¹ wspó³dzielone.
	}

	void Node::render()
	{
		// 1. Dane o przesuniêciu, skalowaniu i obrocie dla shadera
		// 2. Rysowanie
		// 3. Rysowanie wszystkich dzieci

		GLuint transformLoc = glGetUniformLocation(scene->getCurrentShaderProgram()->get_programID(), "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

		if (mesh)
			mesh->render();

		for (auto& child : children)
			child->render();
	}

	void Node::update(float delta_time, glm::mat4 trans)
	{
		glm::mat4 new_trans = glm::mat4(1.0f);

		new_trans = glm::scale(new_trans, scale);
		new_trans = glm::translate(new_trans, position);
		new_trans = glm::rotate(new_trans, glm::radians(rotation.x), glm::vec3(1, 0, 0)); // X
		new_trans = glm::rotate(new_trans, glm::radians(rotation.y), glm::vec3(0, 1, 0)); // Y
		new_trans = glm::rotate(new_trans, glm::radians(rotation.z), glm::vec3(0, 0, 1)); // Z
		

		this->trans = trans * new_trans;

		for (auto& child : children)
			child->update(delta_time, this->trans);
	}

	void Node::setMesh(Mesh* mesh)
	{
		this->mesh = mesh;
	}

	Mesh* Node::getMesh()
	{
		return mesh;
	}

	void Node::addChild(Node* child)
	{
		children.push_back(child);
		child->setScene(scene);
		child->setParent(this);
	}

	void Node::setScene(Scene* scene)
	{
		this->scene = scene;
	}

	Scene* Node::getScene()
	{
		return scene;
	}

	void Node::setParent(Node* parent)
	{
		this->parent = parent;
	}

	Node* Node::getParent()
	{
		return this->parent;
	}
}