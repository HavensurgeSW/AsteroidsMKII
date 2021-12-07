#pragma once
#include "raylib.h"

class Player {
private:
	
	Vector2 pos;
	Vector2 speed;
	float acceleration;
	float rotation;
	float radius;
	
	Texture2D sprite;
	
public:
	Player();
	~Player();

	Vector2 getPos();
	float getRotation();
	float getRadius();
	void zero();

	void update();
	void draw();
};