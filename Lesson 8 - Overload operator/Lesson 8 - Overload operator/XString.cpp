#include "XString.h"



XString::XString()
{
}

XString::XString(char string[])
{
	
	for (int i = 0; i < strlen(string)+1; i++)
	{
		this->string[i] = string[i];
	}

}

XString XString::operator*=(XString & other)
{
	int iterator = 0;
	char tmp[80] = {};

	for (int i = 0; i < strlen(this->string); i++)
	{
		for (int j = 0; j < strlen(other.string); j++)
		{
			if (this->string[i] == other.string[j]) {
				tmp[iterator] = this->string[i];
				iterator++;
			}
		}
		
	}

	for (int i = 0; i < strlen(tmp); i++)
	{
		cout << tmp[i];
	}
	cout << endl;
	
	return tmp;
}

XString XString::operator/=(XString & other)
{
	int iterator = 0;
	char tmp[80] = {};

	for (int i = 0; i < strlen(this->string); i++)
	{
		int counter = 0;
		for (int j = 0; j < strlen(other.string); j++)
		{
			if (this->string[i] != other.string[j]) {
				counter++;
			}
		}
		if (counter == strlen(other.string)) {
			tmp[iterator] = this->string[i];
			iterator++;
		}

	}

	for (int i = 0; i < strlen(tmp); i++)
	{
		cout << tmp[i];
	}
	cout << endl;

	return tmp;
}

XString XString::operator+=(XString & other)
{
	int iterator = 0;
	char tmp[80] = {};

	for (int i = 0; i < strlen(this->string)+strlen(other.string); i++)
	{
		
		if (i < strlen(this->string)) {
			tmp[i] = this->string[i];
		}
		else {
			tmp[i] = other.string[iterator];
			iterator++;
		}

	}

	for (int i = 0; i < strlen(tmp); i++)
	{
		cout << tmp[i];
	}
	cout << endl;

	return tmp;
}

void XString::ShowString()
{
	for (int i = 0; i < strlen(this->string); i++)
	{
		cout << this->string[i];
	}
	cout << endl;
}


XString::~XString()
{
}
