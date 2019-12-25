#include <iostream>
#include <ctime>
#include <string>


using namespace std;


//Опишіть класи "Swordsman" (Мечник), "Archer" (Лучник)і "Mage" (Маг), кожен з яких є екземпляром базового класу "Unit" (штука, елемент) в комп'ютерній грі, 
//і може атакувати, ухилятись від атак і вмирати.
//У мечника 15 хіт - поінтів(життів), пошкодження при атаці 5, шанс ухилятись 60 % .
//Лучник: 12 hp, 4 dmg, 40 % dodge
//	Маг : 8 hp, 10 dmg, 30 % dodge
//	В main() створіть два масива(ворогуючі сторони) по три юніта в кожному, причому тип юніта(мечник, лучник чи маг) має задаватись випадково, при заповненні цих масивів.
//Тобто один раз запустивши вашу програму, може створитись три лучники проти мечника і двох магів, іншого - лучник, мечник і маг проти двох мечників і лучника і т.д.
//	Далі в циклі земулюйте бій між ними, поки бійці однієї з сторін всі не загинуть.В консоль при цьому виводьте повідомлення хто кого атакував, чи вдалась атака, 
//скільки життя залишилось у жертви чи вона загинула.Нехай бій відбувається поступово, по натиснення клавіші spacebar(пробіла), щоб ми могли спостерігати його атака за атакою.
//	В кінці бою оголосіть, яка команда перемогла(перша / друга, синя / червона, альянс / орки - як вже ваша фантазія вам підскаже).
//	Не забудьте здійснити приведення типів там, де це необхідно.

class Unit
{
	

public:
	string name;
	short hp;
	unsigned short damage;
	unsigned short dodge;
	
	Unit() {
		this->name = "Unit";
		this->hp = this->hp;
		this->damage = this->damage;
		this->dodge = this->dodge;
	};
	Unit(short hp, short damage, short dodge) {
		this->name = "Unit";
		this->hp = hp;
		this->damage = damage;
		this->dodge = dodge;
	}
	template <typename T>
	void Attack(T &other) {
		short chance = rand() % 10 + 1;
		if (chance > other.dodge) {
			other.hp -= this->damage;
			cout <<this->name << " attacked " <<other.name <<endl;
		}
		else
		{
			cout << this->name << " dodged " << other.name << endl;
		}
	};
	void ShowInfo() {
		if (this->hp > 0) {
			cout << "Name: " << this->name << "\nHP: " << this->hp  << endl;
		}
		else
		{
			cout << "Name: " << this->name << " - Dead" << endl;
		}
	}
	/*~Unit();*/
	
};

class Swordsman : public Unit
{

public:
	
	Swordsman() {
		this->name = "Swordsman";
		this->hp = 15;
		this->damage = 5;
		this->dodge = 6;
	}
	/*~Swordsman();*/

};

class Archer : public Unit
{

public:

	Archer() {
		this->name = "Archer";
		this->hp = 12;
		this->damage = 4;
		this->dodge = 4;
	}
	/*~Archer();*/

};

class Mage : public Unit
{

public:

	Mage() {
		this->name = "Mage";
		this->hp = 8;
		this->damage = 10;
		this->dodge = 3;
	}
	/*~Mage();*/

};





void FillArr(Unit *arr,int size) {
	for (int i = 0; i < size; i++)
	{
		short tmp = rand() %3 + 1;

		if (tmp == 1) { arr[i] = Swordsman(); }
		else if (tmp == 2) { arr[i] = Archer(); }
		else { arr[i] = Mage(); }
	}
	

};

void ShowArr(Unit *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "*****************\n";
		cout << "Unit " << i + 1 << ":\n";
		arr[i].ShowInfo();
		cout << "*****************\n";
	}
}


void ArrAttack(Unit *arr1, Unit *arr2, int size) {

	for (int i = 0; i < size; i++)
	{
		if (arr1[i].hp>0&&arr2[i].hp>0)
		{
			arr1[i].Attack(arr2[i]);
		}

	}

}

int main() {
	srand(unsigned(time(NULL)));

	
	Unit *arr1 = new Unit[3];
	Unit *arr2 = new Unit[3];
	/*arr[0] = Swordsman();
	arr[1] = Mage();
	arr[2] = Archer();*/
	
	FillArr(arr1, 3);
	FillArr(arr2, 3);


	cout << "----------ARRAY - 1-----------\n";
	ShowArr(arr1, 3);
	cout << "----------ARRAY - 1-----------\n\n";
	
	cout << "----------ARRAY - 2-----------\n";
	ShowArr(arr2, 3);
	cout << "----------ARRAY - 2-----------\n\n";
	

	cout << "Attacks array 1:\n";
	ArrAttack(arr1, arr2, 3);
	cout << "Attacks array 2:\n";
	ArrAttack(arr2, arr1, 3);

	cout << "----------ARRAY - 1-----------\n";
	ShowArr(arr1, 3);
	cout << "----------ARRAY - 1-----------\n\n";

	cout << "----------ARRAY - 2-----------\n";
	ShowArr(arr2, 3);
	cout << "----------ARRAY - 2-----------\n\n";





	system("pause");
	return 0;
}