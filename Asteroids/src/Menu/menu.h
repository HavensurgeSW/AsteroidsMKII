#pragma once
#include "raylib.h"

struct Button {
	Rectangle rec;
	Color color;
};

class Menu {
private:
	int textSizeButton;
	Button play;
	Button credits;
	Button quit;

public:
	Menu();
	~Menu();
	void draw();
	void update();
	int input();
};
