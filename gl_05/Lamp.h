#pragma once
#include "Node.h"
#include "Mesh.h"
#include "Light.h"

class Lamp : public engine::Node
{
public:
	Lamp();
	~Lamp();

	void generate(engine::Mesh* mesh);
	virtual void update(float delta_time, glm::mat4 trans);

private:
	engine::Light light;
};
