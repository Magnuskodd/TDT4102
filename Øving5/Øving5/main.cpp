#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));


	//Setup
	Blackjack game;

	//Game loop
	while (!game.checkGameOver()) {
		//Print to screen and take input
		cout << "\n\n";
		game.showHand();
		cout << "\n";
		game.showDealerhand();
		cout << "\n";
		game.playerChoice();
		cout << "\n";

		//get sum of hands
		vector<int> playerSum = game.getSumVector("player");
		vector<int> dealerSum = game.getSumVector("dealer");

		//Show the hole card
		game.showHoleCard();
		cout << "\n";

		//Check win logic
		if (dealerSum[0] > 16 || dealerSum[1] == 21) {
			if (game.checkBlackjack("dealer")) {
				if (game.checkBlackjack("player")) {
					cout << "You both have blackjack, so you win!\n\n";
					return 0;
				}
				else {
					cout << "The dealer has blackjack, but you dont. Sorry, you lose!\n\n";
					return 0;
				}
			}
			else if (game.checkBlackjack("player")) {
				cout << "You got blackjack! Congratulations, you won!\n\n";
				return 0;
			}
			else {
				int playerScore = getMax(playerSum);
				int dealerScore = getMax(dealerSum);

				if (playerScore > 21) {
					cout << "Sorry, your cards add up to over 21. You lose!\n\n";
					return 0;
				}
				else if (dealerScore > 21) {
					cout << "The dealers cards add up to over 21! You win!\n\n";
					return 0;
				}

				if (playerScore > dealerScore) {
					cout << "Your cards add up to more than the dealers! You win!\n\n";
					return 0;
				}
				else {
					cout << "Your cards add up to less than or equal to the dealers. Sorry, you lose!\n\n";
					return 0;
				}
			}
		}
		else {
			game.dealerDraw();
		}

	}
	return 0;
}