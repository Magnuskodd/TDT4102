#include"Fibonacci.h"
#include<iostream>
#include<array>

using namespace std;

void fillInFibonacciNumbers(int result[], int length) {
	for (int i = 0; i < length; ++i) {
		if (i == 0) {
			result[i] = 0;
		}

		else if (i == 1) {
			result[i] = 1;
		}

		else {
			result[i] = result[i - 1] + result[i - 2];
		}
	}
}

void printArray(int arr[], int length) {

	for (int i = 0; i < length; ++i) {
		cout << arr[i] << endl;
	}
}

void createFibonnaci() {
	int input = 0;
	cout << "Hvor mange fibonnacitall skal genereres? \n";
	cin >> input;

	int const length = input;
	int *fibArr = new int[length] {};

	fillInFibonacciNumbers(fibArr, length);
	printArray(fibArr, length);

	delete[] fibArr;
	fibArr = nullptr;
}