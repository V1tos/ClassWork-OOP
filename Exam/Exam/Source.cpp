	/*1. Написати програму обліку заявок на обмін квартир і пошуку варіантів обміну.
	Кожна заявка містить дані про дві квартири : необхідної(шуканої) і наявної.

	Дані про кожну квартиру містять : кількість кімнат, площу, поверх, район.

	Програма повинна забезпечувати вибір за допомогою меню і виконання однієї
	наступних функцій :
		 введення заявки на обмін;
		 пошук у картотеці потрібного варіанта :

		при співпадінні вимог і	пропозицій : 
			при співпадінні по кількості кімнат і поверховості і
			розходженні по показнику «площа» у межах 10 % виводиться відповідна
			картка і видаляється зі списку, 
			
			у противному випадку заявка, що
			надійшла, включається до картотеки;

		 вивід усієї картотеки.

	Для збереження даних картотеки використовувати контейнерний клас vector.*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>                                  // ANTON KOZYAR : https://github.com/eloyEntony/OOP/tree/master/Exam_Work/Exam
#include<fstream>

using namespace std;

class Apartments {

	int rooms;		// кімнати
	float s;		// площа
	int over;		// поверх
	string area;    // район

public:
	
	Apartments() {	//конструктор
		Exchange_request();
	};

	Apartments(int rooms, float s, int over, string area) {
		this->rooms = rooms;
		this->s = s;
		this->over = over;
		this->area = area;
	};
	void Exchange_request() { //заявкa на обмін, заповнення екземпляру
		
		cout << "\n\t <<<Create request >>> \n" << endl;
		cout << " Enter room   : ";
		cin >> this->rooms;
		cout << " Enter S      : ";
		cin >> this->s;
		cout << " Enter over   : ";
		cin >> this->over;
		cout << " Enter area   : ";
		cin.ignore();
		getline(cin, this->area);
	}

	void Show() {
		cout << "---------------------------------" << endl;		
		cout << " ROOM  : " << this->rooms << endl;
		cout << " S     : " << this->s << endl;
		cout << " OVER  : " << this->over << endl;
		cout << " AREA  : " << this->area << endl;
		cout << "---------------------------------" << endl;
	}

	int Get_room()     { return this->rooms; }
	int Get_over()     { return this->over; }
	float Get_s()      { return this->s; }
	string Get_area()  { return this->area; }

	~Apartments() {};	
};


void Serch(vector<Apartments> &first) {
	Apartments my_card;
	bool exit = false;
	for (int i = 0; i < first.size(); i++) {
		float temp = first[i].Get_s() * 0.10;
		if ((first[i].Get_room() == my_card.Get_room()) && (first[i].Get_over() == my_card.Get_over()) && ((my_card.Get_s() >= (first[i].Get_s() - temp)) && (my_card.Get_s() <= (first[i].Get_s() + temp)))) 
		{													//пошук схожого екземпляра класу
			cout << " >>>[ DELETE ]<<< " << endl;			
			first.erase(first.begin()+i);					// якщо є схожий тоді з вектора видаляється
			exit = true;									// викідає з циклу якщо найшло зхожий
			break;
		}					
	}
	if (!exit) {
	cout << " >>>[ ADD ]<<< " << endl;
	first.push_back(my_card);		//якщо схожого немає, цей що шукали додається у вектор
	}
}

//district, w,r file, sort rooms, sale flat

void SearchByDistrict(vector<Apartments> &first) {
	string district;
	cout << "Enter finding district: ";
	cin >> district;

	int i = 0;
	while (i<first.size())
	{


		if (district == first.at(i).Get_area())
		{
			first.at(i).Show();
		}

		i++;

	}
		

}


bool sort_by_room(Apartments &obj, Apartments &other) {
	return obj.Get_room() > other.Get_room();
}

void SortByRooms(vector<Apartments> &first) {


	sort(first.begin(), first.end(), sort_by_room);
	
	for (int i = 0; i < first.size(); i++) {
		cout << "Flat N: " << i + 1 << endl;
		first[i].Show();				
	}
}

void SaleRoom(vector<Apartments> &first) {
	for (int i = 0; i < first.size(); i++) {
		cout << "Flat N: " << i + 1 << endl;
		first[i].Show();
	}

	int number = 0,i=0;
	cout << "Enter flat to sale:\nFlat N";
	cin >> number;

	while (i<first.size())
	{
		if (i==(number - 1))
		{
			first.erase(first.begin() + i);
			i = first.size();
		}
		i++;
	}

}


void WriteFile(vector <Apartments> first) {

	string path = "Apartaments.txt";
	ofstream writeFile;


	writeFile.open(path);


	if (!writeFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else
	{
		int i = 0;
		writeFile << first.size() << endl;
		
		while (i <first.size())
		{
			writeFile << first.at(i).Get_room() << endl;
			writeFile << first.at(i).Get_s() << endl;
			writeFile << first.at(i).Get_over() << endl;
			writeFile << first.at(i).Get_area() << endl;
			i++;
		}
	}

	writeFile.close();
}

void ReadFile(vector <Apartments> &first) {

	string path = "Apartaments.txt";
	ifstream readFile;
	

	char temp[255];
	int rooms;		
	float s;		
	int over;		
	string area;



	readFile.open(path);

	if (!readFile.is_open()) {
		cout << "Can't open file!\n";
	}
	else
	{
		
		int size = 0, i = 0;
		readFile.getline(temp, 255);
		size = atoi(temp);

		while (i<size)
		{
			readFile.getline(temp, 255);
			rooms = atoi(temp);
			readFile.getline(temp, 255);
			s = atoi(temp);
			readFile.getline(temp, 255);
			over = atoi(temp);
			readFile.getline(temp, 255);
			area = temp;
			
			first.push_back(Apartments(rooms, s, over, area));
			i++;
		}
		
		
		

	}

	readFile.close();

}


void Menu() {
	vector<Apartments> cartoteka;	
	int choise;
	bool exit = false;

	while (!exit) {

		cout << " ------------------- CARTOTEKA --------------------" << endl;
		cout << "\n ~[1] CREATE \n ~[2] SEARCH\n ~[3] SHOW\n ~[4] SEARCH BY DISTRICT\n ~[5] SORT BY ROOMS\n ~[6] SALE FLAT\n ~[7] WRITE FILE\n ~[8] READFILE\n ~[0] EXIT" << endl;
		cout << " Enter your choise : ";
		cin >> choise;
		
		switch (choise)
		{
			case 1:			
				cout << "\n ------------------- CREATE --------------------" << endl;
				cout << " Enter count : ";
				cin >> choise;
				for (int i = 0; i < choise; i++) { cartoteka.push_back(Apartments()); }	//створення відповідної кількості контейнерів вектора
				break;

			case 2:
				cout << "\n ------------------- SEARCH --------------------" << endl;				
				Serch(cartoteka);
				break;

			case 3:
				cout << "\n ------------------- SHOW --------------------" << endl;
				for (int i = 0; i < cartoteka.size(); i++) {
					cartoteka[i].Show();				//вивід вектора
				}
				break;
			case 4:
				cout << "\n ---------------SEARCH BY DISTRICT -----------------" << endl;
				SearchByDistrict(cartoteka);
				break;
			case 5:
				SortByRooms(cartoteka);
				break;
			case 6:
				SaleRoom(cartoteka);
				break;
			case 7:
				WriteFile(cartoteka);
				break;
			case 8:
				ReadFile(cartoteka);
				break;
			case 0:
				exit = true;
				break;

			default:
				break;
		}
	}	
}

int main() {
	Menu();	
	return 0;
}