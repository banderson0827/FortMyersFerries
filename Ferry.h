#pragma once
#include <iostream>
#include <string>
#include <list>





class Ferry {

	double price;
	int durationMinutes;
	std::string date;
	std::string time;
	int availableSeats;
	int totalSeats;

public:
	Ferry();
	Ferry(double, int, std::string, std::string, int, int);
	double getPrice() { return this->price; };
	int getDurationMinutes() { return this->durationMinutes; };
	std::string getDate() { return this->date; };
	std::string getTime() { return this->time; };
	int getAvailableSeats() { return this->availableSeats; };
	int getTotalSeats() { return this->totalSeats; };
};