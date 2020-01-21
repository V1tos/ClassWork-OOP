#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;



//ООП
//Написати програму, яка дозволяє записувати в файл інформацію про результати сесії(оцінки) певної групи студентів.
//Організувати зчитування даної інформації з файлу та підрахунок середнього балу в групі.
//Використайте, розроблені в уроці 6 класи Group("Група") та Student("Студент").Додати методи Save() та Read() для запису та зчитування обєктів в / з файла.



class Group
{
	
	class Student
	{
		
	private:
		string name;
		string surname;
		static unsigned int counter;
		unsigned short mark;

	public:
		Student() {};
		Student(string name, string surname, short mark) {
			this->name = name;
			this->surname = surname;
			this->mark = mark;
			this->counter++;
		};
		void SetName(string name)        { this->name = name; };
		void SetSurname(string surname)  { this->surname = surname; };
		void SetMark(short mark)         { this->mark = mark; };

		string GetName()                 { return this->name; };
		string GetSurname()              { return this->surname; };
		short GetMark()                  { return this->mark; };

		void ShowStudent()               { cout << "Name: " << this->name << "\nSurname: " << this->surname <<"\nMark: "<<this->mark << endl; };
		~Student() {};
	};

	static string groupName;
	static unsigned short course;
	static string proffession;
	unsigned short studentsCount;
	Student *students;

public:
	Group() {};
	Group(unsigned short studentsCount) {
		this->studentsCount = studentsCount;
		this->students = new Student[this->studentsCount];
	};
	void FillStudent() {
		string name;
		string surname;
		unsigned short mark;
		for (int i = 0; i < this->studentsCount; i++) {
			cout << "Student N" << i + 1 << endl;
			cout << "Enter name: "; cin >> name;
			cout << "Enter surname: "; cin >> surname;
			mark = rand() % 5 + 1;
			this->students[i] = Student(name, surname,mark);
		}
	};
	void ShowGroup() {
		cout << "--------------------------------\n";
		cout << "|Group name: " << this->groupName << "             |\n|Course: " << this->course << "                     |\n|Proffession: " << this->proffession << "|\n";
		cout << "--------------------------------\n";
		for (int i = 0; i < this->studentsCount; i++) {
			cout << "********************\n";
			cout << "Student N" << i + 1 << endl;
			students[i].ShowStudent();
			cout << "********************\n";
		};
	}
	void EditStudent() {
		unsigned short studentsNumber;
		string name;
		string surname;
		cout << "Enter student's number: "; cin >> studentsNumber;
		cout << "Enter name: "; cin >> name;
		cout << "Enter surname: "; cin >> surname;
		this->students[studentsNumber - 1].SetName(name);
		this->students[studentsNumber - 1].SetSurname(surname);
	};
	void Save() {
		string path = "File.txt";
		ofstream writeFile;
		writeFile.exceptions(ifstream::badbit | ifstream::failbit);

		try
		{
			writeFile.open(path);

			writeFile << this->studentsCount << endl;
			for (int i = 0; i < this->studentsCount; i++)
			{
				writeFile << this->students[i].GetName() << endl;
				writeFile << this->students[i].GetSurname() << endl;
				writeFile << this->students[i].GetMark() << endl;

			}

			writeFile.close();
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
			cout << "Can't open file." << endl;

		}


	}

	void Read() {
		int size = 0;
		unsigned short sumMark = 0;
		char temp[255];
		string path = "File.txt";
		ifstream readFile;

		readFile.exceptions(ifstream::badbit | ifstream::failbit);

		try
		{
			readFile.open(path);

			readFile.getline(temp, 255);
			size = atoi(temp);
			Student *newStudents = new Student[size];
			for (int i = 0; i < size; i++)
			{
				readFile.getline(temp, 255);
				newStudents[i].SetName(temp);
				readFile.getline(temp, 255);
				newStudents[i].SetSurname(temp);
				readFile.getline(temp, 255);
				newStudents[i].SetMark(atoi(temp));
				sumMark += newStudents[i].GetMark();
				
			}
			this->studentsCount += size;

			this->students = newStudents;

			readFile.close();

			this->ShowGroup();
			cout << "Average mark: " << double(sumMark) / double(this->studentsCount) << endl;
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
			cout << "Can't open file." << endl;

		}




	}
	~Group() {
		this->students = nullptr;
		delete[] this->students;
	};
};


string Group::groupName = "CE-31";
unsigned short Group::course = 3;
string Group::proffession = "Civil Engineering";

unsigned int Group::Student::counter = 0;


int	main() {
	srand(unsigned(time(NULL)));



	/*unsigned short studentsCount = 0;
	cout << "Enter student's count: "; cin >> studentsCount;
	Group group(studentsCount);
	group.FillStudent();
	system("cls");
	group.ShowGroup();
	group.Save();*/

	Group group;
	group.Read();
	/*group.ShowGroup();*/



	system("pause");
	return 0;
}
