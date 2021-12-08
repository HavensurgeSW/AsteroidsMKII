#include "player.h"

#include <cmath>
#include <iostream>

using namespace std;


namespace MK2 {
	Player::Player()
	{
		pos.x = static_cast<float>(GetScreenWidth() / 2);
		pos.y = static_cast<float>(GetScreenHeight() / 2);
		force.x = 0.0f;
		force.y = 0.0f;
		acceleration = 15.0f;
		rotation = 0.0f;
		radius = 22.5f;

		sprite = LoadTexture("res/player.png");
	}

	Player::~Player()
	{
		UnloadTexture(sprite);
	}


	float Player::getRotation()
	{
		return rotation;
	}
	float Player::getRadius()
	{
		return radius;
	}
	void Player::zero()
	{
		pos.x = static_cast<float>(GetScreenWidth() / 2);
		pos.y = static_cast<float>(GetScreenHeight() / 2);
		force.x = 0.0f;
		force.y = 0.0f;
	}

	void Player::input()
	{
#if _DEBUG
		if (IsKeyPressed(KEY_H))
		{
			zero();
		}
#endif
	}

	void Player::accelerate()
	{
		followMouse();
		move();
	}

	void Player::update()
	{
		pos.x += (force.x * acceleration * GetFrameTime());
		pos.y -= (force.y * acceleration * GetFrameTime());
	}

	void Player::draw()
	{
		DrawTexturePro(sprite, Rectangle{ 0,0,(float)sprite.width,(float)sprite.height }, Rectangle{ pos.x, pos.y, (float)sprite.width * 1.5f,(float)sprite.height * 1.5f },
			Vector2{ ((float)sprite.width * 1.5f) / 2, ((float)sprite.height * 1.5f) / 2 }, rotation, WHITE); //30width texture amplified to fit 45pix diameter.
	}

	//PRIVATE - (Update)
	void Player::followMouse()
	{
		rotation = atan2f(GetMousePosition().y - pos.y, GetMousePosition().x - pos.x);
		rotation = (rotation * 180 / PI) + 90; //+90 for texture to point properly
	}

	void Player::move()
	{
		force.x = sin(rotation * DEG2RAD) * acceleration;
		force.y = cos(rotation * DEG2RAD) * acceleration;
	}
}
