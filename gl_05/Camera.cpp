#include "Camera.h"
#include "Scene.h"
#include <glm/vec3.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
using namespace std;

namespace engine
{
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
		//cout << "Position: " << position.x << " " << position.y << " " << position.z << endl;
		//cout << "Rotation: " << rotation.x << " " << rotation.y << " " << rotation.z << endl;

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

	void Camera::update(float delta_time, bool forward, bool backward, bool left, bool right, bool up, bool down, double mouse_x, double mouse_y)
	{
		// Na razie na sztywno
		update( glm::vec3((left - right)*delta_time, (down - up)*delta_time, (forward - backward)*delta_time), glm::vec3(mouse_x*0.1f,mouse_y*0.1f,0.0f) );
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
		/*update(glm::vec3(0.0f), glm::vec3(0.0f));
		glm::vec3 pos = glm::vec3(view*glm::vec4(0.0f,0.0f,0.0f,1.0f));
		cout << "Position: " << pos.x << " " << pos.y << " " << pos.z << endl;*/
	}
}