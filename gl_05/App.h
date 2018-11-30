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

// Do poprawy, to jest tak na szybko..
struct Keyboard
{
	bool W;
	bool A;
	bool S;
	bool D;
	bool E;
	bool Q;
};

// Tak samo do poprawy
struct Mouse
{
	double pos_x;
	double pos_y;
	double diff_x;
	double diff_y;
};

struct Gamepad
{
	float left_horizontal;
	float left_vertical;

	float right_horizontal;
	float right_vertical;
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

	ShaderProgram* theProgram; // tymczasowe

	bool init();

	void render();
	void logic();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static Keyboard keyboard;
	static Mouse mouse;
	static Gamepad gamepad;
};