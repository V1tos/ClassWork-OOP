#pragma once
#include "Car.h"


class Train
{
private:
	unsigned short number;
	unsigned short passengersCount;
	string name;
	int size;
	Car *train = new Car[size];
public:
	Train();
	Train(unsigned short number, string name,int size);
	string GetName();
	unsigned short GetNumber();
	void SetName(string name);
	void SetNumber(unsigned short number);
	void ShowTrain();
	void SetCars(Car *cars);
	void ShowCars();
	void ShowAllPassengers();
	void ShowMaxPassengers();
	void ShowMinPassengers();
	
};

