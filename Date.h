#pragma once
#include <iostream>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

	bool isLeapYear(); //Ïðîâåðêà íà âèñîêîñíûé ãîä
	int monthDays(); //Êîëè÷åñòâî äíåé ïî ìåñÿöó
	void nextDate(); //Ñëåäóþùàÿ äàòà
	void prevDate(); //Ïðåäûäóùàÿ äàòà

public:
	//---------ÊÎÍÑÒÐÓÊÒÎÐÛ è ÄÅÑÒÐÓÊÒÎÐ---------
	Date(); // Ïî óìîë÷àíèþ  - òåêóùàÿ äàòà
	Date(int seconds);
	Date(int year, int month, int day); //Ñ ïàðàìåòðàìè - çàäàííàÿ äàòà
	Date(const Date& obj); //Êîïèðîâàíèÿ
	~Date();// Äåñòðóêòîð

			//---------ÀÊÑÅÑÑÎÐÛ---------
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	const char* getSMonth(const char* lan = "EN");
	void setDay(int day);
	int getDay();

	bool valid(); //Ïðîâåðêà äàòû íà êîððåêòíîñòü
	void showDate();

				  //--------- ÎÏÅÐÀÒÎÐÛ ÑÐÀÂÍÅÍÈß ---------
	bool operator == (const Date&  obj);
	bool operator != (const Date& obj);
	bool operator > (const Date& obj);
	bool operator < (const Date& obj);
	bool operator >= (const Date& obj);
	bool operator <= (const Date& obj);

	//--------- ÎÏÅÐÀÒÎÐÛ ÏÐÈÑÂÎÅÍÈß ---------
	Date& operator = (const Date& obj);
	Date& operator += (int n);
	Date& operator -= (int n);

	//--------- ÀÐÈÔÌÅÒÈ×ÅÑÊÈÅ ÎÏÅÐÀÒÎÐÛ ---------
	Date operator + (int n);
	Date operator - (int n);

	friend ostream& operator << (ostream& out, Date& obj);
};

