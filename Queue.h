#ifndef QUEUE_H
#define QUEUE_H

#include "Creature.h"

struct QueueNode
{
	Creature crea;
	struct QueueNode *next;
//	Creature creature;
//	QueueNode *next;
//	QueueNode *prev;
};

class Queue {
private:
	QueueNode *head;
	QueueNode *tail;
//	QueueNode *front;
//	QueueNode *back;
public:
	Queue();
	void add(Creature *c);
	void remove();
	void display();
	void moveFrontToBack();
	bool isEmpty();
	Creature getFront();
	/*
	Queue();
	~Queue();
	QueueNode *createNode(Creature c);
	void addCreature(Creature c);		//Adding to back
	Creature getFront();				//Get front creature
	void moveFrontToBack(Creature c);	//Move winner from front of list to back
	void removeFront();					//Remove front creature
	bool isEmpty();						//Checks if queue is empty
	void display();
	*/

};

#endif