#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter first integer: ";
    cin >> a;
    cout << "Enter second integer: ";
    cin >> b;

    cout << "Sum: " << a + b << endl;
    cout << "Difference: " << a - b << endl;
    cout << "Product: " << a * b << endl;

    cout << "Divisors of " << a << ": ";
    for (int i = 1; i <= abs(a); i++) {
        if (a % i == 0) {
            cout << i << " " << -i << " ";
        }
    }
    cout << endl;

    return 0;
}
