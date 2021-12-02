#pragma once

#include <vector>
#include <gl/glew.h>
#include "../../glm/glm.hpp"

struct Vertex {
	Vertex(glm::vec3 position, glm::vec3 color = glm::vec3(1.f),
		glm::vec2 texCoord = glm::vec2(0)) 
		: position(position), color(color), texCoord(texCoord) {}

	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texCoord;
};

class Quad {
	private:
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;

		unsigned int VAO;
		unsigned int VBO[2];

		void initBuffers();

	public:
		Quad(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices);
		unsigned int getVAO();
};