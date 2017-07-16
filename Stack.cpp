#include "Stack.h"
#include <iostream>
#include <string>

void Stack::push(Creature c) {
	StackNode *temp = new StackNode;
	if (top == NULL) {
		temp->crea = c;
		temp->next = NULL;
		top = temp;
	}
	else {
		temp->crea = c;
		temp->next = top;
		top = temp;
	}
}

bool Stack::isEmpty() {
	return top == nullptr;
}

void Stack::display() {
	StackNode *p = top;
	int count = 1;
	if (top == NULL) {
		std::cout << "The Graveyard is empty. Please complete the tournament first.\n";
	}
	else {
		while (p != NULL) {
			std::cout << count << ": ";
			std::cout << p->crea.getName() << " the " << p->crea.getStrType() << '\n';
			p = p->next;
			count++;
		}
	}
	std::cout << '\n';
}

Stack::~Stack() {
	StackNode *garbage = top;
	while (garbage != nullptr) {
		top = top->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = top;
	}
}