#include "std_lib_facilities.h"
#include "Card.h"
#include<string>
#include<locale>

vector<int> getSum(vector<Card> summer) {
	int sum = 0; 
	int sumWithAce = 0;
	bool canBlackjack = false;

	for (auto card : summer) {
		switch(card.getRank()) {
		case Rank::ace:
			sum += 1;
			sumWithAce += 11;
			break;
		case Rank::king:
			sum += 10;
			sumWithAce += 10;
			break;
		case Rank::queen:
			sum += 10;
			sumWithAce += 10;
			break;
		case Rank::jack:
			sum += 10;
			sumWithAce += 10;
			break;
		default:
			int adder = static_cast<int>(card.getRank()) + 2;
			sum += adder;
			sumWithAce += adder;
			break;
		}
	}

	vector<int> sumsVector{ sum, sumWithAce };
	return sumsVector;
}

bool blackjack(vector<Card> user) {
	bool isBlackjack = false;

	if (user.size() == 2) {
		if (user[0].getRank() == Rank::ace) {
			if (static_cast<int>(user[1].getRank()) <= 11 && static_cast<int>(user[1].getRank()) >= 8) {
				isBlackjack = true;
			}
		}
		else if (static_cast<int>(user[0].getRank()) <= 11 && static_cast<int>(user[0].getRank()) >= 8) {
			if (user[1].getRank() == Rank::ace) {
				isBlackjack = true;
			}
		}
	}

	return isBlackjack;
}

int getMax(vector<int> summer) {
	int max = 0;
	if (summer[1] > 21) {
		max = summer[0];
	}
	else {
		max = summer[1];
	}
	return max;
}