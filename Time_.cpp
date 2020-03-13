#define _CRT_SECURE_NO_WARNINGS
#include "Time_.h"
#include <cstring>


Time_::Time_()
{
	time_t tt;
	struct tm* tim = new tm;
	tt = time(NULL);
	localtime_s(tim, &tt);
	this->hour = tim->tm_hour;
	this->minutes = tim->tm_min;
	this->seconds = tim->tm_sec;
	this->format = new char[strlen("utc")];
	strcpy(this->format, "utc");

	this->utc = true;
}

Time_::Time_(int hour, int minutes, int seconds, const char* format)
{
	if ((minutes > 60 || minutes < 1 || seconds > 60 || seconds < 1) ||
		((strcmp(format, "am") == 0 || strcmp(format, "pm") == 0) && (hour > 12 || hour < 1)) ||
		(strcmp(format, "utc") == 0 && (hour > 24 || hour < 1)) ||
		(strcmp(format, "utc") != 0 && strcmp(format, "pm") != 0 && strcmp(format, "am") != 0))
	{
		cout << "Некорректно заданы параметры! Установлено время по умолчанию (utc, 12:00)!" << endl;
		system("pause");
		this->format = new char[strlen("utc")];
		strcpy(this->format, "utc");
		this->hour = 12;
		this->minutes = 0;
		this->seconds = 0;
	}
	else
	{
		this->hour = hour;
		this->minutes = minutes;
		this->seconds = seconds;

		this->format = new char[strlen(format)];
		strcpy(this->format, format);

		if (strcmp(this->format, "utc") == 0)this->utc = true;
		else this->utc = false;
	}

}

Time_::Time_(const Time_& obj)
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;

	//if (this->format != NULL)delete this->format;

	this->format = new char[strlen(obj.format)];
	strcpy(this->format, obj.format);

	if (strcmp(this->format, "utc") == 0) this->utc = true;
	else this->utc = false;
}


Time_::~Time_()
{
	//delete[] this->format; выдает ошибку с квадратными скобками и без!
}

void Time_::setHour(int hour)
{
	if ((strcmp(this->format, "utc") == 0 && (hour <= 24 && hour >= 1)) || (strcmp(this->format, "am") == 0 || strcmp(this->format, "pm") == 0 && (hour >= 1 && hour <= 12)))
	{
		this->hour = hour;
	}
}

int Time_::getHour()
{
	return this->hour;
}

void Time_::setMinutes(int minutes)
{
	if (minutes >= 1 && minutes <= 60)
	{
		this->minutes = minutes;
	}
}

int Time_::getMinutes()
{
	return this->minutes;
}

void Time_::setSeconds(int seconds)
{
	if (seconds <= 60 && seconds >= 1)this->seconds = seconds;
}

int Time_::getSeconds()
{
	return this->seconds;
}

void Time_::setFormat(const char* format)
{
	if (strcmp(this->format, format) == 0)return;
	if ((strcmp(this->format, "am") == 0 && strcmp(format, "pm") == 0) || (strcmp(this->format, "pm") == 0 && strcmp(format, "am") == 0))
	{
		cout << "Перевод из am в pm и наоборот - невозможен!" << endl;
		return;
	}

	if (strcmp(format, "am") == 0)
	{
		if (this->hour > 12)
		{
			cout << "Перевод невозможен!" << endl;
		}
		else
		{
			//delete[] this->format;
			this->format = new char[strlen("am")];
			strcpy(this->format, "am");
		}
	}
	else if (strcmp(format, "pm") == 0)
	{
		if (this->hour <= 12)
		{
			cout << "Перевод невозможен!" << endl;
		}
		else
		{
			this->hour -= 12;

			//delete[] this->format;  error
			this->format = new char[strlen("pm")];
			strcpy(this->format, "pm");
		}
	}
	else if (strcmp(format, "utc") == 0)
	{
		if (strcmp(this->format, "am") == 0)
		{
			//delete[] this->format;
			this->format = new char[strlen("utc")];
			strcpy(this->format, "utc");
		}
		else if (strcmp(this->format, "pm") == 0)
		{
			//delete[] this->format;
			this->format = new char[strlen("utc")];
			strcpy(this->format, "utc");

			this->hour += 12;
		}
	}

	if (strcmp(this->format, "utc") == 0)this->utc = true;
	else this->utc = false;
}

const char* Time_::getFormat()
{
	return this->format;
}

void Time_::reGetLocalTime()
{
	char form[10];
	strcpy(form, this->format);

	time_t tt;
	struct tm* tim = new tm;
	tt = time(NULL);
	localtime_s(tim, &tt);
	this->hour = tim->tm_hour;
	this->minutes = tim->tm_min;
	this->seconds = tim->tm_sec;
	this->format = new char[strlen("utc")];
	strcpy(this->format, "utc");

	this->setFormat(form);

	if (strcmp(form, "utc") == 0)this->utc = true;
}

void Time_::reGetLocalTimeInUtc()
{
	time_t tt;
	struct tm* tim = new tm;
	tt = time(NULL);
	localtime_s(tim, &tt);
	this->hour = tim->tm_hour;
	this->minutes = tim->tm_min;
	this->seconds = tim->tm_sec;
	this->format = new char[strlen("utc")];
	strcpy(this->format, "utc");

	this->utc = true;
}

void Time_::changeFormat()
{
	if (strcmp(this->format, "am") == 0 || strcmp(format, "pm") == 0)
	{
		this->setFormat("utc");
	}
	else if (strcmp(this->format, "utc") == 0)
	{
		if (this->hour <= 12)this->setFormat("am");
		else if (this->hour >= 12)this->setFormat("pm");
	}

	if (strcmp(this->format, "utc") == 0)this->utc = true;
	else this->utc = false;
}

