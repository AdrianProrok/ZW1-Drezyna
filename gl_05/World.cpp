#include "World.h"
#include "ShaderProgram.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
	
	light.color = { 1.0f, 1.0f, 1.0f };
	light.intensity = 1.0f;
	light.position = { 0.0f, 15.0f, 0.0f };

	GLuint lightPosLoc = glGetUniformLocation(getCurrentShaderProgram()->get_programID(), "lightPos");
	glUniform3fv(lightPosLoc, 1, glm::value_ptr(light.position));

	GLuint lightColorLoc = glGetUniformLocation(getCurrentShaderProgram()->get_programID(), "lightColor");
	glUniform3fv(lightColorLoc, 1, glm::value_ptr(light.color));

	Scene::init(aspect_ratio);
}

void World::render()
{	
	Scene::render();
}

void World::update(float delta_time, const Input& input)
{	
	Scene::update(delta_time, input);
}