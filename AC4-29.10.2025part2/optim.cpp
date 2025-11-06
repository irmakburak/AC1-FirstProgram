#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;


vector<long long> getDivisorsOptimized(long long n) {
    vector<long long> smallDivisors;
    vector<long long> largeDivisors;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            smallDivisors.push_back(i);
            if (i != n / i) {
                largeDivisors.push_back(n / i);
            }
        }
    }

  
    for (int i = largeDivisors.size() - 1; i >= 0; i--) {
        smallDivisors.push_back(largeDivisors[i]);
    }

    return smallDivisors;
}

int main() {
    vector<long long> testValues = { 100000000, 1000000000, 1000000000000LL, 100000000000000000LL, 1000000000000000000LL };

    for (long long n : testValues) {
        double totalTime = 0.0;

        // Run 10 times and calculate total time
        for (int k = 0; k < 10; k++) {
            auto start = high_resolution_clock::now();
            vector<long long> divisors = getDivisorsOptimized(n);
            auto end = high_resolution_clock::now();

            duration<double> diff = end - start;
            totalTime += diff.count();
        }

        double averageTime = totalTime / 10.0;
        cout << "n = " << n << " average time: " << averageTime << " s" << endl;
    }

    return 0;
}
