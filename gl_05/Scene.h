#pragma once

#include "Node.h"
#include "Mesh.h"
#include "Material.h"

#include <vector>

class Scene
{
public:
	Scene();
	~Scene();

	void render();

protected:
	Node* root_node;
	std::vector<Material> materials;
	std::vector<Mesh> meshes;
};