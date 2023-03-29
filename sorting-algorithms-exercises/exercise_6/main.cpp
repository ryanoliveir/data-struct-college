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



struct Person {
    std::string name;
    int age;
    char sex;

};


void registerPerson(std::string name, int age, char sex, std::vector<Person> &people);
void listPerson(const std::vector<Person>& people);

//bubble_sort_v3
void sortByAge(std::vector<Person> &vector);

//quicksort
void sortByName(std::vector<Person> &vector);

int partition(std::vector<Person>& vector, int begin, int end);
void quickSort(std::vector<Person>& vector, int begin, int end);

bool compareByName(const Person& person1, const Person& person2);

int main(){

    LOG console;
    console.enableColorMode();

    std::vector<Person> people;

    std::string name_input;
    int age_input, amount_people;
    char sex_input;


    

    console.sucess("[*] Please, provide the following data:");
    std::cout << console.blue() <<"\n[*] Amount of people: " << console.reset();
    std::cin >> amount_people;

    int count = 0;
    do {
        
        std::cout << "\n[*] People "<< count + 1 << std::endl;

        std::cout << "[*] Name: ";
        std::cin >> name_input;

        std::cout << "[*] Your age: ";
        std::cin >> age_input;

        std::cout << "[*] Sex(m/f): ";
        std::cin >> sex_input;

        registerPerson(name_input, age_input, sex_input, people);

        count++;
    } while (count < amount_people);

    sortByName(people);

    std::cout << console.blue() <<"\n[*] People registered (By Name): " << console.reset() << people.size() << std::endl;
    listPerson(people);
    std::cout << console.blue() <<"\n[*] ======================================== " << console.reset() << std::endl;




    sortByAge(people);


    std::cout << console.blue() <<"\n[*] People registered (By Age): " << console.reset() << people.size() << std::endl;
    listPerson(people);
    std::cout << console.blue() <<"\n[*] ======================================== " << console.reset() << std::endl;




}

void registerPerson(std::string name, int age, char sex, std::vector<Person> &people){
    
    Person person;

    person.name = name;
    person.age = age;
    person.sex = sex;
    

    people.push_back(person);

}

void listPerson(const std::vector<Person>& people){


    for (const auto& person : people) {
        std::cout << "[>] Name: "<<person.name << std::endl;
        std::cout << "    Age: "<< person.age << std::endl;
        std::cout << "    Sex: "<< person.sex << std::endl;
        std::cout << std::endl;
    }


}

//bubble_sort_v3
void sortByAge(std::vector<Person> &vector){

    int troca = 1;
    Person temporary_buffer;
    int iterations = 0;

    while (troca == 1) {
        
        troca = 0;

        for (int i = 0; i < vector.size() - 1; i++){

            if (vector[i].age < vector[i + 1].age) {

                troca = 1;
                temporary_buffer = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = temporary_buffer; 
            }
        }   
    
    }
}

//quicksort
int partition(std::vector<Person>& vector, int begin, int end) {
    Person pivot = vector[end];
    int i = begin;

    Person temp;

    for (int j = begin; j < end; j++) {
        if (compareByName(vector[j], pivot)) {
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


void quickSort(std::vector<Person>& vector, int begin, int end){

    if (begin < end) {
        int pivot = partition(vector, begin, end);
        quickSort(vector, begin, pivot - 1);
        quickSort(vector, pivot + 1, end);


    }
    

}


void sortByName(std::vector<Person>& vector){
    int begin = 0;
    int end = vector.size() - 1;

    quickSort(vector, begin, end);
}


bool compareByName(const Person& person1, const Person& person2) {
    return std::strcmp(person1.name.c_str(), person2.name.c_str()) < 0;
}