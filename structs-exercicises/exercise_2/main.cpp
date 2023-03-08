#include <iostream>
#include <string>
#include <vector>
#include <set>


const int people = 2;

struct Resident{
    std::string ID;
    int age, numberOfChildren;
    float salary;
    char sex;
};

void registerResidente(int age, int children, float salary, char sex, std::vector<Resident> &residents, std::set<int> &uniqueIDs);
std::string uniqueID(std::set<int> &setOfIDs);
float averageWage(std::vector<Resident> &residents);

int main(){

    

    std::vector<Resident> residents;

    std::set<int> uniqueIDs;

    int age_input, children_number_input;
    float salary_input, residentesAvegageWage;
    char sex_input;

    
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

        
        registerResidente(age_input, children_number_input, salary_input, sex_input, residents, uniqueIDs);

    } while (count < people);


    residentesAvegageWage = averageWage(residents);
    std::cout << "\n[+] Average Wage: U$ " << residentesAvegageWage << std::endl;


    return 0;
}



std::string uniqueID(std::set<int> &setOfIDs){
    srand(time(0)); // semente para a função rand() ser mais aleatória
    
    // std::set<int> uniqueIDs;
    int num[4], numberGenereted;


    do {
        for (int i = 0; i < 4; i++){
            num[i] = rand() % 10;        
        }

        numberGenereted = num[0]*1000 + num[1]*100 + num[2]*10 + num[3];

    } while (setOfIDs.find(numberGenereted) != setOfIDs.end());
    
    setOfIDs.insert(numberGenereted);

    return std::to_string(numberGenereted);
}



void registerResidente(int age, int children, float salary, char sex, std::vector<Resident> &residents, std::set<int> &uniqueIDs){
    // std::cout << age << std::endl;
    // std::cout << salary << std::endl;
    // std::cout << sex<< std::endl;
    
    Resident resident;

    resident.ID = uniqueID(uniqueIDs);
    resident.age = age;
    resident.numberOfChildren = children;
    resident.salary = salary;
    resident.sex = sex;


    // std::cout << resident.ID << std::endl;
    // std::cout << resident.age << std::endl;
    // std::cout << resident.salary << std::endl;
    // std::cout << resident.sex << std::endl;

    residents.push_back(resident);

    
}

float averageWage(std::vector<Resident> &residents){

    float x = 0;
    for (int i = 0; i < residents.size(); i++)
    {
        x += residents[i].salary;
    }

    // std::cout << x / (float) residents.size() << std::endl;

    return x / (float) residents.size();



}


