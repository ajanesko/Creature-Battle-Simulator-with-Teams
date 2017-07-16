#include "Battle.h"

void Battle(Creature* a, Creature* b) {
	int aHealth = a->getStrPts(),
		bHealth = b->getStrPts(),
		aTurns = 0,
		bTurns = 0;
	//Output Creature name
	switch (a->getType()) {
	case 'b':
		std::cout << "Player 1 selects Barbarian and ";
		break;
	case 'm':
		std::cout << "Player 1 selects Medusa and ";
		break;
	case 'h':
		std::cout << "Player 1 selects Harry Potter and ";
		break;
	case 'v':
		std::cout << "Player 1 selects Vampire and ";
		break;
	case 'a':
		std::cout << "Player 1 selects Blue Men and ";
		break;
	}

	switch (b->getType()) {
	case 'b':
		std::cout << "Player 2 selects Barbarian.\n";
		break;
	case 'm':
		std::cout << "Player 2 selects Medusa.\n";
		break;
	case 'h':
		std::cout << "Player 2 selects Harry Potter.\n";
		break;
	case 'v':
		std::cout << "Player 2 selects Vampire.\n";
		break;
	case 'a':
		std::cout << "Player 2 selects Blue Men.\n";
		break;
	}

	while (aHealth > 0 && aTurns == bTurns) {
		std::cout << "Round " << (aTurns + 1) << '\n';
		int aAtk = a->attack(*b);
		std::cout << "Player 1 attack: " << aAtk << '\n';
		bHealth -= aAtk;
		aTurns++;
		while (bHealth > 0 && bTurns == (aTurns - 1)) {
			int bAtk = b->attack(*a);
			std::cout << "Player 2 attack: " << bAtk << '\n';
			aHealth -= bAtk;
			bTurns++;
		}
		//If Player 1 loses
		if (aHealth <= 0) {
			if (a->getType() == 'h' && a->getLives() == 1) {
				a->setLives(0);
				aHealth = 20;
				std::cout << "Player 1 - Harry Potter uses Hogwarts ability!\n";
				std::cout << "Player 1 has " << aHealth << " Strength Points remaining.\n";
				std::cout << "Player 2 has " << bHealth << " Strength Points remaining.\n\n";
			}
			else {
				aHealth = 0;
				std::cout << "Player 1 has " << aHealth << " Strength Points remaining.\n";
				std::cout << "Player 2 has " << bHealth << " Strength Points remaining.\n";
				std::cout << "Player 1 is out of Strength Points, Player 2 wins.\n";
			}
		}
		//If Player 2 loses
		else if (bHealth <= 0) {
			if (b->getType() == 'h' && b->getLives() == 1) {
				b->setLives(0);
				bHealth = 20;
				bTurns++;
				std::cout << "Player 2 - Harry Potter uses Hogwarts ability!\n";
				std::cout << "Player 1 has " << aHealth << " Strength Points remaining.\n";
				std::cout << "Player 2 has " << bHealth << " Strength Points remaining.\n\n";
			}
			else {
				bHealth = 0;
				std::cout << "Player 1 has " << aHealth << " Strength Points remaining.\n";
				std::cout << "Player 2 has " << bHealth << " Strength Points remaining.\n";
				std::cout << "Player 2 is out of Strength Points, Player 1 wins.\n";
			}
		}
		//If the game continues
		else {
			std::cout << "Player 1 has " << aHealth << " Strength Points remaining.\n";
			std::cout << "Player 2 has " << bHealth << " Strength Points remaining.\n\n";
		}
	}
	a->setStrPts(aHealth);
	b->setStrPts(bHealth);
}