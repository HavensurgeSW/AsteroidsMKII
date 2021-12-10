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
		int id;

		Texture2D atlas[3];
		Texture2D sprite;
		Sound death;
	public:
		Meteor(int type);
		~Meteor();

		float getRadius();
		Vector2 getCenter();
		bool getActive();
		Vector2 getPos();
		void setPos(Vector2 p);
		void setActive(bool a);

		void explode();
		void setSpeed(Vector2 s);
		static int getBMAmount();

		void update();
		void draw();

	private:
		void movement();
		void randomSpeed();
		void screenLimit();
		
	};
}