#include <iostream>
// #include <cstdlib>
#include <string>
#include <utility>
#include <vector>


const int people = 3;

void registerAge(int age, std::vector<int> &age_vector);
void registerChildren(int children, std::vector<int> &children_vector);
void registerSalary(float salary, std::vector<float> &salary_vector);
void registerSex(char char_sex, std::vector<char> &char_vector);


float averageWage(std::vector<float> &salaryVector);
std::pair<int, int> max_min_Age(const std::vector<int> &age);
// int womenStatistics (const std::vector<int> &children_vector, const std::vector<float> &salary_vector, const std::vector<char> sex_vector);
int womenStatistics (const std::vector<int> &children_vector, const std::vector<float> &salary_vector, const std::vector<char>& sex_vector);

int main(){

    std::vector<int> age;
    std::vector<int> childrenNumber;
    std::vector<float> salaryVector;
    std::vector<char> sexVector;

    int age_input, children_number_input;
    float salary_input, residentesAvegageWage;
    char sex_input;

    float avarage_wage = 0.0; 
    std::pair<int, int>  ages;
    int womanWithThreeChild;
    
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
    ages = max_min_Age(age);
    womanWithThreeChild = womenStatistics(childrenNumber, salaryVector, sexVector);
    
    std::cout << "\n[+] Avarage: U$ " << avarage_wage << std::endl;
    std::cout << "[+] Older: "<< ages.first << " years" << std::endl;
    std::cout << "[+] Younger: "<< ages.second << " years" << std::endl;

    std::cout << "[+] Number of women with 3 children (U$ 500): " << womanWithThreeChild << std::endl;


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
    for (int i = 0; i < salaryVector.size(); i++) {
        x += salaryVector[i];
    }

    return x / (float) salaryVector.size();

}


std::pair<int, int> max_min_Age(const std::vector<int> &age) {

    int max_Age = age[0];
    int min_Age = age[0];

    for (const auto &age_value : age){ 
        if (max_Age > age_value) max_Age = age_value;
        if (min_Age < age_value) min_Age = age_value;
    }

    // for (int i = 1; i < age.size(); i++){
    //     if (max_Age > age[i]) max_Age = age[i];
    //     if (min_Age < age[i]) min_Age = age[i];
    // }

    return std::make_pair(max_Age, min_Age);

}

int womenStatistics (const std::vector<int> &children_vector, const std::vector<float> &salary_vector, const std::vector<char>& sex_vector) {
    int women_count = 0;
    for (const auto& sex : sex_vector) {
        if( sex == 'f') {
            const auto i = &sex - &sex_vector[0];
            if (children_vector[i] == 3 && salary_vector[i] <= 500.0){
                women_count++;
            }
        }
    }

    return women_count;

}

// int womenStatistics (const std::vector<int> &children_vector, const std::vector<float> &salary_vector, const std::vector<char> sex_vector) {
//     int women_count = 0;
//     for (int i = 0; i < sex_vector.size(); i++) {
//         if (sex_vector[i] == "f" && children_vector[i] == 3 && salary_vector[i] >= 500.0) {
//             women_count++;
//         }
//     }

//     return women_count;

// }




