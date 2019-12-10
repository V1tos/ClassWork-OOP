#include "Var.h"



Var::Var()
{
	this->intType = 0;
	this->doubleType = 0;
	this->stringType = "";
}

Var::Var(int intType)
{
	this->intType = intType;
	this->doubleType = 0;
	this->stringType = "";
}

Var::Var(double doubleType)
{
	this->doubleType = doubleType;
	this->intType = 0;
	this->stringType = "";
}

Var::Var(string stringType)
{
	this->intType = 0;
	this->doubleType = 0;
	this->stringType = stringType;
}

Var Var::operator+(Var & other)
{

	if (this->intType>0&&other.intType==0&&other.stringType=="")
	{
		
		return (this->intType + int(other.doubleType));
		
	}

}

void Var::ShowVar()
{
	if (this->intType > 0&&this->doubleType==0&&this->stringType=="") {
		cout << this->intType;
	}
	else if (this->doubleType > 0 && this->intType == 0 && this->stringType == "") {
		cout << this->doubleType;
	}
	else
	{
		cout << this->stringType;
	}
}


Var::~Var()
{
}
