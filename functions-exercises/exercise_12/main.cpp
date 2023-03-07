#include <iostream>

using namespace std;

float powCalc(float x, float z);

int main(){

    int number_x, number_z;


    cout << "[*] Please, provide 2 numbers" << endl;


    cout << "[*] > ";
    cin >> number_x;

    cout << "[*] > ";
    cin >> number_z;


    float result = powCalc(number_x, number_z);
    
    cout << "[+] " << number_x << " ^ " << number_z << " = "<< result << endl;

    return 0;
}

float powCalc(float x, float z){

    float pow = 1;

    if (z == 0) return pow;

    for (int i = 1; i <= z; i++){
        pow *= x;
    }


    return pow;
  
}