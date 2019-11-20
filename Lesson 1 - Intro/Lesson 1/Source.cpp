#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class Point
{
private:
	int x;
	int y;

public:

	void SetX(int value) {

		x = value;
	}
	
	void SetY(int value) {

		y = value;
	}
	
	void ShowPoint() {
		cout << "X: " << x << "\nY: " << y << endl;
	}

};

class Account
{
private:
	unsigned int number;
	unsigned int countCosts;

public:

	void OpenAccount() {
		number = rand() % 99000 + 10000;
		cout << "Enter cost: ";
		cin >> countCosts;
	}
	void AddCost() {
		unsigned int value = 0;
		cout << "Enter value: ";
		cin >> value;
		countCosts += value;
	}

	void PullCost() {
		unsigned int value = 0;
		cout << "Enter value: ";
		cin >> value;
		countCosts -= value;
	}

	void ShowAccount() {
		cout << "Cost number: " << number << "\nCount costs: " << countCosts << " UAH\n";
	}

	

};


void AddAccount(Account *&account, int &size) {
	Account *newAccount = new Account[size + 1];


	for (int i = 0; i < size+1; i++)
	{
		if (i >= size) {
			newAccount[i].OpenAccount();
		}
		else {
			newAccount[i] = account[i];
		}
	}


	size++;

	delete account;
	account = newAccount;


}

void AccountList(Account *&account, int &size) {

	for (int i = 0; i < size; i++) {
		cout << "Account N" << i + 1 << endl;
		account[i].ShowAccount();
	}
}

void PlusCost(Account *&account, int &size) {
	AccountList(account, size);
	int number = 0;

	cout << "Enter account's number: ";
	cin >> number;

	account[number - 1].AddCost();
}

void MinusCost(Account *&account, int &size) {
	AccountList(account, size);
	int number = 0;

	cout << "Enter account's number: ";
	cin >> number;

	account[number - 1].PullCost();
}

void Transfer(Account *&account, int &size) {
	AccountList(account, size);
	int outNumber = 0, inNumber = 0, outCost = 0;
	cout << "Enter account's number: ";
	cin >> outNumber;
	cout << "Enter sum: ";
	cin >> outCost;
	account[outNumber - 1].PullCost();




}



int main() {
	srand(unsigned(time(NULL)));

	int size = 0;
	Account *account=new Account[size];
	
	bool exit = false;

	while (!exit) {
		system("cls");
		
		int choice = 0;
		cout << "1 - Create account\n2 - Add cost\n3 - Pull cost\n4 - Show account info\n0 - Exit\nYour choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			AddAccount(account, size);
			cout << "Opened\n";
			system("pause");
			break;
		case 2:
			system("cls");
			/*account.AddCost()*/;
			system("pause");
			break;
		case 3:
			system("cls");
			/*account.PullCost();*/
			system("pause");
			break;
		case 4:
			system("cls");
			AccountList(account, size);
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