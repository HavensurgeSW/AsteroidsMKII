#include "player.h"

Player::Player()
{
	pos.x = GetScreenWidth()/2;
	pos.y = GetScreenHeight()/2;
	speed.x = 0.0f;
	speed.y = 0.0f;
	acceleration = 0.0f;
	rotation = 0.0f;
	radius = 22.5f;

	sprite = LoadTexture("res/player.png");
}

Player::~Player()
{
}


Vector2 Player::getPos()
{
	return pos;
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
	pos.x = 0.0f;
	pos.y = 0.0f;
	speed.x = 0.0f;
	speed.y = 0.0f;
	acceleration = 0.0f;
}

void Player::update()
{
}

void Player::draw()
{
	DrawCircle(pos.x, pos.y, radius, RED);
	DrawTexturePro(sprite, Rectangle{ 0,0,(float)sprite.width,(float)sprite.height },Rectangle{ pos.x, pos.y, (float)sprite.width *1.5f,(float)sprite.height * 1.5f },
		Vector2{ ((float)sprite.width * 1.5f) / 2, ((float)sprite.height * 1.5f) / 2 }, rotation, WHITE); //30width texture amplified to fit 45pix diameter.
}
