// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#ifndef CUBICLE_H
#define CUBICLE_H

// Adjacency list class

class CubicleList {
public:
	Cubicle* cubicle;
	CubicleList* next;

	CubicleList(Cubicle* cubicle);
	CubicleList(Cubicle* cubicle, CubicleList* next);
	~CubicleList();
};

// cubicle class

class Cubicle {
private:
	CubicleList* head;
	int row, column;

public:
	Cubicle(int row, int column);
	~Cubicle();

	CubicleList* getList() const;
	int getRow() const;
	int getColumn() const;
};

// list functions

void addCubicle(CubicleList*& list, int row, int column);
void addCubicle(CubicleList*& list, Cubicle* cubicle);
Cubicle* getCubicle(CubicleList* list, int row, int column);
#endif
