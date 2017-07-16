#include "menu.h"
#include "Queue.h"
#include <iostream>

void Menu::case1() {
	game.selectTeam();
}

void Menu::case2() {
	game.displayTeams();
}

void Menu::case3() {
	game.playGame();
}

void Menu::case4() {
	game.displayGraveyard();
}

void Menu::case5() {
	//Quit Program
	exit(1);
}

void Menu::showChoices() {
	std::cout << "Please choose from the following:\n";
	std::cout << "1: Team selection\n";
	std::cout << "2: Display each player's teams\n";
	std::cout << "3: Start Tournament\n";
	std::cout << "4: Display the Graveyard\n";
	std::cout << "5: Quit\n\n";
}