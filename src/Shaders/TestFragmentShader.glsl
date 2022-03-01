#version 330

in vec2 tex_coord;

uniform sampler2D in_texture;
uniform float time;

uniform int render_flipped;
uniform int time_stop;

void main() {
	if (render_flipped == 1) {
		gl_FragColor = texture2D(in_texture, vec2(1 - tex_coord.x, tex_coord.y));
	} else {
		gl_FragColor = texture2D(in_texture, tex_coord);
	}

	if (time_stop == 1) {
		float div = clamp(time * 0.005, 0.95, 3.0);
		float average = (gl_FragColor.r + gl_FragColor.g + gl_FragColor.b) / div;

		gl_FragColor = vec4(vec3(average), gl_FragColor.a);
	}
}