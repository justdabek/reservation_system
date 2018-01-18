#pragma once
#include "Film.h"

using namespace std;

Film::Film(string title, string fRTitle, Room room) : title(title), filmRoomTitle(fRTitle), room(room)
{
	
}


Film::~Film()
{
}

Film::Film(const Film &other)
{
	room = other.room;
	title = other.title;
	filmRoomTitle = other.filmRoomTitle;
	filmDates = other.filmDates;
	fRoom = other.fRoom;
};

void Film::setDates(int startDay) {
	for (int i = startDay; i < (startDay + 5); i++)
	{
		DateClass date( i,1,20,30 );
		filmDates.push_back(date);
	}
}



DateClass Film::getfDate(int nr) //zwraca datê
{
	return filmDates.at(nr-1);
}

void Film::makeRoom()
{
	room.fill_Chairs();
	for (auto k : filmDates) {
		fRoom.push_back(room);
	}

}


void Film::fmakeReservation(string name, string surname,int r, int k, int chosenDate) {
	Reservation person(name, surname, r, k);
	if (fRoom.at(chosenDate - 1).checkChair(r,k)) {
		fRoom.at(chosenDate - 1).makeReservation(person);
	}
	else cout<<"Miejsce zajete!"<<endl;
}

Room *Film::getfRoom(int chosenDate) {
	return &fRoom.at(chosenDate - 1);
}



//void Film::dateChoosing(int chooseDate)
//{
//	fRoom.at(chooseDate - 1);
//}

void Film::showDates()
{
	int i=1;
	for (auto k : filmDates)
	{
		cout<<i<<". " << k.getStringDate();
		i++;
	}
}