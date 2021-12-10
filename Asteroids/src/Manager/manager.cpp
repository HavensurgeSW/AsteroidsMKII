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
		pausedClass = new Pause();
		currentScreen = Screens::Menu;
		p1 = new Player;
		
		winTarget = bigMeteorCount + midMeteorCount + smallMeteorCount;
		score = 0;

		for (int i = 0; i < bigMeteorCount; i++)
		{
			bigMeteor[i] = new Meteor(0);
		}	
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
		delete menu;
		delete pausedClass;
		delete p1;

		for (int i = 0; i < bigMeteorCount; i++)
		{
			delete bigMeteor[i];
		}
		for (int i = 0; i < midMeteorCount; i++)
		{
			delete midMeteor[i];
		}
		for (int i = 0; i < smallMeteorCount; i++)
		{
			delete smallMeteor[i];
		}
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
		// Bullets vs Meteors
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < bigMeteorCount; j++)
				{
					if (CheckCollisionCircles(p1->magazine[i]->getCenter(), p1->magazine[i]->getRadius(), bigMeteor[j]->getCenter(), bigMeteor[j]->getRadius()) && p1->magazine[i]->getActive() && bigMeteor[j]->getActive())
					{
						p1->magazine[i]->destroy();
						bigMeteor[j]->setActive(false);
						bigMeteor[j]->explode();

						midMeteor[midMeteorPool]->setActive(true);
						midMeteor[midMeteorPool]->setPos(bigMeteor[j]->getPos());
						midMeteor[midMeteorPool + 1]->setActive(true);
						midMeteor[midMeteorPool + 1]->setPos(bigMeteor[j]->getPos());

						midMeteorPool += 2;
						score++;
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
						score++;
					}
				}
				for (int j = 0; j < smallMeteorCount; j++)
				{
					if (CheckCollisionCircles(p1->magazine[i]->getCenter(), p1->magazine[i]->getRadius(), smallMeteor[j]->getCenter(), smallMeteor[j]->getRadius()) && p1->magazine[i]->getActive() && smallMeteor[j]->getActive())
					{
						p1->magazine[i]->destroy();
						smallMeteor[j]->explode();
						smallMeteor[j]->setActive(false);
						score++;
					}
				}
			}
		}  
		// Player vs Meteors
		{
			for (int i = 0; i < bigMeteorCount; i++)
			{
				if (CheckCollisionCircles(p1->getCenter(),p1->getRadius(),bigMeteor[i]->getCenter(),bigMeteor[i]->getRadius())&&bigMeteor[i]->getActive())
				{
					currentScreen = Screens::Menu;
				}
			}
			for (int i = 0; i < midMeteorCount; i++)
			{
				if (CheckCollisionCircles(p1->getCenter(), p1->getRadius(), midMeteor[i]->getCenter(), midMeteor[i]->getRadius()) && midMeteor[i]->getActive())
				{
					currentScreen = Screens::Menu;
				}
			}
			for (int i = 0; i < smallMeteorCount; i++)
			{
				if (CheckCollisionCircles(p1->getCenter(), p1->getRadius(), smallMeteor[i]->getCenter(), smallMeteor[i]->getRadius()) && smallMeteor[i]->getActive())
				{
					currentScreen = Screens::Menu;
				}
			}
		}
	}

	void Manager::winCon()
	{
		if (score == winTarget)currentScreen = Screens::Menu;
	}

	void Manager::input()
	{
		switch (currentScreen) 
		{
			case Screens::Menu:
				menuInput();
				break;
			case Screens::Gameplay:
				if (pause == false)
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
				pauseInput();
				if (IsKeyPressed(KEY_ESCAPE))
				{
					pause = !pause;
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
			if (!pause)
			{
				p1->update();
				meteorUpdate();
				collisions();
				winCon();
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

	void Manager::draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		UI::drawMousePointer(pause);
		switch (currentScreen)
		{
		case Screens::Menu:
			menu->draw();
			break;
		case Screens::Gameplay:
			UI::drawCoordinates(p1->getCenter());
			p1->draw();
			meteorDraw();
			UI::drawEdges();
			if (pause)
			{
				UI::drawPause();
				pausedClass->draw();
			}
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
		case 1:
			for (int i = 0; i < bigMeteorCount; i++)
			{
				bigMeteor[i]->resetMeteor();
			}
			for (int i = 0; i < midMeteorCount; i++)
			{
				midMeteor[i]->resetMeteor();
			}
			for (int i = 0; i < smallMeteorCount; i++)
			{
				smallMeteor[i]->resetMeteor();
			}
			p1->zero();
			currentScreen = Screens::Gameplay; //PLAY
			break;
		case 3:
			program = false; //EXIT
			break;
		default:
			break;
		}
	}

	void Manager::pauseInput()
	{
		switch (pausedClass->input())
		{
		case 1:
			pause = false;
			break;
		case 2:
			pause = false;
			currentScreen = Screens::Menu;
			break;
		default:
			break;
		}
	}
}
