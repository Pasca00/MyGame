#version 330

in vec2 tex_coord;

uniform sampler2D in_texture;

void main() {
	gl_FragColor = vec4(0.5f, 0.22f, 0.21f, 1.f); 
}