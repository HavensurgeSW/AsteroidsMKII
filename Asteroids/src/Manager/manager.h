#pragma once
#include "raylib.h"

enum class Screens
{
	Menu = 0, Gameplay, Gameover, Credits
};

class App
{
private:
	const int screenWidth = 800;
	const int screenHeight = 450;
	bool program;
	Screens currentScreen;
public:
	App();
	~App();
	void loop();

	void input();
	void update();
	void draw();
};

