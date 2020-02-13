#include <iostream>
#include <string>
#include <map>
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
		cout << "================\nName: " << name << endl;
		for (auto el : parts)
		{
			cout << el.first << "\t" << el.second << endl;
		}
	}
	~Vehicle() {};
};


 class AutoTechnology abstract {
protected:
	Vehicle *vehicle;
public:
	AutoTechnology() {this->vehicle = new Vehicle();}
	Vehicle *GetVehicle() { return vehicle;}
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
	MiniAutoTechnology() { this->vehicle = new Vehicle("Mini auto"); }
	void  BuildBody() override { this->vehicle->SetPart("Body", "Length - 2.3m   Height - 1.5m    Weight - 2 t. "); }
	void  InstallEngine() override { this->vehicle->SetPart("Engine", "1,6 l.");}
	void  InstallWheels() override { this->vehicle->SetPart("Wheels", "40 sm."); }
	void  Paint() override { this->vehicle->SetPart("Colour", "White"); }
	void  PrepareSalon() override { this->vehicle->SetPart("Salon", "Leather interior, air conditioning, 4 seater");}

};



class Director : public AutoTechnology
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







int main() {





	system("pause");
	return 0;
}