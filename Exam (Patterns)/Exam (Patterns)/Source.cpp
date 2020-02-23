#include <iostream>
#include <string>
#include <Windows.h>
#include "Date.h"
using namespace std;

//Реализуйте с использованием паттернов проектирования простейшую систему планирования задач.
//Должна быть возможность создания списка дел, установки приоритетов, установки дат выполнения, удаление и изменения дел.
//Каждому делу можно установить тег.Список дел можно загружать и сохранять в файл.
//Необходимо реализовать возможность поиска конкретного дела.Критерии поиска : по датам, по тегам, по приоритету и так далее.
//
//class Date
//{
//	const short DAYS_IN_MONTH = 31;
//	const short MONTHS_IN_YEAR = 12;
//	const short MIN_YEAR = 2020;
//	const short MAX_YEAR = 2100;
//	short day;
//	short month;
//	short year;
//
//public:
//	Date() {};
//	Date(short day, short month, short year) {
//		this->day = day;
//		this->month = month;
//		this->year = year;
//	}
//
//	bool CheckDate(short inputDay, short inputMonth, short inputYear) {
//		return (inputDay <= DAYS_IN_MONTH && inputMonth <= MONTHS_IN_YEAR && inputYear >= MIN_YEAR && inputYear <= MAX_YEAR);	
//	}
//
//
//	void SetDate(short day, short month, short year) {
//		this->day = day;
//		this->month = month;
//		this->year = year;
//	}
//
//	Date GetDate() {
//		return *this;
//	}
//
//
//	void ShowDate() {
//		cout << day << "." << month << "." << year << endl;
//	}
//	~Date() {};
//
//};

enum Teg
{
	PLANED=1,
	IN_PROCESS,
	DONE
};

class Case
{
protected:
	string name;
	Date *executeDate;
	string teg;
public:
	Case() {};
	
	void SetTeg(int inputTeg) {
		switch (inputTeg)
		{
		case PLANED:
			teg = "Planned";
			break;
		case IN_PROCESS:
			teg = "In process";
			break;
		case DONE:
			teg = "Done";
			break;
		default:
			cout << "Wrong teg!\n";
			break;
		}

	}



	virtual ~Case() {};
	virtual void Execute() = 0;
};

class CaseReboot : public Case
{
public:
	CaseReboot() {};
	CaseReboot(){
		name = "Reboot System";
		SetTeg(PLANED);
		executeDate = new Date();
	};
	~CaseReboot() override {
		delete executeDate;
	};

};



class CaseProject 
{
	static CaseProject caseList;



};





int main() {
	Date *date = new Date(20, 6, 2020);


	cout << CheckDate(14, 12, 2021);
	int a = DONE;
	
	/*Date date1(25, 8, 2020);*/

	

	system("pause");
	return 0;
}