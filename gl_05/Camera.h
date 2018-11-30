#pragma once
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace engine
{
	class Scene;
	class Camera
	{
	public:
		void setScene(Scene* scene);
		Scene* getScene();

		// Przesuni�cie klawiatur�, obr�t myszk�
		void update(float delta_time, bool forward, bool backward, bool left, bool right, bool up, bool down, double mouse_x, double mouse_y);

		// Gamepad
		// void update(float delta_time, glm::vec2 left_analog, glm::vec2 right_analog);

		// Przesuni�cie i obr�t o dok�adn� warto��
		void update(glm::vec3 d_position, glm::vec3 d_rotation);

		void set(glm::vec3 position, glm::vec3 rotation);

	private:
		Scene* scene;

		glm::vec3 position;
		glm::vec3 rotation;

		glm::mat4 view;
	};
}