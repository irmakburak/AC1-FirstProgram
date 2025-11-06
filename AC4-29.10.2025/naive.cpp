#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Naive algoritma: tüm bölenleri bul
vector<long long> getDivisorsNaive(long long n) {
    vector<long long> divisors;
    for (long long i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

int main() {
    vector<long long> testValues = { 1000000, 10000000, 100000000, 1000000000 };

    for (long long n : testValues) {
        double totalTime = 0.0;

        // 10 kez çalýþtýrýp toplam süreyi hesapla
        for (int k = 0; k < 10; k++) {
            auto start = high_resolution_clock::now();
            vector<long long> divisors = getDivisorsNaive(n);
            auto end = high_resolution_clock::now();

            duration<double> diff = end - start;
            totalTime += diff.count();
        }

        double averageTime = totalTime / 10.0;
        cout << "n = " << n << " average time: " << averageTime << " s" << endl;
    }

    return 0;
}
