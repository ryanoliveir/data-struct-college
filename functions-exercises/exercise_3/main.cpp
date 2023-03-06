#include <iostream>

using namespace std;


int checkDivisor(int first_number, int second_number) {
    int divisor = first_number / second_number;

    if (first_number % second_number == 0)
        return 0;
    else
        return (divisor + 1) * second_number;  
}

int main(){

    int number_1, number_2;

    cout << "[*] Please, provide 2 numbers:" << endl;
    cout << "[*] >  ";
    cin >> number_1;

    cout << "[*] >  ";
    cin >> number_2;
    

    int result = checkDivisor(number_1, number_2);

    if (result != 0)
        cout << "[*] Next divisor: " << result << endl;
    else
        cout << "[*]" << number_1 << "is divisble by" << number_2 << endl;

    return 0;
}