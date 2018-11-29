#include "App.h"

// STD
#include <chrono>
#include <iostream>
#include <string>
#include <sstream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

App::App()
{
	is_running = false;
	settings.width = 800;
	settings.height = 600;
}

App::~App()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void App::run() 
{
	if (!init())
		return;

	auto time_start = std::chrono::system_clock::now();
	while (is_running)
	{
		auto time_end = std::chrono::system_clock::now();
		time_d = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start);
		time_start = time_end;
		//std::cout << "Time: " << time_d.count() << "ms\n";
		std::ostringstream time_string;
		time_string << time_d.count() << "ms";
		glfwSetWindowTitle(window, (std::string("GKOM - drezyna | Czas renderowania: ") + time_string.str()).c_str() );

		render();
		logic();
		scene.update(time_d.count() / 1000.0f); // DO ZMIANY !!!
	}

	return;
}

void App::logic()
{
	glfwPollEvents();
	is_running = !glfwWindowShouldClose(window);
}

void App::render()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	scene.render();

	glfwSwapBuffers(window);
}

bool App::init()
{
	try
	{
		if (is_running)
			throw std::exception("App is already running!");

		if (glfwInit() != GL_TRUE)
			throw std::exception("GLFW initialization failed");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		window = glfwCreateWindow(settings.width, settings.height, "GKOM - Drezyna", nullptr, nullptr);
		if (window == nullptr)
			throw std::exception("GLFW window not created");

		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, key_callback);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw std::exception("GLEW Initialization failed");
	}
	catch( std::exception ex )
	{
		std::cout << ex.what() << std::endl;
		return false;
	}

	glViewport(0, 0, settings.width, settings.height);
	glEnable(GL_DEPTH_TEST);

	scene.init();

	is_running = true;

	return true;
}

