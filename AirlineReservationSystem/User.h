#pragma once
#include <string>

namespace AirlineReservationSystem {
	class User
	{
	public:
		User() = default;
		User(const std::string& fisrtName,
			const std::string& lastName);

		void addUser();
		void removeUser();

		void display() const;

		//Getters and setters
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setIdNumber(int employeeNumber);
		int getIdNumber() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		int idNumber = -1;
	};
}