#include "App.h"
#include "Camera.h"

// STD
#include <chrono>
#include <iostream>
#include <string>
#include <sstream>

Keyboard App::keyboard;
Mouse App::mouse;
Gamepad App::gamepad;

void App::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
		keyboard.W = true;
	if (key == GLFW_KEY_W && action == GLFW_RELEASE)
		keyboard.W = false;

	if (key == GLFW_KEY_A && action == GLFW_PRESS)
		keyboard.A = true;
	if (key == GLFW_KEY_A && action == GLFW_RELEASE)
		keyboard.A = false;

	if (key == GLFW_KEY_S && action == GLFW_PRESS)
		keyboard.S = true;
	if (key == GLFW_KEY_S && action == GLFW_RELEASE)
		keyboard.S = false;

	if (key == GLFW_KEY_D && action == GLFW_PRESS)
		keyboard.D = true;
	if (key == GLFW_KEY_D && action == GLFW_RELEASE)
		keyboard.D = false;

	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		keyboard.E = true;
	if (key == GLFW_KEY_E && action == GLFW_RELEASE)
		keyboard.E = false;

	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
		keyboard.Q = true;
	if (key == GLFW_KEY_Q && action == GLFW_RELEASE)
		keyboard.Q = false;
}
void App::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	mouse.diff_x = mouse.pos_x - xpos;
	mouse.diff_y = mouse.pos_y - ypos;
	mouse.pos_x = xpos;
	mouse.pos_y = ypos;

	std::cout << "Pozycja x: " << mouse.diff_x << std::endl;
	std::cout << "Pozycja y: " << mouse.diff_y << std::endl;
	//glfwSetCursorPos(window, 0, 0);
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
		time_d = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start);
		time_start = time_end;
		//std::cout << "Time: " << time_d.count() << "ms\n";
		std::ostringstream time_string;
		time_string << time_d.count() << "ms";
		glfwSetWindowTitle(window, (std::string("GKOM - drezyna | Czas renderowania: ") + time_string.str()).c_str() );

		render();
		logic();
		//scene.getCamera()->update(glm::vec3(0.0f, 0.0f, -0.5f*time_d.count() / 1000.0f), glm::vec3(0.0f,0.0f,5.0f));
		scene.update(time_d.count() / 1000000.0f); // DO ZMIANY !!!
	}

	return;
}

void App::logic()
{
	double xpos;
	double ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	glfwSetCursorPos(window, 0, 0);
	//mouse.diff_x = 0;
	//mouse.diff_y = 0;
	glfwPollEvents();
	is_running = !glfwWindowShouldClose(window);

	scene.getCamera()->update(time_d.count() / 1000000.0f, keyboard.W, keyboard.S, keyboard.A, keyboard.D, keyboard.E, keyboard.Q, ypos, xpos);
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
		//glfwSetCursorPosCallback(window, cursor_position_callback);

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

	scene.init();

	is_running = true;

	return true;
}

