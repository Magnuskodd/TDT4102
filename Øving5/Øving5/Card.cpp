#include "std_lib_facilities.h"
#include "Card.h"
#include<string>
#include<locale>

string suitToString(Suit card) {
	switch (card) {
		case Suit::clubs:
			return "clubs";
			break;
		case Suit::diamonds:
			return "diamonds";
			break;
		case Suit::hearts:
			return "hearts";
			break;
		case Suit::spades:
			return "spades";
			break;
	}
}

string rankToString(Rank card) {
	switch (card) {
		case Rank::two:
			return "two";
		case Rank::three:
			return "three";
		case Rank::four:
			return "four";
		case Rank::five:
			return "five";
		case Rank::six:
			return "six";
		case Rank::seven:
			return "seven";
		case Rank::eight:
			return "eight";
		case Rank::nine:
			return "nine";
		case Rank::ten:
			return "ten";
		case Rank::jack:
			return "jack";
		case Rank::queen:
			return "queen";
		case Rank::king:
			return "king";
		case Rank::ace:
			return "ace";
	}
}

string toString(CardStruct card) {
	string suit = suitToString(card.s);
	string rank = rankToString(card.r);
	string cardValue = rank + " of " + suit;
	return cardValue;
}

string toStringShort(CardStruct card) {
	string suit = suitToString(card.s);
	char suitShort = suit[0];

	int rank = static_cast<int>(card.r) + 2;

	string rankString = to_string(rank);

	return suitShort + rankString;
}