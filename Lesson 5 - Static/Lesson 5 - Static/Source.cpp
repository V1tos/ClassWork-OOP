#include "Group.h";


string Group::groupName = "CE-31";
unsigned short Group::course = 3;
string Group::proffession = "Civil Engineering";

unsigned int Student::counter = 0;

int main() {
	unsigned short studentsCount = 0;
	cout << "Enter student's count: "; cin >> studentsCount;
	Group group(studentsCount);
	system("cls");
	group.ShowGroup();



	system("pause");
	return 0;
}