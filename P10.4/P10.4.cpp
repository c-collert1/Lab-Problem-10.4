#include <iostream>
#include <cmath>
using namespace std;

bool creditCardCheck(int Credit_Card_Number, int Digits);
int main() {

	int Counter = 0;
	int Sum = 0;
	int Credit_Card;
	int Digits = 8;
	int Second_Digit = 0;


	cout << "Please enter your Credit Card number: ";
	cin >> Credit_Card;

	if (creditCardCheck(Credit_Card, Digits)) {
		cout << "valid credit card";
	}
	else {
		cout << "invalid credit card";
	}
}

bool creditCardCheck(int Credit_Card_Number, int Digits) {
	int Sum = 0;
	int Second_Digit;
	int Counter = 0;
	while (Credit_Card_Number > 0) {
		Digits = Credit_Card_Number % 10;
		Credit_Card_Number /= 10;
		if (Counter % 2 == 0) {
			Sum = Sum + Digits;

		}
		else {
			Second_Digit = Digits * 2;
			if (Second_Digit >= 10) {
				Second_Digit = 1 + Second_Digit % 10;
			}
			Sum = Sum + Second_Digit;
		}

		Counter++;

	}
	if (Sum % 10 == 0) {
		return true;
	}
	else {
		return false;
	}
}