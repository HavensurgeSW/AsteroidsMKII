#include "meteor.h"

Meteor::Meteor()
{
}

Meteor::~Meteor()
{
}

float Meteor::getRadius()
{
	return radius;
}

bool Meteor::getActive()
{
	return active;
}

void Meteor::setActive(bool a)
{
	active = a;
}

void Meteor::explode()
{
}

void Meteor::setSpeed(Vector2 f)
{
	force  = f;
}

void Meteor::update()
{
	movement();
}

void Meteor::draw()
{
	DrawCircle(pos.x, pos.y, radius, RED);
}

void Meteor::movement()
{
	if (active)
	{
		pos.x += force.x * GetFrameTime();
		pos.y += force.y * GetFrameTime();
	}
}
