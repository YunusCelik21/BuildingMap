#include "Stack.h"

Stack::Stack() : head(nullptr) {}

Stack::~Stack() {
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
		delete head->next;
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

Cubicle* Stack::top() const {
	if (!head) {
		return nullptr;
	}

	Node* node = head;

	while (node->next) {
		node = node->next;
	}

	return &(node->cubicle);
}

Node::Node(Cubicle cubicle) : cubicle(cubicle), next(nullptr) {}

Node::Node(Cubicle cubicle, Node* next) : cubicle(cubicle), next(nullptr) {}

Node::~Node() {
	if (next)
		delete next;
}
