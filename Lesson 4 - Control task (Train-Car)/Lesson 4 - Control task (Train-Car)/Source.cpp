#include "Train.h"



int main() {
	int trainsCount = 2;
	
	Train *trains = new Train[trainsCount];
	unsigned short number = 0;
	string name;

	for (int i = 0; i < trainsCount; i++) {
		cout << "Train N" << i + 1 << endl;
		cout << "Enter train's number: ";
		cin >> number;
		cout << "Enter train's name: ";
		cin >> name;
		trains[i] = Train(number, name);
		system("cls");
	}

	for (int i = 0; i < trainsCount; i++) {
		cout << "Train N" << i + 1 << endl;
		trains[i].FillCars();
		system("cls");
	}
	
	for (int i = 0; i < trainsCount; i++) {
		cout << "Train N" << i + 1 << endl;
		cout <<"All passengers: " << trains[i].SumaPassengers();
		cout << endl;
	}

	for (int i = 0; i < trainsCount; i++) {
		cout << "Train N" << i + 1 << endl;
		trains[i].ShowTrain();
		cout << endl;
		
	}

	for (int i = 0; i < trainsCount; i++) {
		cout << "Train N" << i + 1 << endl;
		trains[i].FindMaxPassengers();
		cout << endl;

	}

	for (int i = 0; i < trainsCount; i++) {
		cout << "Train N" << i + 1 << endl;
		trains[i].FindMinPassengers();
		cout << endl;

	}

	system("pause");
	return 0;
}