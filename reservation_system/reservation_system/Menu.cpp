#pragma once
#include "Menu.h"



void menuInit(Film &film1, Film &film2, Film &film3) {

	film1.setDates(2);
	film2.setDates(3);
	film3.setDates(4);

	film1.makeRoom();
	film2.makeRoom();
	film3.makeRoom();

}

template<typename inputType>
inputType inputVariable(const char *toCout, inputType &choose) //function ensure expected input
{
	cin.clear(); //clear bad input flag
	cin.ignore(INT_MAX, '\n'); //discard input
	while (cout << PL(toCout) && !(cin >> choose)) {
		cin.clear(); //clear bad input flag
		cin.ignore(INT_MAX, '\n'); //discard input
		cout << PL("Z≥a dana, wprowadü ponownie!\n");
	}
	return choose;
}

void menuScreen(Film film1, Film film2, Film film3) // display all options on console
{
	string Menu[5] = { film1.getTitle(), film2.getTitle(),film3.getTitle(),PL("Pokaø wszystkie reserwacje"), "Exit" };
	int pointer = 0;

	while (true)
	{

		cls();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "KINO\n\n";

		for (int i = 0; i < 5; ++i) //pÍtla wyúwietlajπca Opcje menu (string z tablicy Menu)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << Menu[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Menu[i] << endl;
			}
		}

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0) // button handling
			{
				pointer--;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer++;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			{
				switch (pointer)
				{
				case 0:
					menuFilm(film1);
					pointer = 0;
					Sleep(1000);
					break;

				case 1:
					menuFilm(film2);
					Sleep(1000);
					break;

				case 2:
					menuFilm(film3);
					Sleep(1000);
					break;
				case 3:
					cout << "\n\n";
					menuShowAllReservations(film1);
					menuShowAllReservations(film2);
					menuShowAllReservations(film3);
					cout << "\n\n\n";
					system("pause");
					break;
				case 4:
					exit(0);
					break;
				}
				break;
			}

		}

		Sleep(150);

	}

	return;
}

void menuFilm(Film &film)
{
	int chooseDate, chooseRow, chooseColumn;
	string name, surname;
	cls();

	cout << PL("\n\nDaty seansÛw: ") << endl;
	film.showDates();

	inputVariable("\nWybierz datÍ: ", chooseDate);


	if (chooseDate < 6 && chooseDate>0) {

		cls();
		film.getfRoom(chooseDate)->showChairs();

		inputVariable<int>("Wybierz rzπd: ", chooseRow);
		inputVariable<int>("Wybierz miejsce: ", chooseColumn);
		inputVariable<string>("\nPodaj imiÍ: ", name);
		inputVariable<string>("Podaj nazwisko: ", surname);

		if (chooseRow <= film.getfRoom(chooseDate)->getRow() && chooseColumn <= film.getfRoom(chooseDate)->getColumn()) {
			film.fmakeReservation(name, surname, chooseRow, chooseColumn, chooseDate);
			cls();
			Sleep(150);
			menuAddChair(film, chooseDate);
			return;
		}
	}
}



void menuAddChair(Film &film, int chooseDate)
{

	string Menu[5] = { "Dodaj miejsce",PL("UsuÒ miejsce"), PL("Pokaø rezerwacje"),PL("UsuÒ rezerwacje"), "Exit" };
	int pointer = 0;
	int chooseRow = 0;
	int chooseColumn = 0;

	while (true)
	{
		cls();
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		film.getfRoom(chooseDate)->showChairs();


		for (int i = 0; i < 5; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << Menu[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Menu[i] << endl;
			}
		}

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer--;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer++;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}

			else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			{
				switch (pointer)
				{
				case 0:
					cin.clear(); 
					cin.ignore(INT_MAX, '\n');

					inputVariable<int>("Wybierz rzπd: ", chooseRow);
					inputVariable<int>("Wybierz miejsce: ", chooseColumn);

					if (chooseRow <= film.getfRoom(chooseDate)->getRow() && chooseColumn <= film.getfRoom(chooseDate)->getColumn())
					{
						if (film.getfRoom(chooseDate)->addChair(chooseRow, chooseColumn))
							cout << "\nDodano!" << endl;
					}
					else cout << PL("\nNie ma takiego miejsca!!") << endl;

					Sleep(1000);
					break;

				case 1:
					if (film.getfRoom(chooseDate)->getPerson()->getPair().empty()) {
						cout << PL("\nBrak miejsc do usuniÍcia!") << endl;
					}
					else {
						film.getfRoom(chooseDate)->deleteChair();
						cout << PL("\nUsuniÍto ostatniπ pozycjÍ!") << endl;
					}
					Sleep(1000);
					break;
				case 2:
					film.getfRoom(chooseDate)->showLastPerson();

					Sleep(2000);
					break;
				case 3:
					film.getfRoom(chooseDate)->deleteReservation();
					cout << PL("\n\nUsuniÍto rezerwacjÍ!");
					return;
				case 4:
					return;
				}


				break;
			}
		}


		Sleep(150);

	}

	return;
}



void menuShowAllReservations(Film &film)
{
	int chooseDate=1;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << film.getTitle() << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


	for (auto k : film.getFilmDates())
	{
		if (!(film.getfRoom(chooseDate)->getReserveList().empty()))
		{
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << k.getStringDate() << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			film.getfRoom(chooseDate)->showList();
			cout<<PL("IloúÊ wolnych miejsc: ")<<film.getfRoom(chooseDate)->checkRoomAvailibility()<<endl;
		}
		chooseDate++;
	}
	cout << endl << "------------------------------------------------------------------" << endl;
}

string PL(const char * text)
{
	string result;
	for (; *text; text++)
		switch (*text)
		{
		case 'π': result += static_cast <char>(0xa5); break;
		case 'Ê': result += static_cast <char>(0x86); break;
		case 'Í': result += static_cast <char>(0xa9); break;
		case '≥': result += static_cast <char>(0x88); break;
		case 'Ò': result += static_cast <char>(0xe4); break;
		case 'Û': result += static_cast <char>(0xa2); break;
		case 'ú': result += static_cast <char>(0x98); break;
		case 'ø': result += static_cast <char>(0xbe); break;
		case 'ü': result += static_cast <char>(0xab); break;
		case '•': result += static_cast <char>(0xa4); break;
		case '∆': result += static_cast <char>(0x8f); break;
		case ' ': result += static_cast <char>(0xa8); break;
		case '£': result += static_cast <char>(0x9d); break;
		case '—': result += static_cast <char>(0xe3); break;
		case '”': result += static_cast <char>(0xe0); break;
		case 'å': result += static_cast <char>(0x97); break;
		case 'Ø': result += static_cast <char>(0xbd); break;
		case 'è': result += static_cast <char>(0x8d); break;
		default: result += *text; break;
		}
	return result;
}

void cls() //windows h function to replace screen with nulls
{
	DWORD n;
	DWORD size;
	COORD coord = { 0 };
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);
	size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
	SetConsoleCursorPosition(h, coord);
}