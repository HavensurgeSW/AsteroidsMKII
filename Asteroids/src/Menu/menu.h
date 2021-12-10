#pragma once
#include "raylib.h"

struct Button {
	Rectangle rec;
	Color color;
	const char text[10];
};

class Menu {
private:
	Button play;
	Button credits;
	Button quit;
public:
	Menu();
	~Menu();

};
