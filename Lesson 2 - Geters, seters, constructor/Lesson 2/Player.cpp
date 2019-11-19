#include "Player.h"


Player::Player() {
	cout << "Hello" << endl;
}

Player::Player(string pName, string pCountry, string pPosition, string pTeam, unsigned int pGoals, unsigned int pSalary, unsigned int pPrice)
{
	name = pName;
	country = pCountry;
	position = pPosition;
	team = pTeam;
	goals = pGoals;
	salary = pSalary;
	price = pPrice;
}

void Player::ShowPlayer() {

	cout << "Name: " << name << "\nCountry: " << country << "\nPosition: " << position << "\nTeam: " << team << "\nGoals: " << goals << "\nSalary: "
		<< salary << "\nPrice: " << price << endl;

}

int Player::GetGoals() {
	return goals;
}

void Player::SetGoals(unsigned int pGoals) {
	UpdateGoals(goals);
	UpdatePrice();
}

void Player::UpdateGoals(unsigned int pGoals) {
	goals += pGoals;
}

void Player::UpdatePrice() {
	price += 1000;
}