#include <iostream>
#include <iomanip>
#include "CurrentFerriesDisplay.h"








CurrentFerriesDisplay::CurrentFerriesDisplay(Subject &ferryData) : ferryData_(ferryData) {
	this->ferryData_.registerObserver(this);
}





void CurrentFerriesDisplay::update(const std::list<Ferry>& ferries) {
	this->ferries.assign(ferries.begin(), ferries.end());
	display();
}





void CurrentFerriesDisplay::removeMeFromList() {
	ferryData_.removeObserver(this);
}





void CurrentFerriesDisplay::display() {
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << "Available Ferries:" << '\n' << '\n';

	for (Ferry ferry : ferries) {
		std::cout << "Date: " << ferry.getDate() << '\n'
			<< "Time: " << ferry.getTime() << '\n'
			<< "Duration: " << ferry.getDurationMinutes() << '\n'
			<< "Seats Available: " << ferry.getAvailableSeats() << "/" << ferry.getTotalSeats() << '\n'
			<< "Price: $" << ferry.getPrice() << '\n' << '\n' << '\n';
	}
}