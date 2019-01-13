#include "World.h"
#include "ShaderProgram.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

#include "App.h"

World::World()
{
	ambientStrength = 0.2f;
}

World::~World()
{
	
}

void World::init(float aspect_ratio)
{
	// Najpierw shader, bo potem ró¿ne rzeczy s¹ do niego ³adowane
	setCurrentShaderProgram(new engine::ShaderProgram("gl_05.vert", "gl_05.frag"));
	shader_program->Use();

	// Potem RootNode
	setRootNode(&desert);

	desert.generate();
	// I ca³a reszta

	camera.setScene(this);
	camera.set(glm::vec3(0.0f, 0.0f, 15.0f), glm::vec3(0.0f, 180.0f, 0.0f));
	
	light[0].color = { 1.0f, 1.0f, 1.0f };
	light[0].intensity = 3000000.0f;
	light[0].position = { 1000.0f, 1000.0f, 1000.0f };
	
	light[1].color = { 1.0f, 0.0f, 0.0f };
	light[1].intensity = 100.0f;
	light[1].position = { 15.0f, 0.0f, 0.0f };
	
	light[2].color = { 0.0f, 1.0f, 0.0f };
	light[2].intensity = 100.0f;
	light[2].position = { 15.0f, 0.0f, 6.0f };
	
	light[3].color = { 0.0f, 0.0f, 1.0f };
	light[3].intensity = 100.0f;
	light[3].position = { 18.0f, 0.0f, 3.0f };

	lights.push_back(&light[0]);
	lights.push_back(&light[1]);
	lights.push_back(&light[2]);
	lights.push_back(&light[3]);
	
	Scene::init(aspect_ratio);
}

void World::render()
{	
	Scene::render();
}

void World::update(float delta_time, const Input& input)
{	
	static int light_index = 0;
	static int light_sens = 100;

	if (input.keyboard.keys_pressed[GLFW_KEY_0])
		light_index = 0;
	if (input.keyboard.keys_pressed[GLFW_KEY_1])
		light_index = 1;
	if (input.keyboard.keys_pressed[GLFW_KEY_2])
		light_index = 2;
	if (input.keyboard.keys_pressed[GLFW_KEY_3])
		light_index = 3;
	if (input.keyboard.keys_pressed[GLFW_KEY_4])
		light_index = 0;
	if (input.keyboard.keys_pressed[GLFW_KEY_5])
		light_index = 0;
	if (input.keyboard.keys_pressed[GLFW_KEY_6])
		light_index = 0;
	if (input.keyboard.keys_pressed[GLFW_KEY_7])
		light_index = 0;
	if (input.keyboard.keys_pressed[GLFW_KEY_8])
		light_index = 0;
	if (input.keyboard.keys_pressed[GLFW_KEY_9])
		light_index = 0;

	if (light_index == 0)
		light_sens = 1000000;
	else
		light_sens = 100;

	if (input.keyboard.keys_pressed[GLFW_KEY_U])
		ambientStrength -= delta_time * 0.5f;
	if (input.keyboard.keys_pressed[GLFW_KEY_I])
		ambientStrength += delta_time * 0.5f;
	if (input.keyboard.keys_pressed[GLFW_KEY_J])
		light[light_index].intensity -= delta_time * light_sens;
	if (input.keyboard.keys_pressed[GLFW_KEY_K])
		light[light_index].intensity += delta_time * light_sens;
	if (input.keyboard.keys_pressed[GLFW_KEY_H]) {
		light[0].intensity = 3000000.0f;
	}

	if (light[light_index].intensity < 0)
		light[light_index].intensity = 0;
	if (ambientStrength < 0)
		ambientStrength = 0;

	Scene::update(delta_time, input);
}