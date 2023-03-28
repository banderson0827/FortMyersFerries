#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "Account.h"
#include "Ferry.h"
#include "UserAccount.h"
#include "GuestAccount.h"





class Reservation {

	Ferry ferry;
	Account account;

	Reservation(Ferry, Account);
	void userPurchaseTicket(UserAccount&);
	void generatePurchaseReceipt(Account&);
	void guestPurchaseTicket(GuestAccount&);
};