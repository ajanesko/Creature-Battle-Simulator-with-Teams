#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <ctime>
#include <iostream>

class Creature {
private:
	int atkD,
		atkS,
		defD,
		defS,
		armor,
		strPts,
		lives,
		maxStr;
	char type;
	bool alive = true;
	std::string name;
	std::string strType;
public:
	Creature();
	void setAtkD(int ad);
	void setAtkS(int as);
	void setDefD(int dd);
	void setDefS(int ds);
	void setArmor(int a);
	void setStrPts(int sp);
	void setType(char t);
	void setLives(int l);
	void setMaxStr(int ms);
	void setName();
	void setStrType(std::string st);
	int getAtkD();
	int getAtkS();
	int getDefD();
	int getDefS();
	int getArmor();
	int getStrPts();
	char getType();
	int getLives();
	int getMaxStr();
	std::string getName();
	std::string getStrType();
	bool isAlive();
	int rollDie(int max);
	virtual int attack(Creature b);
};

#endif