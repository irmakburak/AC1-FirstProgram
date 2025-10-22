#include <iostream>
#include <vector>
using namespace std;


vector<long> findDivisors(long number);

int main() {
    long number;
    cout << "Enter an integer number: ";
    cin >> number;

    vector<long> result = findDivisors(number);

    cout << "Divisors: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}


vector<long> findDivisors(long number) {
    vector<long> divisors;
    for (long i = 1; i <= number; i++) {
        if (number % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}
