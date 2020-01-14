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



class Magazine
{
	
private:
	class Bullet
	{
		static unsigned int counter;

	public:
		Bullet *nextBullet;
		unsigned int bulletID;
		
		
		Bullet(Bullet *nextBullet=nullptr) 
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
		if (bulletsCount < magazineSize-1) {
			
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
		else
		{
			cout << "Magazine has been full charged\n";
		}
	
		
		
	}

	void GiveBullet(int index) {
		if (index-1 == 0) {
			Bullet *tmp = this->head;
			this->head = this->head->nextBullet;
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
			delete toDel;
			bulletsCount--;
		}
	}

	void ShowInfo() {
		Bullet *current = this->head;

		while (current!=0)
		{
			current->ShowBullet(); cout << endl;
			current = current->nextBullet;
		}
	}
	~Magazine() {};
	





};

unsigned int Magazine::Bullet::counter = 0;


int main() {
	srand(unsigned(time(NULL)));
	int a = rand() % 29 + 1;
	
	Magazine maga;
	maga.GiveBullet(a);
	/*maga.ShowInfo();*/
	/*maga.ChargeMagazine();*/
	/*maga.ShowInfo();*/
	



	system("pause");
	return 0;
}