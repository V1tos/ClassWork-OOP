#include "Group.h"



Group::Group()
{
	
}

Group::Group(unsigned short studentsCount)
{
	this->studentsCount = studentsCount;
	this->students = new Student[this->studentsCount];
	FillStudent();

}

void Group::FillStudent()
{
	string name;
	string surname;
	for (int i = 0; i < this->studentsCount; i++) {
		cout << "Student N" << i + 1 << endl;
		cout << "Enter name: "; cin >> name;
		cout << "Enter surname: "; cin >> surname;
		this->students[i] = Student(name, surname);
	}
	
}

void Group::ShowGroup()
{
	cout << "--------------------------------\n";
	cout << "|Group name: " << this->groupName << "             |\n|Course: " << this->course << "                     |\n|Proffession: " << this->proffession <<"|\n";
	cout << "--------------------------------\n";
	for (int i = 0; i < this->studentsCount; i++) {
		cout << "********************\n";
		cout << "Student N" << i + 1 << endl;
		students[i].ShowStudent();
		cout << "********************\n";
	}
}

void Group::EditStudent()
{
	unsigned short studentsNumber;
	string name;
	string surname;
	cout << "Enter student's number: "; cin >> studentsNumber;
	cout << "Enter name: "; cin >> name;
	cout << "Enter surname: "; cin >> surname;
	this->students[studentsNumber - 1].SetName(name);
	this->students[studentsNumber - 1].SetSurname(surname);

}


Group::~Group()
{
}
