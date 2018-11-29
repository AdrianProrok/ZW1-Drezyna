#pragma once

#include "Node.h"
#include "Camera.h"
#include "Light.h"
#include "ShaderProgram.h"

#include <list>

//#include "Mesh.h"
//#include "Material.h"
//#include <vector>

namespace engine
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		// Renderuje scene, wywo�uje renderowanie root_node
		virtual void render();

		// Aktualizowanie sceny - przemieszczanie obiekt�w na scenie itp.
		virtual void update( float delta_time );
	
		void setCurrentShaderProgram(ShaderProgram* program);
		ShaderProgram* getCurrentShaderProgram();
	protected:

		void setRootNode(Node* node);
		Node* getRootNode();

		ShaderProgram* shader_program;

		// Obiekt podstawowy sceny, reszta obiekt�w jest ustawiona relatywnie od niego
		Node* root_node;
		
		// Kamera
		Camera camera;
		
		// �wiat�a
		std::list<Light> lights;

		glm::mat4 view;
		glm::mat4 projection;

		// �atwiej chyba trzyma� mesh i material w Node
		//std::vector<Material> materials;
		//std::vector<Mesh> meshes;
	};
}