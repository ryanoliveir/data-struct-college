#include <iostream>
#include <string>

using namespace std;

// averaging
float averageCalc(float x, float y);
float inputData();

int main(){

    float result;


    result = inputData();

    cout << "[*] Avarage = " <<  result << endl;
    cout << "\nBye :)";


    return 0;
}


float averageCalc(float x, float y) {
    return x/y;
}


float inputData(){
    string number_input = "";
    float number, count = 0, sum = 0;

    cout << "[*] Please, provide numbers, and type \"q\" to exit:" << endl;
    

    do{
        cout << "[*] > ";
        cin >> number_input;

        if(number_input != "q"){
            number = stof(number_input);
            sum += number;
            count++;
        }

    } while(number_input != "q");



    return averageCalc(sum, count);
   

}


