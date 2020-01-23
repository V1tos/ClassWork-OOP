#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Student
{
	string name;
	unsigned short course;
	unsigned short mark;


public:
	Student() { cout << "Enter name: "; cin >> this->name; cout << "Enter course: "; cin >> this->course; cout << "Enter mark: "; cin >> this->mark; };
	Student(string name, unsigned short course, unsigned short mark) { this->name = name, this->course = course, this->mark = mark; }
	~Student() {};
	void ShowInfo() {
		cout << "Name: " << this->name << "\nCourse: " << this->course << "\nMark: " << this->mark << endl;
	}
	short Get_Mark() { return this->mark; }


};





int main() {
	//vector <int> vArr;

	//vArr.push_back(5);
	//vArr.push_back(12);
	//vArr.push_back(13);
	//vArr.push_back(52);
	//vArr.push_back(83);
	///*vArr.pop_back();*/

	////for (int i = 0; i < vArr.size(); i++)
	////{
	////	/*cout << vArr[i] << endl;*/

	////	cout << vArr.at(i) << endl;
	////}

	//vArr.clear();
	//vArr.reserve(50);



	//vArr.push_back(6);
	//vArr.push_back(5);
	//vArr.push_back(12);
	//vArr.push_back(13);
	//vArr.push_back(52);
	//vArr.push_back(83);
	//vArr.push_back(5);
	//vArr.push_back(14);
	//vArr.push_back(13);
	//vArr.push_back(52);
	//vArr.push_back(83);



	//cout <<vArr.capacity() <<endl;

	//cout << vArr.size() << endl;
	//


	//cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

	///*vector<int>::iterator i;

	//i = vArr.begin();

	//
	//cout << "iterator test: " << *i << endl;*/

	//for (vector<int>::reverse_iterator i=vArr.rbegin(); i<vArr.rend();i++)
	//{
	//	

	//	cout << *i << endl;

	//	/*vArr.at(1) = 200;*/
	//}




	/*Описати клас Студент(ім’я, курс, оцінка у 100 - бальній системі).Перевизначити для
		класу оператор виводу у потік.
		Визначити функцію заповнення вектору(деку) студентів довільними даними
		Визначити функцію виводу вмісту вектору(деку).
		Впорядкувати вектор(дек) за іменами студентів по зростанню.
		Відсортувати вектор(дек) за прізвищами студентів
		Знайти кількість студентів, що добре навчаються(бал &gt; = 74)
		Cкопіювати студентів, що добре навчаються у інший контейнер(вектор, дек чи список)
		Встановити у перші три елементи вектору(деку) студентів самих молодших курсів за
		зростанням(partial_sort_copy).
		Зберегти інформацію про студентів у текстовому файлі
		Почитати інформацію про студентів з файлу у контейнер*/

	

	vector<Student> arr;
	/*Student tmp;*/

	arr.push_back(Student());
	arr.push_back(Student());
	arr.push_back(Student());

	for (int i = 0; i < arr.size(); i++)
	{
		arr.at(i).ShowInfo();
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr.at(i).Get_Mark()<arr.at(i+1).Get_Mark())
		{
			arr.swap;
		}
		
	}
	

	system("pause");
	return 0;
}