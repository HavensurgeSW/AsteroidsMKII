#pragma once
#include "raylib.h"


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
	static int activeMissiles;

public:
	Missile(Vector2 pos, Vector2 force);
	~Missile();
	void update();
	void draw();

	Vector2 getCenter();
	bool getActive();
	void setActive(bool a);

	void updateVec(Vector2 p, Vector2 f);

	static int getMagPos();
	static void reloadMag();
private:
	void move();
	void screenLimits();
	void zero();
};