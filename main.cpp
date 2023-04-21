// (c) 2022 banderson0827 Brett Anderson
// This code is licensed under MIT license (see LICENSE.txt for details)


#include <iostream>
#include <openssl/sha.h>
#include <cstring>
#include <iomanip>
#include <string>
#include <list>
#include "sqlite3.h"
#include "Observer.h"
#include "Ferry.h"
#include "Subject.h"
#include "DisplayElement.h"
#include "FerryData.h"
#include "DatabaseConnection.h"
#include "CurrentFerriesDisplay.h"



// Declarations
std::string encrypt(std::string & plain_text);

enum MenuSelection{
    Create_Account,
    Login,
    View_Ferries,
    Exit
};


// Begin execution
int main() {
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


    MenuSelection menuSelection = View_Ferries;
    while (menuSelection != Exit) {

        std::cout << "Home Screen:" << std::endl;
        std::cout << "0. Create Account" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. View Ferries" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int numChoice;
        std::cout << "Enter your choice (0-3): ";
        std::cin >> numChoice;
        menuSelection = static_cast<MenuSelection>(numChoice); // Change int input to corresponding menu option

        if (menuSelection == Create_Account) {
            /**
             * This is the user facing application so they will only be able to create
             * User Accounts, so no query to see what type of account they want to create.
             * Admin Accounts can only be created on the backend.
             */

            // Get username
            std::string username;
            std::cout << "Enter your desired username: \n";
            std::cin >> username;
            encrypt(username); // encrypt the data

            // Get password
            std::string password;
            std::cout << "Enter your desired password: \n";
            std::cin >> password;
            encrypt(password); // encrypt the data

            // Get first name
            std::string firstName;
            std::cout << "Enter your first name: \n";
            std::cin >> firstName;
            encrypt(firstName); // encrypt the data

            // Get last name
            std::string lastName;
            std::cout << "Enter your last name: \n";
            std::cin >> lastName;
            encrypt(lastName); // encrypt the data

            // Get email
            std::string emailAddress;
            std::cout << "Enter your email address: \n";
            std::cin >> emailAddress;
            encrypt(emailAddress); // encrypt the data

        } // Create Account

        else if (menuSelection == Login) {
            std::cout << "You chose Option 1\n";
            // add code for Option 2

        } // Login

        else if (menuSelection == View_Ferries) {
            std::cout << "You chose Option 2\n";
            // add code for Option 3

        } // View Ferries

        else if (menuSelection == Exit) {
            std::cout << "Exiting...\n";
            std::exit(0);

        } // Exit

        else {
            std::cout << "Invalid choice. Please enter a number between 0 and 3.\n";

        } // End of main menu

    } // While loop for main menu


	// int inputSelection;
	// std::cout << "If you would like to purchase a ticket to one of the listed Ferries, please enter the number of the Ferry now, or enter 0 to exit the application : " << '\t';
	// std::cin >> inputSelection;

	// TODO: Create a Ferry from the selection and use it with the current Account to create a new Reservation and then add it
	//       to the BookingHistory database.


} // main



/**
 * Takes a string and encrypts the content using the OpenSSL SHA256 hash algorithm
 * @param plain_text - String to be encrypted (hashed)
 * @return encrypted (hashed) string
 */
std::string encrypt(std::string & plain_text) {

    // Create a buffer for the hashed data
    unsigned char hash[SHA256_DIGEST_LENGTH];

    // Compute the SHA256 hash
    SHA256((const unsigned char*) plain_text.c_str(), plain_text.length(), hash);

    // Convert the hash to a string
    char hash_str[SHA256_DIGEST_LENGTH*2+1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash_str[i*2], "%02x", hash[i]);
    }

    // Print the hashed data for testing
    // std::cout << "SHA256 hash: " << hash_str << std::endl;

    return hash_str;

} // encrypt