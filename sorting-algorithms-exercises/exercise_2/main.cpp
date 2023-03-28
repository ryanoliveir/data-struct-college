#include <iostream>
#include <string>
#include <vector>

#include <windows.h>

// Uncomment the following line to compile in DEV-C++
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

class LOG {
    private:
        std::string blue = "\033[1;34m";
        std::string yellow = "\033[33m";
        std::string reset = "\033[0m";
        std::string red = "\033[31m";
        std::string green = "\033[32m";

    public:
        void log(std::string message) {
            std::cout << blue + message + reset << std::endl; 
        }

        void warning(std::string message) {
            std::cout << this->yellow + message + this->reset << std::endl;
        }

        void error(std::string message) {
            std::cout << this->red + message + this->reset << std::endl;
        }

        void sucess(std::string message) {
            std::cout << this->green + message + this->reset << std::endl;
        }

        void message(std::string message) {
            std::cout << this->reset + message << std::endl;
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
};

const int AMOUNT_NUMBERS = 10;

void showVector(const std::vector<int> &vector);
void bubble_sort_v1(std::vector<int>& vector);
std::pair<int, int> occurrence_SmallestValue(const std::vector<int> &vector);
std::pair<int, int> occurrence_HighestValue(const std::vector<int> &vector);

int main() {



    LOG console;
    console.enableColorMode();

    
    std::vector<int> numbers;
    int number_input;

    std::pair<int, int>  items;


    console.log("[+] Please provide 10 numbers");


    int count = 0;
    do {

        std::cout << "[*] > ";
        std::cin >> number_input;
        
        count++;

        numbers.push_back(number_input);

    } while (count < AMOUNT_NUMBERS);


    console.log("\n[*] Vector:");
    showVector(numbers);


    bubble_sort_v1(numbers);

    console.log("[*] Ordered vector:");
    showVector(numbers);

    items = occurrence_SmallestValue(numbers);

    console.sucess("[+] Occurrence of the smallest value: ");
    std::cout << "[+] Value: "<< items.first << std::endl;
    std::cout << "[+] Occurrence: "<< items.second << std::endl;


    items = occurrence_HighestValue(numbers);

    console.sucess("\n[+] Occurrence of the highest value: ");
    std::cout << "[+] Value: "<< items.first << std::endl;
    std::cout << "[+] Occurrence: "<< items.second << std::endl;

    return 0;
}



void showVector(const std::vector<int> &vector){

    std::cout << "[*] X["<< vector.size() <<"] = { ";
    for(const auto& element : vector){
        
        if (&element == &vector.back()) {
            std::cout << element << " ";

        } else {
            std::cout << element << ", ";
        }
    }

    std::cout << "}\n"<< std::endl;
}

void bubble_sort_v1(std::vector<int>& vector){

    size_t size = vector.size();
    int iterations = 1
    ;
    if( size == 0) return;

    int temporary_buffer;

    for (int i = 0; i < size; i++){

        for (int j = 0; j < size - 1; j++){

            if ( vector[j] > vector[j + 1]) {
                temporary_buffer = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temporary_buffer;
            } 
        }

    }
}

std::pair<int, int> occurrence_SmallestValue(const std::vector<int> &vector){
    int smallestValue = vector.front();

    int occurrenceCount = 0;

    for (const auto &element : vector){
        if (element == smallestValue) occurrenceCount++;
    }

    return std::make_pair(smallestValue, occurrenceCount);
}

std::pair<int, int> occurrence_HighestValue(const std::vector<int> &vector){
    int highestValue = vector.back();

    int occurrenceCount = 0;

    for (const auto &element : vector){
        if (element == highestValue) occurrenceCount++;
    }

    return std::make_pair(highestValue, occurrenceCount);
}

