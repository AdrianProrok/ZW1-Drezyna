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
	camera.set(glm::vec3(0.0f, -4.0f, 15.0f), glm::vec3(0.0f, 180.0f, 0.0f));
	
	/*lights.push_back(&light[0]);
	lights.push_back(&light[1]);
	lights.push_back(&light[2]);
	lights.push_back(&light[3]);*/
	
	Scene::init(aspect_ratio);
}

void World::render()
{	
	Scene::render();
}

void World::update(float delta_time, const Input& input)
{	
	static unsigned int light_index = 0;
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
		light_index = 4;
	if (input.keyboard.keys_pressed[GLFW_KEY_5])
		light_index = 5;
	if (input.keyboard.keys_pressed[GLFW_KEY_6])
		light_index = 6;
	if (input.keyboard.keys_pressed[GLFW_KEY_7])
		light_index = 7;
	if (input.keyboard.keys_pressed[GLFW_KEY_8])
		light_index = 8;
	if (input.keyboard.keys_pressed[GLFW_KEY_9])
		light_index = 9;

	if (light_index == 0)
		light_sens = 1000000;
	else
		light_sens = 100;

	if (input.keyboard.keys_pressed[GLFW_KEY_U])
		ambientStrength -= delta_time * 0.5f;
	if (input.keyboard.keys_pressed[GLFW_KEY_I])
		ambientStrength += delta_time * 0.5f;
	if (lights.size() > light_index) {
		if (input.keyboard.keys_pressed[GLFW_KEY_J])
			lights[light_index]->intensity -= delta_time * light_sens;
		if (input.keyboard.keys_pressed[GLFW_KEY_K])
			lights[light_index]->intensity += delta_time * light_sens;
		if (lights[light_index]->intensity < 0)
			lights[light_index]->intensity = 0;
	}
	if( lights.size() > 0 )
		if (input.keyboard.keys_pressed[GLFW_KEY_H]) {
			lights[0]->intensity = 3000000.0f;
		}	
	if (ambientStrength < 0)
		ambientStrength = 0;

	Scene::update(delta_time, input);
}