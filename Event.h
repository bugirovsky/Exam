#pragma once
#include"Date.h"
#include"Time_.h"
#include<string>
#include<iostream>
using namespace std;

class Event
{
protected:
	Date date;
	Time_ time;

public:
	Event() = default;
	Event(Date date, Time_ time)
	{
		this->date = date;
		this->time = time;
	};
	
	~Event() {};
	
	virtual string toString() {
		return "Event\nDate: " + to_string(this->date.getDay()) + "-" + to_string(this->date.getMonth()) + "-" + to_string(this->date.getYear()) +
			"\nTime: " + to_string(this->time.getHour()) + ":" + to_string(this->time.getMinutes()) + ":" + to_string(this->time.getSeconds()) + "\n";
	}
	
	// сравнивает и дату и время вместе.
	bool CompareAll(Event& x) 
	{
		if (x.date > date) return true;
		if (x.date < date) return false;
		if (x.date == date) 
		{
			if (x.time > time) return true;
			else return false;
		}
	}
};

