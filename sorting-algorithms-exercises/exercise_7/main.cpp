#include <iostream>
#include <string>
#include <vector>
#include <cstring>
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



struct Employee {
    std::string identifier;
    std::string name;
    float wage;
    std::string admission;

};

const int amount_employees = 2;

void registerEmployee(std::string id, std::string name, std::string admission, float wage, std::vector<Employee> employees);
void listEmployees(const std::vector<Employee>& employees);

int main(){

    std::vector<Employee> employees;

    std::string identifier_input, name_input, admission_input;
    float wage;


    int count = 0;
    do {
        count++;
        std::cout << "\n[*] Residente "<< count << std::endl;

        std::cout << "[*] ID code: ";
        std::cin >> identifier_input;

        std::cout << "[*] Name: ";
        std::cin >>  name_input;
        
        std::cout << "[*] Admission date (dd/mm/aaa): ";
        std::cin >> admission_input;

        std::cout << "[*] Wage:  ";
        std::cin >> wage;

        
        registerEmployee(identifier_input, name_input, admission_input, wage, employees);

    } while (count < amount_employees);


    listEmployees(employees);

}

void registerEmployee(std::string id, std::string name, std::string admission, float wage, std::vector<Employee> employees){

    Employee employee;

    employee.identifier = id;
    employee.name = name;
    employee.admission = admission;
    employee.wage = wage;

    employees.push_back(employee);  
}


void listEmployees(const std::vector<Employee>& employees){


    for (const auto& employee : employees) {
        std::cout << "[>] ID: "<<employee.identifier << std::endl;
        std::cout << "    Name: "<< employee.name << std::endl;
        std::cout << "    Admission: "<< employee.admission << std::endl;
        std::cout << "    Wage: "<< employee.wage << std::endl;
        std::cout << std::endl;
    }


}