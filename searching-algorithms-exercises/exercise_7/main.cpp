#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <exception>
// Uncomment the following line to compile in DEV-C++
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004


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


struct Matrix {
    int row;
    int column;
};

const int None = -1;


void populateVector(std::vector<int> &vector, Matrix& matrix_t);
void showVector(const std::vector<int> &vector, std::string vector_name);

void populateMatrix(const std::vector<int>& vector, std::vector<std::vector<int>>& matrix, Matrix& matrixType);
void showMatrix(const std::vector<std::vector<int>>& matrix, std::string matrix_name);

void quickSort(std::vector<int>& vector, int begin, int end);
void sort(std::vector<int>& vector);
int partition(std::vector<int>& vector, int begin, int end);

      bool binarySearch(std::vector<std::vector<int>>& matrix, int target, int row, int beginCol, int endCol);
bool binarySearchMatrix(std::vector<std::vector<int>>& matrix, int target, int row, int colBegin, int colEnd);

Matrix matrix;

// void load();

int main(){

    LOG console;
    console.enableColorMode();
    console.enableUTF8Mode();

    
    // - Pegar ordem da matriz pelo usuário

    std::string m_input, n_input;
    int target_input = 0;

    console.log("[*] Please, provide matriz order: ");

    do {

        std::cout << "[?] Row(s): ";
        std::cin >> m_input;

        std::cout << "[?] Column(s): ";
        std::cin >> n_input;

        try {
            matrix.row = stoi(m_input);
            matrix.column = stoi(n_input);

            break;

        } catch (std::invalid_argument&){
            console.warning("[!] Provide only numbers...");

        } catch (std::exception&){
            console.warning("[!] Incorrect values, try again...");
        }
        

    } while (true);

    std::cout << "[*] matrix[" << matrix.row <<"]["<< matrix.column << "]"<< std::endl;;

    // - Criar vetor com o numero de elementos que a matriz comporta  nessa ordem com vector<int>

    int matrix_size = matrix.row  * matrix.column;
    std::vector<int> vector_buffer(matrix_size);

    populateVector(vector_buffer, matrix);
    showVector(vector_buffer, "vector_buffer");

    // - Ordenar vetor gerado
    sort(vector_buffer);
    showVector(vector_buffer, "vector_buffer");


    console.log("\n[SEARCH ELEMENT]");
    std::cout << console.blue() <<"\n[*] Element to find : " << console.reset();
    std::cin >> target_input;

    std::vector<std::vector<int>> matrix_main(matrix.row, std::vector<int>(matrix.column));
    populateMatrix(vector_buffer, matrix_main, matrix);
    showMatrix(matrix_main, "matrix_main");

    // if(binarySearch(vector_buffer, target_input)){
    //         std::cout << console.green() << "[*]  The element '"<< target_input <<"' was finded in vector" << std::endl;
    // } else {
    //         std::cout << console.red() << "[*]  The element '"<< target_input <<"' not finded" << std::endl;
    // }
    // for (int i = 0; i < matrix_main.size(); i++){
    //     if(binarySearchMatrix(matrix_main, target_input, i, 0, matrix_main[0].size() - 1)){
    //         std::cout << console.green() << "[*]  The element ' "<< target_input <<"' was finded in vector" << std::endl;
    //     } else {
    //         std::cout << console.red() << "[*]  The element ' "<< target_input <<"' not finded" << std::endl;
    //     }
    // }

    // // std::cout << console.blue() <<"\n[*] Rows: " << matrix.row << console.reset();

    try {

         std::cout << "matrix_main size: " << matrix_main.size() << std::endl;
         for (int i = 0; i < matrix_main.size(); i++){
             std::cout << i << "º  - row "  << std::endl;   

             bool find = binarySearch(matrix_main, target_input, i, 0, matrix_main[0].size() - 1);

             if(find){
                 std::cout << console.green() << "[*]  The element '"<< target_input <<"' was finded in vector" << std::endl;
             } else {
                 std::cout << console.red() << "[*]  The element '"<< target_input <<"' not finded" << std::endl;
             }
         }

        console.log("[*] Finish");
        std::cout << "dadajdaid";
    } catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }


    return 0;

}


void populateVector(std::vector<int> &vector, Matrix& matrix_t){
    std::random_device rd;
    std::mt19937 gen(rd());

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    gen.seed(seed);

    for (int i = 0; i < matrix_t.row * matrix_t.column ; i++){
        std::uniform_int_distribution<> dis(-200, 200);
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

void populateMatrix(const std::vector<int>& vector, std::vector<std::vector<int>>& matrix, Matrix& matrixType){

    int k = 0;
    for (int i = 0; i < matrixType.row; i++){

        for (int j = 0; j < matrixType.column; j++){

            matrix[i][j] = vector[k];
            k++;
        }
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

// TODO: Adapt this to receive a matrix[m][n]
bool binarySearch(std::vector<std::vector<int>>& matrix, int target, int row, int beginCol, int endCol){

    if (endCol == -1 ) endCol = matrix[0].size() - 1;
    if (beginCol <= endCol){
        int m = (beginCol + endCol) / 2;
        if(matrix[row][m] == target){
            return true ;
        } else if (matrix[row][m] > target){
            return binarySearch(matrix, target, row, beginCol, m - 1);
        } else {
            return binarySearch(matrix, target, row, m + 1, endCol);
        }
    }
    return false;
}


bool binarySearchMatrix(std::vector<std::vector<int>>& matrix, int target, int row, int colBegin, int colEnd) {
    if (colEnd == -1) colEnd = matrix[0].size() - 1;
    if (colBegin <= colEnd) {
        int mid = (colBegin + colEnd) / 2;
        if (matrix[row][mid] == target) {
            return true;
        } else if (matrix[row][mid] > target) {
            return binarySearchMatrix(matrix, target, row, colBegin, mid - 1);
        } else {
            return binarySearchMatrix(matrix, target, row, mid + 1, colEnd);
        }
    }
    return false;
}



// void load(){
//     for (int i = 0; i < 7; ++i) {
//         std::cout << ".";
//         // std::cout.flush(); // descarrega o buffer para imprimir imediatamente
//         std::this_thread::sleep_for(std::chrono::milliseconds(100)); // esperar 100 milissegundos
//     }

   
// }

