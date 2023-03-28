#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Ferry.h"






class Observer {

public:

	virtual ~Observer() {};
	virtual void update(const std::list<Ferry> &ferries) = 0;
};