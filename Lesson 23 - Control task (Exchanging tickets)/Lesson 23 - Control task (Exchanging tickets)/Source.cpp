#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>

using namespace std;

//Написати програму обліку заявок на обмін квартир і пошуку варіантів
//обміну.Кожна заявка містить дані про дві квартири : необхідної(шуканої) і
//наявної.Дані про кожну квартиру містять : кількість кімнат, площу, поверх, район.
//Програма повинна забезпечувати вибір за допомогою меню і виконання однієї
//наступних функцій :
// введення заявки на обмін;
// пошук у картотеці потрібного варіанта : при співпадінні вимог і
//пропозицій : при співпадінні по кількості кімнат і поверховості і
//	розходженні по показнику «площа» у межах 10 % виводиться відповідна
//	картка і видаляється зі списку, у противному випадку заявка, що
//	надійшла, включається до картотеки;
// вивід усієї картотеки.
//Для збереження даних картотеки використовувати контейнерний клас vector.


class Flat
{
	unsigned short rooms_count;  //kilkist kimnat
	unsigned short flat_square;  //ploscha
	unsigned short floor;        //poverh  
	string district;             //rayon
 
public:
	Flat(unsigned short rooms_count = 0, unsigned short flat_square = 0, unsigned short floor = 0, string district = nullptr) {
		this->rooms_count = rooms_count;
		this->flat_square = flat_square;
		this->floor=floor;
		this->district = district;
	}
	void ShowInfo() {
		cout << "Room's count:    " << rooms_count << "\nSquare:          " << flat_square << "\nFloor:           " << floor << "\nDistrict:        " << district <<"\n";
	}
	bool operator==(Flat &other) {

		bool checkDif = false;
		double difference = 0;

		if (this->flat_square > other.flat_square)
		{
			difference = this->flat_square - other.flat_square;
			if (difference <= double(this->flat_square*0.1))
			{
				checkDif = true;
			}

		}
		else
		{
			difference = other.flat_square - this->flat_square;

			if (difference <= double(this->flat_square*0.1))
			{
				checkDif = true;
			}

		};



		if (this->rooms_count == other.rooms_count&&checkDif&&this->floor == other.floor)
		{
			return true;
		}
		else
		{
			false;
		}


	}

	~Flat() {};

};






void ShowData(vector <Flat> finding_flat, vector <Flat> exchanging_flat) {
	int i = 0;
	while (i < exchanging_flat.size())
	{
		cout << "Data N" << i + 1 << endl;
		cout << "Finding parameters:\n";
		finding_flat.at(i).ShowInfo();
		cout << "Exchanging parameters:\n";
		exchanging_flat.at(i).ShowInfo();
		cout << "\n";
		i++;
	}
}


void AddFlat(vector <Flat> finding_flat, vector <Flat> exchanging_flat) {

	unsigned short rooms_count;  
	unsigned short flat_square;  
	unsigned short floor;         
	string district;


	
	

	cout << "Enter finding flat's parameters:\n";              //Yaku hoche kvartyru
	cout << "Enter room's count: ";
	cin >> rooms_count;
	cout << "Enter flat's square: ";
	cin >> flat_square;
	cout << "Enter flat's floor: ";
	cin >> floor;
	cout << "Enter flat's district: ";
	cin >> district;
	

	Flat find(rooms_count, flat_square, floor, district);
	cout << "Ready.\n";
	system("pause");
	system("cls");


	cout << "Enter exchanging flat's parameters:\n";           //Yaku maye kvartyru
	cout << "Enter room's count: ";
	cin >> rooms_count;
	cout << "Enter flat's square: ";
	cin >> flat_square;
	cout << "Enter flat's floor: ";
	cin >> floor;
	cout << "Enter flat's district: ";
	cin >> district;

	Flat exchange(rooms_count, flat_square, floor, district);
	cout << "Ready.\n";
	system("pause");
	system("cls");

	





	int i = 0;
	bool check = false;


	while (i < exchanging_flat.size())
	{
		if (find.operator==(exchanging_flat.at(i))==true && exchange.operator==(finding_flat.at(i))==true)
		{
			system("cls");
			char choice;
			cout << "Similar parameters have been found to exchange:\n";
			cout << "Data N" << i + 1 << endl;
			cout << "Finding parameters of client:\n";
			finding_flat.at(i).ShowInfo();
			cout << endl;

			cout << "Exchanging parameters of client:\n";
			exchanging_flat.at(i).ShowInfo();
			cout << endl;
			cout << "Do you want to exchange? (y/n): ";
			cin >> choice;
			switch (choice)
			{
			case 'y':
				system("cls");
				finding_flat.erase(finding_flat.begin() + i);
				exchanging_flat.erase(exchanging_flat.begin() + i);
				cout << "Exchanged!!\n";
				i = exchanging_flat.size()+1;
				check = true;
				break;
			case 'n':
				check = false;
				break;
			default:
				cout << "Wrong choice!!";
				break;
			}
			
		}

		i++;
	}

	if (!check)
	{

		finding_flat.push_back(find);
		exchanging_flat.push_back(exchange);
		cout << "Added new data\n";

	}


	

}

