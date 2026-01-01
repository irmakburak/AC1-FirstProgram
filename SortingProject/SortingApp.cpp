#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "Sorting.h"
#include "IntNumberVectorGenerator.h"
#include "Benchmark.h"

using namespace std;

template<typename T>
bool ascending(const T& a, const T& b) {
    return a < b;
}

template<typename SortFunc>
long long measureSortTime(SortFunc sortFn, vector<int> data) {
    Benchmark<std::chrono::nanoseconds> b;
    sortFn(data);
    return b.elapsed();
}

int main() {

    // CSV dosyasını EN BAŞTA oluştur
    ofstream file("results.csv");
    file << "Algorithm,InputType,Size,AverageTime(ns)\n";
    file.flush();

    int choice;

    cout << "\n=== SORTING BENCHMARK MENU ===\n";
    cout << "1 - BubbleSort\n";
    cout << "2 - BubbleSortFlag\n";
    cout << "3 - SelectionSort\n";
    cout << "4 - InsertionSort\n";
    cout << "5 - QuickSort (First Pivot)\n";
    cout << "6 - QuickSort (Middle Pivot)\n";
    cout << "Your choice: ";
    cin >> choice;

    vector<int> sizes = { 10000, 20000, 30000, 40000, 50000, 60000 };
    vector<string> inputTypes = { "Random", "Sorted", "ReverseSorted" };

    string algoName;

    for (string inputType : inputTypes) {

        // QuickSort First + ReverseSorted = worst case → bilinçli olarak atla
        if (choice == 5 && inputType == "ReverseSorted") {
            cout << "Skipping ReverseSorted for QuickSortFirst (worst case)\n";
            continue;
        }

        for (int size : sizes) {

            long long total = 0;

            for (int iter = 0; iter < 3; iter++) {

                vector<int> data;

                if (inputType == "Random")
                    data = generateRandomNumbers(size);
                else if (inputType == "Sorted")
                    data = generateSortedVector(size);
                else
                    data = generateReverseSortedVector(size);

                long long t = 0;

                if (choice == 1) {
                    algoName = "BubbleSort";
                    t = measureSortTime(
                        [&](vector<int>& v) { bubbleSort(v, ascending<int>); }, data);
                }
                else if (choice == 2) {
                    algoName = "BubbleSortFlag";
                    t = measureSortTime(
                        [&](vector<int>& v) { bubbleSortWithFlag(v, ascending<int>); }, data);
                }
                else if (choice == 3) {
                    algoName = "SelectionSort";
                    t = measureSortTime(
                        [&](vector<int>& v) { selectionSort(v, ascending<int>); }, data);
                }
                else if (choice == 4) {
                    algoName = "InsertionSort";
                    t = measureSortTime(
                        [&](vector<int>& v) { insertionSort(v, ascending<int>); }, data);
                }
                else if (choice == 5) {
                    algoName = "QuickSortFirst";
                    t = measureSortTime(
                        [&](vector<int>& v) {
                            quickSortFirst(v, 0, (int)v.size() - 1, ascending<int>);
                        }, data);
                }
                else if (choice == 6) {
                    algoName = "QuickSortMiddle";
                    t = measureSortTime(
                        [&](vector<int>& v) {
                            quickSortMiddle(v, 0, (int)v.size() - 1, ascending<int>);
                        }, data);
                }

                total += t;
            }

            long long avg = total / 3;

            cout << algoName << " | " << inputType
                << " | " << size << " -> " << avg << " ns\n";

            file << algoName << ","
                << inputType << ","
                << size << ","
                << avg << "\n";

            file.flush(); // crash olsa bile yazılsın
        }
    }

    file.close();
    cout << "\nResults written to results.csv\n";
    return 0;
}
