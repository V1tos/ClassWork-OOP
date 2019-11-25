#pragma once
#include "Car.h"


class Train
{
private:
	unsigned short number;
	string name;
	unsigned short carsCount;
	Car *train;
public:
	Train();
	Train(Train &Object);
	Train(unsigned short number, string name, unsigned short carsCount);
	string GetName();
	unsigned short GetNumber();
	void SetName(string name);
	void SetNumber(unsigned short number);
	void ShowTrain();
	unsigned short SumaPassengers();
	void FindMaxPassengers();
	void FindMinPassengers();
	~Train();
	
};

