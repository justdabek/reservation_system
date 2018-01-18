#pragma once
#include <iostream>
#include "Film.h"
#include <windows.h>
#include <limits>
#include <ios> 


using namespace std;


void menuInit(Film &, Film &, Film &);
void menuScreen(Film ,Film,Film);
void menuFilm(Film &film1);
void menuAddChair(Film &film, int chooseDate);
void menuShowAllReservations(Film &film);
string PL(const char * text);
void cls();

template<typename inputType>
inputType inputVariable(const char *toCout, inputType &choose);

