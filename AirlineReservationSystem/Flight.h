#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "User.h"

namespace AirlineReservationSystem {
	class Flight
	{
	public:
		Flight() = default;
		Flight(const std::string& destinationCity, const std::string& departureCity, int flightNumber, int seatsAmount);

		//Getters and setters
		const std::string& getDestinationCity() const;

		const std::string& getDepartureCity() const;

		int getFlightNumber() const;

		vector<int>& getFreeSeats();

		void reserveSeat(User& user) {
			users.push_back(user);
			int seatNumber = user.getSeatNumber();
			freeSeats.erase(std::remove(freeSeats.begin(), freeSeats.end(), seatNumber), freeSeats.end());
		}
	private:
		std::string mDestinationCity;
		std::string mDepartureCity;
		std::vector<User> users;
		std::vector<int> freeSeats;
		int mFlightNumber = -1;
		time_t mDepartureTime;
		//difftime mFlightDuration;
		int differenceInTimeWithDestination = 0;
		bool mOnTime = true;
	};
}