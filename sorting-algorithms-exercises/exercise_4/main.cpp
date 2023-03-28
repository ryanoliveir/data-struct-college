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

const int VECTOR_SIZE = 20;

void populateVector(std::vector<int> &vector);
void showVector(const std::vector<int>& vector, std::string vector_name);
void merge(std::vector<int>& vector_a, std::vector<int>& vector_b, std::vector<int>& result);

void mergeSort(std::vector<int> &vector);

std::vector<int> mergeArrays(std::vector<int>& vector_a, std::vector<int>& vector_b);
int main(){

    LOG console;
    
    console.enableColorMode();


    std::vector<int> vector_a(VECTOR_SIZE);
    std::vector<int> vector_b(VECTOR_SIZE);
    // std::vector<int> vector_c(VECTOR_SIZE * 2);

    console.log("[+] Generating vectors with 20 elements...\n");

    console.warning("[+] Vector A");
    populateVector(vector_a);
    showVector(vector_a, "A");

    console.warning("[+] Vector B");
    populateVector(vector_b);
    showVector(vector_b, "B");

    console.sucess("[+] Vector C (40 elements)");
    std::vector<int> vector_c = mergeArrays(vector_a, vector_b);
    showVector(vector_c, "C");


    console.log("[+] Sorting Vector C...");
    mergeSort(vector_c);

    console.sucess("[+] Vector C (sorted)");
    showVector(vector_c, "C");
    

    return 0;

}

void populateVector(std::vector<int> &vector){
    std::random_device rd;
    std::mt19937 gen(rd());
   

    for (int i = 0; i < vector.size(); i++){
        std::uniform_int_distribution<> dis(-200, 100);
        vector[i] = dis(gen);
    }

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


std::vector<int> mergeArrays(std::vector<int>& vector_a, std::vector<int>& vector_b){
    for (const auto& element : vector_b)
    {
        vector_a.push_back(element);
    }

    return vector_a;
}

void merge(std::vector<int>& v1, std::vector<int>& v2, std::vector<int>& result){

    int i = 0, j = 0, k = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] <= v2[j]) {
            result[k] = v1[i];
            i++;
        } else {
            result[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < v1.size()) {
        result[k] = v1[i];
        i++;
        k++;
    }

    while (j < v2.size()) {
        result[k] = v2[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& vector){
    if(vector.size() <= 1){
        return;
    }

    int middle = vector.size() / 2;

    std::vector<int> left(vector.begin(), vector.begin() + middle);
    std::vector<int> right(vector.begin() + middle, vector.end());
    mergeSort(left);
    mergeSort(right);
    merge(left, right, vector);

}



