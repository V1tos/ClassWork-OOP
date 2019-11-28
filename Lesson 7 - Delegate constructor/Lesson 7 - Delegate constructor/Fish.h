#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;



class Fish
{
	unsigned short x, y;
	unsigned short health;
	static unsigned short counter;

	void DrawFish();

	static void DrawOcean();

public:
	Fish();
	Fish(short x, short y);
	~Fish();
};

