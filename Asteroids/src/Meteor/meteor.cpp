#include "meteor.h"
#include <iostream>
using namespace std;
namespace MK2 {

	Meteor::Meteor(int type)
	{
		Rectangle safeArea;
		safeArea.width = 200;
		safeArea.height = 200;
		safeArea.x = GetScreenWidth()/2 - safeArea.width/2 ;
		safeArea.y = GetScreenHeight() / 2 - safeArea.height / 2;


		do {
			pos = { static_cast<float>(GetRandomValue(0,GetScreenWidth())), static_cast<float>(GetRandomValue(0, GetScreenHeight())) };
		} while (CheckCollisionPointRec(pos, safeArea));

		randomSpeed();
		rotation = 0;

		id = type;
		atlas[0] = LoadTexture("res/bigMeteor.png");
		atlas[1] = LoadTexture("res/midMeteor.png");
		atlas[2] = LoadTexture("res/smallMeteor.png");
		death = LoadSound("res/muffleExplosion.ogg");

	
		switch (id)
		{
		case 0:
			sprite = atlas[0];
			radius = 40;
			active = true;
			break;
		case 1:
			sprite = atlas[1];
			radius = 30;
			active = false;
			break;
		case 2:
			sprite = atlas[2];
			radius = 15;
			active = false;
			break;
		default:
			break;
		}
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
		result.x = pos.x;
		result.y = pos.y;

		return result;
	}

	void Meteor::explode()
	{
		PlaySound(death);
	}

	Vector2 Meteor::getPos()
	{
		return pos;
	}

	void Meteor::setSpeed(Vector2 f)
	{
		force = f;
	}

	void Meteor::setPos(Vector2 p)
	{
		pos = p;
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
			switch (id)
			{
			case 0:
				DrawTexturePro(sprite,
					Rectangle{ 0,0,(float)sprite.width,(float)sprite.height },
					Rectangle{ pos.x, pos.y, (float)sprite.width * 2.8f,
					(float)sprite.height * 2.8f },
					Vector2{ ((float)sprite.width * 2.8f) / 2, ((float)sprite.height * 2.8f) / 2 },
					rotation,
					WHITE); //30width texture amplified to fit 45pix diameter.
				break;
			case 1:
				DrawTexturePro(sprite,
					Rectangle{ 0,0,(float)sprite.width,(float)sprite.height },
					Rectangle{ pos.x, pos.y, (float)sprite.width * 1.9f,
					(float)sprite.height * 1.9f },
					Vector2{ ((float)sprite.width * 1.9f) / 2, ((float)sprite.height * 1.9f) / 2 },
					rotation,
					WHITE); //30width texture amplified to fit 45pix diameter.
				break;
			case 2:
				DrawTexturePro(sprite,
					Rectangle{ 0,0,(float)sprite.width,(float)sprite.height },
					Rectangle{ pos.x, pos.y, (float)sprite.width * 1.0f,
					(float)sprite.height * 1.0f },
					Vector2{ ((float)sprite.width * 1.0f) / 2, ((float)sprite.height * 1.0f) / 2 },
					rotation,
					WHITE); //30width texture amplified to fit 45pix diameter.
				break;
			default:
				break;
			}
			//DrawCircle(static_cast<int>(pos.x), static_cast<int>(pos.y), radius, SKYBLUE);
			
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

	void Meteor::resetMeteor()
	{
		Rectangle safeArea;
		safeArea.width = 200;
		safeArea.height = 200;
		safeArea.x = GetScreenWidth() / 2 - safeArea.width / 2;
		safeArea.y = GetScreenHeight() / 2 - safeArea.height / 2;

		do {
			pos = { static_cast<float>(GetRandomValue(0,GetScreenWidth())), static_cast<float>(GetRandomValue(0, GetScreenHeight())) };
		} while (CheckCollisionPointRec(pos, safeArea));

		randomSpeed();
		rotation = 0;

		switch (id)
		{
		case 0:
			active = true;
			break;
		case 1:
			active = false;
			break;
		case 2:
			active = false;
			break;
		default:
			break;
		}

	}

	void Meteor::randomSpeed() 
	{
		force.x = static_cast<float>(GetRandomValue(-150, 150));
		force.y = static_cast<float>(GetRandomValue(-150, 150));

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
