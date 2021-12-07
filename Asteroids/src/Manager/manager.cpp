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

}

void App::update()
{

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
