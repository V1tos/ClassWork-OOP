#include <iostream>
#include <string>
using namespace std;



//Створити класи Клієнт, Банк, Рахунок(номер рахунку, пароль, сума).У класі Рахунок
//визначити методи отримання інформації про кошти на рахунку та зняття з рахунку певної
//суми.
//Створити клас Банкомат, який надаватиме сервіси зняття грошей та інформації по
//рахунку певному клієнту.Використати патерн Proxy.

class Client
{

	int accountNumber;
	int accountPassword;
public:
	Client(int accountNumber, int accountPassword) : accountNumber(accountNumber), accountPassword(accountPassword) {};
	~Client();


};


__interface IAccount
{
	
public:
	void ShowSum() = 0;
	void GiveMoney(int clientOutSum) = 0;
	void GetMoney(int clientInSum) = 0;
};

class Account : protected IAccount
{
	int accountNumber;
	int accountPassword;
	int costsSum;
public:

	Account();
	Account(int accountNumber, int accountPassword) {
		this->accountNumber = accountNumber;
		this->accountPassword = accountPassword;
		costsSum = 0;
	}
	void ShowSum() {
		cout << "Your sum on account: " << costsSum << endl;
	}
	void GiveMoney(int clientOutSum) {
		if (clientOutSum <=costsSum)
		{
			costsSum -= clientOutSum;
			cout << "Keep your money\n";
		}
		else
		{
			cout << "You haven't got enough money!\n";
		}
	}
	void SetMoney(int clientInSum) {
		costsSum += clientInSum;
		cout << "Your account's sum has added\n";
	}


	int GetNumber() {
		return accountNumber;
	}
	int GetPassword() {
		return accountPassword;
	}
	~Account();

private:

};

class ATM : IAccount
{
	
	Account * account;
	bool CheckAcces(int accountNumber,int accountPassword){
		if (accountNumber==account->GetNumber()&&accountPassword==account->GetPassword())
		{

		}
	}
public:
	ATM(Account * account) : account(new Account(*account)) {};
	~ATM() {
		delete account;
	}

	
};



int main() {



	system("pause");
	return 0;
}