#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//Создать класс СПРАВОЧНИК со следующими полями :
//1. Название фирмы;
//2. Владелец;
//3. Телефон;
//4. Адрес;
//5. Род деятельности.
//Реализовать следующие возможности :
//1. Поиск по названию;
//2. Поиск по владельцу;
//3. Поиск по номеру телефона;
//4. Поиск по роду деятельности;
//5. Показ всех записей и добавление.
//Вся информация, должна сохранятся в бинарном файле, должна быть реализована
//возможность добавления новых данных.


class Notepad
{


	class Database
	{
		

	public:
		string companyName;
		string owner;
		unsigned int telephoneNumber;
		string address;
		string occupation;
		Database *nextData;


		Database(string companyName, string owner, unsigned int telephoneNumber, string address, string occupation) {
			this->nextData = nullptr;
			this->address = address;
			this->companyName = companyName;
			this->occupation = occupation;
			this->telephoneNumber = telephoneNumber;
			this->owner = owner;

			
		};
		Database() {

		};
		
		void ShowData() {
			cout << "Company's name:      " << this->companyName << endl;
			cout << "Owner's name:        " << this->owner << endl;
			cout << "Telephone's number:  " << this->telephoneNumber << endl;
			cout << "Address:             " << this->address << endl;
			cout << "Occupation:          " << this->occupation << endl;
		}
		~Database() {};

	};

	
	

	

	Database *head;
	int size = 0;
public:
	

	Notepad() {
		this->head = nullptr;
		this->size = 0;
	};

	void AddProfile() {
		
		string companyName;
		string owner;
		unsigned int telephoneNumber=0;
		string address;
		string occupation;

		cout << "Profile N" << this->size + 1 <<":" << endl;
		cout << "Enter company's name: ";
		cin >> companyName;
		cout << "Enter owner's name: ";
		cin.ignore();
		getline(cin, owner);
		cout << "Enter telephone's number: ";
		cin >> telephoneNumber;
		cout << "Enter address: ";
		cin.ignore();
		getline(cin, address);
		cout << "Enter occupation: ";
		cin >> occupation;

		if (this->head == nullptr) {
			this->head = new Database(companyName,owner, telephoneNumber, address, occupation);
			this->size++;
		}
		else
		{
			Database *current = this->head;
			while (current->nextData != nullptr) {
				current = current->nextData;
			}
			current->nextData = new Database(companyName, owner, telephoneNumber, address, occupation);
			this->size++;


		}

		
	};

	void FindCompanyName() {
		Database *current = this->head;
		int iterator = 0;
		string companyName;
		cout << "Enter company's name: ";
		cin >> companyName;
		while (current != nullptr)
		{
			if (current->companyName == companyName) {
				cout << "Profile N" << iterator + 1 << endl;
				current->ShowData();
			}
			current = current->nextData;
			iterator++;

		}

	}

	void FindOwner() {
		Database *current = this->head;
		int iterator = 0;
		string owner;
		cout << "Enter owner: ";
		cin >> owner;
		while (current != nullptr)
		{
			if (current->owner == owner) {
				cout << "Profile N" << iterator + 1 << endl;
				current->ShowData();
			}
			current = current->nextData;
			iterator++;

		}

	}
	void FindTelephoneNumber() {
		Database *current = this->head;
		int iterator = 0;
		unsigned int telephoneNumber=0;
		cout << "Enter telephone's number: ";
		cin >> telephoneNumber;
		while (current != nullptr)
		{
			if (current->telephoneNumber == telephoneNumber) {
				cout << "Profile N" << iterator + 1 << endl;
				current->ShowData();
			}
			current = current->nextData;
			iterator++;

		}

	}

	void FindAddress() {
		Database *current = this->head;
		int iterator = 0;
		string address;
		cout << "Enter addres: ";
		cin >> address;
		while (current != nullptr)
		{
			if (current->address == address) {
				cout << "Profile N" << iterator + 1 << endl;
				current->ShowData();
			}
			current = current->nextData;
			iterator++;

		}

	}

	void FindOccupation() {
		Database *current = this->head;
		int iterator = 0;
		string occupation;
		cout << "Enter occupation: ";
		cin >> occupation;
		while (current != nullptr)
		{
			if (current->occupation == occupation) {
				cout << "Profile N" << iterator + 1 << endl;
				current->ShowData();
			}
			current = current->nextData;
			iterator++;

		}

	}

	void ShowInfo() {
		Database *current = this->head;
		int iterator = 0;
		while (current!=nullptr)
		{
			cout << "Profile N" << iterator + 1 << endl;
			current->ShowData();
			current = current->nextData;
			iterator++;

		}

	};

	void WriteFile() {
		
		ofstream writeFile;
		writeFile.open("Test.txt",ios::app);

	

		writeFile.write((char*)&this->head, sizeof(this->head));

		

		writeFile.close();
	}

	void ReadFile() {
		
		ifstream readFile;
		readFile.open("Test.txt", ios::in);

		
		


		readFile.read((char*)&this->head, sizeof(this->head));

	
		

		while (!readFile.eof()) {
			
			readFile.read((char*)&this->head, sizeof(this->head));
		}


		

	}

	~Notepad() {};

};





int main() {
	Notepad noteList;
	noteList.ReadFile();
	noteList.ShowInfo();

	/*noteList.AddProfile();
	noteList.WriteFile();*/
	/*noteList.AddProfile();*/
	/*noteList.FindCompanyName();
	noteList.ShowInfo();*/


	system("pause");
	return 0;
}