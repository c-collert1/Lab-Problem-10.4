#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool creditCardCheck(long long int Credit_Card_Number);
bool isNumber(char checkForNumber);

int main() {
    string Credit_Card_Info;
    long long int Credit_Card_Number;
    bool userInput = true;
    bool nonNum = false;
    bool nonLength = false;
    int digits;
    cout << "enter the amount of digits: ";
    cin >> digits;
    do {
        cout << endl << "Please enter a " << digits << "-digit number or Q to quit: ";
        cin >> Credit_Card_Info;

        // Check if the user wants to quit
        if (Credit_Card_Info == "Q" || Credit_Card_Info == "q") {
            userInput = false;
            break;
        }

        if (!all_of(Credit_Card_Info.begin(), Credit_Card_Info.end(), isNumber)) {
            cout << "Error: Please enter only numeric values." << endl;
            nonNum = true;
        }

        if (Credit_Card_Info.length() != digits && !nonNum) {
            cout << "Error: Please enter a " << digits << "-digit number." << endl;
            nonLength = true;
        }

        stringstream ss(Credit_Card_Info);
        ss >> Credit_Card_Number;

        if (!nonNum && !nonLength) {
            if (creditCardCheck(Credit_Card_Number)) {
                cout << "This is a valid card." << endl;
            }
            else {
                cout << "This is not a valid card." << endl;
            }
        }
        nonNum = false;
        nonLength = false;
    } while (userInput);

    return 0;
}

bool creditCardCheck(long long int Credit_Card_Number) {
    int Digits = 16;
    int Sum = 0;
    bool secondDigit = false;

    for (int i = Digits - 1; i >= 0; i--) {
        int temp = Credit_Card_Number % 10;
        Credit_Card_Number /= 10;

        if (secondDigit) {
            temp *= 2;
        }

        Sum += temp / 10;
        Sum += temp % 10;

        secondDigit = !secondDigit;
    }

    return (Sum % 10 == 0);
}

bool isNumber(char checkForNumber) {
   
 return (checkForNumber >= '0' && checkForNumber <= '9');
}
