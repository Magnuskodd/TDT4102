#include "utilites.h"
#include <cstdlib>

int getRand(int lowerbound, int upperbound) {
	int randomNumber = -1;

	while (randomNumber <= lowerbound || randomNumber >= upperbound) {
		randomNumber = rand();
	}

	return randomNumber;
}