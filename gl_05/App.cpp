#include "App.h"
#include "Camera.h"

// STD
#include <chrono>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

Input App::input;

void App::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS)
	{
		input.keyboard.keys_pressed[key] = true;
	}
	if (action == GLFW_RELEASE)
	{
		input.keyboard.keys_pressed[key] = false;
	}
}

App::App()
{
	is_running = false;
	settings.width = 1280;
	settings.height = 720;
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
		time_d = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start);
		time_start = time_end;

		static long long time_avg = 0;
		static long long time_refresh = 0;
		time_avg = (time_avg + time_d.count()) / 2;
		time_refresh += time_d.count();

		if (time_refresh > 500000)
		{
			time_refresh = 0;
			std::ostringstream time_string;
			time_string << time_d.count() / 1000.0 << " ms";
			glfwSetWindowTitle(window, (std::string("GKOM - drezyna | ") + time_string.str()).c_str());
		}
		render();
		logic();
	}

	return;
}

void App::logic()
{
	glfwGetCursorPos(window, &input.mouse.pos_x, &input.mouse.pos_y);
	glfwSetCursorPos(window, 0, 0);
	
	glfwPollEvents();
	is_running = !glfwWindowShouldClose(window);

	scene.update(time_d.count() / 1000000.0f, input);
}

void App::render()
{
	scene.render();

	static int n = 10; // ilosc klatek do motion blur
	static int i = 1;
	if (i == 1)
		glAccum(GL_LOAD, 1.0f/n);
	else
		glAccum(GL_ACCUM, 1.0f/n);
	++i;

	if (i >= n)
	{
		i = 1;
		glAccum(GL_RETURN, 1.0f);
		glfwSwapBuffers(window);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
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
		glfwWindowHint(GLFW_SAMPLES, 4);

		window = glfwCreateWindow(settings.width, settings.height, "GKOM - Drezyna", nullptr, nullptr);
		if (window == nullptr)
			throw std::exception("GLFW window not created");

		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, key_callback);

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetCursorPos(window, 0, 0);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw std::exception("GLEW Initialization failed");
	}
	catch( std::exception ex )
	{
		std::cout << ex.what() << std::endl;
		return false;
	}

	glfwSwapInterval(0);
	glViewport(0, 0, settings.width, settings.height);
	glEnable(GL_DEPTH_TEST);

	scene.init(settings.width/float(settings.height));
	
	is_running = true;

	return true;
}

