#include <vector>
#include <string>
#include "DateClass.h"
using namespace std;



class Film 
{
private:
	Room room;
	string title; //tytu³ filmu
	string filmRoomTitle; //nazwa sali w ktorej jest film
	vector <DateClass> filmDates; //wektor dat
	vector <Room> fRoom;

public:
	Film() : title(""), filmRoomTitle("") {};
	Film(string title, string fRTitle, Room room);
	Film(const Film &other);
	
	vector<DateClass> getFilmDates() { return filmDates; }
	string getTitle() { return title; }
	string getfilmRoomTitle() { return filmRoomTitle; }
	DateClass getfDate(int nr);


	Room *getfRoom(int chosenDate);

	void setDates(int startDay);
	//void dateChoosing(int chooseDate);
	void showDates();
	
	void fmakeReservation(string name, string surname, int r, int k, int chosenDate);

	void makeRoom();
	~Film();


};

