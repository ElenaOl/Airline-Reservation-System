#include "stdafx.h"
#include <iostream>
#include "Flight.h"

using namespace std;

namespace AirlineReservationSystem {
	Flight::Flight(const std::string& destinationCity, const std::string& departureCity, int flightNumber, int seatsAmount)
		: mDestinationCity(destinationCity), mDepartureCity(departureCity), mFlightNumber(flightNumber) {
		for (int i = 1; i <= seatsAmount; i++) {
			freeSeats.push_back(i);
		}
	}
	

	const string& Flight::getDestinationCity() const
	{
		return mDestinationCity;
	}

	const string& Flight::getDepartureCity() const
	{
		return mDepartureCity;
	}

	int Flight::getFlightNumber() const {
		return mFlightNumber;
	}

	vector<int>& Flight::getFreeSeats() {
		return freeSeats;
	}

	/*void setDepartureTime(int flightNumber) {


	}

	 getDepartureTime() const {
		return mDepartureTime;
	}


	 void setFlightDuration(int flightNumber) {
	 }
	 int getFlightDuration() const {
		 return 
	 }

	 void setDifferenceInTimeWithDestination(int differenceInTime) {
		 mdifferenceInTimeWithDestination = differenceInTime;
	 }

	 int getDifferenceInTimeWithDestination() const {
		return mdifferenceInTimeWithDestination;
	 }

	 int getArrivalTime() const {
		 return mDepartureTime + 
	 }
*/

	
	 bool Flight::isOnTime() const {
		 return mOnTime;
	}

	void Flight::display() const
	{
		cout << "Flight from: " << getDestinationCity() << "to " << getDepartureCity() << endl;
		cout << "-------------------------" << endl;
		cout << "Flight Number: " << getFlightNumber() << endl;
		cout << "DepartureTime: " << getDepartureTime() << endl;
		cout << "Arrival Time: " << getArrivalTime() << endl;
		cout << endl;
	}


}