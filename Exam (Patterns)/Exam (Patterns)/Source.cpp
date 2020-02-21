#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//Реализуйте с использованием паттернов проектирования простейшую систему планирования задач.
//Должна быть возможность создания списка дел, установки приоритетов, установки дат выполнения, удаление и изменения дел.
//Каждому делу можно установить тег.Список дел можно загружать и сохранять в файл.
//Необходимо реализовать возможность поиска конкретного дела.Критерии поиска : по датам, по тегам, по приоритету и так далее.

class Date
{
	short day;
	short month;
	short year;
public:
	Date() {};
	Date(short day, short month, short year) {
		CheckDate(day, month);
		this->day = day;
		this->month = month;
		this->year = year;
	}

	void CheckDate(short day, short month) {
		if (day > 31)
			day = 31;
		if (month > 12)
			month = 12;
	}

	bool operator>(Date &date) {
		return TotalDays() > date.TotalDays();
	}

	int TotalDays() {
		return day + month * 30 + year * 12 * 30;
	}

	void SetDate(short day, short month, short year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	Date GetDate() {
		return *this;
	}

	void ShowDate() {
		cout << day << "." << month << "." << year << endl;
	}
	~Date() {};

};

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
	int priority;
	Date dateDone;
	string teg;
	static int globalPriority;

public:
	Case() {};
	Case(Date &dateDone) {
		this->name = "Case";
	};

	void SetTeg(int state) {
		switch (state)
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
			break;
		}

	}



	virtual ~Case() {};
	virtual void Execute() = 0;
	virtual void Project() = 0;
};

class CaseReboot : public Case
{
public:
	CaseReboot() {};
	CaseReboot(Date &dateDone) {
		this->name = "Reboot system";
	};
	~CaseReboot();

private:

};



class CaseProject 
{
	static CaseProject caseList;



};


int main() {
	Date date(20, 6, 2020);

	Date date1(25, 8, 2020);

	system("IPconfig");
	system("Start-Sleep");

	system("pause");
	return 0;
}