// AirlineReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Here are the expected features of the system:

//Application will present a menu system of choice to the user
//
//1. Reserve a seat
//
//2. Flight Schedule
//
//3. Display passenger info
//
//4. Flight details
//
//5. User ticket infomation
//
//6. Exit the program

#include "stdafx.h"
#include <iostream>
#include "Database.h"
#include "User.h"
#include "Flight.h"
#include "Database.h"

using namespace std;
using namespace AirlineReservationSystem;

int displayMenu();
void reserveSeat(Database& db);
void presentFlightsSchedule(Database& db);
void displayPassengerInfo(Database& db);
void displayFlightInfo(Database& db);
void userTicketInfomation(Database& db);
Flight chooseFlight(Database& db);


int main()
{
	Database airlineDB;

	Flight f1("Seattle", "Boston", 1, 60);
	Flight f2("New York", "Mexico City", 2, 30);
	Flight f3("Seattle", "Tel Aviv", 3, 50);

	airlineDB.addFlight(f1);
	airlineDB.addFlight(f2);
	airlineDB.addFlight(f3);

	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			reserveSeat(airlineDB);
			break;
		case 2:
			presentFlightsSchedule(airlineDB);
			break;
		case 3:
			displayPassengerInfo(airlineDB);
			break;
		case 4:
			displayFlightInfo(airlineDB);
			break;
		case 5:
			userTicketInfomation(airlineDB);
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}

	return 0;
}

int displayMenu()
{
	int selection;

	cout << endl;
	cout << "Flight Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Reserve a seat" << endl;
	cout << "2) Flight schedule" << endl;
	cout << "3) Pasenger info" << endl;
	cout << "4) Flight details" << endl;
	cout << "5) User ticket info" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "---> ";

	cin >> selection;

	return selection;
}

void presentFlightsSchedule(Database& db) {
	auto allFlights = db.getAllFlight();
	for (Flight f : allFlights) {
		f.display();
	}
}

Flight chooseFlight(Database& db) {
	presentFlightsSchedule(db);
	int flightId;
	cout << "Choose FlightId " << endl;;
	cin >> flightId;
	Flight flight = db.getFlight(flightId);
	return flight;
}

User getUserData() {
	string firstName;
	string lastName;
	int userId;
	cout << "Your First name? ";
	cin >> firstName;
	cout << "Last name? ";
	cin >> lastName;
	cout << "Your Id number? ";
	cin >> userId;
	
	User* user = new User(firstName, lastName, userId);
	return *user;
}
void reserveSeat(Database& db)
{
	presentFlightsSchedule(db);
	int chosenSeat;
	

	Flight flight = chooseFlight(db);
	vector<int> freeSeats = flight.getFreeSeats();
	for (int seat : freeSeats) {
		cout << seat << " " ;
	}
	cout << endl << "Choose Your Seat " << endl;
	cin >> chosenSeat;

	User user = getUserData();
	user.setSeatNumber(chosenSeat);
	flight.reserveSeat(user);
}

void displayPassengerInfo(Database& db) {
	presentFlightsSchedule(db);
	Flight flight = chooseFlight(db);
	vector<User> users = flight.presentPassengers();
	for (User user : users) {
		cout << "Passenger Information:" << endl;
		cout << "-------------------------" << endl;
		cout << "Seat Number: " << user.getSeatNumber() << endl;
		cout << "Name: " << user.getFirstName() << " " << user.getLastName() << endl;
		cout << "Flight Number: " << flight.getFlightNumber() << endl;
		cout << "Flight from: " << flight.getDepartureCity() << "to " << flight.getDestinationCity() << endl;
		cout << endl;
	}
}

void userTicketInfomation(Database& db)
{
	presentFlightsSchedule(db);
	Flight flight = chooseFlight(db);
	User specificUser = getUserData();
	int userId = specificUser.getIdNumber();
	vector<User> users = flight.presentPassengers();
	bool userFound = false;
	for (User user : users) {
		if (userId == user.getIdNumber()) {
			userFound = true;
			cout << "Passenger Information:" << endl;
			cout << "-------------------------" << endl;
			cout << "Name: " << user.getFirstName() << " " << user.getLastName() << endl;
			cout << "Flight Number: " << flight.getFlightNumber() << endl;
			cout << "Flight from: " << flight.getDepartureCity() << "to " << flight.getDestinationCity() << endl;
			cout << "Seat Number: " << user.getSeatNumber() << endl;
			cout << endl;
		}
	}
	if (userFound == false) {
		cout << "Passenger not found." << endl;
	}
}

void displayFlightInfo(Database& db) {
	presentFlightsSchedule(db);
	Flight flight = chooseFlight(db);
	flight.display();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
