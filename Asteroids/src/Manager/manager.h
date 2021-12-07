#pragma once
#include "Player/player.h"

#include "UI/UI.h"

namespace MK2 {
	enum class Screens
	{
		Menu = 0, Gameplay, Gameover, Credits
	};

	class Manager
	{
	private:
		const int screenWidth = 1280;
		const int screenHeight = 720;
		bool program;
		Screens currentScreen;
		Player* p1;
	public:
		Manager();
		~Manager();
		void loop();

		void input();
		void update();
		void draw();
	};
}

