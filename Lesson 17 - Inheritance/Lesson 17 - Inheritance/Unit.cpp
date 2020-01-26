#include <iostream>
#include <ctime>
#include <string>
#include <vector>


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






//Опишіть класи &quot; Swordsman&quot; (Мечник), &quot; Archer&quot; (Лучник)і &quot; Mage&quot; (Маг), кожен з яких є
//екземпляром базового(можна абстрактного) класу &quot; Unit&quot; (штука, елемент) в комп&#39; ютерній
//грі, і може атакувати, ухилятись від атак і вмирати.
//У мечника 15 хіт - поінтів(життів), пошкодження при атаці 5, шанс ухилятись 60 % .
//Лучник: 12 hp, 4 dmg, 40 % dodge
//	Маг : 8 hp, 10 dmg, 30 % dodge
//
//	------------------------------------------------------------------------------------------------------------ -
//	Опишіть клас &quot; Team&quot; (Команда), у якому є поля
//	o назва команди
//	o масив чи вектор по три(чи більше) юніта,
//	причому тип юніта(мечник, лучник чи маг) має задаватись випадково, при
//	заповненні команди(на початку гри).
//	Написати методи :
//o перевірки чи у команді є не вбиті гравці
//o виводу гравців команди
//------------------------------------------------------------------------------------------------------------ -
//Опишіть клас &quot; Game&quot; (Гра), що містить 2 команди ворогуючих сторін
//Можливі варіанти ворогуючих сторін : три лучники проти мечника і двох магів, або -
//лучник, мечник і маг проти двох мечників і лучника і т.д(при кількості гравців у команді
//	3).
//	Опишіть метод бою між КОМАНДАМИ, поки бійці однієї з сторін всі не загинуть.В
//	консоль при цьому виводьте повідомлення хто кого атакував, чи вдалась атака, скільки
//	життя залишилось у жертви чи вона загинула.Нехай бій відбувається поступово, по
//	натиснення клавіші spacebar(пробіла), щоб ми могли спостерігати його атака за атакою.
//	В кінці бою оголосіть, яка команда перемогла(перша / друга, синя / червона, альянс / орки чи
//		ін.).
//	...............................................................................................................
//	Правила бою : кожен боєць(Воїн, Лучник чи Маг) вишукує серед ворогів суперника свого
//	типу і атакує його.
//	Скажімо, якщо маємо команди :
//A11 - M21
//A12 - S22
//S13 - A23
//...то А11 має вибрати своєї ціллю А23.
//Якщо ворогів свого типу не знайдено, тоді нехай бійці атакують довільного суперника






class Unit
{
protected:
	string name;
	short hp;
	unsigned short damage;
	unsigned short dodge;
	

public:
	
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
	
	void Attack(Unit &other) {

		if (other.CheckUnitLive()==true)
		{
			short chance = rand() % 10 + 1;
			if (chance > other.dodge) {
				other.hp -= this->damage;
				cout << this->name << " attacked " << other.name;
			}
			else
			{
				cout << this->name << " dodged " << other.name;
			}
		}
		
	};

	
	bool CheckBrother(vector <Unit> &arr) {
		bool check = false;

		for (int i = 0; i < arr.size(); i++)
		{
			if (this->name == arr.at(i).GetName()&&arr.at(i).CheckUnitLive())
			{
				check = true;
				break;
			}
			
		}

		if (check)
		{
			return true;
		}
		else
		{
			false;
		}
		
	}

	bool CheckUnitLive() {

		if (this->hp>0)
		{
			return true;

		}
		else
		{
			return false;
		}
	}



	void ShowInfo() {
		if (this->hp > 0) {
			cout << "Name: " << this->name << "\nHP: " << this->hp  << endl;
		}
		else
		{
			cout << "Name: " << this->name << " - Dead" << endl;
		}
	}
	~Unit() {

		
	
	};
	
};

