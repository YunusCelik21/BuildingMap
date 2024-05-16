// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#include "Cubicle.h"

// cubicle class

Cubicle::Cubicle() : row(0), column(0) {}

Cubicle::Cubicle(int row, int column) : row(row), column(column) {}

Cubicle::~Cubicle() {}

int Cubicle::getRow() const {
	return row;
}

int Cubicle::getColumn() const {
	return column;
}

string Cubicle::getCoordinates() const {
	return "(" + to_string(row) + "," + to_string(column) + ")";
}

bool Cubicle::operator==(const Cubicle& cubicle) {
	return this->row == cubicle.row && this->column == cubicle.column;
}

//  node class

CubicleNode::CubicleNode(int row, int column) : cubicle(Cubicle(row, column)), next(nullptr) {}

CubicleNode::CubicleNode(int row, int column, CubicleNode* next) : cubicle(Cubicle(row, column)), next(next) {}

CubicleNode::~CubicleNode() {
	if (next) {
		delete next;
	}
}

// cubicle graph class

CubicleGraph::CubicleGraph() : rows(0), columns(0), nodes(nullptr) {}

CubicleGraph::CubicleGraph(int rows, int columns) : rows(rows), columns(columns) {
	
	nodes = new CubicleNode*[rows * columns];

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			nodes[i * columns + j] = new CubicleNode(i, j);
		}
	}
}

CubicleGraph::~CubicleGraph() {
	if (nodes) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				delete nodes[i * columns + j];
			}
		}

		delete[] nodes;
	}
}

CubicleNode** CubicleGraph::getNodes() {
	return nodes;
}

void CubicleGraph::addEdge(int row, int column, int addedEdgeRow, int addedEdgeColumn) {
	addCubicle(nodes[row * columns + column]->next, addedEdgeRow, addedEdgeColumn);
}

string CubicleGraph::getAdjacentCubicles(int row, int column) const {
	CubicleNode* head = nodes[row * columns + column];
	string s = (head->cubicle).getCoordinates() + " -> ";

	if (head->next == nullptr) {
		return s;
	}

	while (head->next) {
		s += (head->next->cubicle).getCoordinates() + ",";
		head = head->next;
	}

	return s.substr(0, s.length() - 1);
}

string CubicleGraph::getAllNodes() const {
	string s = "";

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			s += (nodes[i * columns + j]->cubicle).getCoordinates() + ",";
		}
		s = s.substr(0, s.length() - 1);

		if (i < rows - 1) {
			s += "\n";
		}			
	}

	return s;
}

string CubicleGraph::getAllNodesWithAdjacentCubicles() const {
	string s = "";

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			s += getAdjacentCubicles(i ,j);

			if (i < rows - 1 || j < columns - 1) {
				s += "\n";
			}
		}
	}

	return s;
}

CubicleNode* CubicleGraph::getList(int row, int column) const {
	return nodes[row * columns + column]->next;
}

// node functions

void addCubicle(CubicleNode*& list, int row, int column) {
	if ((list == nullptr) ||
		(row < (list->cubicle).getRow() || (row == (list->cubicle).getRow() && column < (list->cubicle).getColumn()))) {
		CubicleNode* ptr = list;
		list = new CubicleNode(row, column, ptr);
	}
	else {
		addCubicle(list->next, row, column);
	}
}