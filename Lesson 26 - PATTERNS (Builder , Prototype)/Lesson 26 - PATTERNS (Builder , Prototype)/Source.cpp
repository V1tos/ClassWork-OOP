#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;



class Vehicle {
	string name;
	map <string, string> parts;
public:
	Vehicle(string name = "car") : name(name) {};
	void SetPart(const string &key, const string &value) { 
		this->parts[key] = value; }
	Vehicle GetPart(const string&key) {
		return this->parts.at(key);
	}
	void Show(){
		cout << "Name: " << name << endl;
		for (auto el : parts)
		{
			cout << el.first << ": " << el.second << endl;
		}
	}
	~Vehicle() {};
};


 class AutoTechnology abstract {
protected:
	Vehicle *vehicle;
public:
	AutoTechnology() {
		this->vehicle = new Vehicle();
	}
	Vehicle *GetVehicle() { 
		return vehicle;
	}
	virtual void BuildBody() = 0;
	virtual void InstallEngine() = 0;
	virtual void InstallWheels() = 0;
	virtual void Paint() = 0;
	virtual void PrepareSalon() = 0;
	~AutoTechnology() { delete this->vehicle; }

};

class MiniAutoTechnology : public AutoTechnology 
{	
public:
	MiniAutoTechnology() { 
		this->vehicle = new Vehicle("Mini auto"); 
	}
	void  BuildBody() override { 
		this->vehicle->SetPart("Body", "Length - 2.3m   Height - 1.5m    Weight - 2 t. "); 
	}
	void  InstallEngine() override { 
		this->vehicle->SetPart("Engine", "1,6 l.");
	}
	void  InstallWheels() override { 
		this->vehicle->SetPart("Wheels", "35 sm."); 
	}
	void  Paint() override { 
		this->vehicle->SetPart("Colour", "White"); 
	}
	void  PrepareSalon() override { 
		this->vehicle->SetPart("Salon", "Leather interior, air conditioning, 4 seater");
	}

};

class SportsCarTechnology : public AutoTechnology
{
public:
	SportsCarTechnology() { this->vehicle = new Vehicle("Sport's car"); }
	void  BuildBody() override { 
		this->vehicle->SetPart("Body", "Length - 2.0m   Height - 1.3m    Weight - 1,2 t. "); 
	}
	void  InstallEngine() override { 
		this->vehicle->SetPart("Engine", "2,5 l."); 
	}
	void  InstallWheels() override { 
		this->vehicle->SetPart("Wheels", "30 sm."); 
	}
	void  Paint() override { 
		this->vehicle->SetPart("Colour", "Red"); 
	}
	void  PrepareSalon() override { 
		this->vehicle->SetPart("Salon", "Leather interior, navigator, 2 seater"); 
	}

};

class SUVTechnology : public AutoTechnology
{
public:
	SUVTechnology() {
		this->vehicle = new Vehicle("SUV");
	}
	void  BuildBody() override {
		this->vehicle->SetPart("Body", "Length - 3.3m   Height - 2.1m    Weight - 5 t. ");
	}
	void  InstallEngine() override {
		this->vehicle->SetPart("Engine", "3,2 l.");
	}
	void  InstallWheels() override {
		this->vehicle->SetPart("Wheels", "45 sm.");
	}
	void  Paint() override {
		this->vehicle->SetPart("Colour", "Black");
	}
	void  PrepareSalon() override {
		this->vehicle->SetPart("Salon", "Leather interior, Cruise control, air conditioning, 5 seater");
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
		return new MiniAutoTechnology();
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
Director CreateDirector();


void BuildAuto(AutoTechnology* autoTechnology) {
	 CreateDirector().CreateAuto(autoTechnology);
};

Director CreateDirector() {
	Director *director = new Director();
	return *director;
};


void AddToPark(vector <AutoTechnology*> &autoPark, AutoTechnology* &autoTechnology) {
	autoPark.push_back(autoTechnology);
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
	
	int userChoice = 0;
	while (true)
	{
		system("cls");
		cout << "Enter your choice:\n1 - Mini auto\n2 - Sport car\n3 - SUV\n4 - Show park\n0 - Exit\nYour choice: ";
		cin >> userChoice;
		if (ChoiceTechnology(userChoice))
		{
			AutoTechnology* autoTechnology = ChoiceTechnology(userChoice);
			BuildAuto(autoTechnology);
			AddToPark(autoPark, autoTechnology);
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