#pragma once
#include "raylib.h"
#include "Missile/missile.h"

#include <vector>
using namespace std;

namespace MK2 {
	class Player {
	private:
		const int maxMissiles = 8;
		Vector2 pos;
		Vector2 force;
		float acceleration;
		float rotation;
		float radius;

		Missile* magazine[8];
		float reloadTimer;

		Texture2D sprite;
	public:
		Player();
		~Player();

		float getRotation();
		float getRadius();
		Vector2 getCenter();
		void zero();

		void shoot();
		void accelerate();
		void update();
		void draw();

		void move();
	private:
		void followMouse();
		void screenLimit();
	};
}