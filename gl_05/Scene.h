#pragma once

#include "Node.h"
#include "Camera.h"
#include "Light.h"
#include "ShaderProgram.h"
#include "Skybox.h"

#include <list>
#include <set>

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

		void addLight(Light* light);

		void addMesh(Mesh* mesh);

	protected:

		void setRootNode(Node* node);
		Node* getRootNode();

		void updateCamera(float delta_time, const Input& input);

		void updateShader(ShaderProgram* shader);

		ShaderProgram* shader_program;
		ShaderProgram* skybox_shader;

		SkyBox* skybox;

		// Obiekt podstawowy sceny, reszta obiektów jest ustawiona relatywnie od niego
		Node* root_node;
		
		// Kamera
		Camera camera;
		
		// Œwiat³a
		std::vector<Light*> lights;
		float ambientStrength;

		// Meshes
		std::set<Mesh*> meshes;
	
		bool f_pause;
	};
}