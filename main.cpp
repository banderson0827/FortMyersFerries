// (c) 2022 banderson0827 Brett Anderson
// This code is licensed under MIT license (see LICENSE.txt for details)


#include <iostream>
#include <openssl/aes>
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


unsigned char encrypt(std::string plain_text);
enum MenuSelection{
    Create_Account,
    Login,
    View_Ferries,
    Exit
};

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


    MenuSelection menuSelection = View_Ferries;
    while (menuSelection != Exit) {

        std::cout << "Home Screen:" << std::endl;
        std::cout << "0. Create Account" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. View Ferries" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int numChoice;
        std::cout << "Enter your choice (1-4): ";
        std::cin >> numChoice;
        menuSelection = static_cast<MenuSelection>(numChoice); // Change int input to corresponding menu option

        switch (menuSelection) {
            case Create_Account:
                /**
                 * This is the user facing application so they will only be able to create
                 * User Accounts, so no query to see what type of account they want to create.
                 * Admin Accounts can only be created on the backend.
                 */

                // Get username
                std::string plainUsername;
                std::cout << "Enter your desired username: \n";
                std::cin >> plainUsername;
                unsigned char username = encrypt(plainUsername); // encrypt the data

                // Get password
                std::string plainPassword;
                std::cout << "Enter your desired password: \n";
                std::cin >> plainPassword;
                unsigned char password = encrypt(plainPassword); // encrypt the data

                // Get first name
                std::string plainFirstName;
                std::cout << "Enter your first name: \n";
                std::cin >> plainFirstName;
                unsigned char firstName = encrypt(plainFirstName); // encrypt the data

                // Get last name
                std::string plainLastName;
                std::cout << "Enter your last name: \n";
                std::cin >> plainLastName;
                unsigned char lastName = encrypt(plainLastName); // encrypt the data

                // Get email
                std::string plainEmailAddress;
                std::cout << "Enter your email address: \n";
                std::cin >> plainEmailAddress;
                unsigned char emailAddress = encrypt(plainEmailAddress); // encrypt the data
                break;

            case Login:
                std::cout << "You chose Option 2\n";
                // add code for Option 2
                break;

            case View_Ferries:
                std::cout << "You chose Option 3\n";
                // add code for Option 3
                break;

            case Exit:
                std::cout << "Exiting...\n";
                std::exit(0);

        }
    }


	// int inputSelection;
	// std::cout << "If you would like to purchase a ticket to one of the listed Ferries, please enter the number of the Ferry now, or enter 0 to exit the application : " << '\t';
	// std::cin >> inputSelection;

	// TODO: Create a Ferry from the selection and use it with the current Account to create a new Reservation and then add it
	//       to the BookingHistory database.


}


unsigned char encrypt(std::string plain_text) {
    // The encryption key and initialization vector (IV)
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(key, AES_BLOCK_SIZE);
    RAND_bytes(iv, AES_BLOCK_SIZE);

    // Initialize the encryption context
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 256, &aes_key);

    // Encrypt the data
    int len = plain_text.length();
    unsigned char encrypted[len + AES_BLOCK_SIZE];
    AES_cbc_encrypt((unsigned char*)plain_text.c_str(), encrypted, len, &aes_key, iv, AES_ENCRYPT);

    return encrypted;
} // encrypt