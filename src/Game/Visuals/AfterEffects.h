#pragma once

#include "Core/Quad.h"
#include "Core/Shader.h"

class AfterEffect {
	public:
		AfterEffect(Shader* shader);

		void draw();


		Shader* shader;

		glm::vec3 size;
		glm::vec3 position;
};