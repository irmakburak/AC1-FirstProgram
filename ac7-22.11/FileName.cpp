#include <iostream>
#include "searchUtils.h"

int main() {
    auto arr = generateSortedVector(10000);

    int linComp, binComp;
    int key = 10010;

    int linIndex = linearSearch(arr, key, linComp);
    int binIndex = binarySearch(arr, key, binComp);

    std::cout << "Linear search: index = " << linIndex
        << ", comparisons = " << linComp << "\n";
    std::cout << "Binary search: index = " << binIndex
        << ", comparisons = " << binComp << "\n";

    return 0;
}
