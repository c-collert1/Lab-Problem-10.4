#include <iostream>
using namespace std;

bool creditCardCheck(long long int Credit_Card_Number);

int main() {
   //had to make variable something called "long long" for extra bits
    long long int Credit_Card_Number = 4010046804271206;

    if (creditCardCheck(Credit_Card_Number)) {
        cout << "This is a valid card\n";
    }
    else {
        cout << "This is not a valid card\n";
    }

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
   
    if (Sum % 10 == 0) {
        return true;
    }
    else {
        return false;
    }
}