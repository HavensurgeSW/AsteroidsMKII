#include "manager.h"
#include "raylib.h"

#include "UI/UI.h"

namespace MK2 {
	const int bigMeteorCount = 3;
	const int midMeteorCount = 6;
	const int smallMeteorCount = 12;
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
		
		bigMeteor[0] = new Meteor(0);
		bigMeteor[1] = new Meteor(0);
		bigMeteor[2] = new Meteor(0);

		midMeteor[0] = new Meteor(1);
		midMeteor[1] = new Meteor(1);
		midMeteor[2] = new Meteor(1);
		midMeteor[3] = new Meteor(1);
		midMeteor[4] = new Meteor(1);
		midMeteor[5] = new Meteor(1);

		for (int i = 0; i < smallMeteorCount; i++)
		{
			smallMeteor[i] = new Meteor(2);
		}
		 
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
#if _DEBUG
		for (int i = 0; i < bigMeteorCount; i++)
		{
			if (CheckCollisionCircles(p1->getCenter(), p1->getRadius(), bigMeteor[i]->getCenter(), bigMeteor[i]->getRadius()))
			{
				
			}
		}
#endif

		for (int  i = 0; i <8; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (CheckCollisionCircles(p1->magazine[i]->getCenter(), p1->magazine[i]->getRadius(), bigMeteor[j]->getCenter(), bigMeteor[j]->getRadius()))
				{
					bigMeteor[j]->setActive(false);
				}
			}
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
			meteorUpdate();
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
			meteorDraw();
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

	void Manager::meteorUpdate()
	{
		for (int i = 0; i < bigMeteorCount; i++)
		{
			bigMeteor[i]->update();
		}
		for (int i = 0; i < midMeteorCount; i++)
		{
			midMeteor[i]->update();
		}
		for (int i = 0; i < smallMeteorCount; i++)
		{
			smallMeteor[i]->update();
		}
	}
	void Manager::meteorDraw()
	{
		for (int i = 0; i < bigMeteorCount; i++)
		{
			bigMeteor[i]->draw();
		}
		for (int i = 0; i < midMeteorCount; i++)
		{
			midMeteor[i]->draw();
		}
		for (int i = 0; i < smallMeteorCount; i++)
		{
			smallMeteor[i]->draw();
		}
	}
}
