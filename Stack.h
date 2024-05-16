// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#ifndef STACK_H
#define STACK_H
#include "Cubicle.h"

struct Node {
	Cubicle cubicle;
	Node* next;

	Node(Cubicle cubicle);
	Node(Cubicle cubicle, Node* next);
	~Node();
};

class Stack {
private:
	Node* head;

public:
	Stack();
	~Stack();

	bool isEmpty() const;
	void push(const Cubicle& cubicle);
	bool pop();
	Cubicle top() const;
	string getCurrentPath();
};

#endif