#pragma once
#include "Event.h"
#include<string>

class Custom : public Event
{
protected:
	string description;
public:
	Custom() = default;
	Custom(string description,Date date, Time_ time) :Event(date, time)
	{
		this->description = description;
	}
	~Custom() {};

	string toString() override {
		return "     Custom: \n Description: "+ this->description +
			"\n Date: " + to_string(this->date.getDay()) + "-" + to_string(this->date.getMonth()) + "-" + to_string(this->date.getYear()) +
			"\n Time: " + to_string(this->time.getHour()) + ":" + to_string(this->time.getMinutes()) + ":" + to_string(this->time.getSeconds())+"\n";
	}
};

