#version 330

layout(location = 0) in vec3 v_position;
layout(location = 0) in vec3 v_color;
layout(location = 0) in vec2 v_texture_coord;

uniform mat4 Model;
uniform mat4 Projection;

out vec2 tex_coord;

void main() {
	tex_coord = v_texture_coord;
	gl_Position = vec4(v_position, 0);
}