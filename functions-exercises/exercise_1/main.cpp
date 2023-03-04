#include <iostream>

using namespace std;


int sum(int number);


int main(){

    int result, numberInput;

    cout << "[*] Type a number: ";
    cin >> numberInput;
    
    
    result = sum(numberInput);

    cout << "[*] Result: "<< result << endl;

    return 0;
}

int sum(int number){
    int aux = 0;

    for (int i = 0; i <= number; i++) 
    {
        aux += i;   
    }

    return aux;
}
