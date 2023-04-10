#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <windows.h>

// Uncomment the following line to compile in DEV-C++
// #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

const int amount_numbers = 5; 
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


void showVector(const std::vector<int> &vector, std::string vector_name);


void quickSort(std::vector<int>& vector, int begin, int end);
void sort(std::vector<int>& vector);
int partition(std::vector<int>& vector, int begin, int end);


bool sequencialSearch(std::vector<int>& vector, int target);
bool binarySearch(std::vector<int>& vector, int target, int& position, int begin = 0, int end = None);

void checkPosition(int position, int target, std::string vector_name);

int main(){

    LOG console;
    console.enableColorMode();
    console.enableUTF8Mode();


    std::vector<int> listOfNumbers;
    int number_input, target_input, position;


    console.sucess("[*] Please, provide 15 integer numbers:");

    int count = 0;
    do {
    

        std::cout << "[*] "<< count + 1<<"º : ";
        std::cin >> number_input;

        if (listOfNumbers.size() == 0) {
            listOfNumbers.push_back(number_input);     

        } else {
            console.log("[*] Checking input...");
            
            if (sequencialSearch(listOfNumbers, number_input)){
                console.warning("[!] Provide a different number...");
                continue;
            } else {
                listOfNumbers.push_back(number_input);
            }


        }



        count++;
    } while (count < amount_numbers);


    sort(listOfNumbers);
    showVector(listOfNumbers, "listOfNumber");


    std::cout << "\n[*]  Provide number to search in vector: ";
    std::cin >> target_input;

    if(binarySearch(listOfNumbers, target_input, position)) {

        checkPosition(position, target_input, "listOfNumbers");
    } else {
        std::cout << console.red() << "[*]  The value '"<< target_input <<"' not finded" << std::endl;
    }

    return 0;
}

void showVector(const std::vector<int> &vector, std::string vector_name){

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





bool sequencialSearch(std::vector<int>& vector, int target){

    for (int i = 0; i < vector.size(); i++){
        if (vector[i] == target) return true;
    }

    return false;
}


bool binarySearch(std::vector<int>& vector, int target, int& position, int begin, int end){

    if (end == None ) end = vector.size() -1 ;

    if (begin <= end){
        int m = (begin + end) / 2;

        if(vector[m] == target) {
            position = m;
            return true;
        } // finded 

        if(target < vector[m]){
            return binarySearch(vector, target, position, begin, m - 1);
        } else {
            return binarySearch(vector, target, position, m + 1, end);
        }
    }

    return false;
}

void checkPosition(int position, int target,  std::string vector_name){
    if (position % 2 == 0) {
       std::cout << "[*]  The value '"<< target<<"' was finded in "<< vector_name <<"["<< position <<"] (even)"<< std::endl;
    } else {
        std::cout << "[*]  The value '"<< target<<"' was finded in "<< vector_name <<"["<< position <<"] (odd)"<< std::endl;
    }   
    
}




