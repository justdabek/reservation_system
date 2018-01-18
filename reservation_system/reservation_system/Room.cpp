#pragma once
#include "Room.h"
#include "Menu.h"

Room::Room(int row, int column, string rTitle) : row(row), column(column), rTitle(rTitle)
{
	chairs.assign(row, vector<int>(column));
	reserv_list.reserve(0);
}


Room::~Room()
{
}

void Room::fill_Chairs() {

	for (auto & r : chairs)
	{
		int a = 1;
		for (auto & k : r)
		{
			k = a;
			a++;
		}

	}

}



void Room::makeReservation(Reservation person) {

		vector<int> r{ person.getRow() };
		vector<int> c{ person.getColumn() };

		chairs.at(r.back()-1).at(c.back()-1) = 0;
		reserv_list.push_back(person);
}

void Room::deleteReservation() {
	vector<int> r{ getPerson()->getRow() };
	vector<int> c{ getPerson()->getColumn() };

	chairs.at(r.back()-1).at(c.back()-1) = c.back();

	reserv_list.pop_back();
}

void Room::deleteChair()
{
	int r{ getPerson()->getRow() };
	int c{ getPerson()->getColumn() };
	getPerson()->deletePair();

	chairs.at(r - 1).at(c - 1) = c;

	/*getPerson()->deleteRow();
	getPerson()->deleteColumn();*/
}

bool Room::addChair( int addr,int addc)
{
	if (checkChair(addr, addc)) {
		getPerson()->addPair(addr, addc); //adds nr of row and column to pair type
		int r{ getPerson()->getRow() };
		int c{ getPerson()->getColumn() };

		chairs.at(r - 1).at(c - 1) = 0; //vector of chairs 0=occupied
		return true;
	}
	else 
	{
		cout << endl << PL("Zajête!") << endl;
		Sleep(1000);
		return false;
	}

}

void Room::showLastPerson() {

		cout << reserv_list.back().getName() << " " << reserv_list.back().getSurname() << endl;
		cout << PL("Rzêdy: ");
		for (auto i : reserv_list.back().getPair())
		{
			cout << i.first << ", ";
		}
		cout << endl;
		cout << "Miejsca: ";
		for (auto j : reserv_list.back().getPair())
		{
			cout << j.second << ", ";
		}
		cout << endl;

}


void Room::showList() {

	for (auto k : reserv_list)
	{
		cout<<k.getName()<<" " <<k.getSurname()<<endl;
		cout << PL("Rzêdy: ");
		for(auto i: k.getPair())
		{
			cout << i.first << ", ";
		}
		cout << endl;
		cout << "Miejsca: ";
		for (auto j : k.getPair())
		{
			cout << j.second << ", "  ;
		}
		cout << endl;

	}

}

int Room::checkRoomAvailibility() {
	int free{ 0 };
	for (auto r : chairs)
	{
		for (auto k : r) {

			if (k != 0) {
				free++;
			}
		}
	}
	return free;
}

bool Room::checkChair(int r, int c) {

	if (chairs.at(r-1).at(c-1) != 0) {
		return true;
	}
	return false;
}




void Room::showChairs()
{
	cout<<setw(68) << "-------------------------EKRAN--------------------------" << endl;

	cout << PL("Nr rzêdu: ") << "-------------------------Nr miejsca--------------------------" << endl;
	int rnumber = 1;
	for (auto r : chairs)
	{
		cout << setw(8)  << rnumber <<  setw(2) << " ";
		for (auto k : r)
		{
			if (k == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				cout << setw(3) << "x";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "|";
			}
			else cout << setw(3) << k << "|";
		}
		cout << endl;
		rnumber++;
	}
}