void FindExchangeFlat(vector <Flat> finding_flat, vector <Flat> exchanging_flat) {



	int i = 0;
	bool check = false;
	int index;

	
	ShowData(finding_flat, exchanging_flat);
	cout << "Choose data to exchange.\n";
	cout << "Data N";
	cin >> index;

	
	while (i < exchanging_flat.size())
	{
		if (finding_flat.at(index - 1).operator==(exchanging_flat.at(i))==true && exchanging_flat.at(index - 1).operator==(finding_flat.at(i))==true&&i!=index-1)
		{
			check = true;
			system("cls");
			char choice;
			cout << "Similar parameters have been found to exchange:\n";
			cout << "Data N" << i + 1 << endl;
			cout << "Finding parameters of client:\n";
			finding_flat.at(i).ShowInfo();
			cout << endl;

			cout << "Exchanging parameters of client:\n";
			exchanging_flat.at(i).ShowInfo();
			cout << endl;
			cout << "Do you want to exchange? (y/n): ";
			cin >> choice;
			switch (choice)
			{
			case 'y':
				system("cls");
				finding_flat.erase(finding_flat.begin() + i);
				exchanging_flat.erase(exchanging_flat.begin() + i);
				cout << "Exchanged!!\n";
				i = exchanging_flat.size();
				check = true;
				break;
			case 'n':
				i = exchanging_flat.size();
				break;
			default:
				cout << "Wrong choice!!";
				i = exchanging_flat.size();
				break;
			}

		}

		i++;
	}

	if (!check)
	{
		cout << "Didn't find similar parameters!\n";

	}




}

void WriteFileFind(vector <Flat> &finding_flat) {

	ofstream writeFile("Find.txt");


	if (!writeFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else
	{
		int size = finding_flat.size();
		writeFile.write((const char*)&size, 4);
		writeFile.write((const char*)&finding_flat[0], size * sizeof(Flat));
		
		
	}

	writeFile.close();
}

void WriteFileExchange(vector <Flat> &exchanging_flat) {

	ofstream writeFile("Exchange.txt");


	if (!writeFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else
	{
		int size = exchanging_flat.size();
		writeFile.write((const char*)&size, 4);
		writeFile.write((const char*)&exchanging_flat[0], size * sizeof(Flat));
	}

	writeFile.close();
}

void ReadFileFind(vector <Flat> &finding_flat) {

	ifstream readFile("Find.txt");


	if (!readFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else
	{
		int size = 0;
		readFile.read((char*)&size, sizeof(size));
		finding_flat.resize(size);
		readFile.read((char*)&finding_flat[0], size * sizeof(Flat));

	}
	
	readFile.close();

}

void ReadFileExchange(vector <Flat> &exchanging_flat) {

	ifstream readFile("Exchange.txt");


	if (!readFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else
	{
		int size = 0;
		readFile.read((char*)&size, 4);
		exchanging_flat.resize(size);
		readFile.read((char*)&exchanging_flat[0], size * sizeof(Flat));
		
	}

	readFile.close();

}


void Menu() {

	cout << "=*=*=*=*=*=*=DATABASE=*MENU=*=*=*=*=*=*=\n1 - Add data\n2 - Find possible exchanges\n3 - Show data\n0 - Exit\nYour choice: ";

}

int main() {
	
	bool exit = false;
	short choice = 0;
	vector <Flat> finding_flat;
	vector <Flat> exchanging_flat;

	finding_flat.push_back(Flat(3, 87, 5, "Pivnichnuy"));
	exchanging_flat.push_back(Flat(2, 60, 1, "Yubik"));
	finding_flat.push_back(Flat(2, 65, 1, "Centr"));
	exchanging_flat.push_back(Flat(3, 91, 5, "Basik"));

	WriteFileFind(finding_flat);
	WriteFileExchange(exchanging_flat);

	/*ReadFileFind(finding_flat);
	ReadFileExchange(exchanging_flat);*/
	/*ShowData(finding_flat, exchanging_flat);*/

	while (!exit)
	{
		system("cls");
		Menu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			AddFlat(finding_flat, exchanging_flat);
			system("pause");
			break;
		case 2:
			system("cls");
			FindExchangeFlat(finding_flat, exchanging_flat);
			system("pause");
			break;
		case 3:
			system("cls");
			ShowData(finding_flat, exchanging_flat);
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
