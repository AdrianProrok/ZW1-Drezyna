#include "World.h"

void World::init()
{
	draisine.generate();
	root_node = &draisine;
}