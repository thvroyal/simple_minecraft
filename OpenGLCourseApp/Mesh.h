#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

class Mesh
{
public:
	Mesh();

	void CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);
	void RenderMesh();
	void ClearMesh();
	void SetPosition(glm::vec3 pos);
	glm::vec3 GetPosition();

	~Mesh();

private:
	GLuint VAO, VBO, IBO;
	GLsizei indexCount;
	glm::vec3 position;
};

