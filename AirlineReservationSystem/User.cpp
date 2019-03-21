
#include <string>
#include <vector>
#include "User.h"

using namespace std;

namespace AirlineReservationSystem {
	User::User(const std::string& fisrtName, const std::string& lastName, const int idNumber)
		: mFirstName(fisrtName), mLastName(lastName), mIdNumber(idNumber){}

	void User::setFirstName(const std::string& firstName) {
		mFirstName = firstName;
	}
	const std::string& User::getFirstName() const {
		return mFirstName;
	}

	void User::setLastName(const std::string& lastName) {
		mLastName = lastName;
	}
	const std::string& User::getLastName() const {
		return mLastName;
	}

	void User::setIdNumber(int idNumber) {
		mIdNumber = idNumber;
	}
	int User::getIdNumber() const {
		return mIdNumber;
	}

	void User::setSeatNumber(int seatNumber) {
		mSeatNumber = seatNumber;
	}
	int User::getSeatNumber() const {
		return mSeatNumber;
	}
}