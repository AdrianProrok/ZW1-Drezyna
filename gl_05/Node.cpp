#include "Node.h"
#include "Mesh.h"
#include "Scene.h"

Node::Node()
{
	mesh = nullptr;
}

Node::~Node()
{

}

void Node::render()
{
	// 1. Dane o przesuniêciu, skalowaniu i obrocie dla shadera
	// 2. Rysowanie
	// 3. Rysowanie wszystkich dzieci
	
	if( mesh )
		mesh->render();

	for (auto& child : children)
		child->render();
}