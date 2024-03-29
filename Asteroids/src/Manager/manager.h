#pragma once
#include "Player/player.h"
#include "Meteor/meteor.h"
#include "Menu/menu.h"
#include "Pause/pause.h"




namespace MK2 {
	enum class Screens
	{
		Menu = 0, Gameplay, Gameover, Credits
	};

	class Manager
	{
	private:
		const int screenWidth = 1280;
		const int screenHeight = 720;
		bool program;
		bool pause;
		Screens currentScreen;
	
		Menu* menu;
		Pause* pausedClass;

		//GAMEPLAY ELEMENTS
		Player* p1;
		Meteor* bigMeteor[4];
		Meteor* midMeteor[8];
		int midMeteorPool;
		Meteor* smallMeteor[16];
		int smallMeteorPool;

		int winTarget;
		int score;

		Music background;
		Music breath;
		Music beep;

	public:
		Manager();
		~Manager();
		void loop();

	private:
		void collisions();
		void winCon();

		void input();
		void update();
		void draw();
		void meteorUpdate();
		void meteorDraw();

		void menuInput();
		void pauseInput();
	};
}

