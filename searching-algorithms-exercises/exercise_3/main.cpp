#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cctype>

// Uncomment the following line to compile in DEV-C++
// #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

const int None = 0;

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

void showVector(const std::vector<char> &vector, std::string vector_name);

void quickSort(std::vector<char>& vector, int begin, int end);
int partition(std::vector<char>& vector, int begin, int end);
void sort(std::vector<char>& vector);

bool binarySearch(std::vector<char>& vector, int target, int begin = 0, int end = None);


int main(){

    LOG console;
    console.enableColorMode();
    console.enableUTF8Mode();

    std::vector<char> data;

    int amount_elements = 0;
    std::string element_input;
    char target_input, lower_upper_option;

    console.sucess("[*] Please, provide the following data:");
    
    std::cout << console.blue() << "[*] Amount of elements: " << console.reset();
    std::cin >> amount_elements;
    

    int count = 0;
    do {
        
        std::cout << "[*] " << count + 1 << "º: ";
        std::cin >> element_input;

        if(element_input.length() == 1 && std::isalnum(element_input[0])) {
            data.push_back((char)element_input[0]);
        } else {
            console.warning("[!] Value invalid, please, try again...");
            continue;
        }

        count++;

    } while (count < amount_elements);


    showVector(data, "data");
    sort(data);
    showVector(data, "data");
    

    console.log("\n[SEARCH ELEMENT]");
    std::cout << console.blue() <<"\n[*] Element to find : " << console.reset();
    std::cin >> target_input;


    //TODO: Check if it is uppercase or lowercase
    std::cout << console.blue() <<"\n[*] Uppercase or Lowecase(u/l) : " << console.reset();
    std::cin >> lower_upper_option;

    target_input = lower_upper_option == 'u' ? toupper(target_input) : target_input;


    if(binarySearch(data, target_input)){
        std::cout << console.green() << "[*]  The element ' "<< target_input <<"' was finded in vector" << std::endl;
    } else {
        std::cout << console.red() << "[*]  The element ' "<< target_input <<"' not finded" << std::endl;
    }

    


    return 0;
}


void showVector(const std::vector<char> &vector, std::string vector_name){

    std::cout << "[*] "<< vector_name <<"["<< vector.size() <<"] = { ";
    for(const auto& element : vector){
        
        if (&element == &vector.back()) {
            std::cout << element << " ";

        } else {
            std::cout << element << ", ";
        }
    }

    std::cout << "}\n"<< std::endl;
}


int partition(std::vector<char>& vector, int begin, int end) {
    char pivot = vector[end];
    int i = begin;

    char temp;

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

void quickSort(std::vector<char>& vector, int begin, int end){

    if (begin < end) {
        int pivot = partition(vector, begin, end);
        quickSort(vector, begin, pivot - 1);
        quickSort(vector, pivot + 1, end);


    }
    

}

void sort(std::vector<char>& vector){
    int begin = 0;
    int end = vector.size() - 1;

    quickSort(vector, begin, end);
}


bool binarySearch(std::vector<char>& vector, int target, int begin, int end){

    if (end == None ) end = vector.size() -1 ;

    if (begin <= end){
        int m = (begin + end) / 2;

        if(vector[m] == target) return true; // finded 

        if(target < vector[m]){
            return binarySearch(vector, target, begin, m - 1);

        } else {
            return binarySearch(vector, target, m + 1, end);

        }
    }

    return false;
}