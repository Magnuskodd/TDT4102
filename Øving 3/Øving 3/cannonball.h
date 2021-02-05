#pragma once
//returnerer akselerasjon i y-retning
double acclY();
//returnerer fart i y-retning
double velY(double initVelocityY, double time);
//returner posisjonen i x-retning
double posX(double initPosition, double initVelocity, double time);
//returnerer posisjonen i y-retning
double posY(double initPosition, double initVelocity, double time);
//skriver ut en tid gitt i sekunder
void printTime(double time);
//returnerer flyvetiden med en gitt fart i y-retning
double flightTime(double initVelocityY);

// Ber brukeren om to tall, en vinkel (i grader) og en fart.
void getUserInput(double& theta, double& absVelocity);
// Konverterer fra grader til radianer
double degToRad(double deg);
// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkelen theta
void getVelocityVector(double theta, double absVelocity,
	double& velocityX, double& velocityY);

double getDistanceTraveled(double velocityX, double velocityY);
double targetPratice(double distanceToTarget, double velocityX, double velocityY);
