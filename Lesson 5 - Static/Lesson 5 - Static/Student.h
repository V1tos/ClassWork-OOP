#pragma once
#include <iostream>
#include <string>
using namespace std;


class Student
{
private:
	string name;
	string surname;
	static unsigned int counter;

public:
	Student();
	Student(string name, string surname);
	void SetName(string name);
	void SetSurname(string surname);
	void ShowStudent();
	~Student();
};

