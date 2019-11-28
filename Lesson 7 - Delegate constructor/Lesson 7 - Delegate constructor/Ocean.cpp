#include "Ocean.h"



void Ocean::DrawOcean()
{
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 30; j++)
		{
			if (i == 0 || i == 19) {
				cout << "#";
			}
			else if (j == 0 || j == 29)
			{
				cout << "#";
			}
			/*else if (j == this->x&&i == this->y)
			{
				cout << "F";
			}*/
			else
			{
				cout << " ";
			}

		}
		cout << endl;
	}
}

Ocean::Ocean()
{
	this->DrawOcean();
}


Ocean::~Ocean()
{
}
