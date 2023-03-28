#include "Ferry.h"





Ferry::Ferry() {
	this->price = 0.00;
	this->durationMinutes = 0;
	this->date = "MM/DD/YYYY";
	this->time = "00:00AM";
	this->availableSeats = 0;
	this->totalSeats = 0;
}

Ferry::Ferry(double price, int durationMinutes, std::string date, std::string time, int availableSeats, int totalSeats) {
	this->price = price;
	this->durationMinutes = durationMinutes;
	this->date = date;
	this->time = time;
	this->availableSeats = availableSeats;
	this->totalSeats = totalSeats;
}