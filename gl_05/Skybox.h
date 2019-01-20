#pragma once

#include "Node.h"
#include <vector>

namespace engine
{
	class SkyBox : public Node
	{
	public:
		SkyBox();
		~SkyBox();

		void generate(float size, glm::vec3 color, std::string pathToFile = "");

		/*void loadTexture(std::vector<std::string> faces);
		void render();*/
	};
}