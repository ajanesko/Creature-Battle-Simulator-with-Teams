#include "GamePlay.h"
#include "Creature.h"

#include <iostream>
#include <string>

Creature* GamePlay::selectCreature() {
	int choice;
	Creature *newCrea = NULL;

	showCreatures();

	std::cout << "Please enter an integer: ";
	while (!(std::cin >> choice)) {
		std::cout << "Must enter 1 - 5.\n";
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}

	switch (choice) {
	case 1:
		newCrea = new Barbarian;
		newCrea->setName();
		break;
	case 2:
		newCrea = new Medusa;
		newCrea->setName();
		break;
	case 3:
		newCrea = new HarryPotter;
		newCrea->setName();
		break;
	case 4:
		newCrea = new Vampire;
		newCrea->setName();
		break;
	case 5:
		newCrea = new BlueMen;
		newCrea->setName();
		break;
	}

	return newCrea;
}

void GamePlay::selectTeam() {
	std::cout << "Select the number of creatures on each team.(Minimum of 10)\n";
	while (!(std::cin >> size1)) {
		std::cout << "Please enter an integer.\n";
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
	if (size1 < 10) {
		size1 = 10;
		std::cout << "Reset size to minimum value 10.\n";
	}
	size2 = size1;
	//Player 1 Team Select
	std::cout << "Player 1\nSelect your creatures: \n";
	for (int i = 0; i < size1; i++) {
		queueP1.add(selectCreature());
	}

	//Player 2 Team Select
	std::cout << "Player 2\nSelect your creatures: \n";
	for (int i = 0; i < size2; i++) {
		queueP2.add(selectCreature());
	}
}

void GamePlay::showCreatures() {
	std::cout << "1: Barbarian\n";
	std::cout << "2: Medusa\n";
	std::cout << "3: Harry Potter\n";
	std::cout << "4: Vampire\n";
	std::cout << "5: Blue Men\n";
}

void GamePlay::playRound() {
	Creature player1 = queueP1.getFront();
	Creature player2 = queueP2.getFront();
	
	Battle(&player1, &player2);

	if (player1.getStrPts() == 0) {
		std::cout << player2.getStrType() << "'s health is restored to " << player2.getStrPts() << " and is sent to back of the lineup.\n";
		std::cout << player1.getStrType() << " is sent to the graveyard.\n\n";
		restoreStr(player2);
		queueP2.moveFrontToBack();
		graveyard.push(player1);
		queueP1.remove();
		size1--;
	}
	else {
		std::cout << player1.getStrType() << "'s health is restored to " << player1.getStrPts() << " and is sent to back of the lineup.\n";
		std::cout << player2.getStrType() << " is sent to the graveyard.\n\n";
		restoreStr(player1);
		queueP1.moveFrontToBack();
		graveyard.push(player2);
		queueP2.remove();
		size2--;
	}
}

void GamePlay::playGame() {
	while (size1 > 0 && size2 > 0) {
			playRound();
	}

	if (size1 == 0) {
		std::cout << "Player 1 is out of creatures.\n Player 2 wins!\n\n";
	}
	else if (size2 == 0) {
		std::cout << "Player 2 is out of creatures.\n Player 1 wins!\n\n";
	}
}

void GamePlay::restoreStr(Creature c) {
	int maxStr = c.getMaxStr();
	int curStr = c.getStrPts();
	int strLost = maxStr - curStr;
	curStr += (strLost * .5);
	c.setStrPts(curStr);
}

void GamePlay::displayTeams() {
	std::cout << "Player 1's Team\n";
	queueP1.display();
	std::cout << "\nPlayer 2's Team\n";
	queueP2.display();
	std::cout << '\n';
}

void GamePlay::displayGraveyard() {
	std::cout << "\nThe Graveyard\n";
	graveyard.display();
}
Queue GamePlay::getQueueP1() {
	return queueP1;
}

Queue GamePlay::getQueueP2() {
	return queueP2;
}