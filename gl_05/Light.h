#pragma once

#include "RightRegularPrism.h"
#include "Node.h"

namespace engine
{
	class Light : public Node
	{
	public:
		void generate();

		glm::vec3 lightPos;
		glm::vec3 color;
		float intensity;

		void update(float delta_time, glm::mat4 trans);
	};
}