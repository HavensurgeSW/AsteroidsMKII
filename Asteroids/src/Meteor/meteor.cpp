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
		sprite = LoadTexture("res/smallMeteor.png");
		id = 0;
		
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

	Vector2 Meteor::getCenter()
	{
		Vector2 result;
		result.x = pos.x - radius;
		result.y = pos.y - radius;

		return result;
	}

	void Meteor::explode()
	{
	}

	void Meteor::setSpeed(Vector2 f)
	{
		force = f;
	}

	int Meteor::getBMAmount()
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
			//DrawCircle(static_cast<int>(pos.x), static_cast<int>(pos.y), radius, SKYBLUE);
			DrawTexturePro(sprite,
				Rectangle{ 0,0,(float)sprite.width,(float)sprite.height },
				Rectangle{ pos.x, pos.y, (float)sprite.width * 2.8f,
				(float)sprite.height * 2.8f },
				Vector2{ ((float)sprite.width * 2.8f) / 2, ((float)sprite.height * 2.8f) / 2 },
				rotation,
				WHITE); //30width texture amplified to fit 45pix diameter.
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
		}
	}
}