class Swordsman : public Unit
{

public:
	
	Swordsman() {
		this->name="Swordsman";
		this->hp=15;
		this->damage=5;
		this->dodge=6;
		
	}
	~Swordsman() {};

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
	~Archer() {};

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
	~Mage() {};

};





void FillArr(vector <Unit> &arr,int size) {
	for (int i = 0; i < size; i++)
	{
		short tmp = rand() %3 + 1;
		 
		if (tmp == 1)       { arr.push_back(Swordsman()); }
		else if (tmp == 2)  { arr.push_back(Archer());    }
		else                { arr.push_back(Mage());      }
	}
	

};


bool CheckLive(vector <Unit> &arr) {



	if (arr.size() == 1 && arr.at(0).CheckUnitLive())
	{
		
		return true;
	}
	else if (arr.size() == 1 && !arr.at(0).CheckUnitLive())
	{
		return false;
	}
	else if(arr.size() > 0&&arr.size()!=1) 
	{
		bool tmp = false;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr.at(i).CheckUnitLive())
			{
				tmp = true;
				
			}
			
		}

		if (tmp) return true;
		else if (!tmp) return false;
					
	}


	else
	{
		return false;
	}

}

void ShowArr(vector <Unit> &arr) {


	
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr.at(i).CheckUnitLive())
			{
				cout << "*****************\n";
				cout << "Unit " << i + 1 << ":\n";
				arr.at(i).ShowInfo();
				cout << "*****************\n";
			}
			else if (!arr.at(i).CheckUnitLive())
			{
				cout << "*****************\n";
				cout << "Unit " << i + 1 << ":\n";
				cout <<arr.at(i).GetName()<< " - Dead\n";
				cout << "*****************\n";
			}

		}
	
	
	

}



void ArrAttack(vector <Unit> &arr1, vector <Unit> &arr2) {
	

	
	
	

		for (int i = 0; i < arr1.size(); i++)
		{

			if (arr1.at(i).CheckBrother(arr2)&&arr1.at(i).CheckUnitLive())
			{

				for (int j = 0; j < arr2.size(); j++)
				{

					if (arr1.at(i).GetName() == arr2.at(j).GetName() && arr2.at(j).CheckUnitLive())
					{
						arr1.at(i).Attack(arr2.at(j));
						cout << endl;
						break;
					}

				}
			}
			else if (!(arr1.at(i).CheckBrother(arr2))&& arr1.at(i).CheckUnitLive())
			{
				
				for (int j = 0; j < arr2.size(); j++)
				{
					if (arr2.at(j).CheckUnitLive() > 0)
					{
						arr1.at(i).Attack(arr2.at(j));
						cout << endl;
						break;
						
					}
				
				}


			}



		}


	

		



	

}




int main() {
	srand(unsigned(time(NULL)));

	int size = 3;

	bool game = false;
	bool tmp = 0;

	
	
	vector <Unit> arr1;
	vector <Unit> arr2;
	
	
	
	
	
	FillArr(arr1, size);
	FillArr(arr2, size);

	while (!game)
	{

		cout << "----------TEAM - 1-----------\n";
		ShowArr(arr1);
		cout << "----------TEAM - 1-----------\n\n";

		cout << "----------TEAM - 2-----------\n";
		ShowArr(arr2);
		cout << "----------TEAM - 2-----------\n\n";


		ArrAttack(arr1, arr2);
		
			
			tmp=CheckLive(arr2);
			if (!tmp)
			{
				cout << "Team 1 WIN!!!!!!!!!!!!!!!!!!!\n";
				game = true;
			

			}

		
		





		


		ArrAttack(arr2, arr1);

			tmp = CheckLive(arr1);
			if (!tmp)
			{
				cout << "Team 2 WIN!!!!!!!!!!!!!!!!!!!\n";
				game = true;
				

			}

		

		system("pause");


	}

	



	




	system("pause");
	return 0;
}