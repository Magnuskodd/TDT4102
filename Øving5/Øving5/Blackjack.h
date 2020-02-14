#pragma once
#include "Card.h"
#include "CardDeck.h"

vector<int> getSum(vector<Card> summer);
bool blackjack(vector<Card> user);
int getMax(vector<int> summer);

class Blackjack {
private: 
	vector<Card> player;
	vector<Card> dealer;
	CardDeck deck;
	int playerSum;
	int dealerSum;
	bool gameOver;

public:
	Blackjack() : playerSum{ 0 }, dealerSum{ 0 }, gameOver{ false }
	{
		deck.shuffle();
		for (int i = 0; i < 2; ++i) {
			Card drawed = deck.drawCard();
			player.push_back(drawed);

			Card dealerDrawed = deck.drawCard();
			dealer.push_back(dealerDrawed);
		}

	}
		

	void showHand() {
		cout << "Your cards: \n";
		for (auto x : player) {
			cout << x.toString() << "\n";
		}
	}

	void showDealerhand() {
		cout << "The dealers open cards: \n";
		for (int i = 0; i < dealer.size() - 1; ++i) {
			cout << dealer[i].toString() << "\n";
		}
	}

	void playerChoice(){
		int choice = 0;
		cout << "Do you want to stand(0) or draw(1)? \n ";
		cin >> choice;

		if (choice) {
			Card add = deck.drawCard();
			player.push_back(add);
			cout << "You drew a " << add.toString() << "\n";
		}
	}

	vector<int> getSumVector(string decider) {
		if (decider == "player") {
			vector<int> sumVector = getSum(player);
			return sumVector;
		}
		else if (decider == "dealer") {
			vector<int> sumVector = getSum(dealer);
			return sumVector;
		}
		else {
			cout << "Check the code!";
			return { 0 };
		}
	}

	bool checkGameOver() {
		return gameOver;
	}

	void showHoleCard() {
		cout << "The dealers hole card is " << dealer[dealer.size() - 1].toString() << "\n";
	}

	bool checkBlackjack(string decider) {
		if (decider == "player") {
			bool isBlackjack = blackjack(player);
			return isBlackjack;
		}
		else if (decider == "dealer") {
			bool isBlackjack = blackjack(dealer);
			return isBlackjack;
		}
	}

	void dealerDraw() {
		Card add = deck.drawCard();
		dealer.push_back(add);
	}
};
