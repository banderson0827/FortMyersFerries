#pragma once
#include <string>
#include <list>
#include "Account.h"
#include "Ferry.h"




class GuestAccount : public Account {

	int accountID;
	std::list<Ferry> bookingHistory;

public:

	GuestAccount();
};