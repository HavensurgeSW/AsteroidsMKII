#include "UI/UI.h"

namespace MK2
{
	void UI::drawMousePointer(bool p)
	{
		Color clr;
		if (!p)
		{
			clr = UIGREEN;
		}
		else clr = SKYBLUE;

		DrawLineEx({ 0,GetMousePosition().y },
			{ static_cast<float>(GetScreenWidth()),GetMousePosition().y },
			2.0f, clr);

		DrawLineEx({ GetMousePosition().x,0 },
			{ GetMousePosition().x,static_cast<float>(GetScreenHeight()) },
			2.0f, clr);

		//UI green is a developer inserted DEFINE in Raylib's format
	}

	void UI::drawCoordinates(Vector2 p)
	{
		DrawText(TextFormat("Miss. X: %i", static_cast<int>(GetMousePosition().x)), ((GetScreenWidth() / 100) * 4), ((GetScreenWidth() / 100) * 3), 20, UIGREEN);
		DrawText(TextFormat("Miss. Y: %i", static_cast<int>(GetMousePosition().y)), ((GetScreenWidth() / 100) * 4), (0 + (GetScreenWidth() / 100) * 5), 20, UIGREEN);
		DrawText(TextFormat("Ship X: %i", static_cast<int>(p.x)), ((GetScreenWidth() / 100) * 4), (0 + (GetScreenWidth() / 100) * 5)+40, 20, UIGREEN);
		DrawText(TextFormat("Ship Y: %i", static_cast<int>(p.y)), ((GetScreenWidth() / 100) * 4), (0 + (GetScreenWidth() / 100) * 5)+60, 20, UIGREEN);
	}

	void UI::drawEdges()
	{
		//3 = 3% of map edge.
		DrawLineEx({ 0.0f + (GetScreenWidth() / 100) * 3, 0.0f + (GetScreenHeight() / 100) * 3 }, { 0.0f + (GetScreenWidth() / 100) * 3, static_cast<float>(GetScreenHeight()) - (GetScreenHeight() / 100) * 3 }, 4.0f, DARKGREEN);
		DrawLineEx({ static_cast<float>(GetScreenWidth()) - (GetScreenWidth() / 100) * 3, 0.0f + (GetScreenHeight() / 100) * 3 }, { static_cast<float>(GetScreenWidth()) - (GetScreenWidth() / 100) * 3, static_cast<float>(GetScreenHeight()) - (GetScreenHeight() / 100) * 3 }, 4.0f, DARKGREEN);
		DrawLineEx({ 0.0f + (GetScreenWidth() / 100) * 3, 0.0f + (GetScreenHeight() / 100) * 3 }, { static_cast<float>(GetScreenWidth()) - (GetScreenWidth() / 100) * 3, 0.0f + (GetScreenHeight() / 100) * 3 }, 4.0f, DARKGREEN);
		DrawLineEx({ 0.0f + (GetScreenWidth() / 100) * 3, static_cast<float>(GetScreenHeight()) - (GetScreenHeight() / 100) * 3 }, { static_cast<float>(GetScreenWidth()) - (GetScreenWidth() / 100) * 3, static_cast<float>(GetScreenHeight()) - (GetScreenHeight() / 100) * 3 }, 4.0f, DARKGREEN);
#if _DEBUG
		DrawRectangleLines(GetScreenWidth()/2 - 200,GetScreenHeight()/2-200, 400,400, YELLOW );
#endif
	}
	void UI::drawPause()
	{
		DrawText(TextFormat("P A U S E D", static_cast<int>(GetScreenWidth()/3)), ((GetScreenWidth() / 100) * 38), ((GetScreenWidth() / 100) * 3), 60, SKYBLUE);
	}
}
