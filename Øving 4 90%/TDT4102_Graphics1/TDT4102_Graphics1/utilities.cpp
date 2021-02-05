#include "utilities.h"
#include "std_lib_facilities.h"
#include <cstdlib>

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
}

void swap(int& firstNum, int& secondNum) {
	int temp = firstNum;
	firstNum = secondNum;
	secondNum = temp;
}

void randomizeVector(vector<int>& percentages, int n) {
	for (int i = 0; i < n; i++) {
		int randomNumber = 101;

		while (randomNumber >= 100) {
			randomNumber = rand();
		}

		percentages.push_back(randomNumber);
	}
}

void sortVector(vector<int>& unsortedVector) {
	int i = 1;
	
	while (i < unsortedVector.size()) {
		int j = i;

		while (j > 0 && unsortedVector[j - 1] > unsortedVector[j]) {
			swap(unsortedVector[j], unsortedVector[j - 1]);
				j--;
		}
		i++;
	}
}

int medianOfVector(vector<int> sortedVector) {
	int size = sortedVector.size();
	int median = 0;

	if (size % 2 == 0) {
		 median = (sortedVector[size / 2] + sortedVector[size / 2 - 1]) / 2;
	}
	else {
		 median = sortedVector[size / 2];
	}

	return median;
}

string randomizeString(int numberOfLetters, char lowerBound, char upperBound) {
	string stringOfLetters = "";
	int upper = static_cast<int>(upperBound);
	int lower = static_cast<int>(lowerBound);

	for (int i = 0; i < numberOfLetters; i++) {
		int randomNumber = lower - 1;

		while (randomNumber < lower || randomNumber > upper) {
			randomNumber = rand();
		}
		string appendstring;
		appendstring.push_back(static_cast<char>(randomNumber));

		stringOfLetters.append(appendstring);
	}

	return stringOfLetters;
}

string readInputToString(char lowerBound, char upperBound, int n) {
	string returnString;

	for (int i = 0; i < n; i++) {
		char input;
		cout << "Fyll inn en bokstav innenfor "<< lowerBound << " og " << upperBound << ": ";
		cin >> input;

		char letter = toupper(input);

		if (letter < lowerBound || letter > upperBound) {
			cout << "Ugyldig input. \n";
			i--;
		}
		else {
			returnString.push_back(letter);
		}
	}

	return returnString;
}

int countChar(string countOver, char letter) {
	int appearances = 0;

	for (auto x : countOver) {
		if (x == letter) {
			appearances++;
		}
	}
	return appearances;
}

int checkCharactersAndPosition(string guess, string answer) {
	int correct = 0;

	for (int i = 0; i < guess.length(); i++) {
		if (guess[i] == answer[i]) {
			correct++;
		}
	}

	return correct;
}

int checkCharacters(string guess, string answer) {
	int correct = 0;
	for (auto letter : answer) {
		int sameLetter = countChar(guess, letter);

		if (sameLetter >= 1) {
			correct++;
		}

	}

	return correct;
}