#version 330

uniform float time;
uniform vec2 resolution;


float hash(vec2 p) {
    return fract(1e4 * sin(17.0 * p.x + p.y * 0.1) * (0.1 + abs(sin(p.y * 13.0 + p.x))));
}

float noise(vec2 x) {
	vec2 i = floor(x);
	vec2 f = fract(x);

	float a = hash(i);
	float b = hash(i + vec2(1.0, 0.0));
	float c = hash(i + vec2(0.0, 1.0));
	float d = hash(i + vec2(1.0, 1.0));

	vec2 u = f * f * (3.0 - 2.0 * f);
	return mix(a, b, u.x) + (c - a) * u.y * (1.0 - u.x) + (d - b) * u.x * u.y;
}

#define NUM_OCTAVES 5

float fbm (vec2 _st) {
    float v = 0.0;
    float a = 0.5;
    vec2 shift = vec2(0);

    mat2 rot = mat2(cos(0.5), sin(0.5),
                    -sin(0.5), cos(0.50));

    for (int i = 0; i < NUM_OCTAVES; ++i) {
        v += a * noise(_st);
        _st = _st * 13.0 + shift;
        a *= clamp(time * 0.0003, 0.0, 0.4);
        //shift = -vec2(time * 0.001);
    }
    return v;
}

void main() {
    vec2 st = gl_FragCoord.xy/resolution.xy * 2;

    vec3 color = vec3(0.613, 0.718, 0.886);

    vec2 q = vec2(0.);
    q.x = fbm(st + 0.0001*time);
    q.y = fbm(st + vec2(1.));

    vec2 r = vec2(0.);
    r.x = fbm(st + 1.0*q + vec2(9.7,2.2)+ 0.00015*time);
    r.y = fbm(st + 1.0*q + vec2(time * 0.0001)+ 0.000126*time);

    float f = fbm(st+r);

    f = f*f*f+.6*f*f+.5*f;
    gl_FragColor = vec4(f * color, 0.45);
}


/*
float snow(vec2 uv, float scale) {
    float w = smoothstep(1.0, 0.0, -uv.y * (scale / 10.0));
    
    if (w < 0.1) {
      return 0.0;
    }
    
    float c = time * 0.001 / scale;
    
    // Fall to left:
    // uv += clock;
    
    uv.y += c;
    uv.x -= c;

    uv.y += c * 2.0;
    uv.x += cos(uv.y + time * 0.0001 * 0.5) / scale;
    uv   *= scale;

    vec2 s = floor(uv);
    vec2 f = fract(uv);
    vec2 p = vec2(0.0);

    float k = 3.0;
    float d = 0.0;
    
    p = 0.5 + 0.35 * sin(11.0 * fract(sin((s + p + scale) * mat2(7, 3, 6, 5)) * 5.0)) - f;
    d = length(p);
    k = min(d, k);

    k = smoothstep(0.0, k, sin(f.x + f.y) * 0.01);
    return k * w;
}

void main (void) {
    float size = mix(min(resolution.x, resolution.y), max(resolution.x, resolution.y), 0.5);
    vec2 uv = (gl_FragCoord.xy * 2.0 - resolution.xy) / size;
    float c = smoothstep(1.0, 0.0, clamp(uv.y * 0.1 + 0.75, 0.0, 0.75));

    c += snow(uv, 5.0) * 0.3;
    c += snow(uv, 2.5) * 0.5;
    c += snow(uv, 2.0) * 0.8;
    c += snow(uv, 6.0);
    c += snow(uv, 6.5);

    gl_FragColor = vec4(vec3(c), 1.0); // 0.0

    if (gl_FragColor.r < 0.5) {
        discard;
    }
}
*/