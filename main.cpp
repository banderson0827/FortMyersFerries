// (c) 2022 banderson0827 Brett Anderson
// This code is licensed under MIT license (see LICENSE.txt for details)


#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <sqlite3.h>
#include "Observer.h"
#include "Ferry.h"
#include "Subject.h"
#include "DisplayElement.h"
#include "FerryData.h"
#include "DatabaseConnection.h"
#include "CurrentFerriesDisplay.h"



int main()
{
	const char* ferryDir = R"(C:\FerryDB\FERRIES.db)"; // Local Ferry Database Directory
	const char* accountDir = R"(C:\FerryDB\FERRIES.db)"; // Local Account Database Directory
	DatabaseConnection ferryDB(ferryDir);
	DatabaseConnection accountDB(accountDir);
	FerryData *ferryData = new FerryData;
	CurrentFerriesDisplay *currentFerriesDisplay = new CurrentFerriesDisplay(*ferryData);
	

	ferryDB.createTable(ferryDir);
	ferryDB.insertData(ferryDir);
	ferryDB.updateData(ferryDir);
	ferryDB.deleteData(ferryDir);
	ferryDB.selectData(ferryDir); //command line arguments (config)


	int inputSelection;
	std::cout << "If you would like to purchase a ticket to one of the listed Ferries, please enter the number of the Ferry now, or enter 0 to exit the application : " << '\t';
	std::cin >> inputSelection;

	//TODO: Create a Ferry from the selection and use it with the current Account to create a new Reservation and then add it
	//      to the BookingHistory database.


}