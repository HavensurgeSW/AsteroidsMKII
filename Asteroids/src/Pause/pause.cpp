#include "pause.h"

namespace MK2 {
	Pause::Pause()
	{
		resume.rec.x = (GetScreenWidth() / 2.0f) + (GetScreenWidth() / 100 * 13.0f);
		resume.rec.y = (GetScreenHeight() / 2.0f);
		resume.rec.height = 40.0f;
		resume.rec.width = 150.0f;
		resume.color = SKYBLUE;

		mainMenu.rec.x = GetScreenWidth() / 3.5f;
		mainMenu.rec.y = GetScreenHeight() / 2.0f;
		mainMenu.rec.height = 40.0f;
		mainMenu.rec.width = 100.0f;
		mainMenu.color = SKYBLUE;
	}

	Pause::~Pause()
	{
	}

	void Pause::draw()
	{
		DrawText(FormatText("Resume"), static_cast<int>(resume.rec.x), static_cast<int>(resume.rec.y), 40, resume.color);
		DrawText(FormatText("Menu"), static_cast<int>(mainMenu.rec.x), static_cast<int>(mainMenu.rec.y), 40, mainMenu.color);
	}

	int Pause::input()
	{
		if (CheckCollisionPointRec(GetMousePosition(), resume.rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return 1;
		}

		if (IsKeyPressed(KEY_E) || CheckCollisionPointRec(GetMousePosition(), mainMenu.rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return 2;
		}
		return 0;
	}
}
