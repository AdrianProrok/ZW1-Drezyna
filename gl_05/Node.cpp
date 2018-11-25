#include "Node.h"

void Node::render()
{
	// 1. Dane o przesuni�ciu, skalowaniu i obrocie dla shadera
	// 2. Rysowanie
	// 3. Rysowanie wszystkich dzieci
	
	for (auto& child : children)
		child->render();
}