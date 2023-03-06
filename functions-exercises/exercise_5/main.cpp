#include <iostream>
#include <string>

using namespace std;


string checkSignal(float number);


int main(){


    float number;
    string result;

    cout << "[*] Please, provide a number:" << endl;
    cout << "[*] >  ";
    cin >> number;

    result = checkSignal(number);

    cout << "[*] " << result << endl;

    return 0;
}


string checkSignal(float number){
    if(number == 0)
        return "The number is 0! (unsigned)";
    else
        return number < 0 ? "Negative number" : "Positive number";

}