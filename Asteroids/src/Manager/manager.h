#pragma once
#include <vector>

#include "Player/player.h"
#include "Meteor/meteor.h"

using namespace std;


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
		Screens currentScreen;
		Player* p1;
		//vector<Meteor> bigMeteor;
		Meteor* bigMeteor[3];
		Meteor* midMeteor[6];
		Meteor* smallMeteor[12];

		Music background;
		Music breath;
		Music beep;

	public:
		Manager();
		~Manager();
		void loop();

	private:
		void collisions();

		void input();
		void update();
		void draw();
		void meteorUpdate();
		void meteorDraw();
	};
}

