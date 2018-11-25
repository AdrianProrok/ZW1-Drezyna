#include "App.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	cout << key << endl;
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
	std::cout << "Koniec.\n";
	glfwDestroyWindow(window);
	glfwTerminate();
}

void App::run() 
{
	if (!init())
		return;

	//auto time_start = std::chrono::system_clock::now();
	while (is_running)
	{
		//auto time_end = std::chrono::system_clock::now();
		//std::chrono::duration<float> time_diff = time_end - time_start;
		//time_start = time_end;

		render();
		logic();
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
			throw exception("App is already running!");

		if (glfwInit() != GL_TRUE)
			throw exception("GLFW initialization failed");

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

	is_running = true;

	return true;
}

