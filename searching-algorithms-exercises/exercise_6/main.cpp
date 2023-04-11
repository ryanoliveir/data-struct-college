#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <windows.h>

// Uncomment the following line to compile in DEV-C++
// #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

class LOG {
    private:
        std::string blue_ansi = "\033[1;34m";
        std::string yellow_ansi = "\033[33m";
        std::string reset_ansi = "\033[0m";
        std::string red_ansi = "\033[31m";
        std::string green_ansi = "\033[32m";

    public:

        std::string blue() {
            return this->blue_ansi;
        }

        std::string yellow() {
            return this->yellow_ansi;
        }

        std::string reset() {
            return this->reset_ansi;
        }

         std::string red() {
            return this->red_ansi;
        }

        std::string green() {
            return this->green_ansi;
        }


        void log(std::string message) {
            std::cout << blue_ansi + message + reset_ansi << std::endl; 
        }

        void warning(std::string message) {
            std::cout << this->yellow_ansi + message + this->reset_ansi << std::endl;
        }

        void error(std::string message) {
            std::cout << this->red_ansi + message + this->reset_ansi << std::endl;
        }

        void sucess(std::string message) {
            std::cout << this->green_ansi + message + this->reset_ansi << std::endl;
        }

        void message(std::string message) {
            std::cout << this->reset_ansi + message << std::endl;
        }

        void enableColorMode() {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            GetConsoleMode(hOut, &dwMode);

            if (!GetConsoleMode(hOut, &dwMode)) {
                std::cerr << "Failed to get console mode" << std::endl;
                return;
            }  

            if (!(dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
                dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                if (!SetConsoleMode(hOut, dwMode)) {
                    std::cerr << "Failed to set console mode" << std::endl;
                    return;
                }
            }
        }

        void enableUTF8Mode() {
            SetConsoleOutputCP(65001); // UTF-8 mode
        }
};



struct Schedule {
    std::string destination;
    std::string departure;
    std::string arrival;
};


void listSchedules(const std::vector<Schedule>& schedules);

void quickSort(std::vector<Schedule>& vector, int begin, int end);
void sort(std::vector<Schedule>& vector);
int partition(std::vector<Schedule>& vector, int begin, int end);

void sequencialSearch(std::vector<Schedule>& vector, std::string target);
void showSchedule(Schedule& schedule, int& count);

int main(){

    LOG console;
    console.enableColorMode();
    console.enableUTF8Mode();


    std::vector<Schedule> schedules = {
        {"Statue of Liberty", "09:00", "11:00"},
        {"Statue of Liberty", "12:00", "14:00"},
        {"Statue of Liberty", "15:00", "17:00"},
        {"Central Park", "08:30", "10:30"},
        {"Central Park", "11:00", "13:00"},
        {"Central Park", "14:00", "16:00"},
        {"Empire State Building", "09:30", "11:30"},
        {"Empire State Building", "12:30", "14:30"},
        {"Empire State Building", "15:30", "17:30"},
    };

    std::string targetDestination;


    console.message("\n[SEARCH BUS SCHEDULE]");
    std::cout << console.blue() << "\n[*] Please, provide your destiny: " << console.reset();
    
    std::getline(std::cin, targetDestination);

    // sort(schedules);
    // listSchedules(schedules);

    sequencialSearch(schedules, targetDestination);



    return 0;
}


void sequencialSearch(std::vector<Schedule>& vector, std::string target){

    int count = 0;
    LOG console;

    for (int i = 0; i < vector.size(); i++){
        if (vector[i].destination == target) {
            count++;
            
            if(count == 1 ) std::cout << console.green() <<"[+] Schedule to "<< console.yellow() << target << console.green() << " available: "<< console.reset() << std::endl;

            showSchedule(vector[i], count);
        }

        
    }

    if(count == 0) std::cout << console.red() << "[-] Schedule to "<< target << " not finded: "<< console.reset() << std::endl;
}

void showSchedule(Schedule& schedule, int& count){

    std::cout << "[>] " << count << "º " << std::endl;
    std::cout << "    Departure: "<<  schedule.departure << std::endl;
    std::cout << "    Arrival: "<<  schedule.arrival << std::endl;
    std::cout << std::endl;
}

void listSchedules(const std::vector<Schedule>& schedules){

    for (const auto& schedule : schedules) {
        std::cout << "[>] Destination: "<< schedule.destination << std::endl;
        std::cout << "    Departure: "<<  schedule.departure << std::endl;
        std::cout << "    Arrival : "<<  schedule.arrival << std::endl;
        std::cout << std::endl;
    }


}

int partition(std::vector<int>& vector, int begin, int end) {
    int pivot = vector[end];
    int i = begin;

    int temp;

    for (int j = begin; j < end; j++) {
        if (vector[j] <= pivot ) {
            temp = vector[j];
            vector[j] = vector[i];
            vector[i] = temp;
            i++;
        }
    }

    temp = vector[end];
    vector[end] = vector[i];
    vector[i] = temp;

    return i;
}


void quickSort(std::vector<int>& vector, int begin, int end){

    if (begin < end) {
        int pivot = partition(vector, begin, end);
        quickSort(vector, begin, pivot - 1);
        quickSort(vector, pivot + 1, end);


    }
    

}


void sort(std::vector<int>& vector){
    int begin = 0;
    int end = vector.size() - 1;

    quickSort(vector, begin, end);
}