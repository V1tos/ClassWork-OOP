#include "Car.h"



Car::Car()
{
}

Car::Car(string type, unsigned short passengers)
{
	this->type = type;
	this->passengers = passengers;
}

string Car::GetType()
{
	return this->type;
}

unsigned short Car::GetPassengers()
{
	return this->passengers;
}

void Car::FillCar()
{
	
	cout << "Enter car's type: ";
	cin >> this->type;
	cout << "Enter passenger's count: ";
	cin >> this->passengers;
	

}

void Car::SetType(string type)
{
	this->type = type;
}

void Car::SetPassengers(unsigned short passengers)
{
	this->passengers = passengers;
}

void Car::ShowCar()
{
	cout << "Type of car: " << this->type << "\nPassenger's count: " << this->passengers << endl;
}



