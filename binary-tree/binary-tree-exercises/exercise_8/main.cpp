#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

class LOG {
    public:
        const string reset = "\033[0m",
        bold = "\033[1m",
        dim = "\033[2m",
        italic = "\033[3m",
        underline = "\033[4m",
        blink = "\033[5m",
        reverse = "\033[7m",
        hidden = "\033[8m",
        strikethrough = "\033[9m",
        black = "\033[30m",
        red = "\033[31m",
        green = "\033[32m",
        yellow = "\033[33m",
        blue = "\033[34m",
        magenta = "\033[35m",
        orange = "\033[48;2;255;165;0m",
        cyan = "\033[36m",
        white = "\033[37m",
        gray = "\033[90m",
        sucess = "\033[1m\033[3m\033[32m",
        error = "\033[1m\033[31m",
        highlight = "\033[1m\033[36m",
        yellowBG = "\033[43m",
        grayBG = "\033[47m",
        copperBG = "\033[48;5;166m";

        void enableColorMode() {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            GetConsoleMode(hOut, &dwMode);

            if (!GetConsoleMode(hOut, &dwMode)) {
                std::cerr << "Failed to get log mode" << std::endl;
                return;
            }  

            if (!(dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
                dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                if (!SetConsoleMode(hOut, dwMode)) {
                    std::cerr << "Failed to set log mode" << std::endl;
                    return;
                }
            }
        }
};

LOG console;


struct Student{
    int id, age;
    float height, academiaAverage;
    string name;
};

struct BinaryTree{
    Student* student;
    BinaryTree *left, *right;
};

void continueAndClear();
int menu();

void registerStudent(Student& student);
void printStudentData(const Student& student);
void printStudentTree(BinaryTree* tree);


BinaryTree* insert(BinaryTree* tree, Student* student);


int main(){
    console.enableColorMode();

    BinaryTree* root = nullptr;
    Student student = { 0, 0, 0.0f, 0.0f, ""};

    int choice, input_value;
    bool found = false;

    do{

        choice = menu();

        switch (choice)
        {
        case 1:
            cout << console.highlight << "[*] Insert Student Information [*]" << console.reset << endl;
            registerStudent(student);
            // printStudentData(student);

            root = insert(root, &student);
            printStudentTree(root);
            
            continueAndClear();
            break;
        
        default:
            break;
        }

    }while(choice != 7);
    

    return 0;
}

void continueAndClear() {
    cout << endl << console.gray << "Press any key to continue..." << console.reset;
    getch();
    system("CLS||CLEAR");
}

int menu(){
   int choice;

    do {
        cout << console.highlight << "[*]" << console.underline << " Menu - Student System " << console.reset << console.highlight << "[*]" << console.reset << endl << endl;

        cout << console.gray << "[1]" << console.reset << " - Insert a student" << endl;
        cout << console.gray << "[2]" << console.reset << " - Show the tallest student" << endl;
        cout << console.gray << "[3]" << console.reset << " - Show the oldest student" << endl;
        cout << console.gray << "[4]" << console.reset << " - Show the students who are of legal age" << endl;
        cout << console.gray << "[5]" << console.reset << " - Show the student with the highest academic average" << endl;
        cout << console.gray << "[6]" << console.reset << " - Show the student with the lowest academic average" << endl;
        cout << console.gray << "[7]" << console.reset << " - Exit" << endl << endl;

        cout << console.highlight << "[?]" << console.reset << " Enter your choice: ";

        cin >> choice;

        if(choice < 1 || choice > 7) {
            cout << console.error << endl << "[!] Valor invalido! Tente novamente [!]" << console.reset << endl;
            continueAndClear();
        }
    } while (choice < 1 || choice > 7);
    system("CLS||CLEAR");
    return choice;
}

bool isEmpty(BinaryTree *tree){
    return tree == nullptr ? true : false;
}

void registerStudent(Student& student) {
    cout << "\n[?]Enter student ID: ";
    cin >> student.id;

    cout << "[?]Enter student name: ";
    cin.ignore(); // Ignore the newline character from the previous input
    getline(cin, student.name);

    cout << "[?]Enter student age: ";
    cin >> student.age;

    cout << "[?]Enter student height: ";
    cin >> student.height;

    cout << "[?]Enter student academic average: ";
    cin >> student.academiaAverage;
}


void printStudentData(const Student& student) {
    cout << console.gray << "[+] Student Information:" <<  console.reset << endl;
    cout << console.gray << "[+] ID: " << student.id <<  console.reset << endl;
    cout << console.gray << "[+] Name: " << student.name <<  console.reset << endl;
    cout << console.gray << "[+] Age: " << student.age <<  console.reset << endl;
    cout << console.gray << "[+] Height: " << student.height <<  console.reset << endl;
    cout << console.gray << "[+] Academic Average: " << student.academiaAverage <<  console.reset << endl;
}


BinaryTree* insert(BinaryTree* tree, Student* student){
    if(isEmpty(tree)){
        tree = new BinaryTree;
        tree->student = student;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    else if(student->id < tree->student->id){
        tree->left = insert(tree->left, student);
    }else {
        tree->right = insert(tree->right, student);
    }

    return tree;
}


void printStudentTree(BinaryTree* tree){
    if(isEmpty(tree)){
        return;
    }

    printStudentTree(tree->left);

    Student* student = tree->student;
    cout << console.gray << "[+]Student Information:" <<  console.reset << endl;
    cout << console.gray << "[+]ID: " << student->id <<  console.reset << endl;
    cout << console.gray << "[+]Name: " << student->name <<  console.reset << endl;
    cout << console.gray << "[+]Age: " << student->age <<  console.reset << endl;
    cout << console.gray << "[+]Height: " << student->height <<  console.reset << endl;
    cout << console.gray << "[+]Academic Average: " << student->academiaAverage <<  console.reset << endl;
    cout << console.gray << endl;

    printStudentTree(tree->right);
}

