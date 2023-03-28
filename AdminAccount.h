#pragma once
#include <string>
#include "Account.h"
#include "Ferry.h"
#include "UserAccount.h"
#include "GuestAccount.h"




class AdminAccount : public Account {

	int accountID;
	std::string username;
	std::string password;
	std::string firstName;
	std::string lastName;
	int phoneNumber;
	std::string emailAddress;

public:

	AdminAccount(std::string, std::string, std::string, std::string, int, std::string);
	void viewBookingHistory(Account);
	void removeAccount(UserAccount);
};