#include "Scene.h"
#include "App.h"
#include <glm/vec3.hpp>
#include <string>

namespace engine
{
	Scene::Scene()
	{
		root_node = nullptr;
		shader_program = nullptr;
		ambientStrength = 0.0f;
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
		int i = 0;
		GLuint ambientLightLoc = glGetUniformLocation(getCurrentShaderProgram()->get_programID(), "ambientStrength");
		glUniform1f(ambientLightLoc, ambientStrength);

		GLuint numberOfLightsLoc = glGetUniformLocation(getCurrentShaderProgram()->get_programID(), "numberOfLights");
		glUniform1i(numberOfLightsLoc, lights.size());
		for (auto light : lights) {
			GLuint lightPosLoc = glGetUniformLocation(getCurrentShaderProgram()->get_programID(), ("lightPos[" + std::to_string(i) + "]").c_str());
			glUniform3fv(lightPosLoc, 1, glm::value_ptr(light->position));

			GLuint lightColorLoc = glGetUniformLocation(getCurrentShaderProgram()->get_programID(), ("lightColor[" + std::to_string(i) + "]").c_str());
			glUniform3fv(lightColorLoc, 1, glm::value_ptr(light->color));

			GLuint lightIntensLoc = glGetUniformLocation(getCurrentShaderProgram()->get_programID(), ("lightIntens[" + std::to_string(i) + "]").c_str());
			glUniform1f(lightIntensLoc, light->intensity);
			++i;
		}

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
		const float speed_gamepad_move = 3.5f;
		const float speed_gamepad_angle = 120.0f;
		
		camera.update(
			glm::vec3(
				-speed_gamepad_move*input.gamepad.left_horizontal*delta_time,
				speed_gamepad_move*input.gamepad.trigger*delta_time,
				-speed_gamepad_move*input.gamepad.left_vertical*delta_time),
			glm::vec3(
				speed_gamepad_angle*input.gamepad.right_vertical*delta_time, 
				speed_gamepad_angle*input.gamepad.right_horizontal*delta_time,
				0.0f)
		);

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