#ifndef STACK_H
#define STACK_H

#include <memory>
#include "Creature.h"

struct StackNode {
	Creature crea;
	struct StackNode *next;
};

class Stack {
private:
	StackNode *top;
public:
	~Stack();
	void push(Creature c);
	bool isEmpty();
	void display(); 

	class Underflow {};
};

#endif