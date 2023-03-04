#include <iostream>

using namespace std;

const int hourInSeconds = 3600;
const int minutesInSeconds = 60;


int toSeconds(int hours, int minutes, int seconds);

int main(){

    int hours, minutes, seconds, result;


    cout << "[*] Please, provide the following data:" << endl;
    cout << "[*] Hours(h): ";
    cin >> hours;
    cout << "[*] Minutes(m): ";
    cin >> minutes;
    cout << "[*] Seconds(s): ";
    cin >> seconds;

    result = toSeconds(hours, minutes, seconds);

    cout << "[*] Result: " << result << "(s)" << endl;
    return 0;
}

int toSeconds(int hours, int minutes, int seconds){
    int secondsTotal = 0;

    secondsTotal = (hours * hourInSeconds) + (minutes * minutesInSeconds) + seconds;

    return secondsTotal;
}



