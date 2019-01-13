#include "World.h"
#include "ShaderProgram.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

#include "App.h"

World::World()
{
	
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
	if (input.keyboard.keys_pressed[GLFW_KEY_J])
		light[0].intensity -= delta_time * 1000000;
	if (input.keyboard.keys_pressed[GLFW_KEY_K])
		light[0].intensity += delta_time * 1000000;
	if (input.keyboard.keys_pressed[GLFW_KEY_H]) {
		light[0].intensity = 3000000.0f;
	}

	if (light[0].intensity < 0)
		light[0].intensity = 0;

	Scene::update(delta_time, input);
}