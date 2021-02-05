#include <cstdlib>

int randomWithLimits(int lowerBorder, int upperBorder) {
	int randomNumber = -1;

	while (randomNumber <= lowerBorder || randomNumber >= upperBorder) {
		randomNumber = rand();
	}

	return randomNumber;
}
