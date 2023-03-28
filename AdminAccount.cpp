#include <iostream>
#include <list>
#include "AdminAccount.h"






AdminAccount::AdminAccount(std::string username, std::string password, std::string firstName, std::string lastName, 
	int phoneNumber, std::string emailAddress) {

	this->username = username;
	this->password = password;
	this->firstName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
	this->emailAddress = emailAddress;
	this->accountID = assignAccountID();
}


void AdminAccount::viewBookingHistory(Account account) {
	//TODO: Add Database query to get the booking history of any user/guest account and display it
}



void AdminAccount::removeAccount(UserAccount userAccount) {
	//TODO: Remove any user/guest account from the Database
}