#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <sqlite3.h>
#include <stdio.h>
#include "Ferry.h"




class DatabaseConnection {
	//possibly implement adapter to work with the program to be able to work with any database

public:

	DatabaseConnection() {};
	DatabaseConnection(const char* s);
	virtual ~DatabaseConnection();
	static int createTable(const char* s);
	static int deleteData(const char* s);
	static int insertData(const char* s);
	static int updateData(const char* s);
	static int selectData(const char* s);
	static int callback(void* NotUsed, int argc, char** argv, char** azColName);
};