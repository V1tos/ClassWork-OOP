#include "Student.h"



int main() {

	Student students[2];
	string name;
	string surname;
	for (int i = 0; i < 2; i++) {
		cout << "Student N" << i + 1 << endl;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		students[i]=Student(name, surname);
		students[i].FillEvaluation();
		students[i].AverageEvaluation();
	}

	system("cls");
	for (int i = 0; i < 2; i++) {
		students[i].ShowStudentInfo();
	}

	system("pause");
	return 0;
}