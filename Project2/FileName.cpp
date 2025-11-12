#include "Searching.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = { 2, 4, 7, 9, 12, 15, 15, 15, 15, 15, 29, 70, 80, 80 };
    int result = binarySearchFirst(a, 15);
    cout << "First occurrence of 15: " << result << endl;
    return 0;
}