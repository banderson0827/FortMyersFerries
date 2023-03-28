#include "DatabaseConnection.h"



using namespace std;






// If DB exists, opens DB. If DB does not exist, creates DB.
DatabaseConnection::DatabaseConnection(const char* s) {
	sqlite3* DB;

	int exit = 0;
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);
}






DatabaseConnection::~DatabaseConnection() {
	int sqlite3_close(sqlite3*);
}







int DatabaseConnection::createTable(const char* s) {

	sqlite3* DB;
	char* messageError;

	string sql = "CREATE TABLE IF NOT EXISTS FERRIES("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"PRICE				  DOUB NOT NULL, "
		"DURATION_MINUTES     INT NOT NULL, "
		"DATE				  CHAR(10) NOT NULL, "
		"TIME				  CHAR(7) NOT NULL, "
		"AVAILABLE_SEATS      INT NOT NULL, "
		"TOTAL_SEATS		  INT NOT NULL); ";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

	return 0;
}






int DatabaseConnection::insertData(const char* s) {
	sqlite3* DB;
	char* messageError;

	string sql("INSERT INTO FERRIES (PRICE, DURATION_MINUTES, DATE, TIME, AVAILABLE_SEATS, TOTAL_SEATS) VALUES(45.00, 120, '01/12/2023', '04:30PM', 80, 100);"
		"INSERT INTO FERRIES (PRICE, DURATION_MINUTES, DATE, TIME, AVAILABLE_SEATS, TOTAL_SEATS) VALUES(30.00, 45, '01/23/2023', '01:15PM', 95, 120);"
		"INSERT INTO FERRIES (PRICE, DURATION_MINUTES, DATE, TIME, AVAILABLE_SEATS, TOTAL_SEATS) VALUES(50.00, 120, '02/07/2023', '11:30AM', 90, 100);"
		"INSERT INTO FERRIES (PRICE, DURATION_MINUTES, DATE, TIME, AVAILABLE_SEATS, TOTAL_SEATS) VALUES(65.00, 180, '02/21/2023', '02:00PM', 50, 75);");

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in insertData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records inserted Successfully!" << endl;

	return 0;
}






int DatabaseConnection::updateData(const char* s) {

	sqlite3* DB;
	char* messageError;

	string sql("UPDATE FERRIES SET PRICE = 25.00 WHERE DATE = '01/12/2023'");

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in updateData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records updated Successfully!" << endl;

	return 0;
}






int DatabaseConnection::deleteData(const char* s) {

	sqlite3* DB;
	char* messageError;

	string sql = "DELETE FROM FERRIES WHERE DATE = '01/23/2023';";

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in deleteData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records deleted Successfully!" << endl;

	return 0;
}





int DatabaseConnection::selectData(const char* s) {

	sqlite3* DB;
	char* messageError;

	string sql = "SELECT * FROM FERRIES;";

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error in selectData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records selected Successfully!" << endl;

	return 0;
}




// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
int DatabaseConnection::callback(void* NotUsed, int argc, char** argv, char** azColName) {

	for (int i = 0; i < argc; i++) {
		// column name and value
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;

	return 0;
}