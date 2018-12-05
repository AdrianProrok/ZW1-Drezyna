#pragma once

#include "Node.h"
#include "Camera.h"
#include "Light.h"
#include "ShaderProgram.h"

#include <list>

//#include "Mesh.h"
//#include "Material.h"
//#include <vector>

class Input;

namespace engine
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		virtual void init(float aspect_ratio);

		// Renderuje scene, wywo³uje renderowanie root_node
		virtual void render();

		// Aktualizowanie sceny - przemieszczanie obiektów na scenie itp.
		virtual void update(float delta_time, const Input& input);
	
		void recalculateProj(float aspect_ratio, float angle);

		void setCurrentShaderProgram(ShaderProgram* program);
		ShaderProgram* getCurrentShaderProgram();

		Camera* getCamera();

		//void addLight(glm::vec3 position, glm::vec3 color, float intensity);
	protected:

		void setRootNode(Node* node);
		Node* getRootNode();

		void updateCamera(float delta_time, const Input& input);

		ShaderProgram* shader_program;

		// Obiekt podstawowy sceny, reszta obiektów jest ustawiona relatywnie od niego
		Node* root_node;
		
		// Kamera
		Camera camera;
		
		// Œwiat³a
		std::list<Light> lights;

		glm::mat4 view;
		glm::mat4 projection;

		// £atwiej chyba trzymaæ mesh i material w Node
		//std::vector<Material> materials;
		//std::vector<Mesh> meshes;
	};
}