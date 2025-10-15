#include <iostream>
void fillArray(int a[], int size);
void printArray(int a[], int size);
int main() {
	int arr[1000];
	int s;
	std::cout << "Enter the size of array:";
	std::cin >> s;
	fillArray(arr, s);
	printArray(arr, s);
}
void fillArray(int a[], int size) {
	//a[0], a[1], ...a[size - 1];
	for (int i = 0; i < size; i++) {
		std::cout << "Enter an integer number:";
		std::cin >> a[i];
	}
}
void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << a[i] << " ";
	}
}