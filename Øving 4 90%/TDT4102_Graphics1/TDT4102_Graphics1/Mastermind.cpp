#include "Mastermind.h"
#include "utilities.h"
#include "Graph.h"
#include "Simple_window.h" 
#include "masterVisual.h"

void playMasterMind() {
	constexpr int size = 4;
	constexpr int letters = 6;
	constexpr int attempts = 10;
	int win_w = 400;
	int win_h = 600;

	MastermindWindow mwin{ Point{1100, 100}, win_w, win_h, "Mastermind" };

	string code = randomizeString(size, 'A', 'F');
	addGuess(mwin, code, size, 'A', 0);
	cout << code << endl; 
	hideCode(mwin, size);
	mwin.wait_for_button();

	int attemptNmb = 1;
	while (attemptNmb < attempts) {
		string guess = readInputToString('A', 'F', size);

		cout << "din gjetning:\n";
		for (auto x : guess) {
			cout << x;
		}

		int rightPos = checkCharactersAndPosition(guess, code);
		int rightLetter = checkCharacters(guess, code);

		addGuess(mwin, guess, size, 'A', attemptNmb);
		addFeedback(mwin, rightPos, rightLetter, size, attemptNmb);

		cout << "\nAntall rikitge posisjoner: " << rightPos << "\n Antall riktige bokstaver: " << rightLetter << "\n";

		if (rightPos == size && rightLetter == size) {
			cout << "Gratulerer! du fant den riktige koden.\n";
			break;
		}
		attemptNmb++;
		mwin.wait_for_button();
	}
	if (attemptNmb > attempts) {
		cout << "Beklager, du klarte ikke gjette koden.\n";
	}
	
}