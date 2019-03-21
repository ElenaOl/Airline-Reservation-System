#pragma once

#include <iostream>
#include <vector>
#include "Flight.h"

namespace AirlineReservationSystem {

	class Database
	{
	public:
		Flight& addFlight(Flight flight) { mFlights.push_back(flight); }
		Flight& getFlight(int flightNumber){ }
		vector<Flight>& getAllFlight() { return mFlights; }

	private:
		std::vector<Flight> mFlights;
	};
}
