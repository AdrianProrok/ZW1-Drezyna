#include "Cube.h"

namespace engine
{
	Cube::Cube()
	{
		vertices = {
		//  { {pos1,pos2,pos3}, {nor1,nor2,nor3}, {col1,col2,col3}, {u,v} }
			{{ 0.5f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  0.0f}},
			{{-0.5f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  0.0f}},
			{{-0.5f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  1.0f}},
			{{ 0.5f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  1.0f}},

			{{-0.5f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  0.0f}},
			{{-0.5f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  1.0f}},
			{{ 0.5f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  1.0f}},
			{{ 0.5f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  0.0f}},

			{{-0.5f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  0.0f}},
			{{-0.5f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  1.0f}},
			{{ 0.5f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  1.0f}},
			{{ 0.5f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  0.0f}},

			{{-0.5f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  0.0f}},
			{{-0.5f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  1.0f}},
			{{ 0.5f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  1.0f}},
			{{ 0.5f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  0.0f}},

			{{-0.5f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f,  0.0f}},
			{{-0.5f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f,  1.0f}},
			{{-0.5f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f,  0.0f}},
			{{-0.5f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f, 0.0f}, {1.0f,  1.0f}},

			{{ 0.5f, -0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f,  0.0f}},
			{{ 0.5f, -0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 1.0f}, {0.0f,  0.0f}},
			{{ 0.5f,  0.5f,  0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f,  1.0f}},
			{{ 0.5f,  0.5f, -0.5f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f,  1.0f}}
		};

		faces = {
			{0, 1, 2 },
			{0, 2, 3},
			{4, 5, 6},
			{4, 6, 7},
			{8, 9, 10},
			{8, 10, 11},
			{12, 13, 14},
			{12, 14, 15},
			{16, 17, 18},
			{18, 17, 19},
			{20, 21, 22},
			{20, 22, 23}
		};
	}
	Cube::~Cube()
	{

	}
}