#include "Camera.h"
#include "Scene.h"
#include "App.h"
#include <glm/vec3.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
using namespace std;

namespace engine
{
	Camera::Camera()
	{
		speed = 5.0f;
	}

	Camera::~Camera()
	{

	}

	void Camera::setScene(Scene* scene)
	{
		this->scene = scene;
	}
	Scene* Camera::getScene()
	{
		return scene;
	}

	void Camera::update(glm::vec3 d_position, glm::vec3 d_rotation)
	{
		// Cofniêcie obrotu
		glm::mat4 new_view(1.0f);
		new_view = glm::rotate(new_view, glm::radians(rotation.x), glm::vec3(1, 0, 0)); // X
		new_view = glm::rotate(new_view, glm::radians(rotation.y), glm::vec3(0, 1, 0)); // Y
		//new_view = glm::rotate(new_view, glm::radians(d_rotation.z), glm::vec3(0, 0, 1)); // Z
		view = glm::transpose(new_view)*view;

		//position = glm::vec3(view*glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
		
		// Na³o¿enie nowego obrotu
		new_view = glm::mat4(1.0f);
		rotation = glm::mod(rotation + d_rotation, 360.0f);
		
		// Blokowanie zbyt du¿ego obrotu
		if (rotation.x < 270.0f && rotation.x > 180.0f)
			rotation.x = 270.0f;
		if (rotation.x > 90.0f && rotation.x < 180.0f)
			rotation.x = 90.0f;
		
		new_view = glm::rotate(new_view, glm::radians(rotation.x), glm::vec3(1, 0, 0)); // X
		new_view = glm::rotate(new_view, glm::radians(rotation.y), glm::vec3(0, 1, 0)); // Y
		//new_view = glm::rotate(new_view, glm::radians(d_rotation.z), glm::vec3(0, 0, 1)); // Z
		view = new_view * view;

		// Przesuniêcie
		new_view = glm::mat4(1.0f);
		new_view = glm::translate(new_view, d_position);
		view = new_view * view;

		GLuint viewLoc = glGetUniformLocation(scene->getCurrentShaderProgram()->get_programID(), "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	}

	void Camera::set(glm::vec3 position, glm::vec3 rotation)
	{
		view = glm::mat4(1.0f);
		view = glm::rotate(view, glm::radians(rotation.x), glm::vec3(1, 0, 0)); // X
		view = glm::rotate(view, glm::radians(rotation.y), glm::vec3(0, 1, 0)); // Y
		view = glm::rotate(view, glm::radians(rotation.z), glm::vec3(0, 0, 1)); // Z

		view = glm::translate(view, position);
		this->position = position;
		this->rotation = rotation;
	}

	void Camera::setProj(float aspect_ratio, float view_angle)
	{
		projection = glm::perspective(glm::radians(view_angle), aspect_ratio, 0.001f, 100.0f);

		GLuint projLoc = glGetUniformLocation(scene->getCurrentShaderProgram()->get_programID(), "projection");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		this->aspect_ratio = aspect_ratio;
		this->view_angle = view_angle;
	}
}