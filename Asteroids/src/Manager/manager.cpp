#include "manager.h"

App::App()
{
	program = true;
	InitWindow(screenWidth, screenHeight, "Asteroids MK II");
	SetExitKey(KEY_NUM_LOCK);
	SetTargetFPS(60);
	currentScreen = Screens::Gameplay;
	p1 = new Player;
}

App::~App()
{
}

void App::loop()
{
	while (program&&!WindowShouldClose())
	{
		input();
		update();
		draw();
	}
	CloseWindow();
}

void App::input()
{
	p1->input();
}

void App::update()
{
	switch (currentScreen)
	{
	case Screens::Menu:
		break;
	case Screens::Gameplay:
		p1->update();
		break;
	case Screens::Gameover:
		break;
	case Screens::Credits:
		break;
	default:
		break;
	}
}

void App::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	switch (currentScreen)
	{
	case Screens::Menu:
		break;
	case Screens::Gameplay:	
		p1->draw();
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
