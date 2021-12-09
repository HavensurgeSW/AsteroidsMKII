#include "missile.h"
#include <cmath>
#include <iostream>
using namespace std;

int Missile::missileAmount = 0;

Missile::Missile(Vector2 pos, Vector2 force){
	this->pos = pos;
	this->force.x = force.x * 1.5f;
	this->force.y = force.y * 1.5f;

	radius = 3.0f;
	rotation = 0;
	active = true;
	color = WHITE;
	mouseVector = GetMousePosition();

	rotation = atan2f(mouseVector.y - pos.y, mouseVector.x - pos.x);
	rotation = (rotation * 180 / PI)+90;

	missileAmount++;
	cout << "SHOOT BITCH" << endl;
}

Missile::~Missile()
{
	missileAmount--;
	cout << "D E L E T E T H I S" << endl;
}

void Missile::update()
{
	move();
}

void Missile::draw()
{
	if (active)
	{
		DrawCircleV(getCenter(), radius, color);
	}
}

Vector2 Missile::getCenter()
{
		Vector2 result;
		result.x = pos.x - radius;
		result.y = pos.y - radius;

		return result;
}

//PRIVATE FUNCTIONS:
void Missile::move()
{
	if (active)
	{
		force.x = sin(rotation * DEG2RAD)*20;
		force.y = cos(rotation * DEG2RAD)*20;

		pos.x += force.x * 20 * GetFrameTime();
		pos.y -= force.y * 20 * GetFrameTime();
	}
}

void Missile::screenLimits()
{
	if (pos.x > GetScreenWidth() + radius)delete this;
	else if (pos.x < 0 - radius)delete this;
	if (pos.y > GetScreenHeight() + radius)delete this;
	else if (pos.y < 0 - radius)delete this;
}
