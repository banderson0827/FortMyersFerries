#pragma once
#include <iostream>
#include <string>
#include "Observer.h"






class Subject {

public:

	virtual ~Subject() {};
	virtual void registerObserver(Observer *observer) = 0;
	virtual void removeObserver(Observer *observer) = 0;
	virtual void notifyObservers() = 0;
};