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

class Input
{
public:
	class Keyboard
	{
	public:
		bool keys_pressed[GLFW_KEY_LAST];
	};

	class Mouse
	{
	public:
		double pos_x;
		double pos_y;
	};

	struct Gamepad
	{
		float left_horizontal;
		float left_vertical;

		float right_horizontal;
		float right_vertical;

		float trigger;
	};

	Keyboard keyboard;
	Mouse mouse;
	Gamepad gamepad;

	void updateMouse(GLFWwindow* window);
	void updateGamepad();
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

	std::chrono::microseconds time_d;

	bool init();

	void render();
	void logic();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

	static Input input;
};