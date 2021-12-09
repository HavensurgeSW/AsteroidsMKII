#include "missile.h"
#include <cmath>
#include <iostream>
using namespace std;

int Missile::missileAmount = 0;
int Missile::activeMissiles = 0;

Missile::Missile(Vector2 pos, Vector2 force){
	this->pos = pos;
	this->force.x = force.x * 1.5f;
	this->force.y = force.y * 1.5f;

	radius = 3.0f;
	rotation = 0;
	active = false;
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
	if (active)
	{
		move();
		screenLimits();
	}
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

float Missile::getRadius()
{
	return radius;
}

bool Missile::getActive()
{
	return active;
}

void Missile::setActive(bool a)
{
	active = a;
}

void Missile::updateVec(Vector2 p, Vector2 f)
{
	activeMissiles++;
	pos = p;

	rotation = atan2f(GetMousePosition().y - pos.y, GetMousePosition().x - pos.x);
	rotation = (rotation * 180 / PI) + 90; //+90 for texture to point properly
	cout << rotation << endl;
	cout << "Mag Pos: " << activeMissiles << endl;

	force.x = f.x * 1.5f;
	force.y = f.y * 1.5f;
}

int Missile::getMagPos()
{
	return activeMissiles;
}

void Missile::reloadMag(){
	activeMissiles = 0;
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
	if (pos.x > GetScreenWidth()) {
		zero();
		activeMissiles--;
		cout << "BEGONE DERECHA" << endl;
	}
	else if (pos.x < 0 - radius) {
		zero();
		activeMissiles--;
		cout << "BEGONE IZQUIERDA" << endl;
	}

	if (pos.y > GetScreenHeight() + radius) {
		zero();	
		activeMissiles--;
		cout << "BEGONE ABAJO" << endl;
	}else if (pos.y < 0 - radius) {
		zero();
		activeMissiles--;
		cout << "BEGONE ARRIBA" << endl;
	}	
}

void Missile::zero()
{
	this->pos = pos;
	this->force.x = force.x * 1.5f;
	this->force.y = force.y * 1.5f;

	radius = 3.0f;
	rotation = 0;
	active = false;
}

