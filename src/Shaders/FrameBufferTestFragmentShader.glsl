#version 330

uniform sampler2D screen_texture;

in vec2 tex_coord;

void main() {
	gl_FragColor = texture2D(screen_texture, tex_coord);
}