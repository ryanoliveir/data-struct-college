#include <iostream>
#include <string>

using namespace std;

int factorialCalc(int n);


int main(){

    int number_input, result;
 
    cout << "[*] Please, provide a integer number:" << endl;

    do {
        cout << "[*] > ";
        cin >> number_input;

        if(number_input < 0)
            cout << "[!] Must be positive." << endl;

    } while(number_input < 0);
    
    result = factorialCalc(number_input);

     cout << "[+] " << number_input << "!" << " = "<< result << endl;
    return 0;
}


int factorialCalc(int n){
    
    if(n == 0) return 1;

    int factorial = 1;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    return factorial;
    
}














