#pragma once

#include "Node.h"

class Scene
{
public:
	Scene();
	~Scene();

	void render();

private:
	Node* root_node;
	
};