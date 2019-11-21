#include "Train.h"



int main() {
	int size = 3, tSize = 2;
	Train Poizd(154, "Lviv-Kyiv", size);
	Train *poizd = new Train[tSize];
	Car *cars = new Car[size];

	string type;
	unsigned short passengers;
	for (int i = 0; i < tSize; i++) {
	
		for (int j = 0; j < size; j++) {
			cout << "Car N" << j + 1 << endl;
			cout << "Enter car's type: ";
			cin >> type;
			cout << "Enter passenger's count: ";
			cin >> passengers;
			cars[j] = Car(type, passengers);
		}
		poizd[i].SetCars(cars);
	}

	
	//for (int i = 0; i < size; i++) {
	//	cout << "Car N" << i + 1 << endl;
	//	cout << "Enter car's type: ";
	//	cin >> type;
	//	cout << "Enter passenger's count: ";
	//	cin >> passengers;
	//	cars[i] = Car(type, passengers);
	//}

	Poizd.SetCars(cars);
	Poizd.ShowCars();
	Poizd.ShowAllPassengers();
	Poizd.ShowMaxPassengers();
	Poizd.ShowMinPassengers();
	Poizd.ShowTrain();
	system("pause");
	return 0;
}