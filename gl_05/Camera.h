#pragma once
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Keyboard;
class Mouse;

namespace engine
{
	class Scene;
	class Camera
	{
	public:
		Camera();
		~Camera();

		void setScene(Scene* scene);
		Scene* getScene();

		// Przesuniêcie i obrót o dok³adn¹ wartoœæ
		void update(glm::vec3 d_position, glm::vec3 d_rotation);

		void set(glm::vec3 position, glm::vec3 rotation);
		void setProj(float aspect_ratio, float view_angle);

		float speed;
		float aspect_ratio;
		float view_angle;
	private:
		Scene* scene;

		glm::vec3 position;
		glm::vec3 rotation;

		glm::mat4 view;
		glm::mat4 projection;

		
	};
}