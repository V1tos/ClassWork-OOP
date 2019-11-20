#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
	string name;
	string surname;
	unsigned short evaluation[5];
	unsigned short average;

public:
	Student();
	Student(string name, string surname);
	void FillEvaluation();
	void AverageEvaluation();
	void ShowStudentInfo();
	~Student();
};

