#pragma once
#include <iostream>
#include <string>
using namespace std;


class Player
{
private:
	string name;
	string country;
	string position;
	string team;
	unsigned int goals;
	unsigned int salary;
	unsigned int price;
	void UpdateGoals(unsigned int pGoals);
	void UpdatePrice();

public:
	Player();
	Player(string pName,string pCountry, string pPosition, string pTeam, unsigned int pGoals, unsigned int pSalary, unsigned int pPrice);
	void ShowPlayer();
	int GetGoals();
	void SetGoals(unsigned int pGoals);

};

