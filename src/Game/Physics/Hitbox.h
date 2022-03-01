#pragma once

struct Hitbox {
	float x;
	float y;
	float w;
	float h;

	Hitbox() : x(0), y(0), w(0), h(0) { }
	Hitbox(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) { }

	bool collides(Hitbox* hitbox) {
		return (x + w > hitbox->x) && (x <= hitbox->x + hitbox->w)
			&& (y < hitbox->y + hitbox->h) && (y + h > hitbox->y);
	}
};