#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
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
};

const int VECTOR_SIZE = 16;
const int MATRIX_SIZE = 4;
const int AMOUNT_NUMBERS = 16;

void showVector(const std::vector<int>& vector, std::string vector_name);
void populateMatrix(const std::vector<int>& vector, std::vector<std::vector<int>>& matrix);
void showMatrix(const std::vector<std::vector<int>>& matrix, std::string matrix_name);

void insertionSort(std::vector<int>& vector);
void selectionSort(std::vector<int>& vector);

int main(){

    LOG console;
    
    console.enableColorMode();


    std::vector<int> vector_input;

    std::vector<std::vector<int>> matrix(MATRIX_SIZE, std::vector<int>(MATRIX_SIZE));
    

    int number_input;
    char order_input;

    console.log("[+] Please provide 16 numbers");


    int count = 0;
    do {

        std::cout << "[*] > ";
        std::cin >> number_input;
        
        count++;

        vector_input.emplace_back(number_input);

    } while (count < AMOUNT_NUMBERS);


    console.log("\n[*] Vector:");
    showVector(vector_input, "vector_input");


     std::cout << console.blue() <<"[>] Sort: " << console.reset() << std::endl;
     std::cout <<"    a. Ascending " << console.reset() << std::endl;
     std::cout <<"    b. Descending  " << console.reset() << std::endl;
     std::cout << console.yellow() <<"[!] Type 'a' or 'b': " << console.reset();
     std::cin >> order_input;


    if (order_input == 'a') {
        insertionSort(vector_input);

    } else if (order_input == 'b') {
        selectionSort(vector_input);
        
    }

    populateMatrix(vector_input, matrix);

    console.log("\n[*] Matrix:");
    showMatrix(matrix, "matrix");
    

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

void showMatrix(const std::vector<std::vector<int>>& matrix, std::string matrix_name){

    std::cout << "[*] " << matrix_name << "[" << matrix.size() << "x" << matrix[0].size() << "] = {";
    for (const auto& row : matrix) {
        std::cout << "  { ";
        
        for (const auto& element : row) {

            if (&element == &row.back()) {
                std::cout << element << " ";

            } else {
                std::cout << element << ", ";
            }
        }

        if(&row == &matrix.back()) {
            std::cout << "} ";

        } else {
            std::cout << "}, ";

        }
    }


    std::cout << "}" << std::endl;
}


void populateMatrix(const std::vector<int>& vector, std::vector<std::vector<int>>& matrix){

    int k = 0;
    for (int i = 0; i < MATRIX_SIZE; i++){

        for (int j = 0; j < MATRIX_SIZE; j++){

            matrix[i][j] = vector[k];
            k++;
        }
    }


}


void insertionSort(std::vector<int>& vector){
    int i, j, key, n = vector.size();

    for (i = 1; i < n; i++) {
        key = vector[i]; 
        j = i - 1; 

        while (j >=0 && vector[j] > key) {
            vector[j + 1] = vector[j];
            j = j - 1;
        }

        vector[j + 1] = key;
    }
}

void selectionSort(std::vector<int>& vector) {

    for (int i = 0; i < vector.size() - 1; i++){
        int minIndex = i;

        for (int j = i + 1; j < vector.size(); j++){

            if (vector[j] > vector[minIndex]) {

                minIndex = j;
            }

        }

        if (minIndex != i) {
            int temp = vector[i];
            vector[i] = vector[minIndex];
            vector[minIndex] = temp;
        }

    }
}