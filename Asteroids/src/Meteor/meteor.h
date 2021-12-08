#pragma once
#include "raylib.h"

namespace MK2 {
	class Meteor
	{
	private:
		Vector2 pos;
		Vector2 force;
		float rotation;
		float radius;
		bool active;

		static int bigMeteorCount;

		Texture2D sprite;
	public:
		Meteor();
		~Meteor();
		float getRadius();
		bool getActive();
		void setActive(bool a);
		void explode();
		void setSpeed(Vector2 s);
		static int getAmount();

		void update();
		void draw();

	private:
		void movement();
		void randomSpeed();
		void screenLimit();
	};
}