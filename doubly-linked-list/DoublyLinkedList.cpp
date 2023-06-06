#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

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

        void enableUTF8Mode() {
            SetConsoleOutputCP(65001); // UTF-8 mode
        }
};



struct Node {
    int number;
    Node *next;
    Node *previous;
};

struct DoubleLinkedList {
    Node *begin, *end;
    int size;
};

int menu();
void pause();


bool isEmpty(DoubleLinkedList& list);

void insertHead(DoubleLinkedList& list, int data);
void insertTail(DoubleLinkedList& list, int data);

void showDoubleLinkedList(DoubleLinkedList& list);

bool searchInDoubleLinkedList(DoubleLinkedList& list, int data);

int main(){
     
     DoubleLinkedList list = { nullptr, nullptr, 0};

    int choice, input_number;

    do {

        system("cls||clear");
        choice = menu();

        switch (choice)
        {
        case 1:
            std::cout << "[?] Provide a number: ";
            cin >> input_number;
            insertHead(list, input_number);
            pause();
            break;

        case 2:
            std::cout << "[?] Provide a number: ";
            cin >> input_number;
            insertTail(list, input_number);
            pause();
            break;

        case 3:
            std::cout << "[+] List: ";
            showDoubleLinkedList(list);
            pause();
            break;

        case 4:
            std::cout << "[?] Provide a number to search: ";
            std::cin >> input_number;
            searchInDoubleLinkedList(list, input_number);

        default:
            break;
        }

    } while (choice != 6);


    return 0;
}

int menu(){
    int option;

    do {

        std::cout << std::endl << " MENU OPTIONS" << std::endl;
        std::cout << "[1] Insert at the beginning of the list" << std::endl;
        std::cout << "[2] Insert at the end of the list" << std::endl;
        std::cout << "[3] Print the entire list" << std::endl;
        std::cout << "[4] Search a value in list" << std::endl;
        std::cout << "[5] Remove from the list" << std::endl;
        std::cout << "[6] Empty the list" << std::endl;
        std::cout << "[7] Exit" << std::endl;

        std::cout << "Enter your choice" << std::endl;
        cin >> option;
        if (option < 1 || option > 6)
            std::cout << "\tInvalid choice" << std::endl;
    } while (option < 1 || option > 6);

    return option;
}

void pause(){
    std::cout << "Press any key to continue..." << std::endl;
    getch();
}


bool isEmpty(DoubleLinkedList& list){
    if (list.begin == nullptr)
        return true;
    return false;
}

void insertHead(DoubleLinkedList& list, int data){
    Node* new_node = new Node();
    new_node->number = data;

    if(isEmpty(list)){
        new_node->next = nullptr;
        new_node->previous = nullptr;
        list.begin = new_node;
        list.end = new_node;
    } else {
        new_node->next = list.begin;
        new_node->previous = nullptr;
        list.begin->previous = new_node;
        list.begin = new_node;
    }

    list.size++;
}

void insertTail(DoubleLinkedList& list, int data){
    Node* new_node = new Node();
    new_node->number = data;

    if(isEmpty(list)){
        new_node->next = nullptr;
        new_node->previous = nullptr;
        list.begin = new_node;
        list.end = new_node;
    } else {
        list.end->next = new_node;
        new_node->previous = list.end;
        new_node->next = nullptr;
        list.end = new_node;
    }

    list.size++;
}

void showDoubleLinkedList(DoubleLinkedList& list){
    if(!isEmpty(list)){
        Node *tmp_node = list.begin;

        while (tmp_node != nullptr) {
            std::cout << tmp_node->number << " ";
            tmp_node = tmp_node->next;
        }

        std::cout << "\n[+] List size: " << list.size << std::endl;
    } else {
        std::cout << std::endl << "[!] Empty list...";
    }
}

bool searchInDoubleLinkedList(DoubleLinkedList& list, int data){
    if(!isEmpty(list)){
        std::cout << "[!] List empty..." << std::endl;
        return false;
    }

    Node *tmp_node = list.begin;
    
    while (tmp_node != nullptr) {
        if (tmp_node->number == data)
            return true;
        tmp_node = tmp_node->next;
    }

    return false;
}

