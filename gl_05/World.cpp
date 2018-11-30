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

void World::init()
{
	// Najpierw shader, bo potem ró¿ne rzeczy s¹ do niego ³adowane
	setCurrentShaderProgram(new engine::ShaderProgram("gl_05.vert", "gl_05.frag"));
	shader_program->Use();

	// Potem RootNode
	setRootNode(&draisine);
	
	draisine.generate();

	// I ca³a reszta

	camera.setScene(this);
	camera.set(glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f));
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	
	GLuint projLoc = glGetUniformLocation(shader_program->get_programID(), "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void World::render()
{	
	Scene::render();
}

void World::update(float delta_time)
{	
	Scene::update(delta_time);
}