bool Time_::valid()
{
	if (strcmp(this->format, "utc") != 0 && strcmp(this->format, "am") != 0 && strcmp(this->format, "pm") != 0)return false;
	if (this->minutes > 60 || this->minutes < 1 || this->seconds > 60 || this->seconds < 1)return false;
	else if (((strcmp(this->format, "utc") == 0) && (this->hour > 24 || this->hour < 1)) || (((strcmp(this->format, "am") == 0) || (strcmp(this->format, "pm") == 0)) && (this->hour > 12 || this->hour < 1))) return false;
	else return true;
}

void Time_::tickTime()
{
	this->seconds++;

	if (this->seconds == 60)
	{
		this->minutes++;
		this->seconds = 0;
	}

	if (this->minutes == 60)
	{
		this->hour++;
		this->minutes = 0;
	}

	if (this->utc && this->hour == 24)
	{
		this->hour = 0;
	}
	else if (!this->utc && this->hour == 13)
	{
		this->hour = 1;

		if (strcmp(this->format, "am") == 0)
		{
			delete[] this->format;
			this->format = new char[strlen("pm")];
			strcpy(this->format, "pm");
		}
		else if (strcmp(this->format, "pm") == 0)
		{
			delete[] this->format;
			this->format = new char[strlen("am")];
			strcpy(this->format, "am");
		}
	}
}

void Time_::tickBack()
{
	this->seconds--;

	if (this->seconds == -1)
	{
		this->minutes--;
		this->seconds = 59;
	}

	if (this->minutes == -1)
	{
		this->hour--;
		this->minutes = 59;
	}

	if (this->utc && this->hour == -1)
	{
		this->hour = 23;
	}
	else if (!this->utc && this->hour == 0)
	{
		this->hour = 12;

		if (strcmp(this->format, "am") == 0)
		{
			delete[] this->format;
			this->format = new char[strlen("pm")];
			strcpy(this->format, "pm");
		}
		else if (strcmp(this->format, "pm") == 0)
		{
			delete[] this->format;
			this->format = new char[strlen("am")];
			strcpy(this->format, "am");
		}
	}
}

void Time_::showTime()
{
	cout << " " << this->format << " " << this->hour << ":" << this->minutes << ":" << this->seconds << endl;
}

bool Time_::operator==(const Time_& obj)
{
	char form[10];
	strcpy(form, this->format);

	Time_ tmp(obj);

	tmp.setFormat(form);

	if ((strcmp(this->format, tmp.format) == 0) && this->hour == tmp.hour && this->minutes == tmp.minutes && this->seconds == tmp.seconds)
		return true;
	else return false;
}

bool Time_::operator!=(const Time_& obj)
{
	return !(*this == obj);
}

bool Time_::operator>(const Time_& obj)
{
	char form[10];
	strcpy(form, this->format);

	Time_ tmp(obj);

	tmp.setFormat(form);

	if (strcmp(this->format, tmp.format) == 0)
	{
		if (this->hour > tmp.hour)return true;
		else if (this->hour == tmp.hour)
		{
			if (this->minutes > tmp.minutes)return true;
			else if (this->minutes == tmp.minutes)
			{
				if (this->seconds > tmp.seconds)return true;
				else return false;
			}
		}
	}
	else if (strcmp(this->format, "pm") == 0 && strcmp(tmp.format, "am")) return true;
	else return false;

}

bool Time_::operator<(const Time_& obj)
{
	if (!(*this > obj) && *this != obj)return true;
	else return false;
}

bool Time_::operator>=(const Time_& obj)
{
	if ((*this > obj) || (*this == obj))return true;
	else return false;
}

bool Time_::operator<=(const Time_& obj)
{
	if ((*this < obj) || (*this == obj))return true;
	else return false;
}

Time_& Time_::operator=(const Time_& obj)
{
	// TODO: вставьте здесь оператор return
	this->format = new char[strlen(obj.format)];
	strcpy(this->format, obj.format);

	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	return *this;
}

Time_& Time_::operator+=(int n)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < n; i++)
	{
		this->tickTime();
	}
	return *this;
}

Time_& Time_::operator-=(int n)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < n; i++)
	{
		this->tickBack();
	}
	return *this;
}

Time_ Time_::operator+(int n)
{
	Time_ tmp(*this);

	tmp += n;

	return tmp;
}

Time_ Time_::operator-(int n)
{
	Time_ tmp(*this);

	tmp -= n;

	return tmp;
}

Time_ Time_::operator++()
{
	this->tickTime();

	return *this;
}

Time_ Time_::operator--()
{
	this->tickBack();
	return *this;
}

Time_ Time_::operator++(int a)
{
	Time_ tmp(*this);

	this->tickTime();

	return tmp;
}

Time_ Time_::operator--(int a)
{
	Time_ tmp(*this);

	this->tickBack();

	return tmp;
}

ostream& operator<<(ostream& out, Time_& t)
{
	// TODO: вставьте здесь оператор return
	out << t.format << "  time: " << t.hour << ":" << t.minutes << ":" << t.seconds;
	return out;
}

istream& operator>>(istream& in, Time_& t)
{
	// TODO: вставьте здесь оператор return
	cout << "  Введите формат времени: "; char tmp[10]; in.get(); in.getline(tmp, 10);
	//if (t.format != NULL)delete[]t.format;
	t.format = new char[strlen(tmp)];
	strcpy(t.format, tmp);

	cout << "  Введите часы: "; in >> t.hour;
	cout << "  Введите минуты: "; in >> t.minutes;
	cout << "  Введите секунды: "; in >> t.seconds;

	if (!t.valid())
	{
		cout << "Параметры введены не верно! \nУстановлено текущее время!" << endl;
		t.reGetLocalTimeInUtc();
	}

	return in;
}
