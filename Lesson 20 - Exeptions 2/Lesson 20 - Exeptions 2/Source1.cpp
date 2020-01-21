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

//
//void Find_Short_Word(char *name) {
//
//	for (int i = 0; i < strlen(name); i++)
//	{
//		cout << "i = " << i << " name[i] = " << name[i] << endl;
//	}
//
//}




int main() {

	char name[255] {};
	
	int punct_Counts=0;
	int counter = 0;

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

	for (int i = 0; i < punct_Counts; i++)
	{
		cout << punct[i] << endl;
	}


	system("pause");
	return 0;
}