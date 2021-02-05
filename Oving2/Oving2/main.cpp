#include "std_lib_facilities.h"
#include <cmath>

using namespace std;

void inputAndPrintInteger() 
{
	int x = 0;
	cout << "Skriv inn ett heltall: ";
	cin >> x;
	cout << "Du skrev inn: " << x << "\n";
}

int inputNumber() 
{
	int x = 0;
	cout << "Skriv inn ett heltall: ";
	cin >> x;
	return x;
}

void inputIntegerAndSum() {
	int number1 = inputNumber();
	int number2 = inputNumber();
	cout << "Summen av tallene du skrev inn er: " << number1 + number2 << "\n";
}

bool isOdd(int number) 
{
	if (number % 2 == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void printHumanReadableTime(int seconds)
{
	int constantSec = seconds;

	int hours = seconds / 3600;
	seconds %= 3600;

	int minutes = seconds / 60;
	seconds %= 60;

	cout << constantSec << " er " << hours << " timer, " << minutes << " minutter og " << seconds << " sekunder.\n";
}

void inputIntegersUsingLoopAndPrintSum()
{
	int n = 0;
	cout << "Hvor mange tall vil du summere? ";
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; ++i) 
	{
		int x = inputNumber();
		sum += x;
	}

	cout << "Summen av tallene du skrev inn er " << sum << ".\n";
}

double inputDouble() 
{
	double number = 0;
	cout << "Skriv inn ett flyttall: ";
	cin >> number;
	return number;
}

void convertNOKToEUR() {
	double input = -1;
	double rate = 9.75;
	while (input < 0) {
		input = inputDouble();
		if (input < 0) {
			cout << "Du må skrive inn et positivt desimaltall!";
		}
	}

	double convert = input / rate;

	cout.precision(2);
	cout << fixed;
	cout << input << "NOK er " << convert << " euro.\n";

}

void printMultiplicatorTable() {
	int height, width = 0;
	cout << "Hvilken bredde skal gangetabellen ha? ";
	cin >> width;
	cout << "\n";

	cout << "Hvilken høyde skal gangetabellen ha? ";
	cin >> height;
	cout << "\n";

	for (int i = 1; i <= height; ++i) {
		for (int j = 1; j <= width; ++j) {
			cout << setw(4);
			cout << j * i;
		}
		cout << "\n";
	}
}

double discriminant(double a, double b, double c) {
	double disc = pow(b, 2) - 4 * a * c;
	return disc;
}

void printrealRoots(double a, double b, double c) {
	double disc = discriminant(a, b, c);

	if (disc > 0) {
		double solution1 = (-b + sqrt(disc)) / 2 * a;
		double solution2 = (-b - sqrt(disc)) / 2 * a;
		cout << "De to løsningene er x = " << solution1 << " og x = " << solution2 << "\n";
	}
	else if (disc == 0) {
		double solution = -b / 2 * a; 
		cout << "Løsningen er x = " << solution << "\n";
	}
	else {
		cout << "Denne ligningen har ingen reelle løsninger.";
	}
}

void solveQuadraticEquation() {
	double a, b, c = 0;
	cout << "Hva er a? ";
	cin >> a;
	cout << " Hva er b? ";
	cin >> b;
	cout << " Hva er c? ";
	cin >> c;
	printrealRoots(a, b, c);
}

vector<int> calculateSeries(int years, int loan, int rent) {
	int avdrag = loan / years;
	int remainder = loan;
	vector<int> payments(years);

	for (int i = 0; i < years; ++i) {
		int rents = (remainder*rent) / 100;
		int payment = avdrag + rents;
		payments[i] = payment;
		remainder -= payment;
	}

	return payments;
}

vector<int> calculateAnuity(int years, int loan, double rent) {
	double rentInPercent = rent / 100;
	double divider = 1 - pow(1 + rentInPercent, -years);
	int payment = loan * rentInPercent / divider;
	vector<int> payments(years);

	for (int i = 0; i < years; ++i) {
		payments[i] = payment;
	}

	return payments;
}

void printLoanPayments() {
	int loan, years, rent = 0;
	
	cout << "Hvor stort er lånet? ";
	cin >> loan;
	cout << "Hvor mange år skal det nedbetales over? ";
	cin >> years;
	cout << "Hvor stor er renten? Oppgi renten som et heltall: ";
	cin >> rent;

	vector<int> paymentsSeries(years);
	vector<int> paymentsAnnuity(years);

	paymentsSeries  = calculateSeries(years, loan, rent);
	paymentsAnnuity = calculateAnuity(years, loan, rent);

	cout << setw(5) << "År";
	cout << setw(10) << "Annuitet";
	cout << setw(7) << "Serie";
	cout << setw(13) << "Differanse\n";

	int totalAnnuity = 0;
	int totalSeries = 0;

	for (int i = 0; i < years; ++i) {
		int diff = paymentsAnnuity[i] - paymentsSeries[i];

		cout << setw(5) << i + 1 << setw(10) << paymentsAnnuity[i] << setw(7) << paymentsSeries[i] << setw(12) << diff <<"\n";
		
		totalAnnuity += paymentsAnnuity[i];
		totalSeries += paymentsSeries[i];
	}

	int totDiff = totalAnnuity - totalSeries;
	cout << "-----------------------------------\n";
	cout << setw(5) << "Total" << setw(10) << totalAnnuity << setw(7) << totalSeries << setw(12) << totDiff;

}

int main(){
	setlocale(LC_ALL, "Norwegian");

	////Oppgave 1d: jeg valgte inputNumber() siden den returnerer en verdi, som gjør det lettere å bruke verdien 
	//// videre i funksjonen inputIntegerAndSum().


	////Oppgave 2b: for løsningen jeg valgte, der man deffinerer antall tall, er en for-loop egnet fordi den kan "telle" 
	//// opp til den angitte verdien. For den andre kan man bruke en while-loop, som kan teste for en spesifikk handling
	//// (input = 0) hver iterasjon.


	////Oppgave 2e: Man vil bruke inputDouble og ikke inputInteger fordi brukeren skal gi ha muligheten til å gi et desimaltall.
	////Siden vekselsraten også er et desimaltall, må tallet brukeren gir være definert som et flyttall, selv om brukeren kan gi 
	////et heltall. Jeg valgte typen void for funksjonen siden funksjonen ikke returnerer en verdi, men heller skriver ut som en
	////del av funksjonen.
	while (true) {


		int numberOfTasks = 6;
		int choice = -1;

		cout << "\n\nVelg funksjon: \n";
		cout << "Avslutt(0)\n";
		cout << "Summer to tall(1)\n";
		cout << "Summer flere tall(2)\n";
		cout << "Konverter NOK til EURO(3)\n";
		cout << "Skriv ut gangetabellen (4) \n";
		cout << "Finn løsningen på ax^2 + bx + c = 0 (5)\n";
		cout << "Regne ut betalingene i et serie- og annuitetslån(6)\n";
		cout << "Velg en funksjon (0-" << numberOfTasks << "): ";

		while (choice > numberOfTasks || choice < 0) {
			cin >> choice;

			if (choice > numberOfTasks || choice < 0) {
				cout << "Du valgte ikke en funksjon, eller ga feil input! \n Velg et nytt tall: ";
			}
		}

		switch (choice) {
		case 0:
			return 0;
			break;
		case 1:
			inputIntegerAndSum();
			break;
		case 2:
			inputIntegersUsingLoopAndPrintSum();
			break;
		case 3:
			convertNOKToEUR();
			break;
		case 4:
			printMultiplicatorTable();
			break;
		case 5:
			solveQuadraticEquation();
			break;
		case 6:
			printLoanPayments();
			break;
		}
	}

}