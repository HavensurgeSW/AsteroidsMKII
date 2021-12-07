#include <cmath>
#include <iostream>

#include "player.h"

using namespace std;



Player::Player()
{
	pos.x = GetScreenWidth()/2;
	pos.y = GetScreenHeight()/2;
	force.x = 0.0f;
	force.y = 0.0f;
	acceleration = 0.0f;
	rotation = 0.0f;
	radius = 22.5f;

	sprite = LoadTexture("res/player.png");
}

Player::~Player()
{
	UnloadTexture(sprite);
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
	force.x = 0.0f;
	force.y = 0.0f;
	acceleration = 0.0f;
}

void Player::input()
{
	
}

void Player::update()
{
	followMouse();
}

void Player::draw()
{
	DrawTexturePro(sprite, Rectangle{ 0,0,(float)sprite.width,(float)sprite.height },Rectangle{ pos.x, pos.y, (float)sprite.width *1.5f,(float)sprite.height * 1.5f },
		Vector2{ ((float)sprite.width * 1.5f) / 2, ((float)sprite.height * 1.5f) / 2 }, rotation, WHITE); //30width texture amplified to fit 45pix diameter.
}

//PRIVATE - (Update)
void Player::followMouse()
{
	//rotation = atan2f(GetMousePosition().y - pos.y, GetMousePosition().x - pos.x * (180.0f / PI));
}
