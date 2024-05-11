// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#ifndef CUBICLE_H
#define CUBICLE_H
#include <iostream>
#include <string>
#define print(x) cout << x << endl
using namespace std;

// cubicle class

class Cubicle {
private:
	int row, column;

public:
	Cubicle();
	Cubicle(int row, int column);
	~Cubicle();

	int getRow() const;
	int getColumn() const;
	string getCoordinates() const;
};

// node class

class CubicleNode {
public:
	Cubicle cubicle;
	CubicleNode* next;

	CubicleNode(int row, int column);
	CubicleNode(int row, int column, CubicleNode* next);
	~CubicleNode();
};

// cubicle graph class

class CubicleGraph {
private:
	int rows;
	int columns;
	CubicleNode** nodes;

public:
	CubicleGraph();
	CubicleGraph(int row, int column);
	~CubicleGraph();

	CubicleNode** getNodes();
	void addEdge(int row, int column, int addedEdgeRow, int addedEdgeColumn);
	string getAdjacentCubicles(int row, int column) const;
	string getAllNodes() const;
	string getAllNodesWithAdjacentCubicles() const;
	CubicleNode* getList(int row, int column) const;
};

// node functions

void addCubicle(CubicleNode*& list, int row, int column);
Cubicle getCubicle(CubicleNode* list, int row, int column);
#endif