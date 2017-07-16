#include "Medusa.h"

Medusa::Medusa() {
	setAtkD(2);
	setAtkS(6);
	setDefD(1);
	setDefS(6);
	setArmor(3);
	setStrPts(8);
	setType('m');
	setMaxStr(8);
	setStrType("Medusa");
}

int Medusa::attack(int dd, int ds, int oa, char t) {
	int totalAtk = 0;
	int oppDef = 0;
	//Calculates Attack
	for (int i = 0; i < getAtkD(); i++) {
		totalAtk += rollDie(getAtkS());
	}
	//Medusa stone ability
	if (totalAtk == 12) {
		return 100;
	}
	//Calculates opponents defense
	for (int i = 0; i < dd; i++) {
		oppDef += rollDie(ds);
	}
	//If attack is < 0, set to 0 so it doesnt add strength points to opponent
	if (totalAtk - oppDef - oa < 0) {
		return 0;
	}
	else {
		return totalAtk - oppDef - oa;
	}
}