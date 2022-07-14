#include "TargetCube.h"
#include <glm\glm.hpp>
#include <vector>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\epsilon.hpp>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

unsigned int indices[] = {
	// front
	0, 1, 2,
	2, 3, 0,
	// right
	1, 5, 6,
	6, 2, 1,
	// back
	7, 6, 5,
	5, 4, 7,
	// left
	4, 0, 3,
	3, 7, 4,
	// bottom
	4, 5, 1,
	1, 0, 4,
	// top
	3, 2, 6,
	6, 7, 3
};

GLfloat coord = 0.25f;
GLfloat vertices[] = {
	//	x      y      z			u	  v			nx	  ny    nz
		-coord, -coord, coord,	    0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		coord, -coord, coord,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		coord, coord, coord,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		-coord, coord, coord,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		-coord, -coord, -coord,       0.0f, 0.0f,     0.0f, 0.0f, 0.0f,
		 coord, -coord, -coord,       1.0f, -1.0f,     0.0f, 0.0f, 0.0f,
		 coord,  coord, -coord,       2.0f, -1.0f,     0.0f, 0.0f, 0.0f,
		-coord,  coord, -coord,       1.0f, 1.0f,     0.0f, 0.0f, 0.0f,
};

TargetCube::TargetCube() {
	targetCube = new Mesh();
	centerPoint = glm::vec3(0.0f);
}

void TargetCube::Update(GLuint uniformModel) {
	this->targetCube->CreateMesh(vertices, indices, 64, 36);

	glm::mat4 model(1.0f);
	model = glm::translate(model, centerPoint);
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	this->targetCube->RenderMesh();
}

void TargetCube::DrawSomeCube(GLuint uniformModel)
{
	glm::mat4 model(1.0f);

	for (auto cube : meshList)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, cube->GetPosition());
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		cube->RenderMesh();
	}
}

void TargetCube::keyControl(bool* keys, GLfloat deltaTime)
{
	GLfloat dMove = 0.5f;
	glm::vec3 dX = glm::vec3(dMove, 0.0f, 0.0f),
		dY = glm::vec3(0.0f, dMove, 0.0f),
		dZ = glm::vec3(0.0f, 0.0f, dMove);

	if (keys[GLFW_KEY_0])
	{
		centerPoint += dX;
		_sleep(200);
	}
	if (keys[GLFW_KEY_1])
	{
		centerPoint -= dX;
		_sleep(200);
	}
	if (keys[GLFW_KEY_2])
	{
		centerPoint += dY;
		_sleep(200);
	}
	if (keys[GLFW_KEY_9])
	{
		centerPoint -= dY;
		_sleep(200);
	}
	if (keys[GLFW_KEY_3])
	{
		centerPoint += dZ;
		_sleep(200);
	}
	if (keys[GLFW_KEY_8])
	{
		centerPoint -= dZ;
		_sleep(200);
	}
	if (keys[GLFW_KEY_5])
	{
		// check if cube is existed, delete it
		bool isExisted = false;
		std::vector<Mesh*> newMeshList;
		for (auto cube : meshList)
		{
			glm::vec3 cubePos = cube->GetPosition();

			if (cubePos.x == centerPoint.x && cubePos.y == centerPoint.y && cubePos.z == centerPoint.z)
			{
				isExisted = true;
				continue;
			}
			else newMeshList.push_back(cube);
		}
		meshList = newMeshList;
		// else, create it
		if (isExisted == false) {
			Mesh* newCube = new Mesh();
			newCube->CreateMesh(vertices, indices, 64, 36);
			newCube->SetPosition(centerPoint);
			meshList.push_back(newCube);
		}

		_sleep(200);

	}
}