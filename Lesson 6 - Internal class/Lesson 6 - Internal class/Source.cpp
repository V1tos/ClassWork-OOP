#include <iostream>
#include <string>

using namespace std;


class Train {
public:
	Train() {
		cout << "Default train constructor." << endl;
	}
	Train(string route, int distance,int carsCount) {
		this->route = route;
		this->distance = distance;
		this->carsCount = carsCount;
		this->car = new Car[this->carsCount];
		cout << "Overload train constructor." << endl;
	}
	void ShowTrain() {
		cout << "Route: " << this->route << "\nDistance: " << this->distance << endl;
		for (int i = 0; i < this->carsCount; i++)
		{
			cout << "Car N" <<this->car[i].GetCarNumber(); cout << endl;
			this->car[i].ShowCar();
		}
		
	}
	void FillCars() {
		string type;
		int passengers = 0;
		for (int i = 0; i < this->carsCount; i++)
		{
			cout << "Enter car's type: ";
			cin >> type;
			cout << "Enter passenger's count: ";
			cin >> passengers;
			this->car[i] = Car(type, passengers);
		}
	}
	void ShowCount() {
		int count = 0;
		for (int i = 0; i < this->carsCount; i++)
		{
			count = this->car[i].GetCounter();
		}
		cout << "Count = " << count << endl;

	}
	~Train() {
		this->car = nullptr;
		delete[] this->car;
	}
private:

	class Car {
	private:
		string type;
		int passengers;
		static int counter;
		int carNumber;
	public:
		Car() {
			cout << "Default car constructor. " << endl;
		}
		Car(string type, int passengers) {
			this->type = type;
			this->passengers = passengers;
			this->counter++;
			this->carNumber = counter;
			cout << "Overload car constructor. " << endl;
		}
		void ShowCar() {

			cout << "Type: " << this->type << "\nPassengers: " << this->passengers << endl;
		}

		int GetCarNumber() {
			return this->carNumber;
		}

		int GetCounter() {
			return this->counter;
		}


	};


	string route;
	int distance;
	int carsCount;
	Car *car;
	
};



int Train::Car::counter = 0;
int main() {

	
	/*Train train("Ternopil - Kyiv", 250, 3);
	train.FillCars();
	train.ShowTrain();*/
	
	string route;
	int distance = 0, carsCount = 0;

	Train *trains = new Train[2];

	for (int i = 0; i < 2; i++)
	{
		cout << "Enter train's route: ";
		cin >> route;
		cout << "Enter route's distance: ";
		cin >> distance;
		cout << "Enter car's count: ";
		cin >> carsCount;
		trains[i] = Train(route, distance, carsCount);
	}
	
	for (int i = 0; i < 2; i++)
	{
		cout << "Train N" << i + 1 << endl;
		trains[i].FillCars();
	}

	for (int i = 0; i < 2; i++)
	{
		cout << "Train N" << i + 1 << endl;
		trains[i].ShowTrain();
	}
	for (int i = 0; i < 2; i++)
	{
		trains[i].ShowCount();
		break;
	}

	
	

	system("pause");
	return 0;
}