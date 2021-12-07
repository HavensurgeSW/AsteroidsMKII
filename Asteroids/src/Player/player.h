#pragma once
#include "raylib.h"

class Player {
private:
	
	Vector2 pos;
	Vector2 force;
	float acceleration;
	float rotation;
	float radius;
	
	Texture2D sprite;	
public:
	Player();
	~Player();

	float getRotation();
	float getRadius();
	void zero();

	void input();
	void update();
	void draw();

private:
	void followMouse();
	void move();
};