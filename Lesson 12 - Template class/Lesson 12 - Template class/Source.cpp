#include <iostream>
#include <string>
using namespace std;
class Book;

template <typename T>
class CShop
{
	friend Book;
	int size;
	T *arr;
public:
	CShop() {};
	
	CShop(int size) {
		this->size = size;
		this->arr = new T[this->size];
		for (int  i = 0; i < this->size; i++)
		{
			this->arr[i];

		}

		};
	void SortArr() {
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (this->arr[j].price < this->arr[j + 1].price) {
					swap(this->arr[j], this->arr[j + 1]);
				}
			}
			
		}
	};
	void ShowArr() {
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i].ShowInfo();
		}
		
		cout << endl;
		
	}
	
};


class Book
{
	
	string title;
	string author;
	int price;
	unsigned short pages;
	unsigned short count;

public:
	Book() {
		cout << "Enter title: ";
		cin >>this->title;
		cout << "Enter author: ";
		cin >> this->author;
		cout << "Enter price: ";
		cin >> this->price;
		cout << "Enter pages: ";
		cin >> this->pages;
		cout << "Enter count: ";
		cin >> this->count;
	}
	Book(string title, string author, unsigned short price, unsigned short pages, unsigned short count) {
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


int main() {
	

	CShop <Book> shop(2);
	shop.ShowArr();
	shop.SortArr();
	shop.ShowArr();

	system("pause");
	return 0;
}