#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Creature.h"
#include "Barbarian.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "Battle.h"
#include "Queue.h"
#include "Stack.h"

class GamePlay {
private:
	Queue queueP1,
		  queueP2;
	Stack graveyard;
	int size1,
		size2;
public:
	Creature* selectCreature();
	void selectTeam();
	void showCreatures();
	void playRound();
	void playGame();
	void restoreStr(Creature c);
	void displayTeams();
	void displayGraveyard();
	Queue getQueueP1();
	Queue getQueueP2();
};

#endif