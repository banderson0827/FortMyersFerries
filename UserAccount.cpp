#include <iostream>
#include "UserAccount.h"





UserAccount::UserAccount(std::string username, std::string password, std::string firstName, std::string lastName, 
	int phoneNumber, std::string emailAddress) {

	this->username = username;
	this->password = password;
	this->firstName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
	this->emailAddress = emailAddress;
	this->accountID = assignAccountID();

	//TODO: Add new account to Account Database

}


void UserAccount::viewBookingHistory() {
	//TODO: Add Database query to get the booking history of this account and display it
}