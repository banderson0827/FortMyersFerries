#pragma once
#include <string>
#include <list>
#include "Observer.h"
#include "Ferry.h"
#include "Subject.h"
#include "DisplayElement.h"
#include "FerryData.h"




class CurrentFerriesDisplay : public Observer, DisplayElement {

	std::list<Ferry> ferries;
	Subject &ferryData_;

public:

	CurrentFerriesDisplay(Subject &ferryData);
	virtual ~CurrentFerriesDisplay() {};
	void update(const std::list<Ferry> &ferries) override;
	void removeMeFromList();
	void display() override;
};