#include "Train.h"



Train::Train()
{
}

Train::Train(Train &Object)
{
	this->number = Object.number;
	this->name = Object.name;
	this->carsCount = Object.carsCount;
	this->train = new Car[this->carsCount];
	for (int i = 0; i < this->carsCount; i++)
	{
		this->train[i] = Object.train[i];
	}
	
		
}

Train::Train(unsigned short number, string name,unsigned short carsCount)
{
	this->number = number;
	this->name = name;
	this->carsCount = carsCount;
	this->train = new Car[this->carsCount];
	for (int i = 0; i < this->carsCount; i++)
	{
		train[i].FillCar();

	}

	
}

string Train::GetName()
{
	return this->name;
}

unsigned short Train::GetNumber()
{
	return this->number;
}

void Train::SetName(string name)
{
	this->name = name;
}

void Train::SetNumber(unsigned short number)
{
	this->number = number;
}



void Train::ShowTrain()
{
	cout << "========================"<<this->name <<"==========================\n";
	cout << "Passenger's count: " << this->SumaPassengers() << "\nCar's count: " << this->carsCount << endl;
	for (int i = 0; i < this->carsCount; i++)
	{
		this->train[i].ShowCar();
	}
	cout << "========================"<< this->name << "==========================\n";
}

unsigned short Train::SumaPassengers()
{
	unsigned short passengersCount = 0;
	for (int i = 0; i < this->carsCount; i++) {
	passengersCount += this->train[i].GetPassengers();
	}

	return passengersCount;
}

void Train::FindMaxPassengers()
{
	int addresI = 0;
	unsigned short max = 0;
	for (int i = 0; i < this->carsCount; i++) {
		if (this->train[i].GetPassengers() > max ) {
			max = this->train[i].GetPassengers();
			addresI = i;
		}
	}

	cout << "Max passengers in car N" << addresI + 1 << endl;
	this->train[addresI].ShowCar();
	
}

void Train::FindMinPassengers()
{
	int addresI = 0;
	unsigned short min = this->train[0].GetPassengers();
	for (int i = 0; i < this->carsCount; i++) {
		if (this->train[i].GetPassengers()<min) {
			min = this->train[i].GetPassengers();
			addresI = i;
		}
	}

	cout << "Min passengers in car N" << addresI + 1 << endl;
	this->train[addresI].ShowCar();
}

Train::~Train()
{
	delete[] this->train;
	this->train = nullptr;
}


