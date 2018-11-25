#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include "shprogram.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
using namespace std;
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>

class App 
{
public:
	App();
	~App();
	void run();

private:
	bool is_running;
	int width;
	int height;

	GLFWwindow* window;

	bool init();

	void render();
	void logic();
};