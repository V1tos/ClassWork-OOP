#include "Student.h"
using namespace std;


Student::Student()
{
}

Student::Student(string name, string surname)
{
	this->name = name;
	this->surname = surname;
}



void Student::ShowStudentInfo()
{
	cout << "Name: " << this->name << "\nSurname: " << this->surname << endl;
	cout << "Evaluations: ";
	for (int i = 0; i < 5; i++) {
		cout << " " << this->evaluation[i];
	}
	cout << endl;
	cout << "Average evaluation: " << this->average << endl;
}

void Student::FillEvaluation()
{
	for (int i = 0; i < 5; i++) {
		this->evaluation[i] = rand() % 12 + 1;
	}

}

void Student::AverageEvaluation()
{
	int res = 0;
	for (int i = 0; i < 5; i++) {
		res += this->evaluation[i];
	}
	this->average = res / 5;
}


Student::~Student()
{
}
