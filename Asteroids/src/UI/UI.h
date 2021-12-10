#pragma once
#include "raylib.h"


namespace MK2 {
	class UI
	{
	public:
		static void drawMousePointer(bool p);
		static void drawCoordinates(Vector2 p);
		static void drawEdges();
		static void drawPause();
	};
}

