#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <iomanip>

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


struct Student {
    std::string name;
    float final_grade;
};

struct Node {
    Student student;
    Node* next;
    Node* previous;
};

struct DoublyLinkedList {
    Node* begin;
    Node* end;
    int size;
};

bool isEmpty(DoublyLinkedList& list);
void pause();

Student registerStudent();


void insertStudent(DoublyLinkedList& list, Student student);
void dumpStudents(DoublyLinkedList& list, std::string filter = "all");


const int AMOUNT_STUDENTS = 5;
const float AVERAGE = 7.0;

int main(){
    
    LOG log;

    DoublyLinkedList studentList = { nullptr, nullptr, 0};
    Student student;

    int count = 0;

    system("clear || cls");
    std::cout << "[Register of Students]"<< std::endl;

    do {
        std::cout << "\n["<< count + 1 <<"] Student"<< std::endl;
        student = registerStudent();
    
        insertStudent(studentList, student);
       
        // std::cout << student.name << std::endl;
        // std::cout << student.final_grade << std::endl;
        count++;


    } while (count < AMOUNT_STUDENTS);

    system("clear || cls");
    std::cout << "[Students]"<< std::endl;
    dumpStudents(studentList);

    std::cout << "[Approved Students]"<< std::endl;
    dumpStudents(studentList, "approved");

    pause();
    return 0;
}

bool isEmpty(DoublyLinkedList& list){
    if (list.begin == nullptr)
        return true;
    return false;
}

void pause(){
    std::cout << "Press any key to continue..." << std::endl;
    getch();
}

Student registerStudent() {
    std::string name;
    float final_grade = 0.0;

    std::cout << "[?] Name: ";
    std::cin >> name;

    std::cout << "[?] Final grade: ";
    std::cin >> final_grade;

    Student student = { name, final_grade };

    return student;
};

void insertStudent(DoublyLinkedList& list, Student student){
    Node* new_node = new Node();
    new_node->student = student;

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


void insertStudent(DoublyLinkedList& list, Student* student) {
    Node* new_node = new Node();
    new_node->student = *student;

    if (isEmpty(list)) {
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

void dumpStudents(DoublyLinkedList& list, std::string filter){
    if(!isEmpty(list)){
        Node *tmp_node = list.begin;


        std::cout << std::endl;
        std::cout << std::left << std::setw(20) << "Name";
        std::cout << std::setw(10) << "Grade" << std::endl;


        if(filter == "approved"){
            while (tmp_node != nullptr) {

                if (tmp_node->student.final_grade >= AVERAGE){
                    std::cout << std::setw(20) << tmp_node->student.name;
                    std::cout << std::setw(10) << std::fixed << std::setprecision(2) << tmp_node->student.final_grade << std::endl;
                }

            tmp_node = tmp_node->next;

            }          

            return;
        }

        while (tmp_node != nullptr) {
            std::cout << std::setw(20) << tmp_node->student.name;
            std::cout << std::setw(10) << std::fixed << std::setprecision(2) << tmp_node->student.final_grade << std::endl;
            tmp_node = tmp_node->next;
        }

        // std::cout << "\n[+] List size: " << list.size << std::endl;
    } else {
        std::cout << std::endl << "[!] Empty list...";
    }
}

