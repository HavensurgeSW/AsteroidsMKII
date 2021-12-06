#pragma once
#include "raylib.h"

class App {
private:
	const int screenWidth = 800;
	const int screenHeight = 450;
	bool program;
public:
	App();
	~App();
	void loop();
};

