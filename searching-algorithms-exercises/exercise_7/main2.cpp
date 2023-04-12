#include <iostream>
#include <vector>

#include <windows.h>
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

const int None = 0;
Matrix matrix;

// Function declarations
bool binarySearch(std::vector<int> &vector, int target, int begin = 0, int end = -1);
void populateMatrix(const std::vector<int> &vector, std::vector<std::vector<int>> &matrix, int row, int column);
void showMatrix(const std::vector<std::vector<int>> &matrix, const std::string &matrixName);

int main()
{

    LOG console;
    console.enableColorMode();
    console.enableUTF8Mode();

    

    int row = 3, column = 4, target_input = 10;
    std::vector<int> vector_buffer = {2, 4, 5, 8, 9, 10, 11, 13, 15, 17, 20, 22};
    std::vector<std::vector<int>> matrix_main(row, std::vector<int>(column));

    populateMatrix(vector_buffer, matrix_main, row, column);
    showMatrix(matrix_main, "matrix_main");

    for (int i = 0; i < matrix.row; i++)
    {
        
            if (binarySearch(matrix_main[i], target_input))
            {
                std::cout << console.green() << "[*]  The element ' " << target_input << "' was found in the matrix" << std::endl;
            }
            else
            {
                std::cout << console.red() << "[*]  The element ' " << target_input << "' was not found in the matrix" << std::endl;
            }
        
    }

    return 0;
}

// Function definitions
bool binarySearch(std::vector<int>& vector, int target, int begin, int end){

    if (end == None ) end = vector.size() -1 ;

    if (begin <= end){
        int m = (begin + end) / 2;

        if(vector[m] == target) {
            matrix.column = m;
            return true;
        } // finded 

        if(target < vector[m]){
            return binarySearch(vector, target, begin, m - 1);

        } else {
            return binarySearch(vector, target, m + 1, end);

        }
    }

    return false;
}

void populateMatrix(const std::vector<int> &vector, std::vector<std::vector<int>> &matrix, int row, int column)
{
    int k = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = vector[k];
            k++;
        }
    }
}

void showMatrix(const std::vector<std::vector<int>> &matrix, const std::string &matrixName)
{
    std::cout << "Matrix " << matrixName << ":" << std::endl;

    for (const auto &row : matrix)
    {
        for (const auto &element : row)
        {
            std::cout << element << "\t";
        }
        std::cout << std::endl;
    }
}