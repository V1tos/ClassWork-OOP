#pragma once
#include "Student.h"


class Group
{
private:
	static string groupName;
	static unsigned short course;
	static string proffession;
	unsigned short studentsCount;
	Student *students;

public:
	Group();
	Group(unsigned short studentsCount);
	void FillStudent();
	void ShowGroup();
	void EditStudent();
	~Group();
};

