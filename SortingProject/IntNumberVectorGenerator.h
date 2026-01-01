#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generateRandomNumbers(int size) {
    std::vector<int> v(size);
    std::srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        v[i] = rand();
    }
    return v;
}

std::vector<int> generateSortedVector(int size) {
    std::vector<int> v(size);
    for (int i = 0; i < size; i++) {
        v[i] = i + 1;
    }
    return v;
}

std::vector<int> generateReverseSortedVector(int size) {
    std::vector<int> v(size);
    for (int i = 0; i < size; i++) {
        v[i] = size - i;
    }
    return v;
}
