#include "Scene.h"

namespace engine
{
	Scene::Scene()
	{
		root_node = nullptr;
		shader_program = nullptr;
	}

	Scene::~Scene()
	{
		if(shader_program)
			delete shader_program;
	}

	void Scene::render()
	{
		if (root_node)
			root_node->render();
	}

	void Scene::update(float delta_time)
	{
		if (root_node)
			root_node->update(delta_time, glm::mat4());
	}

	void Scene::setRootNode(Node* node)
	{
		root_node = node;
		root_node->setScene(this);
	}

	Node* Scene::getRootNode()
	{
		return root_node;
	}

	void Scene::setCurrentShaderProgram(ShaderProgram* program) 
	{
		if (shader_program)
			delete shader_program;

		shader_program = program;
	}

	ShaderProgram* Scene::getCurrentShaderProgram()
	{
		return shader_program;
	}

	Camera* Scene::getCamera()
	{
		return &camera;
	}
}