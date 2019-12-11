#include <iostream>
#include <string>

using namespace std;
const double P = 3.14;



//Задание №4 Напишите шаблон функции, которая возвращает минимум из двух переданных параметров.
//Задание 1 Создайте класс Circle(окружность) : ■ Реализуйте через перегруженные операторы;
//■ Проверка на равенство радиусов двух окружностей(операция = = ); 
//■ Сравнения длин двух окружностей(операция > ).Пропорциональное изменение размеров окружности, путем изменения ее радиуса(операция += и -= ) 
//
//Задание 2 Создать класс Airplane(самолет) С помощью перегрузки операторов реализовать : 
//■ Проверка на равенство типов самолетов(операция = = ) 
//■ Увеличение и уменьшение пассажиров в салоне самолета(операции ++ и - -в префиксной форме) 
//■ Сравнение двух самолетов по максимально возможному количеству пассажиров на борту(операция > )


//template <typename T>
//class Return {
//	T a, b;
//public:
//	Return();
//	Return(T a, T b) {
//		this->a = a;
//		this->b = b;
//	}
//	T Versus() {
//		if (this->a > this->b) {
//			cout << a <<">" <<b << endl;
//			return this->b;
//		}
//		else if (this->a<this->b)
//		{
//			cout << a <<"<" <<b << endl;
//			return this->a;
//		}
//		else
//		{
//			cout << a <<"="<<b << endl;
//			return this->a;
//		}
//	}
//
//};




//class Circle
//{
//	unsigned short r;
//	float d;
//
//public:
//	Circle() {};
//	Circle(unsigned short r) {
//		this->r = r;
//		this->d = 2 * P*r;
//	}
//	
//	void ShowInfo() {
//		cout << "Radius = " << r << "\nLength = " << d << endl;
//	}
//	bool operator==(Circle &other) {
//		
//		if (this->r == other.r) {
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	};
//
//	bool operator>(Circle &other) {
//		if (this->d == other.d) {
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	};
//
//	Circle operator+=(unsigned short a) {
//		
//		this->r += a;
//		this->d = 2 * P*r;
//
//		return *this;
//	}
//
//	Circle operator-=(unsigned short a) {
//
//		this->r -= a;
//		this->d = 2 * P*r;
//
//		return *this;
//	}
//	
//
//
//};

class AirPlane
{
	string type;
	unsigned short passengersCount;
	unsigned short maxPassengers;

public:
	AirPlane() {};
	AirPlane(string type, unsigned short passengersCount, unsigned short maxPassengers) 
	{
		this->type = type;
		if (passengersCount > maxPassengers) {

		this->passengersCount = maxPassengers;

		}
		else
		{
			this->passengersCount = passengersCount;
		}
		
		this->maxPassengers = maxPassengers;

	};

	bool operator==(AirPlane &other) {
		if (this->type == other.type) {
			cout << "True\n";
			return true;
		}
		else
		{
			cout << "False\n";
			return false;
		}
	};

	bool operator>(AirPlane &other) {

		if (this->maxPassengers > other.maxPassengers) {

			cout << "True\n";
			return true;
		}
		else
		{
			cout << "False\n";
			return false;
		}
	};

	AirPlane operator+=(unsigned short passengersCount) {
		this->passengersCount += passengersCount;
		if (this->passengersCount > this->passengersCount) {
			this->passengersCount = maxPassengers;
		}
		return *this;
	};
	AirPlane operator-=(unsigned short passengersCount) {

		this->passengersCount -= passengersCount;
		return *this;
	};
	void ShowInfo() {
		cout << "Type: " << this->type << "\nPassenger's count: " << this->passengersCount << "\nMax passengers: " << this->maxPassengers << endl;
	}
	

};









int main() {

	//Task 1;
	//Return<int> a(5, 5);
	//cout << a.Versus() << endl;
	


	//Task 2;
	//Circle a(5);
	//Circle b(5);
	//a.ShowInfo();
	//cout << a.operator==(b) << endl;
	//cout << a.operator>(b) << endl;
	//a.operator+=(3);
	//a.operator-=(3);
	//a.ShowInfo();



	//Task 3;
	AirPlane a("Boing", 340, 500);
	AirPlane b("Boing", 250, 450);

	cout << a.operator==(b) << endl;
	a.operator+=(20);
	a.ShowInfo();












	system("pause");
	return 0;
}

