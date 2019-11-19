#include "DiscountCard.h"
#include <ctime>


void Menu() {
	system("cls");
	cout << "------------------------Menu---------------------" << endl;
	cout << "1 - Buy products with discount's card\n2 - Show discount's card information\n3 - Show your discount\n4 - Check price for discount\n0 - Exit\n";
	cout << "------------------------Menu---------------------" << endl;
	cout << "Your choice: ";
}


int main() {
	srand(unsigned(time(NULL)));
	bool exit = false;

	DiscountCard test;
	

	while (!exit) {
		short choice = 0;
		unsigned int cost = 0;
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Enter product's price: ";
			cin >> cost;
			test.UpdateDiscount(cost);
			test.BuyProductWithCard(cost);
			test.ShowDiscountProduct(cost);
			system("pause");
			break;
		case 2:
			system("cls");
			test.ShowCardInfo();
			system("pause");
			break;
		case 3:
			system("cls");
			test.ShowDiscount();
			system("pause");
			break;
		case 4:
			system("cls");
			test.Checking();
			system("pause");
			break;
		case 0:
			exit = true;
			break;
		default:
			break;
		}
		
		
		


	}




	system("pause");
	return 0;
}