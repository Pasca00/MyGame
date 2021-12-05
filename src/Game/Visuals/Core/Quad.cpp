#include "Quad.h"

Quad::Quad(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices) {
	this->vertices = vertices;
	this->indices = indices;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(2, &VBO[0]);

	glBindVertexArray(VAO);


	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec3)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(2 * sizeof(glm::vec3)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);

	if (glGetError()) {
		printf("ERROR GENERATING BUFFERS\n");
	}
}

unsigned int Quad::getVAO() {
	return VAO;
}

std::vector<unsigned int> Quad::getIndices() {
	return indices;
}
