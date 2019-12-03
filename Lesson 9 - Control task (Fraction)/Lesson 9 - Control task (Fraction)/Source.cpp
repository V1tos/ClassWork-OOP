#include "Fraction.h"




int main() {

	Fraction test(3, 9);
	Fraction test2(2, 4);
	cout << "=========Fraction 1===========\n";
	test.ShowFraction();
	cout << "=========Fraction 1===========\n\n";
	cout << "=========Fraction 2===========\n";
	test2.ShowFraction();
	cout << "=========Fraction 2===========\n\n";
	cout << "=========Fraction 1 + Fraction 2===========\n";
	test.Plus(test2);
	cout << "=========Fraction 1 + Fraction 2===========\n\n";
	cout << "=========Fraction 1 - Fraction 2===========\n";
	test.Minus(test2);
	cout << "=========Fraction 1 - Fraction 2===========\n\n";
	cout << "=========Fraction 1 * Fraction 2===========\n";
	test.Multiple(test2);
	cout << "=========Fraction 1 * Fraction 2===========\n\n";
	cout << "=========Fraction 1 / Fraction 2===========\n";
	test.Division(test2);
	cout << "=========Fraction 1 / Fraction 2===========\n\n";
	cout << "=========Fraction 1 Reduction===========\n";
	test.Reduction();
	cout << "=========Fraction 1 Reduction===========\n\n";
	cout << "=========Fraction 2 Reduction===========\n";
	test2.Reduction();
	cout << "=========Fraction 2 Reduction===========\n\n";
	cout << "=========Fraction 1 CreateInt===========\n";
	test.CreateInt();
	cout << "=========Fraction 1 CreateInt===========\n\n";
	cout << "=========Fraction 2 CreateInt===========\n";
	test2.CreateInt();
	cout << "=========Fraction 2 CreateInt===========\n\n";
	cout << "=========Fraction 1 CreateDouble===========\n";
	test.CreateDouble();
	cout << "=========Fraction 1 CreateDouble===========\n\n";
	cout << "=========Fraction 2 CreateDouble===========\n";
	test2.CreateDouble();
	cout << "=========Fraction 2 CreateDouble===========\n\n";
	cout << "=========Fraction 1 operator==(Fraction 2)===========\n";
	test.operator==(test2);
	cout << "=========Fraction 1 operator==(Fraction 2)===========\n\n";
	cout << "=========Fraction 1 operator!=(Fraction 2)===========\n";
	test.operator!=(test2);
	cout << "=========Fraction 1 operator!=(Fraction 2)===========\n\n";
	

	


	

	system("pause");
	return 0;
}