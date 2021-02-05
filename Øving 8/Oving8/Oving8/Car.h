#pragma once
class Car {
private:
	int freeSeats;

public:
	Car(int freeSeats) : freeSeats{ freeSeats } {}

	bool hasFreeSeats() const {
		if (freeSeats > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void reserveFreeSeat() {
		--freeSeats;
	}
};