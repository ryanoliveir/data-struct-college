#include <iostream>
#include <math.h>
using namespace std;

const double pi = 3.14;

double sphereVolume(double *radius);


int main(){

    double radius, result;


    cout << "[*] Please, provide the following data:" << endl;
    cout << "[*] Sphere radius (cm): ";
    cin >> radius;
   

    result = sphereVolume(&radius);
    cout << "[*] Sphere volume: " << result << " cm^3" << endl;
    return 0;
}


double sphereVolume(double *radius){
    double volume = (4.0/3.0) * pi * pow(*radius, 3.0);
    return volume;

}