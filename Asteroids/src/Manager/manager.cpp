#include "manager.h"
#include "raylib.h"

#include "UI/UI.h"

namespace MK2 {
	Manager::Manager()
	{
		program = true;
		InitWindow(screenWidth, screenHeight, "Asteroids MK II");
		InitAudioDevice();

		background = LoadMusicStream("res/background.mp3");
		breath = LoadMusicStream("res/breath.mp3");
		beep = LoadMusicStream("res/beep.mp3");


		SetExitKey(0);
		SetTargetFPS(60);
		currentScreen = Screens::Gameplay;
		p1 = new Player;
		meteor = new Meteor;
	}

	Manager::~Manager()
	{
		delete p1;
	}

	void Manager::loop()
	{
		PlayMusicStream(background);
		SetMusicVolume(background, 0.2f);
		PlayMusicStream(breath);
		SetMusicVolume(breath, 0.02f);
		PlayMusicStream(beep);
		SetMusicVolume(beep, 0.05f);

		while (program && !WindowShouldClose())
		{
			input();
			update();
			draw();
		}
		CloseWindow();
	}

	void Manager::collisions()
	{
		if (CheckCollisionCircles(p1->getCenter(), p1->getRadius(), meteor->getCenter(), meteor->getRadius()))
		{
			p1->zero();
		}

		//if (CheckCollisionsCircles(p1->getMissile()))
		{

		}


	}

	void Manager::input()
	{
		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
		{
			p1->accelerate();
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			p1->shoot();
		}
	}

	void Manager::update()
	{
		UpdateMusicStream(background);
		UpdateMusicStream(breath);
		UpdateMusicStream(beep);

		switch (currentScreen)
		{
		case Screens::Menu:
			break;
		case Screens::Gameplay:
			//FALTA INERCIA 
			p1->update();
			meteor->update();
			collisions();
			break;
		case Screens::Gameover:
			break;
		case Screens::Credits:
			break;
		default:
			break;
		}
	}

	void Manager::draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (currentScreen)
		{
		case Screens::Menu:
			break;
		case Screens::Gameplay:

			UI::drawMousePointer();
			p1->draw();
			meteor->draw();

			UI::drawEdges();
			break;
		case Screens::Gameover:
			break;
		case Screens::Credits:
			break;
		default:
			break;
		}
		EndDrawing();
	}
}
