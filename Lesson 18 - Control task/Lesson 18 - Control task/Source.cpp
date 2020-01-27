#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

	
	
	public:
		string companyName;
		string owner;
		unsigned int telephoneNumber;
		string address;
		string occupation;
		
		Notepad(string companyName, string owner, unsigned int telephoneNumber, string address, string occupation) {
			this->companyName = companyName;
			this->owner = owner;
			this->telephoneNumber = telephoneNumber;
			this->address = address;
			this->occupation = occupation;
		};
		Notepad() {
			
		};
		
		
		void ShowData() {
			cout << "Company's name:      " << this->companyName << endl;
			cout << "Owner's name:        " << this->owner << endl;
			cout << "Telephone's number:  " << this->telephoneNumber << endl;
			cout << "Address:             " << this->address << endl;
			cout << "Occupation:          " << this->occupation << endl;
		}

		
		string GetCompanyName()        { return this->companyName; }
		string GetOwner()              { return this->owner; }
		int GetTelephoneNumber()       { return this->telephoneNumber; }
		string GetCompanyAddres()      { return this->companyName; }
		string GetCompanyOccupation()  { return this->companyName; }


		~Notepad() {};

	};

	
	



	vector <Notepad> AddProfile(vector <Notepad> &list) {
		
		string companyName;
		string owner;
		unsigned int telephoneNumber=0;
		string address;
		string occupation;


		cout << "Profile N" << list.size()+1 <<":" << endl;
		cout << "Enter company's name: ";
		getline(cin, companyName);
		cout << "Enter owner's name: ";
		getline(cin, owner);
		cout << "Enter telephone's number: ";
		cin >> telephoneNumber;
		cout << "Enter address: ";
		cin.ignore();
		getline(cin, address);
		cout << "Enter occupation: ";
		cin >> occupation;

		list.push_back(Notepad(companyName, owner, telephoneNumber, address, occupation));

		return list;
		
	};

	void FindCompanyName(vector <Notepad> &list) {
		
		string companyName;
		cout << "Enter company's name: ";
		cin >> companyName;
		for (int i = 0; i < list.size(); i++)
		{
			if (list.at(i).GetCompanyName() == companyName) list.at(i).ShowData();
		}

	}

	void FindOwner(vector <Notepad> &list) {
		
		string owner;
		cout << "Enter owner: ";
		cin >> owner;
		for (int i = 0; i < list.size(); i++)
		{
			if (list.at(i).GetOwner() == owner) list.at(i).ShowData();
		}
		
	}
	void FindTelephoneNumber(vector <Notepad> &list) {
		
		unsigned int telephoneNumber=0;
		cout << "Enter telephone's number: ";
		cin >> telephoneNumber;
	
			for (int i = 0; i < list.size(); i++)
			{
				if (list.at(i).GetTelephoneNumber() == telephoneNumber) list.at(i).ShowData();
			}

	}

	void FindAddress(vector <Notepad> &list) {
		
		string address;
		cout << "Enter addres: ";
		cin >> address;
		for (int i = 0; i < list.size(); i++)
		{
			if (list.at(i).GetCompanyAddres() == address) list.at(i).ShowData();
		}

	}

	void FindOccupation(vector <Notepad> &list) {
		
		string occupation;
		cout << "Enter occupation: ";
		cin >> occupation;
		
		for (int i = 0; i < list.size(); i++)
		{
			if (list.at(i).GetCompanyOccupation() == occupation) list.at(i).ShowData();
		}
	}

	void ShowInfo(vector <Notepad> &list) {
		
		
		for (int i = 0; i < list.size(); i++)
		{
			cout << "Data N" << i + 1 << ":\n";
			list.at(i).ShowData();
		}

	};

	std::ostream& operator<<(std::ostream& os, const Notepad& v)
	{
		os << v.companyName << " " << v.owner << " " << v.telephoneNumber << v.address << " " << v.occupation << " " << endl;
		return os;
	}

	std::istream& operator>>(std::istream& is, Notepad& v)
	{
		is >> v.companyName >> v.owner >> v.telephoneNumber >> v.address >> v.occupation;
		return is;
	}


	void WriteFile(vector <Notepad> &list) {
		
		
		
		ofstream writeFile("Test.txt" ,ios::binary | ios::out );

		
		 


		if (!writeFile.is_open()) {
			cout << "Can't open file!\n";
		}
		else
		{
			int size = list.size();
			writeFile.write((const char*)&size, 4);
			writeFile.write((const char*)&list[0], size * sizeof(Notepad));
				
		}

		

		

		writeFile.close();
	}

	

	void ReadFile(vector <Notepad> &list) {


		
		 
		ifstream readFile("Test.txt",ios::binary);
		
		
	

		if (!readFile.is_open()) {
			cout << "Can't open file!\n";
		}
		else
		{

			int size = 0;
			readFile.read((char*)&size, 4);
			list.resize(size);
			readFile.read((char*)&list[0], size * sizeof(Notepad));



		
		}
		

		
		readFile.close();

		
		

	}









int main() {
	

	vector <Notepad> list;
	
	/*list=AddProfile(list);
	WriteFile(list);*/

	ReadFile(list);

	ShowInfo(list);


	system("pause");
	return 0;
}