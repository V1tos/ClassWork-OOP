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
	
	string name;
	short hp;
	unsigned short damage;
	unsigned short dodge;
public:
	/*string name;
	short hp;
	unsigned short damage;
	unsigned short dodge;*/

	string GetName()                      { return this->name; }
	short  GetHp()                        { return this->hp; }
	unsigned short GetDamage()            { return this->damage; }
	unsigned short GetDodge()             { return this->dodge; }

	void SetName(string name)             { this->name = name; }
	void SetHp(short hp)                  { this->hp = hp; }
	void SetDamage(unsigned short damage) { this->damage = damage; }
	void SetDodge(unsigned short dodge)   { this->dodge = dodge; }
	
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
	~Unit() {};
	
};

class Swordsman : public Unit
{

public:
	
	Swordsman() {
		SetName("Swordsman");
		SetHp(15);
		SetDamage(5);
		SetDodge(6);
		
	}
	/*~Swordsman();*/

};

class Archer : public Unit
{

public:

	Archer() {
		SetName("Archer");
		SetHp(12);
		SetDamage(4);
		SetDodge(4);
	}
	~Archer() {};

};

class Mage : public Unit
{

public:

	Mage() {
		SetName("Mage");
		SetHp(8);
		SetDamage(10);
		SetDodge(3);
		
	}
	~Mage() {};

};





void FillArr(Unit *arr,int size) {
	for (int i = 0; i < size; i++)
	{
		short tmp = rand() %3 + 1;

		if (tmp == 1)      { arr[i] = Swordsman(); }
		else if (tmp == 2) { arr[i] = Archer();    }
		else               { arr[i] = Mage();      }
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
		
		if (arr1[i].GetHp() >0&&arr2[i].GetHp() >0)
		{
			cout << "Unit " << i + 1 << " "; arr1[i].Attack(arr2[i]);
		}
		else if (arr1[i].GetHp() > 0 && arr2[i].GetHp() <= 0&& arr2[i+1].GetHp() >0&&i<size-1)
		{
			cout << "Unit " << i + 1 << " "; arr1[i].Attack(arr2[i+1]);
		}

	}

}

void Attacks(Unit *arr1, Unit *arr2, int size) {

	if (arr1[0].GetHp() > 0 || arr1[1].GetHp() > 0 || arr1[2].GetHp() > 0 /*&& arr2[0].GetHp() > 0 || arr2[1].GetHp() > 0 || arr2[2].GetHp() > 0*/) {
		cout << "Attacks team 1:\n";
		ArrAttack(arr1, arr2, 3);
	}
	else if (arr1[0].GetHp() <= 0 || arr1[1].GetHp() <= 0 || arr1[2].GetHp() <= 0)
	{
		cout << "All team 1 is dead!\n";
	}
	else if (arr2[0].GetHp() <= 0 || arr2[1].GetHp() <= 0 || arr2[2].GetHp() <= 0)
	{
		cout << "All enemies are dead!\n";
	}
	cout << "\n\n\n";

	if (arr2[0].GetHp() > 0 || arr2[1].GetHp() > 0 || arr2[2].GetHp() > 0 /*&& arr1[0].GetHp() > 0 || arr1[1].GetHp() > 0 || arr1[2].GetHp() > 0*/) {
		cout << "Attacks team 2:\n";
		ArrAttack(arr2, arr1, 3);
	}
	else if (arr2[0].GetHp() <= 0 || arr2[1].GetHp() <= 0 || arr2[2].GetHp() <= 0)
	{
		cout << "All team 2 is dead!\n";
	}
	else if (arr1[0].GetHp() <= 0 || arr1[1].GetHp() <= 0 || arr1[2].GetHp() <= 0)
	{
		cout << "All enemies are dead!\n";
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


	cout << "----------TEAM - 1-----------\n";
	ShowArr(arr1, 3);
	cout << "----------TEAM - 1-----------\n\n";
	
	cout << "----------TEAM - 2-----------\n";
	ShowArr(arr2, 3);
	cout << "----------TEAM - 2-----------\n\n";
	

	Attacks(arr1, arr2, 3);

	
	cout << "----------TEAM - 1-----------\n";
	ShowArr(arr1, 3);
	cout << "----------TEAM - 1-----------\n\n";

	cout << "----------TEAM - 2-----------\n";
	ShowArr(arr2, 3);
	cout << "----------TEAM - 2-----------\n\n";


	Attacks(arr1, arr2, 3);


	cout << "----------TEAM - 1-----------\n";
	ShowArr(arr1, 3);
	cout << "----------TEAM - 1-----------\n\n";

	cout << "----------TEAM - 2-----------\n";
	ShowArr(arr2, 3);
	cout << "----------TEAM - 2-----------\n\n";

	Attacks(arr1, arr2, 3);


	cout << "----------TEAM - 1-----------\n";
	ShowArr(arr1, 3);
	cout << "----------TEAM - 1-----------\n\n";

	cout << "----------TEAM - 2-----------\n";
	ShowArr(arr2, 3);
	cout << "----------TEAM - 2-----------\n\n";

	Attacks(arr1, arr2, 3);


	cout << "----------TEAM - 1-----------\n";
	ShowArr(arr1, 3);
	cout << "----------TEAM - 1-----------\n\n";

	cout << "----------TEAM - 2-----------\n";
	ShowArr(arr2, 3);
	cout << "----------TEAM - 2-----------\n\n";

	Attacks(arr1, arr2, 3);


	cout << "----------TEAM - 1-----------\n";
	ShowArr(arr1, 3);
	cout << "----------TEAM - 1-----------\n\n";

	cout << "----------TEAM - 2-----------\n";
	ShowArr(arr2, 3);
	cout << "----------TEAM - 2-----------\n\n";

	Attacks(arr1, arr2, 3);


	cout << "----------TEAM - 1-----------\n";
	ShowArr(arr1, 3);
	cout << "----------TEAM - 1-----------\n\n";

	cout << "----------TEAM - 2-----------\n";
	ShowArr(arr2, 3);
	cout << "----------TEAM - 2-----------\n\n";





	




	system("pause");
	return 0;
}