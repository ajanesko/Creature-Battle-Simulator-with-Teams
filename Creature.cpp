#include "Creature.h"
#include <string>

Creature::Creature() {
	srand((unsigned)time(0));				//For Random number generation
	atkD = 0;
	atkS = 0;
	defD = 0;
	defS = 0;
	armor = 0;
	strPts = 0;
}

void Creature::setAtkD(int ad) {
	atkD = ad;
}

void Creature::setAtkS(int as) {
	atkS = as;
}

void Creature::setDefD(int dd) {
	defD = dd;
}

void Creature::setDefS(int ds) {
	defS = ds;
}

void Creature::setArmor(int a) {
	armor = a;
}

void Creature::setStrPts(int sp) {
	strPts = sp;
}

void Creature::setType(char t) {
	type = t;
}

void Creature::setLives(int l) {
	lives = l;
}

void Creature::setMaxStr(int ms) {
	maxStr = ms;
}

void Creature::setName() {
	std::string n;

	std::cout << "What would you like to name this creature?\n";
	std::cin >> n;

	name = n;
}

void Creature::setStrType(std::string st) {
	strType = st;
}

int Creature::getAtkD() {
	return atkD;
}

int Creature::getAtkS() {
	return atkS;
}

int Creature::getDefD() {
	return defD;
}

int Creature::getDefS() {
	return defS;
}

int Creature::getArmor() {
	return armor;
}

int Creature::getStrPts() {
	return strPts;
}

char Creature::getType() {
	return type;
}

int Creature::getLives() {
	return lives;
}

int Creature::getMaxStr() {
	return maxStr;
}

bool Creature::isAlive() {
	return alive;
}

std::string Creature::getName() {
	return name;
}

std::string Creature::getStrType() {
	return strType;
}

int Creature::rollDie(int max) {
	int randInt;
	randInt = (rand() % max) + 1;
	return randInt;
}

int Creature::attack(Creature b) {
	int totalAtk = 0;
	int oppDef = 0;
	switch (b.getType()) {
		//Damage calculating case for Barbarian, Harry Potter, and Medusa
	case 'b':
	case 'm':
	case 'h':
		for (int i = 0; i < atkD; i++) {
			totalAtk += rollDie(atkS);
		}
		for (int i = 0; i < b.getDefD(); i++) {
			oppDef += rollDie(b.getDefS());
		}
		//If attack is < 0, set to 0 so it doesnt add strength points to opponent
		if (totalAtk - oppDef - b.getArmor() < 0) {
			return 0;
		}
		else {
			return totalAtk - oppDef - b.getArmor();
		}
		break;
		//Damage calculating case for Vampire
	case 'v':
		if (b.rollDie(2) == 2) {
			std::cout << "Vampire charms opponent into not attacking!\n";
			return 0;
		}
		else {
			for (int i = 0; i < atkD; i++) {
				totalAtk += rollDie(atkS);
			}
			for (int i = 0; i < b.getDefD(); i++) {
				oppDef += rollDie(b.getDefS());
			}
			//If attack is < 0, set to 0 so it doesnt add strength points to opponent
			if (totalAtk - oppDef - b.getArmor() < 0) {
				return 0;
			}
			else {
				return totalAtk - oppDef - b.getArmor();
			}
		}
		break;
		//Damage calculating case for Blue Men
	case 'a':
		if (b.getStrPts() > 8) {
			for (int i = 0; i < atkD; i++) {
				totalAtk += rollDie(atkS);
			}
			for (int i = 0; i < b.getDefD(); i++) {
				oppDef += rollDie(b.getDefS());
			}
			//If attack is < 0, set to 0 so it doesnt add strength points to opponent
			if (totalAtk - oppDef - b.getArmor() < 0) {
				return 0;
			}
			else {
				return totalAtk - oppDef - b.getArmor();
			}
		}
		else if (b.getStrPts() > 4) {
			for (int i = 0; i < atkD; i++) {
				totalAtk += rollDie(atkS);
			}
			for (int i = 0; i < (b.getDefD() - 1); i++) {
				oppDef += rollDie(b.getDefS());
			}
			//If attack is < 0, set to 0 so it doesnt add strength points to opponent
			if (totalAtk - oppDef - b.getArmor() < 0) {
				return 0;
			}
			else {
				return totalAtk - oppDef - b.getArmor();
			}
		}
		else {
			for (int i = 0; i < atkD; i++) {
				totalAtk += rollDie(atkS);
			}
			for (int i = 0; i < (b.getDefD() - 2); i++) {
				oppDef += rollDie(b.getDefS());
			}
			//If attack is < 0, set to 0 so it doesnt add strength points to opponent
			if (totalAtk - oppDef - b.getArmor() < 0) {
				return 0;
			}
			else {
				return totalAtk - oppDef - b.getArmor();
			}
		}
		break;
	}
}