// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#include "BuildingMap.h"

BuildingMap::BuildingMap(const string buildingMapFile) {
	ifstream file(buildingMapFile);

	file >> rows;
	file >> columns;

	graph = CubicleGraph(rows, columns);
	string line;

	for (int i = 0; i < rows; ++i) {
		file >> line;
		for (int j = 0; j < columns; ++j) {

			int num = ((int)line[j]) - 48;

			if ((num == 0 || num == 1) && (i < rows - 1)) {
				graph.addEdge(i, j, i + 1, j); // add bottom cubicle as adjacent
				graph.addEdge(i + 1, j, i, j);
			}
			if ((num == 0 || num == 2) && (j > 0)) {
				graph.addEdge(i, j, i, j - 1); // add left cubicle as adjacent
				graph.addEdge(i, j - 1, i, j);
			}
		}
	}

	print(rows << " rows and " << columns << " columns have been read.");
}

BuildingMap::~BuildingMap() {}

void BuildingMap::displayAllCubicles() const {
	print("The cubicles in the building are:");
	print(graph.getAllNodes());
}

void BuildingMap::displayAdjacentCubicles(const int row, const int col) const {
	print("The cubicles adjacent to (" << row << "," << col << ") are:");
	print(graph.getAdjacentCubicles(row, col));
}

void BuildingMap::displayBuildingMap() const {
	print("The building map is as follows:");
	print(graph.getAllNodesWithAdjacentCubicles());
}

void BuildingMap::findPaths(const int startRow, const int startCol, const int endRow, const int endCol) {
	bool** visited = new bool*[rows];

	for (int i = 0; i < columns; ++i) {
		visited[i] = new bool[1];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j)
			visited[i][j] = false;
	}

	Stack stack;
	stack.push(Cubicle(startRow, startCol));

	while (!stack.isEmpty()) {
		Cubicle* cubicle = stack.top(); stack.pop();

		visited[cubicle.getRow()][cubicle.getColumn()] = true;

		CubicleNode* head = graph.getList(cubicle.getRow(), cubicle.getColumn());

		while (head) {
			if (!visited[(head->cubicle).getRow()][(head->cubicle).getColumn()]) {
				stack.push(Cubicle((head->cubicle).getRow(), (head->cubicle).getColumn()));
				head = head->next;
			}
		}
	}
}

void BuildingMap::findPaths(const int startRow, const int startCol, const int endRow, const int endCol, const int avoidRow, const int avoidCol) {
}
