#include "meteor.h"
#include <iostream>
using namespace std;
namespace MK2 {
	int Meteor::bigMeteorCount = 0;

	Meteor::Meteor()
	{
		pos = { 100.0f,100.0f };
		randomSpeed();
		rotation = 0;
		radius = 40;
		active = true;
		bigMeteorCount++;
		sprite = LoadTexture("res/NULL");
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
		force = f;
	}

	int Meteor::getAmount()
	{
		return bigMeteorCount;
	}

	void Meteor::update()
	{
		movement();
		screenLimit();
	}

	void Meteor::draw()
	{
		if (active)
		{
			DrawCircle(static_cast<int>(pos.x), static_cast<int>(pos.y), radius, RED);
		}
	}

	void Meteor::movement()
	{
		if (active)
		{
			pos.x += force.x * GetFrameTime();
			pos.y += force.y * GetFrameTime();
		}
	}

	void Meteor::randomSpeed() 
	{
		force.x = static_cast<float>(GetRandomValue(90, 150));
		force.y = static_cast<float>(GetRandomValue(90, 150));

		cout << force.x << " " << force.y << endl;
	}
	void Meteor::screenLimit()
	{
		if (active)
		{
			if (pos.x > GetScreenWidth() + radius) pos.x = -radius;
			else if (pos.x < 0 - radius) pos.x = GetScreenWidth() + radius;
			if (pos.y > GetScreenHeight() + radius) pos.y = -radius;
			else if (pos.y < 0 - radius) pos.y = GetScreenHeight() + radius;

			cout << pos.x << " " << pos.y << endl;
		}
	}
}
