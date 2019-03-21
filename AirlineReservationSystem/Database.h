#pragma once

#include <iostream>
#include <vector>
#include "Flight.h"

namespace AirlineReservationSystem {

	class Database
	{
		public:
			Flight& addFlight(Flight flight);
			Flight& getFlight(int flightNumber);
			std::vector<Flight>& getAllFlight();

		private:
			std::vector<Flight> mFlights;
	};
}
