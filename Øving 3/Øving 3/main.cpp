#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utlities.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

void playTargetPratice() {

	double targetDistance = randomWithLimits(100, 1000);
	int tries = 0;

	while(true) {
		if (tries > 10) {
			cout << "Du klarte ikke å treffe blinken innen ti forsøk.";
			break;
		}
		double theta, absvelocity, velocityX, velocityY = 0;

		getUserInput(theta, absvelocity);
		theta = degToRad(theta);

		getVelocityVector(theta, absvelocity, velocityX, velocityY);

		int distanceDiff = targetPratice(targetDistance, velocityX, velocityY);
		double time = flightTime(velocityY);

		if (abs(distanceDiff) <= 5.0) {
			cout << "Du traff målet!\n";
			
			printTime(time);
			break;
		}
		else {
			if (distanceDiff < 0) {
				cout << "Du skjøt for langt.\n";
			}
			else {
				cout << "Du skjøt for kort. \n";
			}
			cout << "Kanonkulen havnet " << abs(distanceDiff) << " meter fra målet.\n";
			printTime(time);
		}
		++tries;

	}
	


}

int main(){
	setlocale(LC_ALL, "Norwegian");
	srand(static_cast<unsigned int>(time(nullptr)));

	playTargetPratice();
	return 0;
}
