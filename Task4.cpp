#include <iostream>
using namespace std;

int main() {
	int day, age, isStudent;
	char format;
	double basePrice = 0, finalPrice;

	cout << "Enter day of week (1-7): ";
	cin >> day;
	cout << "Enter age: ";
	cin >> age;
	cout << "Format (N or I): ";
	cin >> format;
	cout << "Student (1 or 0): ";
	cin >> isStudent;

	if (day < 1 || day > 7) {
		cout << "Error: invalid day" << endl;
		return 1;
	}
	if (age < 0) {
		cout << "Error: invalid age" << endl;
		return 1;
	}
	if (format != 'N' && format != 'n' && format != 'I' && format != 'i') {
		cout << "Error: invalid format" << endl;
		return 1;
	}
	switch (day) {
	case 1:
	case 2:
	case 3:
	case 4:
		basePrice = 11;
		break;
	case 5:
		basePrice = 13;
		break;
	case 6:
	case 7:
		basePrice = 16;
		break;
	}
	if (format == 'I' || format == 'i') {
		basePrice = basePrice + 5;
	}
	if (age < 7) {
		finalPrice = 0;
		cout << "Rule: free for kids" << endl;
	}
	else {
		if (age >= 7 && age <= 17) {
			finalPrice = basePrice * 0.5;
			cout << "Rule: 50 percent discount" << endl;
		}
		else if (isStudent == 1) {
			finalPrice = basePrice * 0.8;
			cout << "Rule: 20 percent discount" << endl;
		}
		else {
			finalPrice = basePrice;
			cout << "Rule: no discount" << endl;
		}
		if (finalPrice < 5) {
			finalPrice = 5;
			cout << "Rule added: minimum price is 5" << endl;
		}
	}
	cout << "Final price: " << finalPrice << endl;
	return 0;
}
