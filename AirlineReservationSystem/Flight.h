#pragma once
#include <string>
#include <vector>
#include <ctime>
#include "User.h"

namespace AirlineReservationSystem {
	class Flight
	{
	public:
		Flight() = default;
		Flight(const std::string& destinationCity, const std::string& departureCity);

		void addFlight();
		void removeFlight();
		void delayFlight();
		void display() const;

		//Getters and setters
		void setDestination(const std::string& destination);
		const std::string& getDestination() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setFlightNumber(int flightNumber);
		int getFlightNumber() const;

		bool isHired() const;

	private:
		std::string mDestinationCity;
		std::string mDepartureCity;
		std::vector<User> seats;
		int mFlightNumber = -1;
		std::string mDepartureTime;
		std::string mDuration;
		int differenceInTimeWithDestination = 0;
		bool mArriving = false;
	};
}