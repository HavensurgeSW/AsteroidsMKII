#include "menu.h"

Menu::Menu()
{
	textSizeButton = 40;
	play.rec.x = GetScreenWidth() / 100 * 5.0f;
	play.rec.y = GetScreenHeight() / 3.0f;
	play.rec.height = 40;
	play.rec.width = 110;
	play.color = SKYBLUE;
	play.hover = false;

	credits.rec.x = GetScreenWidth() / 100 * 5.0f;
	credits.rec.y = (GetScreenHeight() - GetScreenHeight() / 4.0f);
	credits.rec.height = 40;
	credits.rec.width = 175;
	credits.color = GREEN;
	credits.hover = false;

	quit.rec.x = GetScreenWidth() / 100 * 5.0f;
	quit.rec.y = (GetScreenHeight() / 2) + (GetScreenHeight() / 100 * 37.3f);
	quit.rec.height = 40;
	quit.rec.width = 100;
	quit.color = GREEN;
	credits.hover = false;
}

Menu::~Menu()
{

}

void Menu::draw()
{
	DrawText(FormatText("ASTEROIDS Mk.II"), GetScreenWidth() / 100 * 5, GetScreenHeight() / 10, 90, GREEN);
	DrawText(FormatText("Software Ver. 1.0"), GetScreenWidth() / 100 * 5, static_cast<int>(GetScreenHeight() / 4.5f), 20, UIGREEN);
	

	DrawText(FormatText("[P]lay"), static_cast<int>(play.rec.x), static_cast<int>(play.rec.y), textSizeButton, play.color);
	DrawText(FormatText(">"), static_cast<int>(play.rec.x)-40, static_cast<int>(play.rec.y), textSizeButton, play.color);

	DrawText(FormatText("[E]xit"), static_cast<int>(quit.rec.x), static_cast<int>(quit.rec.y), textSizeButton, quit.color);
	DrawText(FormatText(">"), static_cast<int>(quit.rec.x)-40, static_cast<int>(quit.rec.y), textSizeButton, quit.color);

	DrawText(FormatText("//OS: Raylib 3.7"), static_cast<int>(GetScreenWidth()-GetScreenWidth()/3), static_cast<int>(play.rec.y), 30, UIGREEN);
	DrawText(FormatText("//Graphics: Karplus"), static_cast<int>(GetScreenWidth() - GetScreenWidth() / 3), static_cast<int>(play.rec.y+40), 30, UIGREEN);
	DrawText(FormatText("//Sounds: Karplus"), static_cast<int>(GetScreenWidth() - GetScreenWidth() / 3), static_cast<int>(play.rec.y + 80), 30, UIGREEN);
	DrawText(FormatText("NedadSimic"), static_cast<int>(GetScreenWidth() - GetScreenWidth() / 5.13f), static_cast<int>(play.rec.y + 120), 30, UIGREEN);
	DrawText(FormatText("//Code: Karplus"), static_cast<int>(GetScreenWidth() - GetScreenWidth() / 3), static_cast<int>(play.rec.y + 160), 30, UIGREEN);
}

void Menu::update()
{

}

int Menu::input()
{
	if (IsKeyPressed(KEY_P))
	{
		return 1;
	}
	if (IsKeyPressed(KEY_C))
	{
		return 2;
	}
	if (IsKeyPressed(KEY_E))
	{
		return 3;
	}

	return 0;
}
