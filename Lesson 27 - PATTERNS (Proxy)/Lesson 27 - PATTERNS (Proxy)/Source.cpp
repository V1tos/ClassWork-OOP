#include <iostream>
#include <string>
#include <vector>
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


	void CashMinus(int inputCashValue) {
		if (IsEnoughBalance(inputCashValue))
		{
			cashBalance -= inputCashValue;
			cout << "Keep your money\n";
		}
		else
		{
			cout << "You haven't got enough money!\n";
		}
	}


	bool IsEnoughBalance(int inputCashValue) {
		return cashBalance >= inputCashValue;
	}


	bool CheckNumberAndPassword(int inputAccountNumber, int inputAccountPassword) {
		return CheckNumber(inputAccountNumber) && CheckPassword(inputAccountPassword);
	}

	bool CheckNumber(int inputAccountNumber) {
		return accountNumber == inputAccountNumber;
	}

	bool CheckPassword(int inputAccountPassword) {
		return accountPassword == inputAccountPassword;
	}


	void ShowBalance() {
		cout << "Your sum on account: " << cashBalance << " UAh" << endl;
	}

	~Account() {};

};




class ATM : public IAccount
{
protected:
	Account * account;
	int inputPassword;

	bool CheckAccountPassword() {
		return (account->CheckPassword(inputPassword));
	}
public:
	ATM() {};
	ATM(Account * account, int inputPassword) {
		this->account = account;
		this->inputPassword = inputPassword;
	};

	void ShowBalance() {
		if (CheckAccountPassword())
			account->ShowBalance();
		else
			cout << "Wrong password\n";
	}

	void CashATMMinus() {
		if (CheckAccountPassword()) {
			
			account->CashMinus(InputCash());
		}
		else {
			cout << "Wrong password\n";
		}
	}

	int InputCash() {
		int inputCashValue = 0;
		cout << "Enter your sum: ";
		cin >> inputCashValue;
		return inputCashValue;
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
	Client(string name, string surname) : name(name), surname(surname){};

	string GetName() {
		return name;
	}
	string GetSurname() {
		return surname;
	}

	Account* GetAccount() {
		return account;
	}


	void SetAccount(Account* otherAccount) {
		account = otherAccount;
	}

	bool IsOpenAccount() {
		return (account!=nullptr);
	}

	
	bool operator == (Client &otherClient){ 
		return (name == otherClient.name && surname == otherClient.surname);
	}

	bool CheckAccountNumber(Client &otherClient) {
		return (account->GetNumber() == otherClient.account->GetNumber());
	}
	void ShowClient() {
		cout << "Name: " << name << " " << surname << endl;
		cout << "Account's number: " << account->GetNumber() << endl;
	}

	void DeleteAccount() {
		delete account;
	}

	~Client() {}


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


	void AddClient(Client newClient) {
		clientsData.push_back(newClient);
		cout << "Client added and client's account has been created.\n";
	}

	Account* CreateAccount(int number, int password) {
		return new Account(number, password);
	}
	

	bool CheckClientByName(Client &otherClient) {
		for (auto client : clientsData) {
			if (client.operator==(otherClient))
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
			if (client.GetAccount()->CheckNumber(inputAccountNumber))
				return client.GetAccount();
		}
	}

	void SetChangesAccount(Account* editAccount) {
		for (auto client : clientsData)
		{
			if (client.GetAccount()->CheckNumber(editAccount->GetNumber()))
				client.SetAccount(editAccount);
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
	~Bank() {
		while (clientsData.size())
		{
			clientsData.pop_back();
		}
	};

};






void CreateClientInBank(Bank &bank);
void OpenBankAccount(Bank &bank, Client &newClient);
Account* RegisterAccount(Bank &bank);

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

	Client *newClient = new Client(clientName, clientSurname);
	

	if (!bank.CheckClientByName(*newClient))
	{
		OpenBankAccount(bank, *newClient);
		delete newClient;
	}
	else
	{
		cout << "Client " << clientName << " " << clientSurname << " has already created!\n";
		delete newClient;
	}
	
}

void OpenBankAccount(Bank &bank, Client &newClient) {
	Account *newAccount = RegisterAccount(bank);
	newClient.SetAccount(newAccount);

	bank.AddClient(newClient);
}


Account* RegisterAccount(Bank &bank) {

	int accountNumber = rand() % 9999999 + 1000000;
	cout << "Client account's number: " << accountNumber << endl;
	int accountPassword = 0;
	cout << "Enter personal password (ex. 3423): ";
	cin >> accountPassword;

	return bank.CreateAccount(accountNumber, accountPassword);
}


void CashOut(ATM* &atmProxy, Account* &clientAccount);
void ShowAccountBalance(ATM* &atmProxy, Account* &clientAccount);

void ATMmanagement(Bank &bank) {
	system("cls");
	int inputAccountNumber = 0, inputAccountPassword=0;
	
	cout << "Enter your account's number: ";
	cin >> inputAccountNumber;
	cout << "Enter your password: ";
	cin >> inputAccountPassword;

	if (bank.CheckATMlogin(inputAccountNumber, inputAccountPassword))
	{
		Account* clientAccount = bank.GetClientAccountByNumber(inputAccountNumber);
		ATM* atmProxy;
		bool ATMexit = false;
		int clientChoice = 0;

		while (!ATMexit)
		{
			system("cls");
			cout << "1 - Cash out\n2 - Show balance \n0 - Exit\nYour choice: ";
			cin >> clientChoice;

			switch (clientChoice)
			{
			case 1:
				system("cls");
				CashOut(atmProxy, clientAccount);
				system("pause");
				break;
			case 2:
				system("cls");
				ShowAccountBalance(atmProxy, clientAccount);
				system("pause");
				break;
			case 0:
				bank.SetChangesAccount(clientAccount);
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


void CashOut(ATM* &atmProxy, Account* &clientAccount) {
	int inputAccountPassword=0;
	cout << "Enter your password: ";
	cin >> inputAccountPassword;

	atmProxy = new ATM(clientAccount, inputAccountPassword);
	atmProxy->CashATMMinus();
}


void ShowAccountBalance(ATM* &atmProxy, Account* &clientAccount) {
	int inputAccountPassword=0;
	cout << "Enter your password: ";
	cin >> inputAccountPassword;

	atmProxy = new ATM(clientAccount, inputAccountPassword);
	atmProxy->ShowBalance();
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

	system("pause");
	return 0;
}