#pragma once
#include "raylib.h"
#

class Missile {
private:
	Vector2 pos;
	Vector2 force;
	float radius;
	float rotation;
	bool active;
	Color color;

	Vector2 mouseVector;

	static int missileAmount;

public:
	Missile(Vector2 pos, Vector2 force);
	~Missile();
	void update();
	void draw();
	Vector2 getCenter();

private:
	void move();
	void screenLimits();
};