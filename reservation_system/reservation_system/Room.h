#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Reservation.h"
#include <iomanip>


using namespace std;

class Room
{
private:
	int row;
	int column;
	string rTitle;

	vector < vector<int> > chairs;
	vector <Reservation> reserv_list;
public:
	Room(): row(0), column(0), rTitle("") { chairs.assign(0, vector<int>(0)); }
	Room(int row, int column, string rTitle);

	string getrTitle() { return rTitle; }
	int getColumn() { return column; }
	int getRow() { return row; }
	vector < vector<int> > getChairs() { return chairs; }
	vector<Reservation> getReserveList() { return reserv_list; }
	Reservation *getPerson() { return &reserv_list.back(); }

	void fill_Chairs();
	void showChairs();
	bool checkChair(int r, int c);

	void makeReservation(Reservation person);
	void deleteReservation();
	bool addChair(int addr, int addc);
	void deleteChair();

	void showList();
	void showLastPerson();

	int checkRoomAvailibility();
	
	~Room();
};

