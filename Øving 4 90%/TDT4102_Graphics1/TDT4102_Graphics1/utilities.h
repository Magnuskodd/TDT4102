#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTImes);

void incrementByValueNumTimesRef(int& startvalue, int increment, int numTimes);

void swap(int& firstNum, int& secondNum);

void randomizeVector(vector<int>& percentages, int n);

void sortVector(vector<int>& unsortedVector);

int medianOfVector(vector<int> sortedVector);

string randomizeString(int numberOfLetters, char lowerBound, char upperBound);

string readInputToString(char upperBound, char lowerBound, int n);

int countChar(string countOver, char letter);

int checkCharactersAndPosition(string guess, string answer);

int checkCharacters(string guess, string answer);