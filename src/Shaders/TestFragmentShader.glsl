#version 330

in vec2 tex_coord;

uniform sampler2D in_texture;
uniform float time;

void main() {
	

	gl_FragColor = texture2D(in_texture, tex_coord);

	if (gl_FragColor.a == 0.f) {
		discard;
	}

	/*
	vec2 coord = tex_coord;
    coord.x += sin(radians(time + coord.y * 500)) * 0.07;
    coord.y += cos(radians(time + coord.x * 250)) * 0.03;
    vec4 pixel_color = texture2D(in_texture, coord);

	gl_FragColor = pixel_color;

	if (gl_FragColor.a == 0.f) {
		discard;
	}
	*/
}