#pragma once

#include <iostream>
#include <vector>
#include "Flight.h"

namespace AirlineReservationSystem {
	const int kFirstFlightNumber = 1000;

	class Database
	{
	public:
		Flight& addFlight(const std::string& destination,
			const int flightNumber);
		Flight& getFlight(int flightNumber);
		Flight& getFlight(const std::string& destination);

		void displayAll() const;
		void displayCurrent() const;
		void displayFuture() const;

	private:
		std::vector<Flight> mFlights;
		int mNextFlightNumber = kFirstFlightNumber;
	};
}
