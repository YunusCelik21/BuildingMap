// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#include "Cubicle.h"

//  adjacency list class

CubicleList::CubicleList(Cubicle* cubicle) : cubicle(cubicle), next(nullptr) {}

CubicleList::CubicleList(Cubicle* cubicle, CubicleList* next) : cubicle(cubicle), next(next) {}

// does not delete objects
CubicleList::~CubicleList() {
	if (next)
		delete next;
}

// cubicle class

Cubicle::Cubicle(int row, int column) : row(row), column(column), head(nullptr) {}

Cubicle::~Cubicle() {
	if (head) {
		delete head;
	}
}

CubicleList* Cubicle::getList() const {
	return head;
}

int Cubicle::getRow() const {
	return row;
}

int Cubicle::getColumn() const
{
	return column;
}

// list functions

void addCubicle(CubicleList*& list, int row, int column) {
	Cubicle* cubicle = new Cubicle(row, column);

	if ((list == nullptr) ||
		(row < list->cubicle->getRow() || (row == list->cubicle->getRow() && column < list->cubicle->getColumn()))) {
		CubicleList* ptr = list;
		list = new CubicleList(cubicle, ptr);
	}
	else {
		delete cubicle;
		addCubicle(list->next, row, column);
	}
}

void addCubicle(CubicleList*& list, Cubicle* cubicle) {
	if ((list == nullptr) ||
		(cubicle->getRow() < list->cubicle->getRow() || (cubicle->getRow() == list->cubicle->getRow() && cubicle->getColumn() < list->cubicle->getColumn()))) {
		CubicleList* ptr = list;
		list = new CubicleList(cubicle, ptr);
	}
	else {
		addCubicle(list->next, cubicle);
	}
}

Cubicle* getCubicle(CubicleList* list, int row, int column) {
	if (list == nullptr) {
		return nullptr;
	}
	
	if (list->cubicle->getRow() == row && list->cubicle->getColumn() == column) {
		return list->cubicle;
	}
	
	return getCubicle(list->next, row, column);
			
}