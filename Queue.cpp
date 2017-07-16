#include "Queue.h"
#include <iostream>
#include <string>
/*
Queue::Queue() {
	front = nullptr;
	back = nullptr;
}

Queue::~Queue() {
	QueueNode *temp = front;
	while (temp != NULL) {
		QueueNode *next = temp->next;
		delete temp;
		temp = next;
	}
}

QueueNode* Queue::createNode(Creature c) {
	struct QueueNode *temp;

	temp = new(struct QueueNode);

	temp->creature = c;
	temp->next = nullptr;
	temp->prev = nullptr;

	return temp;
}

void Queue::addCreature(Creature c) {
	struct QueueNode *temp;
	temp = createNode(c);
	if (front == back && front == nullptr) {
		front = back = temp;
		front->next = back->next = nullptr;
		front->prev = back->prev = nullptr;
	}
	else {
		back->next = temp;
		temp->prev = back;
		back = temp;
		front->prev = back;
		back->next = front;
	}
}

Creature Queue::getFront() {
	return front->creature;
}

void Queue::moveFrontToBack(Creature c) {
	front = front->next;
	back = back->next;
}

void Queue::removeFront() {
	QueueNode *temp = front;
	QueueNode *prev1 = back;

	if (front == back && front == nullptr) {
		std::cout << "The lineup is already empty.\n";
		return;
	}
	if (temp == prev1) {
		std::cout << "The front of the queue has been removed. This was the last element in the queue.\n";
		free(temp);
		return;
	}
	front = temp->next;
	front->prev = back;
	back->next = front;
	temp->next = nullptr;
	std::cout << "The front of the queue has been removed.\n";
	free(temp);
}

bool Queue::isEmpty() {
	if (front == nullptr && front == back) {
		return true;
	}
	else {
		return false;
	}
}

void Queue::display() {
	if (front == nullptr) {
		std::cout << "The queue is empty.\n";
	}
	else if (front == back) {
		std::cout << front->creature.getType() << '\n';
	}
	else {
		for (QueueNode* p = back->next; p != back; p = p->next) {
			std::cout << p->creature.getType() << " ";
		}
		std::cout << back->creature.getType() << '\n';
	}
}
*/

Queue::Queue() {
	head = NULL;
	tail = NULL;
}

void Queue::add(Creature *c) {
	QueueNode *temp = new QueueNode;

	temp->crea = *c;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		tail->next = temp;
	}

	tail = temp;
}

void Queue::remove() {
	QueueNode *temp = new QueueNode;
	if (head == NULL) {
		std::cout << "Queue is empty.\n";
	}
	else {
		temp = head;
		head = head->next;
		delete temp;
	}
}

void Queue::display() {
	QueueNode *p = new QueueNode;
	p = head;
	int count = 1;
	if (head == NULL) {
		std::cout << "This lineup is empty. Please set your lineup first.\n";
	}
	else {
		while (p != NULL) {
			std::cout << count << ": ";
			std::cout << p->crea.getName() << " the " << p->crea.getStrType() << '\n';
			p = p->next;
			count++;
		}
	}
}

void Queue::moveFrontToBack() {
	QueueNode *temp = head;
	head = head->next;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
}

bool Queue::isEmpty() {
	if (head == tail && head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

Creature Queue::getFront() {
	return head->crea;
}