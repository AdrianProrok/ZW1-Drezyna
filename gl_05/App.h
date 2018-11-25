#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include "shprogram.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// STD
#include <chrono>
#include <iostream>
using namespace std;


#include "Scene.h"

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

	Scene scene;

	bool init();

	void render();
	void logic();
};