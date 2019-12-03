#include "Fraction.h"



Fraction::Fraction()
{
	this->numerator = 0;
	this->denominator = 1;
}

Fraction::Fraction(short numerator)
{
	this->numerator = numerator;
}

Fraction::Fraction(short numerator, short denominator)
{
	if (denominator < 0) {
		denominator = (-denominator);
		this->numerator = -numerator;
		this->denominator = denominator;
	}
	else if(numerator<0&&denominator<0)
	{
		this->numerator = -numerator;
		this->denominator = -denominator;
	}
	else
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	
}

Fraction Fraction::operator==(Fraction & other)
{
	if (double(this->numerator / this->denominator) == double(other.numerator / other.denominator)) {
		cout << "===TRUE===" << endl;
	}
	else
	{
		cout << "===FALSE===" << endl;
	}

	return *this;
}

Fraction Fraction::operator!=(Fraction & other)
{
	if (double(this->numerator / this->denominator) != double(other.numerator / other.denominator)) {
		cout << "===TRUE===" << endl;
	}
	else
	{
		cout << "===FALSE===" << endl;
	}

	return *this;
}

void Fraction::Plus(Fraction & other)
{
	if (this->denominator != other.denominator) {
		cout << (other.denominator*this->numerator) + (this->denominator*other.numerator) << "\n--\n" << this->denominator*other.denominator << endl;
	}
	else
	{
		cout << this->numerator + other.numerator << "\n--\n" << this->denominator << endl;
	}


}

void Fraction::Minus(Fraction & other)
{
	if (this->denominator != other.denominator) {
		cout << (other.denominator*this->numerator) - (this->denominator*other.numerator) << "\n--\n" << this->denominator*other.denominator << endl;
	}
	else
	{
		cout << this->numerator - other.numerator << "\n--\n" << this->denominator << endl;
	}
}

void Fraction::Multiple(Fraction & other)
{
	cout << this->numerator*other.numerator << "\n--\n" << this->denominator*other.denominator << endl;
}

void Fraction::Division(Fraction & other)
{
	cout << this->numerator*other.denominator << "\n--\n" << this->denominator*other.numerator << endl;
}

void Fraction::PlusPlus()
{
	this->numerator+=1;
	this->denominator+=1;
}

void Fraction::MinusMinus()
{
	this->numerator-=1;
	this->denominator-=1;
}

void Fraction::CreateInt()
{
	cout << this->numerator / this->denominator << endl;

}

void Fraction::CreateDouble()
{
	cout << double(this->numerator) / double(this->denominator) << endl;
}

void Fraction::Reduction()
{
	if (this->denominator%this->numerator == 0&&this->numerator>0) {
		cout << (this->numerator / this->numerator) << "\n--\n" << (this->denominator / this->numerator) << endl;
		
	}
	else if(this->denominator%this->numerator == 0 && this->numerator < 0)
	{
		cout << -(this->numerator / this->numerator) << "\n--\n" << -(this->denominator / this->numerator) << endl;
	}
	else if(this->numerator%(this->denominator%this->numerator)==0)
	{
		cout << (this->numerator / this->numerator) << "\n--\n" << (this->denominator / (this->denominator%this->numerator)) << endl;
	}
	else
	{
	/*	bool flag = false;
		int i = 0;
		while (!flag)
		{

		}*/
		cout << "Mission impossible!!!" << endl;
	}
}

void Fraction::ShowFraction()
{
	cout << this->numerator << "\n--\n" << this->denominator << endl;

}


Fraction::~Fraction()
{
}
