#pragma once
#include "Event.h"
class Meeting : public Event
{
protected:
	string person;
	string place;

public:
	Meeting() = default;
	Meeting(string person, string place, Date date, Time_ time):Event(date,time)
	{
		this->person = person;
		this->place = place;
	}
	~Meeting() {};

	string toString() override
	{
		return "     Meeting: \n Name: " + this->person +
			"\n Place: " + this->place +
			"\n Date: " + to_string(this->date.getDay()) + "-" + to_string(this->date.getMonth()) + "-" + to_string(this->date.getYear()) +
			"\n Time: " + to_string(this->time.getHour()) + ":" + to_string(this->time.getMinutes()) + ":" + to_string(this->time.getSeconds())+"\n";
	}
};

