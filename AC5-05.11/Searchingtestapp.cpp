#include "Searching.h"
#include <iostream>

int main() {
    std::vector<int> a({ 2,4,7,9,12,15,15,15,15,15,29,70,80,80 });
    int result;

    result = binarySearchFirst(a, 15);
    std::cout << "First occurrence of 15 is at index: " << result << std::endl;

    result = binarySearchFirst(a, 80);
    std::cout << "First occurrence of 80 is at index: " << result << std::endl;

    result = binarySearchFirst(a, 100);
    std::cout << "Target 100 not found: " << result << std::endl;

    return 0;
}
