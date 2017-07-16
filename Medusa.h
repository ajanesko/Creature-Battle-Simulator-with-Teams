#ifndef MEDUSA_H
#define MEDUSA_H

#include "Creature.h"

class Medusa : public Creature {
private:

public:
	Medusa();
	virtual int attack(int dd, int ds, int oa, char t);
};

#endif