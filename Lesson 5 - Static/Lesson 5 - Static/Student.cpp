#include "Student.h"



Student::Student()
{
}

Student::Student(string name, string surname)
{
	this->name = name;
	this->surname = surname;
	this->counter++;
}

void Student::SetName(string name)
{
	this->name = name;
}

void Student::SetSurname(string surname)
{
	this->surname = surname;
}



void Student::ShowStudent()
{
	cout << "Name: " << this->name << "\nSurname: " << this->surname << endl;
}


Student::~Student()
{
}
