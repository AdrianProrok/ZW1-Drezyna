#include "Skybox.h"

#include <iostream>
#include <string>
#include <vector>

#include <SOIL.h>

#include "Mesh.h"
#include "Cube.h"

namespace engine
{
	SkyBox::SkyBox()
	{

	}

	SkyBox::~SkyBox()
	{

	}

	void SkyBox::generate(float size, glm::vec3 color, std::string pathToFile)
	{
		setMesh(new Cube(size, color));
		mesh->translate(glm::vec3(0, -size/2.0f, 0));
		mesh->init();		

		if (pathToFile != "")
			mesh->loadTexture(pathToFile.c_str());
		setSelfIllumination(true);
	}
}