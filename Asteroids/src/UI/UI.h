#pragma once
#include "raylib.h"
#include "Meteor/meteor.h"

namespace MK2 {
	class UI
	{
	public:
		static void drawMousePointer();
		static void drawCoordinates(Vector2 p);
		static void drawEdges();
		static void drawPause();
	};
}

