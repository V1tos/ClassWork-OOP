#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;



class Vehicle {

	string name;
	string bodyGabarites;
	string engineCapacity;
	string wheelsDiameter;
	string colourOutside;
	string salonAppartaments;

public:

	Vehicle(string name = "car") : name(name) {};


	void SetBodyGabarites(string bodyGabarites) {
		this->bodyGabarites = bodyGabarites;
	}
	string GetBodyGabarites() {
		return bodyGabarites;
	}


	void SetEngineCapacity(string engineCapacity) {
		this->engineCapacity = engineCapacity;
	}
	string GetEngineCapacity() {
		return engineCapacity;
	}

	void SetWheelsDiameter(string wheelsDiameter) {
		this->wheelsDiameter = wheelsDiameter;
	}
	string GetWheelsDiameter() {
		return wheelsDiameter;
	}

	void SetColourOutside(string colourOutside) {
		this->colourOutside = colourOutside;
	}
	string GetColourOutside() {
		return colourOutside;
	}


	void SetSalonAppartaments(string salonAppartaments) {
		this->salonAppartaments = salonAppartaments;
	}
	Vehicle GetSalonAppartaments() {
		return salonAppartaments;
	}

	
	string GetName() {
		return name;
	}
	void Show(){
		cout << "Name:   " << name << "\nBody:   " << bodyGabarites << "\nEngine: " << engineCapacity << "\nWheels: " << wheelsDiameter << "\nColour: " << colourOutside
			<< "\nSalon:  " << salonAppartaments << endl;
		
	}
	~Vehicle() {};
};


 class AutoTechnology abstract {
protected:
	Vehicle *vehicle;
public:
	AutoTechnology() {
		vehicle = new Vehicle();
	}
	Vehicle *GetVehicle() { 
		return vehicle;
	}
	virtual void BuildBody() = 0;
	virtual void InstallEngine() = 0;
	virtual void InstallWheels() = 0;
	virtual void Paint() = 0;
	virtual void PrepareSalon() = 0;
	~AutoTechnology() { delete vehicle; }

};

class MiniAutoTechnology : public AutoTechnology 
{	
public:
	MiniAutoTechnology() { 
		vehicle = new Vehicle("Mini auto"); 
	}

	void  BuildBody() override { 
		vehicle->SetBodyGabarites("Length - 2.3m   Height - 1.5m    Weight - 2 t. "); 
	}
	void  InstallEngine() override { 
		vehicle->SetEngineCapacity("1,6 l.");
	}
	void  InstallWheels() override { 
		vehicle->SetWheelsDiameter("35 sm."); 
	}
	void  Paint() override { 
		vehicle->SetColourOutside("White"); 
	}
	void  PrepareSalon() override { 
		vehicle->SetSalonAppartaments("Leather interior, air conditioning, 4 seater");
	}
};


class SportsCarTechnology : public AutoTechnology
{
public:
	SportsCarTechnology() {
		vehicle = new Vehicle("Sport's car"); 
	}

	void  BuildBody() override {
		vehicle->SetBodyGabarites("Length - 2.0m   Height - 1.3m    Weight - 1,2 t.");
	}
	void  InstallEngine() override {
		vehicle->SetEngineCapacity("2,5 l.");
	}
	void  InstallWheels() override {
		vehicle->SetWheelsDiameter("30 sm.");
	}
	void  Paint() override {
		vehicle->SetColourOutside("Red");
	}
	void  PrepareSalon() override {
		vehicle->SetSalonAppartaments("Leather interior, navigator, 2 seater");
	}
};


class SUVTechnology : public AutoTechnology
{
public:
	SUVTechnology() {
		vehicle = new Vehicle("SUV");
	}

	void  BuildBody() override {
		vehicle->SetBodyGabarites("Length - 3.3m   Height - 2.1m    Weight - 5 t.");
	}
	void  InstallEngine() override {
		vehicle->SetEngineCapacity("3,2 l.");
	}
	void  InstallWheels() override {
		vehicle->SetWheelsDiameter("45 sm.");
	}
	void  Paint() override {
		vehicle->SetColourOutside("Black");
	}
	void  PrepareSalon() override {
		vehicle->SetSalonAppartaments("Leather interior, Cruise control, air conditioning, 6 seater");
	}
};



class Director
{
public:
	void CreateAuto(AutoTechnology * vehicleBuild) {
		vehicleBuild->BuildBody();
		vehicleBuild->InstallEngine();
		vehicleBuild->InstallWheels();
		vehicleBuild->Paint();
		vehicleBuild->PrepareSalon();
	}
};

enum Technologies
{
	MINI_AUTO = 1,
	SPORTS_CAR,
	SUV
};

AutoTechnology* ChoiceTechnology(int ueserChoice) {

	switch (ueserChoice)
	{
	case MINI_AUTO:
		return  new MiniAutoTechnology();
		break;
	case SPORTS_CAR:
		return new SportsCarTechnology();
		break;
	case SUV:
		return new SUVTechnology();
		break;
	default:
		return 0;
		break;
	}

}


void BuildAuto(Director *director, AutoTechnology* autoTechnology) {
	 director->CreateAuto(autoTechnology);
};


void AddToPark(vector <AutoTechnology*> &autoPark, AutoTechnology* &autoTechnology) {
	autoPark.push_back(autoTechnology);
	cout << "Added " << autoTechnology->GetVehicle()->GetName() << endl;
};

void ShowPark(vector <AutoTechnology*> &autoPark) {
	int iterator = 0;
	for (auto car : autoPark)
	{
		cout << "Car N" <<iterator+1 <<":\n";
		car->GetVehicle()->Show();
		cout << endl;
		iterator++;
	}
}

void DeletePark(vector <AutoTechnology*> &autoPark) {
	for (auto car : autoPark)
	{
		delete car;
	}
}





int main() {

	vector <AutoTechnology*> autoPark;
	Director *director = new Director();
	AutoTechnology* autoTechnology;

	int userChoice = 0;
	while (true)
	{
		system("cls");
		cout << "Enter your choice:\n1 - Mini auto\n2 - Sport car\n3 - SUV\n4 - Show park\n0 - Exit\nYour choice: ";
		cin >> userChoice;
		if (ChoiceTechnology(userChoice))
		{
			autoTechnology = ChoiceTechnology(userChoice);
			BuildAuto(director, autoTechnology);
			AddToPark(autoPark, autoTechnology);
			system("pause");
		}
		else if(userChoice==4)
		{
			ShowPark(autoPark);
			system("pause");
		}
		else
		{
			break;
		}
	
	}

	DeletePark(autoPark);
	

	system("pause");
	return 0;
}