// (c) 2022 banderson0827 Brett Anderson
// This code is licensed under MIT license (see LICENSE.txt for details)


#include <iostream>
#include <openssl/sha.h>
#include <cstring>
#include <iomanip>
#include <string>
#include <list>
#include <limits>
#include <regex>
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
std::string sanitizeAlphaNumeric(const std::string& input);
std::string sanitizeAlpha(const std::string& input);
std::string sanitizeNumeric(const std::string& input);
void initializeDB(const char* s);


enum MenuSelection{
    Create_Account,
    Login,
    View_Ferries,
    Exit
};


// Begin execution
int main() {
	const char* db_dir = R"(C:\FerryDB\FERRIES.db)"; // Local SQLite3 Database Directory
	DatabaseConnection db(db_dir);
	auto *ferryData = new FerryData;
	auto *currentFerriesDisplay = new CurrentFerriesDisplay(*ferryData);

    // Initialize the local DB
    initializeDB(db_dir);



    MenuSelection menuSelection = View_Ferries;
    while (menuSelection != Exit) {

        std::cout << "Home Screen:" << std::endl;
        std::cout << "0. Create Account" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. View Ferries" << std::endl;
        std::cout << "3. Exit" << std::endl;

        // Get menu choice from user with validation
        int numChoice;
        bool isValidInput = false;
        while (!isValidInput) {
            std::cout << "Enter your choice (0-3): ";
            std::cin >> numChoice;

            if (std::cin.fail() || numChoice < 0 || numChoice > 3) {
                std::cout << "Invalid input. Please enter a number between 0 and 3." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                isValidInput = true;
            }
        } // Input Validation


        menuSelection = static_cast<MenuSelection>(numChoice); // Change int input to corresponding menu option


        if (menuSelection == Create_Account) {
            /**
             * This is the user facing application so they will only be able to create
             * User Accounts, so no query to see what type of account they want to create.
             * Admin Accounts can only be created on the backend.
             */

            // Get username with validation 6 - 20 characters and removing non-alphanumeric characters
            std::string username;
            std::cout << "Enter your desired username: \n";
            std::cin >> username;

            // Validate the input
            while (username.empty() || username.length() < 6 || username.length() > 20) {
                std::cout << "Your username must be between 6 and 20 characters long. Please try again: \n";
                std::cin >> username;
            } // Validation

            username = sanitizeAlphaNumeric(username); // sanitize the input
            std::cout << "Accepted Username:\t" << username << std::endl;
            encrypt(username); // encrypt the data



            // Get password with validation 6 - 20 characters long. No need for sanitization here.
            std::string password;
            std::cout << "Enter your desired password: \n";
            std::cin >> password;

            // Validate the input
            while (password.empty() || password.length() < 6 || password.length() > 20) {
                std::cout << "Your password must be between 6 and 20 characters long. Please try again: \n";
                std::cin >> password;
            } // Validation

            std::cout << "Password accepted!";
            encrypt(password); // encrypt the data



            // Get first name with validation 1 - 20 characters long and removing non-alpha characters
            std::string firstName;
            std::cout << "Enter your first name: \n";
            std::cin >> firstName;

            // Validate the input
            while (firstName.empty() || firstName.length() < 1 || firstName.length() > 20) {
                std::cout << "Your first name must be between 1 and 20 characters long. Please try again: \n";
                std::cin >> firstName;
            } // Validation

            firstName = sanitizeAlpha(firstName); // sanitize the input
            std::cout << "Accepted First Name:\t" << firstName << std::endl;
            encrypt(firstName); // encrypt the data



            // Get last name with validation 1 - 20 characters long and removing non-alpha characters
            std::string lastName;
            std::cout << "Enter your last name: \n";
            std::cin >> lastName;

            // Validate the input
            while (lastName.empty() || lastName.length() < 1 || lastName.length() > 20) {
                std::cout << "Your last name must be between 1 and 20 characters long. Please try again: \n";
                std::cin >> lastName;
            } // Validation

            lastName = sanitizeAlpha(lastName); // sanitize the input
            std::cout << "Accepted Last Name:\t" << lastName << std::endl;
            encrypt(lastName); // encrypt the data




            // Get phone number with validation 10 characters long and removing non-numeric characters
            std::string phoneNumber;
            std::cout << "Enter your phone number (Example - 1234567890): \n";
            std::cin >> phoneNumber;

            // Validate the input
            while (phoneNumber.empty() || phoneNumber.length() != 10) {
                std::cout << "Your phone number must be 10 characters long. Please try again: \n";
                std::cin >> phoneNumber;
            } // Validation

            phoneNumber = sanitizeNumeric(phoneNumber); // sanitize the input
            std::cout << "Accepted Phone Number:\t" << phoneNumber << std::endl;
            encrypt(phoneNumber); // encrypt the data



            // Get email with validation 1 - 30 characters long. No need for sanitizing here.
            std::string emailAddress;
            std::cout << "Enter your email address: \n";
            std::cin >> emailAddress;

            // Validate the input
            while (emailAddress.empty() || emailAddress.length() < 1 || emailAddress.length() > 30) {
                std::cout << "Your email address must be between 1 and 30 characters long. Please try again: \n";
                std::cin >> emailAddress;
            } // Validation

            encrypt(emailAddress); // encrypt the data



            // Create the account and add it to the DB

            // Define the SQL query
            std::string sql = "INSERT INTO UserAccount"
                              "     VALUES (?, ?, ?, ?, ?, ?)";


        } // Create Account




        else if (menuSelection == Login) {
            std::cout << "You chose Option 1\n";
            // TODO: add code for Login

        } // Login

        else if (menuSelection == View_Ferries) {
            std::cout << "You chose Option 2\n";
            // TODO: add code for View_Ferries

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



// Sanitize the input by removing any non-alphanumeric characters
std::string sanitizeAlphaNumeric(const std::string& input) {
    std::regex pattern("[^a-zA-Z0-9]+");
    return std::regex_replace(input, pattern, "");

} // sanitizeAlphaNumeric



// Sanitize the input by removing any non-alpha characters
std::string sanitizeAlpha(const std::string& input) {
    std::regex pattern("[^a-zA-Z]+");
    return std::regex_replace(input, pattern, "");

} // sanitizeAlpha



// Sanitize the input by removing any non-numeric characters
std::string sanitizeNumeric(const std::string& input) {
    std::regex pattern("[^0-9]+");
    return std::regex_replace(input, pattern, "");

} // sanitizeNumeric



// Create tables if not exist already
void initializeDB(const char* s) {

    // DB Tables to be created
    std::string createFerry = "CREATE TABLE IF NOT EXISTS Ferry ("
                                        "id                   INT PRIMARY KEY AUTOINCREMENT, "
                                        "price				  DOUBLE NOT NULL, "
                                        "duration_minutes     INT NOT NULL, "
                                        "date				  DATE NOT NULL, "
                                        "time				  CHARACTER(5) NOT NULL, "
                                        "available_seats      INT NOT NULL, "
                                        "total_seats		  INT NOT NULL); ";

    std::string createUserAccount = "CREATE TABLE IF NOT EXISTS UserAccount ("
                                        "id                   INT PRIMARY KEY AUTOINCREMENT, "
                                        "username			  VARCHAR(20) NOT NULL, "
                                        "password             VARCHAR(20) NOT NULL, "
                                        "first_name			  VARCHAR(20) NOT NULL, "
                                        "last_name			  VARCHAR(20) NOT NULL, "
                                        "phone_number         CHARACTER(10) NOT NULL, "
                                        "email		          VARCHAR(30) NOT NULL); ";

    // Create the tables in the DB
    DatabaseConnection::createTable(s, createFerry);
    DatabaseConnection::createTable(s, createUserAccount);

} // initializeDB