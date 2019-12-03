#pragma once
#include <iostream>;

using namespace std;

class Fraction
{
private:
	short numerator;
	short denominator;

public:
	Fraction();
	Fraction(short numerator);
	Fraction(short numerator, short denominator);
	Fraction operator==(Fraction &other);
	Fraction operator!=(Fraction &other);
	void Plus(Fraction &other);
	void Minus(Fraction &other);
	void Multiple(Fraction &other);
	void Division(Fraction &other);
	void PlusPlus();
	void MinusMinus();
	void CreateInt();
	void CreateDouble();
	void Reduction();
	void ShowFraction();
	~Fraction();
};

