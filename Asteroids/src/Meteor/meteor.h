#pragma once
#include "raylib.h"

class Meteor
{
private:
	Vector2 pos;
	Vector2 force;
	float maxSpeed;
	float rotation;
	float radius;
	bool active;

	Texture2D sprite;
public:
	Meteor();
	~Meteor();
	float getRadius();
	bool getActive();
	void setActive(bool a);
	void explode();
	void setSpeed(Vector2 s);
	void update();
	void draw();

private:
	void movement();
};