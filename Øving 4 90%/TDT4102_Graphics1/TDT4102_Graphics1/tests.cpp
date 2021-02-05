#include "tests.h"
#include "utilities.h"
#include "std_lib_facilities.h"

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0
		<< "increment: " << increment
		<< "iterations: " << iterations
		<< "result: " << result << endl;
}

void testCallByReference() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;

	incrementByValueNumTimesRef(v0, increment, iterations);

	cout << "v0: " << v0
		<< "increment: " << increment
		<< "iterations: " << iterations
		<< "result: " << v0 << endl;
}

void testVectorSorting(){
	vector<int> percentages;
	randomizeVector(percentages, 6);

	for (auto i : percentages) {
		cout << i << endl;
	}
	cout << endl;
	swap(percentages[0], percentages[1]);

	for (auto i : percentages) {
		cout << i << endl;
	}

	sortVector(percentages);
	cout << endl;

	for (auto i : percentages) {
		cout << i << endl;
	}

	cout << medianOfVector(percentages);

}

void testString() {
	string grades = randomizeString(8, 'A', 'F');
	cout << grades << endl;
	
	vector<int> gradCount;	
	int sumOfGrades = 0;

	for (int i = 70; i > 64; i--) {
		gradCount.push_back(countChar(grades, static_cast<char>(i)));
	}

	for (auto x : gradCount) {
		cout << x << endl; 
	}

	for (int i = 0; i < 6; i++) {
		sumOfGrades += gradCount[i] * i;
	}
	
	char average = static_cast<char>(70 - sumOfGrades / grades.length() );

	cout << "gjennomsnittet var " << average << endl;
}