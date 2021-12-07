#include "UI/UI.h"

void UI::drawMousePointer()
{
	//DrawLine(0,0,GetMouseX(), GetMouseY(),DARKGREEN);
	DrawLineEx({ 0,GetMousePosition().y }, 
		{static_cast<float>(GetScreenWidth()),GetMousePosition().y},
		2.0f, UIGREEN);

	DrawLineEx({ GetMousePosition().x,0 },
		{ GetMousePosition().x,static_cast<float>(GetScreenHeight()) },
		2.0f, UIGREEN);
	//UI green is a developer inserted DEFINE in Raylib's format
}
