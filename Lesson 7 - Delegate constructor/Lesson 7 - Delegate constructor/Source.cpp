#include "Fish.h"
#include "Ocean.h"

void DrawOcean() {

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
			
			else
			{
				cout << " ";
			}

		}
		cout << endl;
	}

}

int main() {
	srand(unsigned(time(NULL)));
	system("cls");
	DrawOcean();
	Fish fish(5,6);

	



	system("pause");
	return 0;
}