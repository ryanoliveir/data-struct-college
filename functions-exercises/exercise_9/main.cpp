#include <iostream>
#include <string>

using namespace std;

int sumOfDivisors(int number);


int main(){

    int number_input, result;
 
    cout << "[*] Please, provide a integer number:" << endl;

    do {
        cout << "[*] > ";
        cin >> number_input;

        if(number_input < 0)
            cout << "[!] Must be positive." << endl;

    } while(number_input < 0);
    
    result = sumOfDivisors(number_input);

    cout << "[+] Sum of divisors: " << result << endl;
    return 0;
}



int sumOfDivisors(int number){

    int sum = 0;

    for (int i = 1; i <= number; i++){
        if(number % i == 0)
            sum += i;
    }

    return sum;
}


