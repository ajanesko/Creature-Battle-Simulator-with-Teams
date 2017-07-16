/****************************************************
*Program Name: Project 4							*
*Author: Gary Janesko								*
*Date: 05/12/2017									*
*Description: Creates two queues to hold each		*
*players lineups and creates a stack to hold the	*
*defeated creatures. Runs by battling each players	*
*leading creature and stops when one player is out	*
*out creatures.										*
****************************************************/
#include <iostream>
#include "menu.h"

int main() {
	Menu m;						//Creates menu object
	int choice;					//menu choice variable
	bool playAgain = true;		//Bool variable to re-run program

	std::cout << "Project 4\n";

	while (playAgain) {
		m.showChoices();
		while (!(std::cin >> choice)) {
			std::cout << "Must enter a number.\n";
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

		std::cout << '\n';

		switch (choice) {
		case 1:			//Select teams
			m.case1();
			break;
		case 2:			//Display teams
			m.case2();
			break;
		case 3:			//Start tournament
			m.case3();
			break;
		case 4:			//Display graveyard
			m.case4();
			break;
		case 5:			//Quit
			m.case5();
			playAgain = false;
		}
	}


	return 0;
}