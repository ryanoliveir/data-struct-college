#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

struct Stack {
    int number;
    Stack* next;
    Stack* top;
};


int menu();
void pause();
void push(Stack& stack, int data);
void pop();
void empytStack();

void printNumberBox(int number);
void dump(Stack& stack, std::string filter="all");

int main(){

    Stack stack = { 0, nullptr, nullptr };

    int choice , input_number;

    do {
        system("cls||clear");
        choice = menu();

        switch (choice)
        {
        case 1:
            std::cout << "[?] Provide a number: ";
            std::cin >> input_number;
            push(stack, input_number);
            pause();
            break;

        case 2:
            std::cout << "[?] Dumping in stack..." << std::endl;
            dump(stack);
            pause();
            break;

        case 3:
            std::cout << "[?] Removing da stack..." << std::endl;
            // pop(stack);
            break;

        case 4:
            std::cout << "[?] Empty stack..." << std::endl;
            // empytStack(&stack);
            break;
        default:
            std::cout << "[-] Saindo..." << std::endl;
        }
    } while (choice != 0);

    return 0;


    return 0;
}



int menu(){
    int option;

    do {

        std::cout << std::endl << " MENU OPTIONS" << std::endl;
        std::cout << "[1] Insert in Stack" << std::endl;
        std::cout << "[2] Dump stack" << std::endl;
        std::cout << "[3] Print the entire list" << std::endl;
        std::cout << "[4] Search a value in list" << std::endl;
        std::cout << "[5] pop from the list" << std::endl;
        std::cout << "[6] Empty the list" << std::endl;
        std::cout << "[7] Exit" << std::endl;

        std::cout << "Enter your choice" << std::endl;
        std::cin >> option;
        if (option < 1 || option > 6)
            std::cout << "\tInvalid choice" << std::endl;
    } while (option < 1 || option > 6);

    return option;
}

void pause(){
    std::cout << "Press any key to continue..." << std::endl;
    getch();
}


void push(Stack& stack, int data){
    Stack* stackElement = new Stack();
    stackElement->number = data;
    stackElement->next = stack.top;
    stack.top = stackElement;

    std::cout << "[!] Number "<< data << " inserted"<< std::endl;
}



void printNumberBox(int number) {
    std::cout << "\t[" << number << "]" << std::endl;
}

void dump(Stack& stack, std::string filter){
    Stack* tmpStackType = stack.top;

    if(tmpStackType == nullptr){
        std::cout << std::endl << "[!] Empty list...";
        return;
    } else {
        std::cout << "\n[Stack]" << std::endl;
        while(tmpStackType != nullptr){
            printNumberBox(tmpStackType->number);
            tmpStackType = tmpStackType->next;
        }
    }


}


