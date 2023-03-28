#pragma once
#include <string>
#include <list>
#include "Account.h"
#include "Ferry.h"




class UserAccount : public Account {

	int accountID;
	std::string username;
	std::string password;
	std::string firstName;
	std::string lastName;
	int phoneNumber;
	std::string emailAddress;
	std::list<Ferry> bookingHistory;

public:

	UserAccount(std::string, std::string, std::string, std::string, int, std::string);
	void viewBookingHistory();
};