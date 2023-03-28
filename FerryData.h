#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Observer.h"
#include "Ferry.h"
#include "Subject.h"






class FerryData : public Subject {

	std::list<Observer *> observers;
	std::list<Ferry> ferries;

public:

	FerryData() {};
	virtual ~FerryData() {};
	void registerObserver(Observer *observer) override;
	void removeObserver(Observer *observer) override;
	void notifyObservers() override;
	void ferriesUpdated();
	void setFerries(std::list<Ferry>); //Simulating Database Administrator. Need to implement database rather than using this method.

};