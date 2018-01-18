// reservation_system.cpp : Defines the entry point for the console application.
//
#pragma once
#include <iostream>
#include "Menu.h"

using namespace std;


int main()
{


	Room duzasala1(10, 15, "Duza sala 1.");
	Room salakameralna(8, 12, "Sala kameralna");
	Room duzasala2(13, 16, "Duza sala 2.");

	Film film1("Ojciec chrzestny", duzasala1.getrTitle(), duzasala1);
	Film film2("Forest Gump", salakameralna.getrTitle(), salakameralna);
	Film film3("Pulp fiction", duzasala2.getrTitle(), duzasala2);

	menuInit(film1, film2, film3);
	
	while (1)
	{
		menuScreen(film1,film2,film3);
	}

	system("pause");
	return 0;
}
