#include "Reservation.h"


Reservation::Reservation(std::string name, std::string surname, int Row, int Column):
	name(name), surname(surname)
{
	RowColumn.push_back({ Row,Column });
}


Reservation::~Reservation()
{
}
