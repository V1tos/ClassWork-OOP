#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



//Створити класи Клієнт, Банк, Рахунок(номер рахунку, пароль, сума).У класі Рахунок
//визначити методи отримання інформації про кошти на рахунку та зняття з рахунку певної
//суми.
//Створити клас Банкомат, який надаватиме сервіси зняття грошей та інформації по
//рахунку певному клієнту.Використати патерн Proxy.




__interface IAccount
{	
public:
	void ShowBalance() = 0;
	void CashMinus(int inputCashValue) = 0;
};

class Account : public IAccount
{
protected:
	int accountNumber;
	int accountPassword;
	int cashBalance;
public:

	Account() {};
	Account(int accountNumber, int accountPassword) {
		this->accountNumber = accountNumber;
		this->accountPassword = accountPassword;
		cashBalance = 1000;
	}

	int GetNumber() {
		return accountNumber;
	}

	void ShowBalance() {
		cout << "Your sum on account: " << cashBalance <<" UAh" << endl;
	}

	void CashMinus(int inputCashValue) {
		if (inputCashValue <= cashBalance)
		{
			cashBalance -= inputCashValue;
			cout << "Keep your money\n";
		}
		else
		{
			cout << "You haven't got enough money!\n";
		}
	}


	bool CheckPassword(int inputAccountNumber) {
		if (accountPassword == inputAccountNumber)
			return true;
		return false;
	}


	bool CheckNumberAndPassword(int inputAccountNumber, int inputAccountPassword) {
		if(accountPassword == inputAccountPassword &&accountNumber == inputAccountNumber)
			return true;
		return false;
	}
	~Account() {};

};




class ATM : public IAccount
{
protected:
	Account * account;
	int inputPassword;
	
	bool CheckAccountPassword(){
		return (account->CheckPassword(inputPassword));
	}
public:
	ATM() {};
	ATM(Account * account,int inputPassword){
		this->account = account;
		this->inputPassword = inputPassword;
	};

	void ShowBalance(){
		if (CheckAccountPassword())
			account->ShowBalance();
		else
			cout << "Wrong password\n";
	}


	void CashATMminus() {
		if (CheckAccountPassword()) {
			int inputCashValue = 0;
			cout << "Enter your sum: ";
			cin >> inputCashValue;
			account->CashMinus(inputCashValue);
		}
		else {
			cout << "Wrong password\n";
		}
	}

	void CashMinus(int inputCashValue) {
		if (CheckAccountPassword())
			account->CashMinus(inputCashValue);
		else
			cout << "Wrong password\n";

	}


	~ATM() {
		delete account;
	}
	
};


class Client
{
	string name;
	string surname;
	Account* account;

public:
	Client(string name, string surname, Account* account) : name(name), surname(surname),account(account) {};

	string GetName() {
		return name;
	}
	string GetSurname() {
		return surname;
	}


	Account* GetAccount() {
		if (account != nullptr)
			return account;
		else
			cout << "You don't have opening account!!\n";
			return 0;	
	}	

	void ShowClient() {
		cout << "Name: " << name << " " << surname << endl;
		cout << "Account's number: " << account->GetNumber() << endl;
	}

	~Client() {};


};

class Bank
{
	string name;
	vector <Client> clientsData;

public:
	Bank(string name = "Default bank") : name(name) {};

	vector <Client> GetClientsData() {
		return clientsData;
	}


	void AddClientAndCreateAccount(string clientName, string clientSurname) {
		if (!CheckClient(clientName, clientSurname))
		{
			int accountNumber = rand() % 9999999 + 1000000;
			int accountPassword = 0;
			cout << "Your account's number: " << accountNumber << endl;
			cout << "Create your personal password (ex. 3423): ";
			cin >> accountPassword;

			clientsData.push_back(Client(clientName, clientSurname, new Account(accountNumber, accountPassword)));
			cout << "Client added and client's account has created.\n";
		}
		else
		{
			cout << "Client " << clientName << " " << clientSurname << " has already created!\n";
		}

		
	}


	bool CheckClient(string inputName, string inputSurname) {
		for (auto client : clientsData) {
			if (client.GetName() == inputName && client.GetSurname() == inputSurname)
				return true;
		}
		return false;
	}

	bool CheckATMlogin(int inputAccountNumber, int inputAccountPassword) {
		for (auto client : clientsData) {
			if (client.GetAccount()->CheckNumberAndPassword(inputAccountNumber, inputAccountPassword))
				return true;
		}	
		return false;
	}

