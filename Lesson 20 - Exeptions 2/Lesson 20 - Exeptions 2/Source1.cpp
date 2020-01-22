#include <iostream>
#include <string>
using namespace std;


//Додаткове необов'язкове завдання (додаткових 12 балів)
//Написати програму, яка виводить статистику по вказаному користувачем файлу в наступному вигляді :
//кількість коротких слів(який складається максимум з 10 символів);
//кількість великих слів;
//кількість цифр;
//кількість символів пунктуації, наприклад, (!), (, ), (.), (-).
//Крім того, у відповідь на написанення довільної клавіши або на певний пункт меню, 
//здійснити заміну всіх цифр в файлі на символи(*), а додатково(на 12 балів) зробити видалення всіх символів пунктуації.


void Find_Short_Word(int *punct,int punct_Counts) {
	int short_Words_Count = 0;

	for (int i = 0; i < punct_Counts; i++)
	{
		if (i == 0) {
			if ((punct[i]) < 10) {
				short_Words_Count++;
			}
		}
		else
		{
			if ((punct[i]-(punct[i-1]+1)) < 10) {
				short_Words_Count++;
			}
		}

	}

	cout << "Short word's count: " << short_Words_Count << endl;

}

void Find_Long_Word(int *punct, int punct_Counts) {

	int long_Words_Count = 0;

	for (int i = 0; i < punct_Counts; i++)
	{
		if (i == 0) {
			if ((punct[i]) > 10) {
				long_Words_Count++;
			}
		}
		else
		{
			if ((punct[i] - (punct[i - 1] + 1)) > 10) {
				long_Words_Count++;
			}
		}

	}

	cout << "Long word's count: " << long_Words_Count << endl;

}

void Find_Digits_Count(char *name) {
	
	int digits_Count = 0;

	for (int i = 0; i < strlen(name); i++)
	{

		for (int j = 48; j < 58; j++)
		{
			if (int(name[i])==j)
			{
				digits_Count++;
			}
		}

	}



	cout << "Digit's count: " << digits_Count << endl;

}

void Change_Digits(char *name) {

	

	for (int i = 0; i < strlen(name); i++)
	{

		for (int j = 48; j < 58; j++)
		{
			if (int(name[i]) == j)
			{
				name[i] = '*';
			}
		}

	}

	for (int i = 0; i < strlen(name); i++)
	{
		cout << name[i];
	}

	cout << endl;

}

void Delete_puncts(char *name) {


	for (int i = 0; i < strlen(name); i++)
	{

		if (int(name[i]) == 33 || int(name[i]) == 44 || int(name[i]) == 45 || int(name[i]) == 46) {

			name[i] = 32;
		}
	}

	for (int i = 0; i < strlen(name); i++)
	{
		cout << name[i];
	}
	cout << endl;
}


int main() {

	char name[255] {};
	
	int punct_Counts=0;
	int counter = 0;


	cout << "Enter text: ";
	cin >> name;
	



	for (int i = 0; i < strlen(name); i++)
	{
		
		if (int(name[i]) == 33 || int(name[i]) == 44 || int(name[i]) == 45 || int(name[i]) == 46  ) {

			punct_Counts++;
		}
	}

	int *punct = new int[punct_Counts];

	for (int i = 0; i < strlen(name); i++)
	{

		if (int(name[i]) == 33 || int(name[i]) == 44 || int(name[i]) == 45 || int(name[i]) == 46) {

			punct[counter] = i;
			counter++;
		}
	}



	cout << "Punct's count: " << punct_Counts << endl;
	Find_Short_Word(punct, punct_Counts);
	Find_Long_Word(punct, punct_Counts);
	Find_Digits_Count(name);

	system("pause");
	Change_Digits(name);
	Delete_puncts(name);


	system("pause");
	return 0;
}