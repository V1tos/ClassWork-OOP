#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Drink abstract
{
protected:
	string drinkName;
public:
	void Keep() {
		cout << "Youe kept " << drinkName << endl;
	};
	virtual ~Drink() {};

};

class Coffee : public Drink
{
public:
	Coffee() { this->drinkName = "Coffee"; }
};

class Tea : public Drink
{
public:
	Tea() { this->drinkName = "Tea"; }
};

class Chocolate : public Drink
{
public:
	Chocolate() { this->drinkName = "Chocolate"; }
};

class Capuccino : public Drink
{
public:
	Capuccino() { this->drinkName = "Capuccino"; }
};

enum Drinks
{
	COFFEE = 1,
	TEA,
	CHOCOLATE,
	CAPUCCINO
};

class FabricMethod
{
public:

	 static Drink* CreateDrink(Drinks drinksType) {

		switch (drinksType)
		{
		case COFFEE:
			return new Coffee;
			break;
		case TEA:
			return new Tea;
			break;
		case CHOCOLATE:
			return new Chocolate;
			break;
		case CAPUCCINO:
			return new Coffee;
			break;
		}
	}
	~FabricMethod() {};

};



int main() {
	vector <Drink*> drinks;

	int choice = 0;
	while (true)
	{
		system("cls");
		cout << "Change drink:\n1 - Coffe\n2 - Tea\n3 - Chocolate\n4 - Capuccino\n0 - Exit\nYour choice: ";
		cin >> choice;

		if (choice == 0)break;

		drinks.push_back(FabricMethod::CreateDrink((Drinks)choice));
	}

	for (auto el : drinks)
	{
		el->Keep();
	}
	
	for (auto el : drinks)
	{
		delete el;
	}

	system("pause");
	return 0;
}