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

//		for (int i = 0; i < 5; i++) //Missile MAG size is 5.
//		{
//
//#if _DEBUG
//			cout << "Mag Size creation: " << i << endl;
//#endif
//		}

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
	Vector2 Player::getCenter()
	{
		Vector2 result;
		result.x = pos.x - radius;
		result.y = pos.y - radius;
	
		return result;
	}
	void Player::zero()
	{
		pos.x = static_cast<float>(GetScreenWidth() / 2);
		pos.y = static_cast<float>(GetScreenHeight() / 2);
		force.x = 0.0f;
		force.y = 0.0f;
	}

	void Player::shoot()
	{

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			missiles.push_back(new Missile(pos, force));
			
		}

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

		for (size_t i = 0; i < missiles.size(); i++){
			missiles[i]->update();
		}

		screenLimit();
	}

	void Player::draw()
	{
		DrawTexturePro(sprite, Rectangle{ 0,0,(float)sprite.width,(float)sprite.height }, Rectangle{ pos.x, pos.y, (float)sprite.width * 1.5f,(float)sprite.height * 1.5f },
			Vector2{ ((float)sprite.width * 1.5f) / 2, ((float)sprite.height * 1.5f) / 2 }, rotation, WHITE); //30width texture amplified to fit 45pix diameter.

		for (size_t i = 0; i < missiles.size(); i++) {
			missiles[i]->draw();
		}
	}

	//PRIVATE - (Update)
	void Player::move()
	{
		force.x = sin(rotation * DEG2RAD) * acceleration;
		force.y = cos(rotation * DEG2RAD) * acceleration;
	}

	void Player::followMouse()
	{
		rotation = atan2f(GetMousePosition().y - pos.y, GetMousePosition().x - pos.x);
		rotation = (rotation * 180 / PI) + 90; //+90 for texture to point properly

	}

	void Player::screenLimit()
	{
		if (pos.x > GetScreenWidth() + radius) pos.x = -radius;
		else if (pos.x < 0 - radius) pos.x = GetScreenWidth() + radius;
		if (pos.y > GetScreenHeight() + radius) pos.y = -radius;
		else if (pos.y < 0 - radius) pos.y = GetScreenHeight() + radius;
	}
}
