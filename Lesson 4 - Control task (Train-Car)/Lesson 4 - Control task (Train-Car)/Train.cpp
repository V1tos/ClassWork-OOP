#include "Train.h"



Train::Train()
{
}

Train::Train(unsigned short number, string name, int size)
{
	this->number = number;
	this->name = name;
	this->size = size;
	
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
	cout << "========================LVIV-KYIV==========================\n";
	cout << "Passenger's count: " << this->passengersCount << "\nCar's count: " << this->size << endl;
	cout << "========================LVIV-KYIV==========================\n";
}

void Train::SetCars(Car *cars)
{
	this->train = cars;
}

void Train::ShowCars()
{
	for (int i = 0; i < this->size; i++) {
		cout << "Car N" << i + 1<<":" << endl;
		this->train[i].ShowCar();
	}

}

void Train::ShowAllPassengers()
{
	
	for (int i = 0; i < this->size; i++) {
	this->passengersCount += this->train[i].GetPassengers();
	}

	cout << "All passengers: " << this->passengersCount << endl;
}

void Train::ShowMaxPassengers()
{
	unsigned short max = 0;
	for (int i = 0; i < this->size; i++) {
		if (this->train[i].GetPassengers() > max ) {
			max = this->train[i].GetPassengers();
		}
	}

	cout << "Max passengers ";
	for (int i = 0; i < this->size; i++) {
		if (max==this->train[i].GetPassengers() ) {
			cout << "in car N" << i + 1 <<":" << endl;
			this->train[i].ShowCar();
		}
	}

	
}

void Train::ShowMinPassengers()
{
	unsigned short min = this->train[0].GetPassengers();
	for (int i = 0; i < this->size; i++) {
		if (this->train[i].GetPassengers()<min) {
			min = this->train[i].GetPassengers();
		}
	}

	cout << "Min passengers ";
	for (int i = 0; i < this->size; i++) {
		if (min == this->train[i].GetPassengers()) {
			cout << "in car N" << i + 1 << ":" << endl;
			this->train[i].ShowCar();
		}
	}


}


