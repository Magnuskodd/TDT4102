#include "std_lib_facilities.h"
#include<cmath>
const double PI = 3.1415926535897;

double acclY() {
	return -9.81;
}

double velY(double initVelocityY, double time) {
	double velocity = initVelocityY + acclY() * time;
	return velocity;
}

double posX(double initPosition, double initVelocity, double time) {
	double pos = initPosition + initVelocity * time;
	return pos;
}

double posY(double initPosition, double initVelocity, double time) {
	double pos = initPosition + initVelocity * time + (acclY() * time * time) / 2; 
	return pos;
}

void printTime(double time) {
	int seconds = time;

	int hours = seconds / 3600;
	seconds %= 3600;

	int minutes = seconds / 60;
	seconds %= 60;

	cout << setw(5) << "Hours" << setw(9) << "Minutes" << setw(10) << "Seconds\n";
	cout << setw(5) << hours << setw(9) << minutes << setw(9) << seconds << "\n";
}

double flightTime(double initVelocityY) {
	double time = (-2 * initVelocityY) / acclY();
	return time;
}

void getUserInput(double& theta, double& absVelocity) {
	cout << "Deffinerer farten til kanonkulen: ";
	cin >> absVelocity;
	cout << "Oppgi vinkelen i grader kanonkulen skytes ut ifra: ";
	cin >> theta;
}

double degToRad(double deg) {
	double rad = deg * PI / 180; 
	return rad;
}

double getVelocityX(double theta, double absVelocity) {
	double velocityX = absVelocity * cos(theta);
	return velocityX;
}

double getVelocityY(double theta, double absVelocity) {
	double velocityY = absVelocity * sin(theta);
	return velocityY;
}

void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY) {
	velocityX = getVelocityX(theta, absVelocity);
	velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
	double totTime = flightTime(velocityY);
	double distance = posX(0, velocityX, totTime);

	return distance;
}

double targetPratice(double distanceToTarget, double velocityX, double velocityY) {
	double distanceTraveled = getDistanceTraveled(velocityX, velocityY);
	double diff = distanceToTarget - distanceTraveled;
	return diff;
}
