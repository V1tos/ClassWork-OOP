#pragma once
#include "Car.h"


class Train
{
private:
	unsigned short number;
	string name;
	int carsCount;
	Car *train;
public:
	Train();
	Train(unsigned short number, string name);
	string GetName();
	unsigned short GetNumber();
	void SetName(string name);
	void SetNumber(unsigned short number);
	void ShowTrain();
	void FillCars();
	unsigned short SumaPassengers();
	void FindMaxPassengers();
	void FindMinPassengers();
	
};

