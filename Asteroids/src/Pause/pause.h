#pragma once
#include "raylib.h"

namespace MK2 {
	struct ButtonP {
		Rectangle rec;
		Color color;
	};

	class Pause
	{
	private:
		ButtonP resume;
		ButtonP mainMenu;
	public:
		Pause();
		~Pause();

		void draw();
		int input();
	};
}