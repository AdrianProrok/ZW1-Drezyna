#pragma once

#include <GL/glew.h>

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include <list>

namespace engine
{
	class Scene;
	class Mesh;

	class Node
	{
	public:
		Node();
		~Node();

		virtual void render();
		virtual void update(float delta_time, glm::mat4 trans);

		void setMesh(Mesh* mesh);
		Mesh* getMesh();

		void setParent(Node* parent);
		Node* getParent();

		glm::mat4 trans;

		void setScene(Scene* scene);
		Scene* getScene();
		
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		void addChild(Node* child);

		void setSelfIllumination(bool isSelfIllumination);
		void setSelfIlluminationIntens(float intens);
		float getSelfIlluminationIntens();

	protected:
		Mesh* mesh;
		Scene* scene;
	
	private:
		std::list<Node*> children;
		Node* parent;

		bool isSelfIlluminated;
		float selfIlluminationIntens;
	};
}