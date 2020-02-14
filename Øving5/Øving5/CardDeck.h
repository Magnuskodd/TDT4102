#pragma once
#include "Card.h"

class CardDeck {
private:
	vector<Card> cards;
	int currentCardIndex;

	void swap(int firstIndex, int secondIndex) {
		Card temp = cards[firstIndex];
		cards[firstIndex] = cards[secondIndex];
		cards[secondIndex] = temp;
	}

public:
	CardDeck() : currentCardIndex{ 0 } 
	{
		array<Suit, 4> suits = { Suit::clubs, Suit::diamonds, Suit::hearts, Suit::spades };
		
		array<Rank, 13> ranks = { Rank::two, Rank::three, Rank::four, Rank::five, Rank::six, Rank::seven, Rank::eight, Rank::nine, Rank::ten, Rank::jack, Rank::queen, Rank::king, Rank::ace };

		for (auto x : suits) {
			for (auto y : ranks) {
				Card add(x, y);
				cards.push_back(add);
			}
		}
		
	}

	void print() {
		for (auto x : cards) {
			cout << x.toString() << "\n";
		}
	}

	void printShort() {
		for (auto x : cards) {
			cout << x.toStringShort() << "\n";
		}
	}

	void shuffle() {
		
		for (int i = 0; i < 58; ++i) {
			int firstRandomIndex = rand() % 52;
			int secondRandomIndex = rand() % 52;

			swap(firstRandomIndex, secondRandomIndex);
		}
	}

	const Card& drawCard() {
		Card returnCard = cards[currentCardIndex];
		currentCardIndex++;
		return returnCard;
	}
};