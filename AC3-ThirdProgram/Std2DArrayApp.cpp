#include "Std2DArray.h"
#include <iostream>
int main() {
	std::array < std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS> a;
	int numberOfRows, numberOfColumns;
	std::cout << "Enter the number of row:";
	std::cin >> numberOfRows;
	std::cout << "Enter the number of columns:";
	std::cin >> numberOfColumns;
	fillArray(a, numberOfRows, numberOfColumns);
	printArray(a, numberOfRows, numberOfColumns);
}