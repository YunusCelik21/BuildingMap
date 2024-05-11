// Name: Yunus Dildar Celik
// Section: 1
// ID No: 22203347

#ifndef BUILDING_MAP_H
#define BUILDING_MAP_H
#include <iostream>

class BuildingMap {
public:
	BuildingMap(const string buildingMapFile);
	~BuildingMap();
	void displayAllCubicles() const;
	void displayAdjacentCubicles(const int row, const int col) const;
	void displayBuildingMap() const;
	void findPaths(const int startRow, const int startCol, const int endRow, const int endCol);
	void findPaths(const int startRow, const int startCol, const int endRow, const int endCol, const int avoidRow, const int avoidCol);
};

#endif