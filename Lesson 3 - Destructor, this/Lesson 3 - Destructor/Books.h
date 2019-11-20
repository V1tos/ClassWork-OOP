#pragma once
#include <iostream>
#include <string>
using namespace std;

class Books
{
private:
	string title;
	string author;
	unsigned short pages;
	unsigned short published;
	string description;
public:
	Books();
	Books(string title, string author, unsigned short pages, unsigned short published, string description);
	~Books();
};

