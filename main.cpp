#include"Events.h"

int main()
{
	int exit = 1, choice;
	Events ev = Events();

    ev.addEvent(new Meeting("Sergey Lavrov", "Microsoft Office", Date(2020, 3, 10), Time_(15,30,20)));
	ev.addEvent(new BirthDay("Mikhail Sidorkin", "Restaurant <<Argentina>>", 24, Date(2020, 5, 27), Time_(17,20,45)));
	ev.addEvent(new Custom("Study", Date(2020, 3, 12), Time_(9,30,35)));
	ev.addEvent(new Custom("Barbershop", Date(2020, 3, 31), Time_(16,15,55)));

	while (exit != 0) {
		cout << "\n\n\n\t\t\t\t         My Notebook";
		cout << "\n\t\t\t\t      Show my posts - 1\n";
		cout << "\t\t\t          Sort by date and time - 2\n";
		cout << "\t\t\t\t\t   Exit - 0\n";
		cout << "\n   Make your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			system("cls");

			exit = 0;
			break;
		case 1:
			system("cls");
			
			ev.show();
			break;
		case 2:
			system("cls");

			ev.Sort();
			ev.show();
			break;

		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}