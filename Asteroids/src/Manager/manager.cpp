#include "manager.h"

App::App()
{
	program = true;
	InitWindow(screenWidth, screenHeight, "Asteroids MK II");
	SetTargetFPS(60);
}

App::~App()
{
}

void App::loop()
{
	while (program&&!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}
	CloseWindow();
}
