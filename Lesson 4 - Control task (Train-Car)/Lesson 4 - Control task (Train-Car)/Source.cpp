#include "Train.h"



int main() {
	/*int trainsCount = 1;
	
	Train *trains = new Train[trainsCount];
	unsigned short number = 0;
	string name;
	unsigned short carsCount = 0;*/

	Train ternopil(1337, "Ternopil-Kyiv", 2);
	ternopil.ShowTrain();

	Train test(ternopil);
	test.ShowTrain();
	string name = "Poltava-Kharkiv";
	test.SetName(name);
	test.ShowTrain();

	//for (int i = 0; i < trainsCount; i++) {
	//	cout << "Train N" << i + 1 << endl;
	//	cout << "Enter train's number: ";
	//	cin >> number;
	//	cout << "Enter train's name: ";
	//	cin >> name;
	//	cout << "Enter car's count: ";
	//	cin >> carsCount;
	//	trains[i] = Train(number, name, carsCount);
	//	system("cls");
	//}

	//
	//
	//for (int i = 0; i < trainsCount; i++) {
	//	cout << "Train N" << i + 1 << endl;
	//	cout <<"All passengers: " << trains[i].SumaPassengers();
	//	cout << endl;
	//}

	//for (int i = 0; i < trainsCount; i++) {
	//	cout << "Train N" << i + 1 << endl;
	//	trains[i].ShowTrain();
	//	cout << endl;
	//	
	//}

	//for (int i = 0; i < trainsCount; i++) {
	//	cout << "Train N" << i + 1 << endl;
	//	trains[i].FindMaxPassengers();
	//	cout << endl;

	//}

	//for (int i = 0; i < trainsCount; i++) {
	//	cout << "Train N" << i + 1 << endl;
	//	trains[i].FindMinPassengers();
	//	cout << endl;

	//}

	system("pause");
	return 0;
}