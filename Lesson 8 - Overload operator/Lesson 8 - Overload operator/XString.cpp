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

XString XString::operator*(XString & other)
{
	char tmp[80];
	int iterator = 0;
	cout << strlen(this->string) << endl;
	cout << strlen(other.string) << endl;

	for (int i = 0; i < strlen(this->string); i++)
	{
		for (int j = 0; j < strlen(other.string); j++)
		{
			if (this->string[i] == other.string[j]) {
				tmp[iterator] == other.string[j];
				iterator++;
			}
		}
		
	}

	for (int i = 0; i < strlen(tmp); i++)
	{
		cout << tmp[i];
	}
	return *this;
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
