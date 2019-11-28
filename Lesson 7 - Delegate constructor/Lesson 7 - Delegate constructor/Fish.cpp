#include "Fish.h"




void Fish::DrawFish()
{
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 30; j++)
		{
			
			if (j == this->x&&i == this->y)
			{
				cout << "F";
			}
			

		}
		cout << endl;
	}
}

void Fish::DrawOcean()
{
}

Fish::Fish()
{
	this->x = rand()%33 + 1;
	this->y = rand()%18 + 1;
	DrawFish();
}

Fish::Fish(short x, short y)
{
	this->x = x;
	this->y = y;
	DrawFish();
}


Fish::~Fish()
{
}
