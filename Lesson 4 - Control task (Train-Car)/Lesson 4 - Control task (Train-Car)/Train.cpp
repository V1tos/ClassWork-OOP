#include "Train.h"



Train::Train()
{
}

Train::Train(unsigned short number, string name)
{
	this->number = number;
	this->name = name;
	
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

void Train::FillCars()
{
	this->carsCount = 3;
	this->train = new Car[this->carsCount];
	
	string type;
	unsigned short passengers = 0;
	for (int i = 0; i < this->carsCount; i++) {
		
		cout << "Enter car's type: ";
		cin >> type;
		cout << "Enter passenger's count: ";
		cin >> passengers;
		this->train[i] = Car(type, passengers);
	}
	
	
}

void Train::ShowTrain()
{
	cout << "========================"<<this->name <<"==========================\n";
	cout << "Passenger's count: " << this->SumaPassengers() << "\nCar's count: " << this->carsCount << endl;
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


