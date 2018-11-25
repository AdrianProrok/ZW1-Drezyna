#include "App.h"

// STD
#include <chrono>
#include <iostream>
#include <string>

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
	std::cout << "Koniec.\n";

	delete theProgram;

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
		std::cout << "Time: " << time_d.count() << "ms\n";

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

	// TYMCZASOWO
	glm::mat4 trans;
	static GLfloat rot_angle = 0.0f;
	trans = glm::rotate(trans, -glm::radians(rot_angle), glm::vec3(1.0, 0.0, 0.0));
	rot_angle += 45.0f * time_d.count()/1000.0f;
	if (rot_angle >= 360.0f)
		rot_angle -= 360.0f;
	GLuint transformLoc = glGetUniformLocation(theProgram->get_programID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

	glm::mat4 camRot;
	camRot = glm::rotate(camRot, glm::radians(rot_angle), glm::vec3(0.0, 1.0, 0.0));
	glm::vec3 cameraPos = glm::vec3(camRot * glm::vec4(0.0f, 0.0f, -3.0f, 1.0f));
	glm::mat4 view;
	glm::mat4 projection;
	view = glm::lookAt(cameraPos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	projection = glm::perspective(glm::radians(45.0f), (GLfloat)settings.width / (GLfloat)settings.height, 0.1f, 100.0f);
	GLuint viewLoc = glGetUniformLocation(theProgram->get_programID(), "view");
	GLuint projLoc = glGetUniformLocation(theProgram->get_programID(), "projection");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	theProgram->Use();
	// -------------------------------

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

	theProgram = new ShaderProgram("gl_05.vert", "gl_05.frag");

	scene.init();

	is_running = true;

	return true;
}

