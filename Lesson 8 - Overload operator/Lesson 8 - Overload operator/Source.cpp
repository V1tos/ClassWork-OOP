#include "XString.h"



int main() {

	char microsoftName[80];
	char windowsName[80];
	
	
	cin >> microsoftName;

	XString microsoft(microsoftName);


	cin >> windowsName;

	XString windows(windowsName);

	microsoft.operator*(windows);

	system("pause");
	return 0;
}