#pragma once
#include "raylib.h"
#include "Player/player.h"

enum class Screens
{
	Menu = 0, Gameplay, Gameover, Credits
};

class App
{
private:
	const int screenWidth = 1280;
	const int screenHeight = 720;
	bool program;
	Screens currentScreen;
	Player* p1;
public:
	App();
	~App();
	void loop();

	void input();
	void update();
	void draw();
};

