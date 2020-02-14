#pragma once
#include "std_lib_facilities.h"

enum class Suit {clubs, diamonds, hearts, spades};

enum class Rank {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

string suitToString(Suit card);

string rankToString(Rank card);

struct CardStruct {
	Suit s;
	Rank r;
};

string toString(CardStruct card);

string toStringShort(CardStruct card);

class Card {
private:
	Suit s;
	Rank r;
	bool valid;

public:
	Card() : valid{ false } {}

	Card(Suit suit, Rank rank) : s{ suit }, r{ rank }, valid{ true }{}

	string suit() {
		string suit = suitToString(s);
		return suit;
	}

	string rank() {
		string rank = rankToString(r);
		return rank;
	}

	Rank getRank() {
		return r;
	}

	bool isValid() {
		return valid;
	}

	string toString() {
		if (valid) {
			string suit = suitToString(s);
			string rank = rankToString(r);
			string cardValue = rank + " of " + suit;
			return cardValue;
		}
		else {
			return "Unvalid card";
		}
	}

	string toStringShort() {
		if (valid) {
			string suit = suitToString(s);
			char suitShort = suit[0];

			int rank = static_cast<int>(r) + 2;

			string rankString = to_string(rank);

			return suitShort + rankString;
		}
		else {
			return "Unvalid card";
		}
	}
};
