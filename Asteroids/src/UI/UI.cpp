#include "UI/UI.h"

#include "raylib.h"

namespace MK2
{
	void UI::drawMousePointer()
	{
		DrawLineEx({ 0,GetMousePosition().y },
			{ static_cast<float>(GetScreenWidth()),GetMousePosition().y },
			2.0f, UIGREEN);

		DrawLineEx({ GetMousePosition().x,0 },
			{ GetMousePosition().x,static_cast<float>(GetScreenHeight()) },
			2.0f, UIGREEN);

		//UI green is a developer inserted DEFINE in Raylib's format

		DrawText(TextFormat("X: %i", static_cast<int>(GetMousePosition().x)), ((GetScreenWidth() / 100) * 4), ((GetScreenWidth() / 100) * 3), 20, UIGREEN);
		DrawText(TextFormat("Y: %i", static_cast<int>(GetMousePosition().y)), ((GetScreenWidth() / 100) * 4), (0 + (GetScreenWidth() / 100) * 5), 20, UIGREEN);
	}

	
	void UI::drawEdges()
	{
		//3 = 3% of map edge.
		DrawLineEx({ 0.0f + (GetScreenWidth() / 100) * 3, 0.0f + (GetScreenHeight() / 100) * 3 }, { 0.0f + (GetScreenWidth() / 100) * 3, static_cast<float>(GetScreenHeight()) - (GetScreenHeight() / 100) * 3 }, 4.0f, DARKGREEN);
		DrawLineEx({ static_cast<float>(GetScreenWidth()) - (GetScreenWidth() / 100) * 3, 0.0f + (GetScreenHeight() / 100) * 3 }, { static_cast<float>(GetScreenWidth()) - (GetScreenWidth() / 100) * 3, static_cast<float>(GetScreenHeight()) - (GetScreenHeight() / 100) * 3 }, 4.0f, DARKGREEN);
		DrawLineEx({ 0.0f + (GetScreenWidth() / 100) * 3, 0.0f + (GetScreenHeight() / 100) * 3 }, { static_cast<float>(GetScreenWidth()) - (GetScreenWidth() / 100) * 3, 0.0f + (GetScreenHeight() / 100) * 3 }, 4.0f, DARKGREEN);
		DrawLineEx({ 0.0f + (GetScreenWidth() / 100) * 3, static_cast<float>(GetScreenHeight()) - (GetScreenHeight() / 100) * 3 }, { static_cast<float>(GetScreenWidth()) - (GetScreenWidth() / 100) * 3, static_cast<float>(GetScreenHeight()) - (GetScreenHeight() / 100) * 3 }, 4.0f, DARKGREEN);
	}
}
