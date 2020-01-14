#include <iostream>
#include <string>
#include <ctime>

using namespace std;
//Напишіть програму з трьома класами - автомат, магазин, набій.
//Кожен набій пронумерований(нумерація послідовна і при запуску програми починається
//	з випадкового числа) і вміє вистрілювати і влучати в мішень з імовірністю 70 % .Кожен
//	набій у програмі має унікальний номер.
//	Магазин реалізований у вигляді стеку, містить 30 набоїв і вміє :
//o заряджати набій(отримує його &quot; готовим&quot;)
//o віддавати набій(верхній)
//Автомат вміє :
//o прийняти магазин(тобто можна змінювати магазини у автоматі)
//o стріляти - попросити магазин дати 1 набій, і, якщо дав, попросити набій вистрелити
//(набій при цьому скаже, чи влучив, а автомат передасть результат &quot; нагору&quot; )
//При пострілі в консоль має виводитись повідомлення такого типу :
//Автомат вистрелив кулю 5, і промахнувся.
//Автомат вистрелив кулю 6, і влучив.

class Automatic {
	private:

	class Magazine
	{

	private:
		class Bullet
		{
			static unsigned int counter;

		public:
			Bullet *nextBullet;
			unsigned int bulletID;


			Bullet(Bullet *nextBullet = nullptr)
			{
				counter++;
				this->bulletID = counter;
				this->nextBullet = nextBullet;

			};
			void ShowBullet() {
				cout << "Bullet N" << bulletID;
			}

			~Bullet() {};

		};


		Bullet *head;
		short magazineSize;
		short bulletsCount;
		void ChargeMagazine() {

			while (bulletsCount < magazineSize)
			{

				if (this->head == nullptr) {
					this->head = new Bullet;
					bulletsCount++;
				}
				else
				{
					Bullet *current = this->head;
					while (current->nextBullet != nullptr)
					{
						current = current->nextBullet;
					}
					current->nextBullet = new Bullet;
					bulletsCount++;

				}

			}


		}


	public:
		Magazine() {
			this->head = nullptr;
			this->bulletsCount = 0;
			this->magazineSize = 30;
			this->ChargeMagazine();

		};
		void RechargeMagazine() {
			if (bulletsCount < magazineSize) {

				while (bulletsCount < magazineSize)
				{

					if (this->head == nullptr) {
						this->head = new Bullet;
						bulletsCount++;
					}
					else
					{
						Bullet *current = this->head;
						while (current->nextBullet != nullptr)
						{
							current = current->nextBullet;
						}
						current->nextBullet = new Bullet;
						bulletsCount++;

					}

				}
				cout << "Magazine has been successfully recharched\n";
			}
			else
			{
				cout << "Magazine has been already charged\n";
			}



		}

		void GiveBullet(int index) {
			
				if (index - 1 == 0) {
					Bullet *tmp = this->head;
					this->head = this->head->nextBullet;
					cout << "Bullet N" << tmp->bulletID;
					delete tmp;
					bulletsCount--;
				}
				else {
					Bullet  *prev = this->head;
					for (int i = 0; i < index - 2; i++) {
						prev = prev->nextBullet;
					}

					Bullet  *toDel = prev->nextBullet;
					prev->nextBullet = toDel->nextBullet;
					cout << "Bullet N" << toDel->bulletID;
					delete toDel;
					bulletsCount--;
				}
			
			
			
		}

		void ShowInfo() {
			Bullet *current = this->head;

			cout << "All bullets: " << this->bulletsCount << endl;
			while (current != 0)
			{
				current->ShowBullet(); cout << endl;
				current = current->nextBullet;
			}
		}

		short GetBulletsCount() {
			return this->bulletsCount;
		}
		~Magazine() {
		
			Bullet *tmp = this->head;
			this->head = this->head->nextBullet;
			delete tmp;
			bulletsCount--;
		};






	};

	Magazine magazine;
	unsigned short engageChance;
	
	public:
		Automatic() {
			this->engageChance = 7;
		}
		void Shot() {
			if (this->magazine.GetBulletsCount() > 0) {
				unsigned short chance = rand() % 10 + 1;
				unsigned short randBullet = rand() % (this->magazine.GetBulletsCount()) + 1;
				this->magazine.GiveBullet(randBullet);
				if (chance <= this->engageChance)
				{
					cout << " engaged\n";
				}
				else
				{
					cout << " didn't engage\n";
				}
			}
			else
			{
				cout << "Magazine is empty!\n";
			}
			

		}
		void Recharging() {
			this->magazine.RechargeMagazine();
		}
		void ShowMagazine() {

			this->magazine.ShowInfo();
		}


		~Automatic() {};
};

unsigned int Automatic::Magazine::Bullet::counter = 0;


void Menu() {

	cout << "1 - Shot\n2 - Show information about magazine\n3 - Recharching\n0 - Exit\nYour choice: ";
}


int main() {
	srand(unsigned(time(NULL)));

	
	Automatic ak47;

	int choice = 0;
	bool exit = false;
	while (!exit)
	{
		system("cls");
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			ak47.Shot();
			system("pause");
			break;
		case 2:
			system("cls");
			ak47.ShowMagazine();
			system("pause");
			break;
		case 3:
			system("cls");
			ak47.Recharging();
			system("pause");
			break;
		case 0:
			system("cls");
			exit = true;
			break;
		default:
			system("cls");
			cout << "Wrong choice!! Try again.\n";
			system("pause");
			break;
		}

	}
	

	



	system("pause");
	return 0;
}