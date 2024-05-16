// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#include "Stack.h"

Stack::Stack() : head(nullptr) {}

Stack::~Stack() {
	if (head) {
		delete head;
	}
}

bool Stack::isEmpty() const {
	return head == nullptr;
}

void Stack::push(const Cubicle& cubicle) {
	if (!head) {
		head = new Node(cubicle);
	}
	else {
		Node* node = head;

		while (node->next) {
			node = node->next;
		}

		node->next = new Node(cubicle);
	}
}

bool Stack::pop() {
	if (isEmpty()) {
		return false;
	}

	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return true;
	}

	Node* node = head;

	while (node->next->next) {
		node = node->next;
	}

	delete node->next;
	node->next = nullptr;
	return true;
}

Cubicle Stack::top() const {
	if (isEmpty()) {
		return Cubicle(-1, -1);
	}

	Node* node = head;

	while (node->next) {
		node = node->next;
	}

	return node->cubicle;
}

string Stack::getCurrentPath() {
	if (isEmpty()) {
		return "";
	}

	Stack reversedStack;
	string path = "";

	while (!isEmpty()) {
		reversedStack.push(this->top());
		this->pop();
	}

	while (!reversedStack.isEmpty()) {
		path += reversedStack.top().getCoordinates() + " -> ";
		this->push(reversedStack.top());
		reversedStack.pop();
	}

	return path.substr(0, path.length() - 4);
}

Node::Node(Cubicle cubicle) : cubicle(cubicle), next(nullptr) {}

Node::Node(Cubicle cubicle, Node* next) : cubicle(cubicle), next(nullptr) {}

Node::~Node() {
	if (next) {
		delete next;
	}
}