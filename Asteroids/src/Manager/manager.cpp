#include "manager.h"

App::App()
{
	program = true;
	InitWindow(screenWidth, screenHeight, "Asteroids MK II");
	SetExitKey(KEY_NUM_LOCK);
	SetTargetFPS(60);
	currentScreen = Screens::Gameplay;
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

}

void App::update()
{

}

void App::draw()
{
	BeginDrawing();
	switch (currentScreen)
	{
	case Screens::Menu:
		break;
	case Screens::Gameplay:	
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
