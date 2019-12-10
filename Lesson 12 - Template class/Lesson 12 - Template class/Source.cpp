#include <iostream>
#include <string>
using namespace std;


template <typename T>
class CShop
{
	
	int size;
	T *arr;
public:
	CShop() {};
	
	CShop(int size) {
		this->size = size;
		this->arr = new T[this->size];
		for (int  i = 0; i < this->size; i++)
		{
			arr[i];
		}

		};
	void SortArrMaxToMin() {
	
		int *tmp = new int[this->size];
			for (int i = 0; i < this->size; i++)
			{
				tmp[i] = this->arr[i].GetPrice();
			}


			for (int i = 0; i < this->size; i++)
			{
				for (int j = 0; j < this->size; j++)
				{
					if (tmp[j] < tmp[j + 1]) {
						swap(tmp[j], tmp[j + 1]);
					}
				}
			}

			for (int i = 0; i < this->size; i++)
			{
				for (int j = 0; j < this->size; j++)
				{
					if (tmp[i] == this->arr[j].GetPrice()) {
						cout << this->arr[j].GetClassName() << " N" << i + 1 << endl;
						this->arr[j].ShowInfo();
						cout << endl;
					}
				}
			}

			delete[] tmp;
			tmp = nullptr;
		
	};
	void SortArrMinToMax() {

		int *tmp = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			tmp[i] = this->arr[i].GetPrice();
		}


		for (int i = 0; i < this->size; i++)
		{
			for (int j = this->size-1; j >= 0; j--)
			{
				if (tmp[j] < tmp[j - 1]) {
					swap(tmp[j], tmp[j - 1]);
				}
			}
		}

		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (tmp[i] == this->arr[j].GetPrice()) {
					cout << this->arr[j].GetClassName() << " N" << i + 1 << endl;
					this->arr[j].ShowInfo();
					cout << endl;
				}
			}
		}


		delete[] tmp;
		tmp = nullptr;

	};

	void ShowArr() {
		for (int i = 0; i < this->size; i++)
		{
			cout << this->arr[i].GetClassName() <<" N"<<i+1<<":\n";
			this->arr[i].ShowInfo();
			cout << endl;
		}
		
	}
	void MostExpensiveGoods() {
		int max = 0;
		max = this->arr[0].GetPrice();

		for (int i = 0; i < this->size; i++)
		{
			if (max < this->arr[i].GetPrice()) {
				max = this->arr[i].GetPrice();
			}
		}

		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i].GetPrice() == max) {
				cout << "The most expensive - " <<this->arr[i].GetClassName() << " N" << i + 1 << ":\n";
				this->arr[i].ShowInfo();
				cout << endl;
			}
		}

	}

	void LeastExpensiveGoods() {
		int min = 0;
		min = this->arr[0].GetPrice();

		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i].GetPrice() < min) {
				min = this->arr[i].GetPrice();
			}
		}

		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i].GetPrice() == min) {
				cout << "The least expensive - " << this->arr[i].GetClassName() << " N" << i + 1 << ":\n";
				this->arr[i].ShowInfo();
				cout << endl;
			}
		}

	}

	void AveragePrice() {
		int sum = 0;

		for (int  i = 0; i < this->size; i++)
		{
			sum += this->arr[i].GetPrice();
		}

		cout << this->arr[0].GetClassName() << "'s average price - " << double(sum) / double(this->size) << endl;

	}
	int & operator[](int index) {
		int tmp = arr[index].GetPrice();
		return tmp;
	}
	
};


class Book
{
	
	string title;
	string author;
	int price;
	unsigned short pages;
	string className;
	static unsigned short booksCounter;

public:
	Book() {
		this->className = "Book";
		booksCounter++;
		cout << this->className << " N" << booksCounter <<": " <<endl;
		cout << "Enter title: ";
		cin >>this->title;
		cout << "Enter author: ";
		cin >> this->author;
		cout << "Enter price: ";
		cin >> this->price;
		cout << "Enter pages: ";
		cin >> this->pages;
		cout << endl;
	}
	Book(string title, string author, unsigned short price, unsigned short pages) {
		booksCounter++;
		this->className = "Book";
		this->title = title;
		this->author = author;
		this->price = price;
		this->pages = pages;
	}
	int GetPrice() {
		return this->price;
	}
	string GetClassName() {
		return this->className;
	}
	void ShowInfo() {
		cout << "Title: " << this->title << "\nAuthor: " << this->author << "\nPrice: " << this->price << "\nPage's count: " << this->pages << endl;
	}

};


