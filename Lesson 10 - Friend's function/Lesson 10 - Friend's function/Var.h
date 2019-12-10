#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

class Var
{
	int intType;
	double doubleType;
	string stringType;
public:
	Var();
	Var(int intType);
	Var(double doubleType);
	Var(string stringType);
	Var operator+(Var &other);
	Var operator-(Var &other);
	Var operator*(Var &other);
	Var operator/(Var &other);
	void ShowVar();
	~Var();
};

