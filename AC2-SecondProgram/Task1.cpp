#include <array>
#include <iostream>

const int MAXNUMBEROFROWS = 100;
const int MAXNUMBEROFCOLUMNS = 100;

// Function to print the 2D array
void printArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int nrrows, int nrcolumns) {
    for (int i = 0; i < nrrows; ++i) {
        for (int j = 0; j < nrcolumns; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to fill the 2D array with user input
void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int nrrows, int nrcolumns) {
    for (int i = 0; i < nrrows; ++i) {
        for (int j = 0; j < nrcolumns; ++j) {
            std::cout << "Enter element at row " << i << ", column " << j << ": ";
            std::cin >> arr[i][j];
        }
    }
}

int main() {
    std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS> matrix;
    fillArray(matrix, 5, 4); // elements are entered row by row
    printArray(matrix, 5, 4);
}
