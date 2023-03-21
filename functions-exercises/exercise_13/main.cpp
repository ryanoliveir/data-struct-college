#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <time.h>


const int people = 2;

void registerAge(int age, std::vector<int> &age_vector);
void registerChildren(int children, std::vector<int> &children_vector);
void registerSalary(float salary, std::vector<float> &salary_vector);
void registerSex(char char_sex, std::vector<char> &char_vector);


float averageWage(std::vector<float> &salaryVector);
int majorAge(std::vector<int> &age);
int minorAge(std::vector<int> &age);

int main(){

    std::vector<int> age;
    std::vector<int> childrenNumber;
    std::vector<float> salaryVector;
    std::vector<char> sexVector;

    int age_input, children_number_input;
    float salary_input, residentesAvegageWage;
    char sex_input;

    float avarage_wage = 0.0; 
    int old, young;
    
    std::cout << "[*] Please, provide the following data:" << std::endl;
    

    int count = 0;
    do {
        count++;
        std::cout << "\n[*] Residente "<< count << std::endl;

        std::cout << "[*] Your age: ";
        std::cin >> age_input;

        std::cout << "[*] Number of children: ";
        std::cin >> children_number_input;
        
        std::cout << "[*] Salary: ";
        std::cin >> salary_input;

        std::cout << "[*] Sex(m/f): ";
        std::cin >> sex_input;

        
        
        registerAge(age_input, age);
        registerChildren(children_number_input, childrenNumber);
        registerSalary(salary_input, salaryVector);
        registerSex(sex_input, sexVector);

    } while (count < people);


    avarage_wage = averageWage(salaryVector);
    old = majorAge(age);
    
    std::cout << "\n[+] Avarage: U$ " << avarage_wage << std::endl;



    return 0;
}

void registerAge(int age, std::vector<int> &age_vector) {
    age_vector.push_back(age);
}

void registerChildren(int children, std::vector<int> &children_vector) {
    children_vector.push_back(children);
}

void registerSalary(float salary, std::vector<float> &salary_vector) {
    salary_vector.push_back(salary);
}

void registerSex(char char_sex, std::vector<char> &char_vector) {
    char_vector.push_back(char_sex);
}



float averageWage(std::vector<float> &salaryVector) {
    float x = 0;
    for (int i = 0; i < salaryVector.size(); i++)
    {
        x += salaryVector[i];
    }
    return x / (float) salaryVector.size();
}


int majorAge(std::vector<int> &age) {
    return 10;
}


