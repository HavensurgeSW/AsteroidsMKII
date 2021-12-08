#include "manager.h"
#include "raylib.h"

#include "UI/UI.h"

namespace MK2 {
	Manager::Manager()
	{
		program = true;
		InitWindow(screenWidth, screenHeight, "Asteroids MK II");
		SetExitKey(0);
		SetTargetFPS(60);
		currentScreen = Screens::Gameplay;
		p1 = new Player;
		meteor = new Meteor;
	}

	Manager::~Manager()
	{
		delete p1;
	}

	void Manager::loop()
	{
		while (program && !WindowShouldClose())
		{
			input();
			update();
			draw();
		}
		CloseWindow();
	}

	void Manager::input()
	{
		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
		{
			p1->accelerate();
		}
	}

	void Manager::update()
	{
		switch (currentScreen)
		{
		case Screens::Menu:
			break;
		case Screens::Gameplay:
			//FALTA INERCIA 
			p1->update();
			meteor->update();
			break;
		case Screens::Gameover:
			break;
		case Screens::Credits:
			break;
		default:
			break;
		}
	}

	void Manager::draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (currentScreen)
		{
		case Screens::Menu:
			break;
		case Screens::Gameplay:

			UI::drawMousePointer();
			p1->draw();
			meteor->draw();

			break;
		case Screens::Gameover:
			break;
		case Screens::Credits:
			break;
		default:
			break;
		}
		EndDrawing();
	}
}
