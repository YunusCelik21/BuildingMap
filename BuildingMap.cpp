// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#include "BuildingMap.h"

BuildingMap::BuildingMap(const string buildingMapFile) {
	ifstream file(buildingMapFile);
	int rows;
	int columns;

	file >> rows;
	file >> columns;

	graph = CubicleGraph(rows, columns);
	string line;

	for (int i = 0; i < rows; ++i) {
		file >> line;
		for (int j = 0; j < columns; ++j) {

			int num = ((int)line[j]) - 48;

			switch (num) {
			case 0:
				if (j > 0) {
					graph.addEdge(i, j, i, j - 1); // add left cubicle as adjacent
					graph.addEdge(i, j - 1, i, j);
				}
				if (i < rows - 1) {
					graph.addEdge(i, j, i + 1, j); // add bottom
					graph.addEdge(i + 1, j, i, j);
				}
				break;
			case 1:
				if (i < rows - 1) {
					graph.addEdge(i, j, i + 1, j);
					graph.addEdge(i + 1, j, i, j);
				}
				break;
			case 2:
				if (j > 0) {
					graph.addEdge(i, j, i, j - 1);
					graph.addEdge(i, j - 1, i, j);
				}
				break;
			default:
				break;
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
}

void BuildingMap::findPaths(const int startRow, const int startCol, const int endRow, const int endCol, const int avoidRow, const int avoidCol) {
}
