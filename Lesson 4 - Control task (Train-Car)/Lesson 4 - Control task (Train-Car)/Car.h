#pragma once
#include <iostream>
#include <string>
using namespace std;


class Car
{
private:
	string type;
	unsigned short passengers;
	static unsigned int counter;
	unsigned int carID;
public:
	Car();
	Car(string type, unsigned short passengers);
	string GetType();
	unsigned short GetPassengers();
	void FillCar();
	void SetType(string type);
	void SetPassengers(unsigned short passengers);
	void ShowCar();
};

