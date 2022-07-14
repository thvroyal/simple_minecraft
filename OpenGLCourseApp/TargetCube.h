#pragma once

#include "Mesh.h"
#include <vector>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class TargetCube
{
public:
	glm::vec3 centerPoint;
	std::vector<Mesh*> meshList;

	TargetCube();
	void ProcessInput();
	void Update(GLuint uniformModel);
	void keyControl(bool* keys, GLfloat deltaTime);
	void DrawSomeCube(GLuint uniformModel);

private:
	Mesh *targetCube;
};