class Magazine
{
	
	string title;
	int price;
	unsigned short pages;
	string className;
	static unsigned short magazinesCounter;

public:
	Magazine() {
		magazinesCounter++;
		this->className = "Magazine";
		cout << this->className << " N" << magazinesCounter << ": " << endl;
		cout << "Enter title: ";
		cin >> this->title;
		cout << "Enter price: ";
		cin >> this->price;
		cout << "Enter pages: ";
		cin >> this->pages;
		cout << endl;
	}
	Magazine(string title,unsigned short price, unsigned short pages) {
		magazinesCounter++;
		this->className = "Magazine";
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	int GetPrice() {
		return this->price;
	}
	string GetClassName() {
		return this->className;
	}
	void ShowInfo() {
		cout << "Title: " << this->title << "\nPrice: " << this->price << "\nPage's count: " << this->pages << endl;
	}

};

class AudioDisk
{
	
	string title;
	string singer;
	int price;
	unsigned short tracksCount;
	string className;
	static unsigned short audioDiskCounter;

public:
	AudioDisk() {
		audioDiskCounter++;
		this->className = "Audio disk";
		cout << this->className << " N" << audioDiskCounter << ": " << endl;
		cout << "Enter title: ";
		cin >> this->title;
		cout << "Enter singer: ";
		cin >> this->singer;
		cout << "Enter track's count: ";
		cin >> this->tracksCount;
		cout << "Enter price: ";
		cin >> this->price;
		cout << endl;
	}
	AudioDisk(string title, string singer, unsigned short price, unsigned short tracksCount) {
		this->className = "Audio disk";
		audioDiskCounter++;
		this->title = title;
		this->singer = singer;
		this->price = price;
		this->tracksCount = tracksCount;
	}
	int GetPrice() {
		return this->price;
	}
	string GetClassName() {
		return this->className;
	}
	void ShowInfo() {
		cout << "Title: " << this->title << "\nSinger: " << this->singer << "\nPrice: " << this->price << "\nTrack's count: " << this->tracksCount << endl;
	}

};

unsigned short Book::booksCounter = 0;
unsigned short Magazine::magazinesCounter = 0;
unsigned short AudioDisk::audioDiskCounter = 0;

int main() {
	

	//CShop <Book> b_shop(3);
	//system("cls");
	//b_shop.ShowArr();
	//system("pause");
	//b_shop.MostExpensiveGoods();
	//b_shop.LeastExpensiveGoods();
	//system("pause");
	//cout << "------------Sorted price (max to min)------------\n";
	//b_shop.SortArrMaxToMin();
	//cout << "------------Sorted price (max to min)------------\n";
	//system("pause");
	//cout << "------------Sorted price (min to max)------------\n";
	//b_shop.SortArrMinToMax();
	//cout << "------------Sorted price (min to max)------------\n";
	//system("pause");
	//b_shop.AveragePrice();
	//system("pause");
	//system("cls");




	CShop <Magazine> m_shop(3);
	system("cls");
	m_shop.ShowArr();
	system("pause");
	m_shop.MostExpensiveGoods();
	m_shop.LeastExpensiveGoods();
	system("pause");
	cout << "------------Sorted price (max to min)------------\n";
	m_shop.SortArrMaxToMin();
	cout << "------------Sorted price (max to min)------------\n";
	system("pause");
	cout << "------------Sorted price (min to max)------------\n";
	m_shop.SortArrMinToMax();
	cout << "------------Sorted price (min to max)------------\n";
	system("pause");
	m_shop.AveragePrice();
	system("pause");
	system("cls");





	//CShop <AudioDisk> a_shop(3);
	//system("cls");
	//a_shop.ShowArr();
	//system("pause");
	//a_shop.MostExpensiveGoods();
	//a_shop.LeastExpensiveGoods();
	//system("pause");
	//cout << "------------Sorted price (max to min)------------\n";
	//a_shop.SortArrMaxToMin();
	//cout << "------------Sorted price (max to min)------------\n";
	//system("pause");
	//cout << "------------Sorted price (min to max)------------\n";
	//a_shop.SortArrMinToMax();
	//cout << "------------Sorted price (min to max)------------\n";
	//system("pause");
	//a_shop.AveragePrice();
	


	system("pause");
	return 0;
}