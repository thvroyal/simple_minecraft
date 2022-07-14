#pragma once

#include "Mesh.h"

class Cube
{
public:
	GLfloat centerX, centerY, centerZ, edgeLength;

	void CreateCube();
	void DrawCube();
	~Cube();
};

