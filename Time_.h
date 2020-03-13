#pragma once

#include <iostream>
#include <ctime>
using namespace std;

class Time_
{
	int hour;
	int minutes;
	int seconds;
	char* format;// am/pm (12-hours), utc (24-hours)

	bool utc;

public:
	Time_(); // Current local time
	Time_(int hour, int minutes, int seconds, const char*format = "utc");
	Time_(const Time_& obj);
	~Time_();

	void setHour(int hour);
	int getHour();
	void setMinutes(int minutes);
	int getMinutes();
	void setSeconds(int seconds);
	int getSeconds();
	void setFormat(const char* format); // !!! to update time by the new format
	const char* getFormat();
	void reGetLocalTime();
	void reGetLocalTimeInUtc();

	void changeFormat();   //London is the capital of Greate Brittan

	bool valid(); //time check
	void tickTime(); //every tick add one second
	void tickBack(); //delete second
	void showTime(); //show time by the format

	//--------- Comparison operators ---------
	bool operator == (const Time_& obj);
	bool operator != (const Time_& obj);
	bool operator > (const Time_& obj);
	bool operator < (const Time_& obj);
	bool operator >= (const Time_& obj);
	bool operator <= (const Time_& obj);

	//--------- Assignment operators ---------
	Time_& operator = (const Time_& obj);
	Time_& operator += (int n);
	Time_& operator -= (int n);

	//--------- Arithmetic operators ---------
	Time_ operator + (int n);
	Time_ operator - (int n);

	////ÈÍÊÐÅÌÅÍÒ È ÄÅÊÐÅÌÅÍÒ
	Time_ operator++();
	Time_ operator--();

	Time_ operator ++(int a);
	Time_ operator --(int a);

	friend ostream& operator << (ostream& out, Time_& t);
	friend istream& operator >> (istream& in, Time_& t);

};
