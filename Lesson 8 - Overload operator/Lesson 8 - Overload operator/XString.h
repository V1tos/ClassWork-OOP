#pragma once
#include <iostream>
using namespace std;



class XString
{
private:
	char string[80];
public:
	XString();
	XString(char string[]);
	XString operator*(XString &other);
	void ShowString();
	~XString();
};

