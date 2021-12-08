#pragma once
#include "raylib.h"
namespace MK2 {
	class Player {
	private:

		Vector2 pos;
		Vector2 force;
		float acceleration;
		float rotation;
		float radius;

		Texture2D sprite;
	public:
		Player();
		~Player();

		float getRotation();
		float getRadius();
		void zero();

		void input();
		void accelerate();
		void update();
		void draw();

		void move();
	private:
		void followMouse();
	};
}