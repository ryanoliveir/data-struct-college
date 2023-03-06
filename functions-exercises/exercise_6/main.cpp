#include <iostream>

using namespace std;


float getIdealWeight(char sex, float height);


int main(){

    char sex;
    float height, idealWeight;
    
    cout << "[*] Please, provide the following data:" << endl;
    cout << "[*] Sex (m/f): ";
    cin >> sex;

    cout << "[*] Height (m): ";
    cin >> height;


   idealWeight = getIdealWeight(sex, height);

   cout << "[*] Ideal Weight: "<< idealWeight <<"kg"<< endl;

    return 0;
}


float getIdealWeight(char sex, float height){

    if(sex == 'm')
        return 72.7 * height - 58.0;
    else
        return 62.1 * height - 44.7;

}