	Account* GetClientAccountByNumber(int inputAccountNumber) {
		for (auto client : clientsData)
		{
			if (client.GetAccount()->GetNumber() == inputAccountNumber)
			{
				return client.GetAccount();
			}
		}
		
	}

	void ShowClient() {
		int iterator = 0;
		for (auto client : clientsData)
		{
			cout << "Client N: " << ++iterator << endl;
			client.ShowClient();
			cout << endl;
		}
	}
	~Bank() {};

};




void CreateClientInBank(Bank &bank);


void BankManagement(Bank &bank) {
	int choice = 0;
	bool bankExit = false;

	while (!bankExit)
	{
		system("cls");
		cout << "1 - Add client and create client's account\n2 - Show information about client\n0 - Exit\nYour choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			CreateClientInBank(bank);
			system("pause");
			break;
		case 2:
			system("cls");
			bank.ShowClient();
			system("pause");
			break;
		case 0:
			bankExit = true;
			break;
		default:
			cout << "Wrong choice!! Try again.\n";
			system("pause");
			break;
		}
	}

}

void CreateClientInBank(Bank &bank) {
	string clientName, clientSurname;
	cout << "Enter your name: ";
	cin >> clientName;
	cout << "Enter your surname: ";
	cin >> clientSurname;
	bank.AddClientAndCreateAccount(clientName, clientSurname);
}




void CashOut(Bank &bank, int inputAccountNumber, ATM* &atmProxy);
void ShowAccountBalance(Bank &bank, int accountNumber, ATM* &atmProxy);

void ATMmanagement(Bank &bank) {
	system("cls");
	bool ATMexit = false;
	int inputAccountNumber = 0, inputAccountPassword=0, clientChoice = 0;
	ATM* atmProxy;

	cout << "Enter your account's number: ";
	cin >> inputAccountNumber;
	cout << "Enter your password: ";
	cin >> inputAccountPassword;

	if (bank.CheckATMlogin(inputAccountNumber, inputAccountPassword))
	{
		while (!ATMexit)
		{
			system("cls");
			cout << "1 - Cash out\n2 - Show balance \n0 - Exit\nYour choice: ";
			cin >> clientChoice;

			switch (clientChoice)
			{
			case 1:
				system("cls");
				CashOut(bank, inputAccountNumber, atmProxy);
				system("pause");
				break;
			case 2:
				system("cls");
				ShowAccountBalance(bank, inputAccountNumber, atmProxy);
				system("pause");
				break;
			case 0:
				ATMexit = true;
				break;
			default:
				cout << "Wrong choice!! Try again.\n";
				system("pause");
				break;
			}
		}
	}
	else
	{
		cout << "Wrong Number or Password!!\n";
		system("pause");

	}
}


void CashOut(Bank &bank, int inputAccountNumber, ATM* &atmProxy) {
	int inputCashValue = 0;
	int inputAccountPassword;
	cout << "Enter your password: ";
	cin >> inputAccountPassword;


	Account* clientAccount = bank.GetClientAccountByNumber(inputAccountNumber);

	if (clientAccount)
	{
		atmProxy = new ATM(clientAccount, inputAccountPassword);
		atmProxy->CashATMminus();
	}
	else
	{
		cout << "Wrong account's password!\n";
	}
}


void ShowAccountBalance(Bank &bank, int accountNumber, ATM* &atmProxy) {
	int accountPassword;
	cout << "Enter your password: ";
	cin >> accountPassword;

	Account* clientAccount = bank.GetClientAccountByNumber(accountNumber);

	if (clientAccount)
	{
		atmProxy = new ATM(clientAccount, accountPassword);
		atmProxy->ShowBalance();
	}
	
}



void DeleteBank(Bank &bank) {

	for (auto client : bank.GetClientsData())
	{
		delete client.GetAccount();
	}
}



int main() {

	bool exit = false;
	Bank privat("Privat bank");
	int choice = 0;

	while (!exit)
	{
		system("cls");
		cout << "1 - Bank management\n2 - Client's using (ATM)\n0 - Exit\nYour choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			BankManagement(privat);
			break;
		case 2:
			ATMmanagement(privat);
			break;
		case 0:
			exit = true;
			break;
		default:
			cout << "Wrong choice!!\n";
			break;
		}
	}
	DeleteBank(privat);

	system("pause");
	return 0;
}