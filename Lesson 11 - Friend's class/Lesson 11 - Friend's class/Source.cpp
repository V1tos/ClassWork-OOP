#include <iostream>
#include <string>

using namespace std;
class Shop;
class Book;
class Magazine;
class AudioDisk;


class Shop
{
	string name;
	int money;


public:
	Shop(string name, int money) {
		this->name = name;
		this->money = money;
	}
	void BuyBook(Book &book);
	void BuyMagazine(Magazine &magazine);
	void BuyAudiodisk(AudioDisk &audioDisk);
	void SaleBook(Book &book);
	void SaleMagazine(Magazine &magazine);
	void SaleAudiodisk(AudioDisk &audioDisk);
	void ShowShop() {
		cout << "Shop's name: " << this->name << "\nMoney: " << this->money << endl;
	}
	

};

class Book
{
	friend Shop;
	string title;
	string author;
	unsigned short price;
	unsigned short pages;
	unsigned short count;

public:
	Book() {

	}
	Book(string title, string author, unsigned short price, unsigned short pages,unsigned short count ) {
		this->title = title;
		this->author = author;
		this->price = price;
		this->pages = pages;
		this->count = count;
	}
	void ShowInfo() {
		cout << "Title: " << this->title << "\nAuthor: " << this->author << "\nPrice: " << this->price << "\nPage's count: " << this->pages 
			<< "\nCount: " << this->count << endl;
	}

};

class Magazine
{
	friend Shop;
	string title;
	string author;
	unsigned short price;
	unsigned short pages;
	unsigned short count;

public:
	Magazine(string title, string author, unsigned short price, unsigned short pages, unsigned short count) {
		this->title = title;
		this->author = author;
		this->price = price;
		this->pages = pages;
		this->count = count;
	}
	void ShowInfo() {
		cout << "Title: " << this->title << "\nAuthor: " << this->author << "\nPrice: " << this->price << "\nPage's count: " << this->pages
			<< "\nCount: " << this->count << endl;
	}

};

class AudioDisk
{
	friend Shop;
	string title;
	string author;
	unsigned short price;
	unsigned short duration;
	unsigned short count;

public:
	AudioDisk(string title, string author, unsigned short price, unsigned short duration, unsigned short count) {
		this->title = title;
		this->author = author;
		this->price = price;
		this->duration = duration;
		this->count = count;
	}
	void ShowInfo() {
		cout << "Title: " << this->title << "\nAuthor: " << this->author << "\nPrice: " << this->price << "\nDuration: " << this->duration
			<< "\nCount: " << this->count << endl;
	}

};



void Shop::BuyBook(Book &book) {
	unsigned short count = 0;
	cout << "How many examples do you want to buy?\n";
	cin >> count;
	this->money -= book.price;
	book.count += count;
}

void Shop::BuyMagazine(Magazine &magazine) {
	unsigned short count = 0;
	cout << "How many examples do you want to buy?\n";
	cin >> count;
	this->money -= magazine.price;
	magazine.count += count;
}

void Shop::BuyAudiodisk(AudioDisk &audioDisk) {
	unsigned short count = 0;
	cout << "How many examples do you want to buy?\n";
	cin >> count;
	this->money -= audioDisk.price;
	audioDisk.count += count;
}



void Shop::SaleBook(Book &book) {
	unsigned short count = 0;
	cout << "How many examples do you want to buy?\n";
	cin >> count;
	this->money += book.price;
	book.count -= count;
}

void Shop::SaleMagazine(Magazine &magazine) {
	unsigned short count = 0;
	cout << "How many examples do you want to buy?\n";
	cin >> count;
	this->money += magazine.price;
	magazine.count -= count;
}

void Shop::SaleAudiodisk(AudioDisk &audioDisk) {
	unsigned short count = 0;
	cout << "How many examples do you want to buy?\n";
	cin >> count;
	this->money += audioDisk.price;
	audioDisk.count -= count;
}



int main() {
	Shop veselka("Veselka", 20000);
	Book *books=new Book[3];

	string title;
	string author;
	unsigned short price = 0, unsigned short pages = 0, unsigned short count = 0;

	for (int i = 0; i < 3; i++)
	{
		
		cout << "Enter book's title: ";
		cin >> title;
		cout << "Enter book's author: ";
		cin >> author;
		cout << "Enter book's page's price: ";
		cin >> price;
		cout << "Enter book's page's count: ";
		cin >> pages;
		cout << "Enter book's count: ";
		cin >> count;
		books[i] = Book(title,author,price,pages,count);
	}

	system("cls");
	/*for (int i = 0; i < 3; i++)
	{
		books[i].ShowInfo();
	}*/

	system("pause");
	return 0;
}





