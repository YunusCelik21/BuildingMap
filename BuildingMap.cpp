// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#include "BuildingMap.h"

BuildingMap::BuildingMap(const string buildingMapFile) {
	ifstream file(buildingMapFile);

	file >> rows;
	file >> columns;

	graph = new CubicleGraph(rows, columns);
	string line;

	for (int i = 0; i < rows; ++i) {
		file >> line;
		for (int j = 0; j < columns; ++j) {

			int num = ((int)line[j]) - 48;

			if ((num == 0 || num == 1) && (i < rows - 1)) {
				graph->addEdge(i, j, i + 1, j); // add bottom cubicle as adjacent
				graph->addEdge(i + 1, j, i, j); // add the symmetrical
			}
			if ((num == 0 || num == 2) && (j > 0)) {
				graph->addEdge(i, j, i, j - 1); // add left cubicle as adjacent
				graph->addEdge(i, j - 1, i, j);
			}
		}
	}

	print(rows << " rows and " << columns << " columns have been read.");

	visitedAdjacentCount = new int*[rows];

	for (int i = 0; i < rows; ++i) {
		visitedAdjacentCount[i] = new int[columns];
		for (int j = 0; j < columns; ++j) {
			visitedAdjacentCount[i][j] = 0;
		}
	}
}

BuildingMap::~BuildingMap() {
	for (int i = 0; i < rows; ++i) {
		delete[] visitedAdjacentCount[i];
	}

	delete[] visitedAdjacentCount;

	delete graph;
}

void BuildingMap::displayAllCubicles() const {
	print("The cubicles in the building are:");
	print(graph->getAllNodes());
}

void BuildingMap::displayAdjacentCubicles(const int row, const int col) const {
	print("The cubicles adjacent to (" << row << "," << col << ") are:");
	print(graph->getAdjacentCubicles(row, col));
}

void BuildingMap::displayBuildingMap() const {
	print("The building map is as follows:");
	print(graph->getAllNodesWithAdjacentCubicles());
}

void BuildingMap::findPaths(const int startRow, const int startCol, const int endRow, const int endCol) {
	print("Paths from (" << startRow << "," << startCol << ") to (" << endRow << "," << endCol << ") are:");
	findPaths(startRow, startCol, endRow, endCol, -111, -111); // avoid nothing
}

// exhaustive dfs solution using cubicle stack
void BuildingMap::findPaths(const int startRow, const int startCol, const int endRow, const int endCol, const int avoidRow, const int avoidCol) {
	bool** visited = new bool*[rows];

	for (int i = 0; i < rows; ++i) {
		visited[i] = new bool[columns];
		for (int j = 0; j < columns; ++j) {
			visited[i][j] = false;
		}
	}

	if (avoidRow != -111) {
		print("Paths from (" << startRow << "," << startCol << ") to (" << endRow << "," << endCol << ") avoiding (" << avoidRow << "," << avoidCol << ") are:");
		visited[avoidRow][avoidCol] = true; // label as visited to avoid 
	}
	clearNextUnvisited();
	bool isPossible = false;

	Stack stack;
	stack.push(Cubicle(startRow, startCol));
	visited[startRow][startCol] = true;

	while (!stack.isEmpty()) {
		Cubicle currentCubicle = stack.top();

		if (currentCubicle == Cubicle(endRow, endCol)) { // if destination is reached
			print(stack.getCurrentPath());
			stack.pop();
			visited[currentCubicle.getRow()][currentCubicle.getColumn()] = false;
			isPossible = true;
			continue;
		}

		Cubicle nextUnvisited = getNextUnvisited(currentCubicle.getRow(), currentCubicle.getColumn());

		if (nextUnvisited == Cubicle(-1, -1)) { // if there is no more unvisited adjacent cubicle
			stack.pop();
			visited[currentCubicle.getRow()][currentCubicle.getColumn()] = false;
			visitedAdjacentCount[currentCubicle.getRow()][currentCubicle.getColumn()] = 0;
		}
		else if (!visited[nextUnvisited.getRow()][nextUnvisited.getColumn()]) {
			stack.push(nextUnvisited);
			visited[nextUnvisited.getRow()][nextUnvisited.getColumn()] = true;
		}

	}

	if (!isPossible) {
		print("None");
	}

	for (int i = 0; i < rows; ++i) {
		delete[] visited[i];
	}
	delete[] visited;
}

Cubicle BuildingMap::getNextUnvisited(int row, int column) {
	CubicleNode* node = graph->getList(row, column);

	for (int i = 0; i < visitedAdjacentCount[row][column]; ++i) {
		node = node->next;
	}

	if (node == nullptr) {
		return Cubicle(-1, -1);
	}

	visitedAdjacentCount[row][column] += 1;
	return node->cubicle;
}

void BuildingMap::clearNextUnvisited() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			visitedAdjacentCount[i][j] = 0;
		}
	}
}