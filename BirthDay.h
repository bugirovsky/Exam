#pragma once
#include "Event.h"
#include<string>

class BirthDay : public Event
{
protected:
	string hero;
	string place;
	int age;

public:
	BirthDay() = default;

	BirthDay(string hero, string place, int age, Date date, Time_ time): Event(date,time)
	{
		this->hero = hero;
		this->place = place;
		this->age = age;
	};

	~BirthDay() {};
	
	string toString() override
	{
		return "     Birthday: \n Name: " + this->hero +
			"\n Place: " + this->place +
			"\n Age: " + to_string(this->age) +
			"\n Date: " + to_string(this->date.getDay()) + "-" + to_string(this->date.getMonth()) + "-" + to_string(this->date.getYear())+
			"\n Time: " + to_string(this->time.getHour()) + ":" + to_string(this->time.getMinutes()) + ":" + to_string(this->time.getSeconds())+"\n";
	}
};

