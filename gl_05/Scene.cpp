#include "Scene.h"

Scene::Scene()
{
	root_node = nullptr;
}

Scene::~Scene()
{
}

void Scene::render()
{
	if( root_node )
		root_node->render();
}