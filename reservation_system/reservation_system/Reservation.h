#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Reservation
{
private:
	string name;
	string surname;
	vector<pair<int, int>>RowColumn;
public:
	Reservation() : name(""), surname(""), RowColumn() { RowColumn.reserve(0); };
	Reservation(string name, string surname, int Row, int Column);
	string getName() { return name; }
	string getSurname() { return surname; }
	vector<pair<int, int>> getPair() { return RowColumn; }
	int getRow() { return RowColumn.back().first; }
	int getColumn() { return RowColumn.back().second; }

	void setName(std::string name) { this->name = name; }
	void setSurName(std::string surname) { this->name = surname; }

	void deletePair() { RowColumn.pop_back(); }
	void addPair(int addr, int addc) { RowColumn.push_back({ addr,addc }); }


	~Reservation();
};

