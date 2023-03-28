#include "FerryData.h"







void FerryData::registerObserver(Observer *observer) {
	observers.push_back(observer);
}



void FerryData::removeObserver(Observer *observer) {
	observers.remove(observer);
}



void FerryData::notifyObservers() {
	std::list<Observer *>::iterator iterator = observers.begin();
	while (iterator != observers.end()) {
		(*iterator)->update(ferries);
		++iterator;
	}
}



void FerryData::ferriesUpdated() {
	notifyObservers();
}



void FerryData::setFerries(std::list<Ferry> ferries) {
	this->ferries.assign(ferries.begin(), ferries.end());
	ferriesUpdated();
}