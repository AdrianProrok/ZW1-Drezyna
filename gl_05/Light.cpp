#include "Light.h"

namespace engine
{
	void Light::generate() {
		setMesh(new Cylinder(0.5f, 0.5f * sqrt(2) / 2, 4, color, glm::vec3(1.0f, 1.0f, 1.0f)));
		mesh->init();

		setSelfIllumination(true);
	}

	void Light::update(float delta_time, glm::mat4 trans) {
		Node::update(delta_time, trans);
		lightPos = glm::vec3(trans * glm::vec4(position,1.0f));
	}
}