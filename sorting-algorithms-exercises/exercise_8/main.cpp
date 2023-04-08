#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <windows.h>
// g++ -std=gnu++11 -o main ./main.cpp


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
};



struct House {
    std::string identifier;
    std::string neighborhood;
    float sale, rent;

};

const int amount_houses = 3;

void registerHouse(std::string id, std::string neighborhood, float sale, float rent, std::vector<House>& houses);
void listHouse(const std::vector<House>& houses);

void sortBySale(std::vector<House> &vector);

int main(){

    LOG console;
    console.enableColorMode();
    std::vector<House> houses;

    std::string identifier_input, neighborhood_input;
    float sale, rent;



    console.sucess("[*] Please, provide the following data:");

    int count = 0;
    do {
        
        std::cout << "\n[*] House "<< count + 1 << std::endl;

        std::cout << "[*] ID: ";
        std::cin >> identifier_input;

        std::cout << "[*] Neighborhood: ";
        std::cin >>  neighborhood_input;
        
        std::cout << "[*] Sale: ";
        std::cin >> sale;

        std::cout << "[*] Rent: ";
        std::cin >> rent;

        
        registerHouse(identifier_input, neighborhood_input, sale, rent, houses);

        count++;
    } while (count < amount_houses);

    std::cout << console.blue() <<"\n[*] Houses registered: " << console.reset() << houses.size() << std::endl;
    listHouse(houses);


    sortBySale(houses);

    std::cout << console.yellow() <<"\n[*] Houses registered (sorted by sale value): " << console.reset() << houses.size() << std::endl;
    listHouse(houses);
}

void registerHouse(std::string id, std::string neighborhood, float sale, float rent, std::vector<House>& houses){

    House house;

    house.identifier = id;
    house.neighborhood = neighborhood;
     house.sale = sale;
     house.rent = rent;

    houses.push_back(house);  
}


void listHouse(const std::vector<House>& houses){


    for (const auto& house : houses) {
        std::cout << "[>] ID: "<< house.identifier << std::endl;
        std::cout << "    Neighborhood: "<< house.neighborhood << std::endl;
        std::cout << "    Sale: "<< house.sale << std::endl;
        std::cout << "    Rent: "<< house.rent << std::endl;
        std::cout << std::endl;
    }


}

void sortBySale(std::vector<House> &vector){
    int troca = 1;
    House temporary_buffer;
    int iterations = 0;

    while (troca == 1) {
        
        troca = 0;

        for (int i = 0; i < vector.size() - 1; i++){

            if (vector[i].sale < vector[i + 1].sale) {

                troca = 1;
                temporary_buffer = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = temporary_buffer; 
            }
        }   
    
    }
}