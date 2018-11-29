#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include "ShaderProgram.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "World.h"

#include <chrono>

using namespace engine;

struct AppSettings
{
	int width;
	int height;

};

class App 
{
public:
	App();
	~App();
	void run();

private:
	bool is_running;

	AppSettings settings;

	GLFWwindow* window;

	World scene;

	std::chrono::milliseconds time_d;

	ShaderProgram* theProgram; // tymczasowe

	bool init();

	void render();
	void logic();
};