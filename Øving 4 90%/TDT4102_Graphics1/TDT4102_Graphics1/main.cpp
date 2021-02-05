// Example program in TDT4102_Graphics template, from PPP page 415
//Oppgave a) 25
//Oppgave e) Vi bør bruke refereanse, siden vi ikke har noe måte å returnere 2 verdier fra en funksjon som er call-by-value
#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "Graph.h"
#include "Simple_window.h" 
#include "Mastermind.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

int main() {
	setlocale(LC_ALL, "Norwegian");
	srand(static_cast<unsigned int>(time(nullptr)));


	testCallByValue();
	testCallByReference();

	int a = 5;
	int b = 4;
	cout << "a: " << a << " b: " << b << endl;
	swap(a, b);
	cout << "a: " << a << " b: " << b << endl;

	testVectorSorting();
	cout << endl;
	testString();

	playMasterMind();

	keep_window_open();

	return 0;
}

