#include "Scene.h"
#include "App.h"
#include <glm/vec3.hpp>


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

	void Scene::update(float delta_time, const Input& input)
	{
		updateCamera(delta_time, input);
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

	void Scene::updateCamera(float delta_time, const Input& input)
	{
		camera.update(
			glm::vec3(
				camera.speed*(input.keyboard.keys_pressed[GLFW_KEY_A] - input.keyboard.keys_pressed[GLFW_KEY_D])*delta_time,
				camera.speed*(input.keyboard.keys_pressed[GLFW_KEY_Q] - input.keyboard.keys_pressed[GLFW_KEY_E])*delta_time,
				camera.speed*(input.keyboard.keys_pressed[GLFW_KEY_W] - input.keyboard.keys_pressed[GLFW_KEY_S])*delta_time),
			glm::vec3(
				input.mouse.pos_y*0.1f,
				input.mouse.pos_x*0.1f, 0.0f)
		);

		if (input.keyboard.keys_pressed[GLFW_KEY_T])
			recalculateProj(camera.aspect_ratio, camera.view_angle+10.0f*delta_time);
		if (input.keyboard.keys_pressed[GLFW_KEY_G])
			recalculateProj(camera.aspect_ratio, camera.view_angle-10.0f*delta_time);
	}

	void Scene::recalculateProj(float aspect_ratio, float angle)
	{
		camera.setProj(aspect_ratio, angle);
	}

	void Scene::init(float aspect_ratio)
	{
		recalculateProj(aspect_ratio, 55.0f);
	}
}