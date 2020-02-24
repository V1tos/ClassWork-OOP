#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
using namespace std;

//Реализуйте с использованием паттернов проектирования простейшую систему планирования задач.
//Должна быть возможность создания списка дел, установки приоритетов, установки дат выполнения, удаление и изменения дел.
//Каждому делу можно установить тег.Список дел можно загружать и сохранять в файл.
//Необходимо реализовать возможность поиска конкретного дела.Критерии поиска : по датам, по тегам, по приоритету и так далее.


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
	
	string GetName() {
		return name;
	}

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
	string GetTeg() {
		return teg;
	}

	void SetDate(Date* date) {
		executeDate = date;
	}

	void ShowInfo() {
		cout << "Case's name: " << name << "\nTeg: " << teg << "\nExecute's day: "; executeDate->ShowDate();
	}

	virtual ~Case() {};
	virtual void Execute() = 0;
};

class CaseReboot : public Case
{
public:
	CaseReboot(){
		name = "Reboot";
		SetTeg(PLANED);
	};

	void Execute() override {

		cout << "System is going to rebooting.\n";
	}
	~CaseReboot() override {
		delete executeDate;
	};

};

class CaseOff : public Case
{
public:
	CaseOff() {
		name = "Off";
		SetTeg(PLANED);
	};

	void Execute() override {

		cout << "System is going to off.\n";
	}
	~CaseOff() override {
		delete executeDate;
	};

};

class CaseSleep : public Case
{
public:
	CaseSleep() {
		name = "Off";
		SetTeg(PLANED);
	};
	void Execute() override {
		cout << "System is going to sleep.\n";
	}

	~CaseSleep() override {
		delete executeDate;
	};

};

class CaseOther : public Case
{
public:
	CaseOther() {
		name = "Other";
		SetTeg(PLANED);
	};

	void Execute() override {
		cout << "System is going to do other operation.\n";
	}

	~CaseOther() override {
		delete executeDate;
	};

};

enum Cases
{
	REBOOT_SYSTEM=1,
	OFF_SYSTEM,
	SLEEP_SYSTEM,
	OTHER_OPERATION
};

class FabricMethod
{
public:
	static Case* createCase(Cases inputCaseNumber)
	{
		switch (inputCaseNumber)
		{
		case REBOOT_SYSTEM: return new CaseReboot();
		case OFF_SYSTEM: return new CaseOff();
		case SLEEP_SYSTEM: return new CaseSleep();
		default:
		case OTHER_OPERATION:
			return new CaseOther();
		}
	}
};



class CaseProjecter 
{
	static CaseProjecter *caseObject;
	vector <Case*> caseList;

	CaseProjecter() {};

public:

	static CaseProjecter* getObject();

	void AddCase(Case* concreteCase) {
		caseList.push_back(concreteCase);
	}

	void ExecuteNow() {
		ShowCases();
		int caseNumber = 0;
		cout << "Enter case, which you wanna execute: ";
		cin >> caseNumber;

		caseList.at(caseNumber - 1)->SetTeg(IN_PROCESS);
		caseList.at(caseNumber - 1)->SetDate(new Date(24, 2, 2020)); //Real date
		system("cls");
		caseList.at(caseNumber - 1)->Execute();
		caseList.at(caseNumber - 1)->ShowInfo();
		system("pause");
		system("cls");
		caseList.at(caseNumber - 1)->SetTeg(DONE);
		cout << "Case (" << caseList.at(caseNumber - 1)->GetName()  <<") has done.\n";
	}

	void FindCaseByName(string name) {
		for (auto caseType : caseList)
		{
			if (caseType->GetName()==name)
			{
				caseType->ShowInfo();
			}
		}
	}

	void FindCaseByTeg(string teg) {
		for (auto caseType : caseList)
		{
			if (caseType->GetTeg() == teg)
			{
				caseType->ShowInfo();
			}
		}
	}

	void ShowCases() {
		int iterator = 0;
		for (auto caseType : caseList)
		{
			cout << "Case N" << ++iterator << endl;
			caseType->ShowInfo();
		}
	}

};



CaseProjecter* CaseProjecter::getObject() {
	if (caseObject==nullptr)
	{
		caseObject = new CaseProjecter();
	}
	else
	{
		return caseObject;
	}
};

CaseProjecter* CaseProjecter::caseObject = 0;



bool CheckDate(short inputDay, short inputMonth, short inputYear) {
	return (inputDay <= DAYS_IN_MONTH && inputMonth <= MONTHS_IN_YEAR && inputYear >= MIN_YEAR && inputYear <= MAX_YEAR);
}


Date* CreateDate() {
	short day=0, month=0, year=0;
	system("cls");
	while (!CheckDate(day, month, year))
	{
		system("cls");
		cout << "Enter valid executing date (ex. 23.5.2020)\n";
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
	}

	return new Date(day, month, year);
}

void CreateCase(CaseProjecter* caseProject) {

	int userChoice = 0;
	cout << "1 - Reboot system\n2 - Off system\n3 - Sleep system\n4 - Other operation with system\nYour choice: ";
	cin >> userChoice;
	Case* userCase = FabricMethod::createCase(Cases(userChoice));
	Date* userDate = CreateDate();
	userCase->SetDate(userDate);

	caseProject->AddCase(userCase);
	cout << "Cases added.\n";
}

void FindCase(CaseProjecter* caseProject) {
	int userChoice = 0;
	cout << "1 - Find by name\n2 - Find by teg\nYour choice: ";
	cin >> userChoice;
	string name,teg;
	
	switch (userChoice)
	{
	case 1:
		system("cls");
		cout << "Enter case's name: ";
		cin >> name;
		caseProject->FindCaseByName(name);
		system("pause");
		break;
	case 2:
		system("cls");
		cout << "Enter teg: ";
		cin >> teg;
		caseProject->FindCaseByTeg(teg);
		system("pause");
		break;
	default:
		break;
	}



}

int main() {
	

	CaseProjecter* caseProject = CaseProjecter::getObject();

	bool exit = false;
	int userChoice = 0;
	while (!exit)
	{
		system("cls");
		cout << "1 - Create case\n2 - Show cases\n3 - Execute case now\n4 - Find case\n0 - Exit\nYour choice: ";
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			system("cls");
			CreateCase(caseProject);
			system("pause");
			break;
		case 2:
			system("cls");
			caseProject->ShowCases();
			system("pause");
			break;
		case 3:
			system("cls");
			caseProject->ExecuteNow();
			system("pause");
			break;
		case 4:
			system("cls");
			FindCase(caseProject);
			break;
		case 0:
			exit = true;
			break;
		default:
			break;
		}

	}

	/*Case* userCase = new CaseSleep();
	userCase->SetDate(new Date(26, 10, 2023));

	

	caseProject->AddCase(userCase);
	
	
	userCase = new CaseReboot();
	userCase->SetDate(new Date(18, 5, 2022));
	caseProject->AddCase(userCase);

	caseProject->ExecuteNow();*/
	/*caseProject->ShowCases();*/

	system("pause");
	return 0;
}