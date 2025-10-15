#include <array>
#include <iostream>
const int MAXSIZE = 1000;

void fillArray(std::array<int, MAXSIZE>& arr, int size) {
    if (size > MAXSIZE) {
        std::cout << "Size must be not greater than " << MAXSIZE;
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << "Enter an integer number: ";
        std::cin >> arr[i];
    }
}

void printArray(std::array<int, MAXSIZE>& arr, int size) {
    // write the code to display elements separated by space
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; // satýr sonu
}

int main() {
    std::array<int, MAXSIZE> stdarr;
    std::cout << "Enter the size of the array: ";
    int size;
    std::cin >> size;
    fillArray(stdarr, size);
    printArray(stdarr, size);
}
