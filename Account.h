#pragma once
#include <string>



class Account {

	int accountID;
	std::string username;
	std::string password;
	std::string firstName;
	std::string lastName;
	int phoneNumber;
	std::string emailAddress;

public:

	int assignAccountID();
};