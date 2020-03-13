#pragma once
#include"Event.h"
#include <list>
#include"BirthDay.h"
#include"Custom.h"
#include"Event.h"
#include"Events.h"
#include"Meeting.h"

class Events
{
public:
	list <Event*> events;
	Events() = default;
	~Events() {
		for (Event* ev : events)
		{
			delete ev;
		}

	}

	void show()
	{
		for (Event* ev : events)
		{
			cout << ev->toString() << endl;
		}

	}

	void addEvent(Event* newEvent)
	{
		events.push_back(newEvent);
	}

	bool static compare_time(Event*& first, Event*& second)
	{
		return first->CompareAll(*second);
	}

	void Sort() 
	{
		events.sort(compare_time);
	}
};
