#include <iostream>

using namespace std;

float sequence(int n);

int main(){

    int number_of_terms;


    cout << "[*] Please, provide a integer number:" << endl;

    do {
        cout << "[*] > ";
        cin >> number_of_terms;

        if(number_of_terms < 1)
            cout << "[!] Must be positive(+) and greater than 1." << endl;

    } while(number_of_terms < 1);



    float result = sequence(number_of_terms);
    
    cout << "[+] The sum  of the firts " << number_of_terms << " terms is " << result << endl;

    return 0;
}

float sequence(int n){
    float s = 0;


    for(int i = 1; i <= n; i++){
        s += 1.0f / i;
    }


    return s;
  
}