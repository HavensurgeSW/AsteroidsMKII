#include "manager.h"
#include "raylib.h"

#include "UI/UI.h"

namespace MK2 {
	const int bigMeteorCount = 4;
	const int midMeteorCount = 8;
	const int smallMeteorCount = 16;
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
		menu = new Menu();
		currentScreen = Screens::Menu;
		p1 = new Player;
		
		bigMeteor[0] = new Meteor(0);
		bigMeteor[1] = new Meteor(0);
		bigMeteor[2] = new Meteor(0);
		bigMeteor[3] = new Meteor(0);


		for (int i = 0; i < midMeteorCount; i++)
		{
			midMeteor[i] = new Meteor(1);
		}


		for (int i = 0; i < smallMeteorCount; i++)
		{
			smallMeteor[i] = new Meteor(2);
		}

		midMeteorPool = 0;
		smallMeteorPool = 0; 
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
		for (int  i = 0; i <8; i++)
		{
			for (int j = 0; j < bigMeteorCount; j++)
			{
				if (CheckCollisionCircles(p1->magazine[i]->getCenter(), p1->magazine[i]->getRadius(), bigMeteor[j]->getCenter(), bigMeteor[j]->getRadius())&&p1->magazine[i]->getActive()&&bigMeteor[j]->getActive())
				{
					p1->magazine[i]->destroy();
					bigMeteor[j]->setActive(false);
					bigMeteor[j]->explode();

					midMeteor[midMeteorPool]->setActive(true);
					midMeteor[midMeteorPool]->setPos(bigMeteor[j]->getPos());
					midMeteor[midMeteorPool+1]->setActive(true);
					midMeteor[midMeteorPool+1]->setPos(bigMeteor[j]->getPos());

					midMeteorPool += 2;
				}
			}

			for (int j = 0; j < midMeteorCount; j++)
			{
				if (CheckCollisionCircles(p1->magazine[i]->getCenter(), p1->magazine[i]->getRadius(), midMeteor[j]->getCenter(), midMeteor[j]->getRadius()) && p1->magazine[i]->getActive() && midMeteor[j]->getActive())
				{
					p1->magazine[i]->destroy();
					midMeteor[j]->setActive(false);
					midMeteor[j]->explode();

					smallMeteor[smallMeteorPool]->setActive(true);
					smallMeteor[smallMeteorPool]->setPos(midMeteor[j]->getPos());
					smallMeteor[smallMeteorPool + 1]->setActive(true);
					smallMeteor[smallMeteorPool + 1]->setPos(midMeteor[j]->getPos());

					smallMeteorPool += 2;
				}
			}
			for (int j = 0; j < smallMeteorCount; j++)
			{
				if (CheckCollisionCircles(p1->magazine[i]->getCenter(), p1->magazine[i]->getRadius(), smallMeteor[j]->getCenter(), smallMeteor[j]->getRadius()) && p1->magazine[i]->getActive() && smallMeteor[j]->getActive())
				{
					p1->magazine[i]->destroy();
					smallMeteor[j]->explode();
					smallMeteor[j]->setActive(false);
				}
			}
		}
	}

	void Manager::input()
	{
		switch (currentScreen) 
		{
			case Screens::Menu:
				menuInput();
				break;
			case Screens::Gameplay:
				if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
				{
					p1->accelerate();
				}
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					p1->shoot();
				}
				break;
			case Screens::Gameover:

				break;
			case Screens::Credits:

				break;
			default:
				break;
		
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
		UI::drawMousePointer();
		switch (currentScreen)
		{
		case Screens::Menu:
			menu->draw();
			break;
		case Screens::Gameplay:
			UI::drawCoordinates();
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

	void Manager::menuInput()
	{
		switch (menu->input())
		{
		case 0:
			break;
		case 1:
			currentScreen = Screens::Gameplay;
			break;
		case 2:

			break;
		case 3:

			break;
		default:
			break;
		}
	}
}
