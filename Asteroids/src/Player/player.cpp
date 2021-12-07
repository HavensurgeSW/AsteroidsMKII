#include "player.h"

Player::Player()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	speed.x = 0.0f;
	speed.y = 0.0f;
	acceleration = 0.0f;
	rotation = 0.0f;
	radius = 10.0f;

	sprite = LoadTexture("res/NULL");
}

Player::~Player()
{
}

void Player::setPos()
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
}
