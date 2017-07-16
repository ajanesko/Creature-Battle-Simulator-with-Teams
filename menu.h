#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "GamePlay.h"
#include "Battle.h"

class Menu {
private:
	GamePlay game;
public:
	void showChoices();
	void case1();			//Select number of creatures for each team and set lineups
	void case2();			//Display each players teams
	void case3();			//Play game
	void case4();			//Print graveyard
	void case5();			//Quit
};

#endif