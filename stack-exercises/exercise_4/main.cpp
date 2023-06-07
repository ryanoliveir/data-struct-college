#include <iostream>
#include <string>
#include <conio.h>
#include <conio.h>

struct Stack {
    int number;
    Stack* next;
    Stack* top;
};

struct Queue {
    int number;
    Queue* front;
    Queue* back;
    Queue* next;
};

void header();
void pause();

void pushStack(Stack& stack, int data);
void pushQueue(Queue& queue, int data);

void printNumberBox(int number, std::string type="stack");

void dumpStack(Stack& stack);

void populateQueue(Stack& stack, Queue& queue, std::string filter="none");
void dumpQueue(Queue& queue, std::string filter="all");


int main(){

    Stack stack = { 0, nullptr, nullptr };
    Queue queuePairNumbers = { 0, nullptr, nullptr, nullptr};
    Queue queueOddNumbers = { 0, nullptr, nullptr, nullptr};

    int number;

    system("cls||clear");

    do {
       header();
       std::cout << "\n[*] > ";
       std::cin >> number;
       
       if(number <= 0) {
            std::cout << "\n[+] Done... :)" << std::endl;
        } else {
            pushStack(stack, number);
        }

        system("cls||clear");

    } while (number > 0);


    dumpStack(stack);

    std::cout << "\n[Queue with Pairs Numbers]" << std::endl;
    populateQueue(stack, queuePairNumbers, "pair");
    dumpQueue(queuePairNumbers);

    populateQueue(stack, queueOddNumbers, "ood");
    std::cout << "\n[Queue with Odd Numbers]" << std::endl;
    dumpQueue(queueOddNumbers);

    pause();


    return 0;
}

void header(){
    std::cout << std::endl << "[Stack & Queue]" << std::endl;
    std::cout << "[*] Please provide integer numbers: " << std::endl;
    std::cout << "[?] Type 0 or less to end [?]" << std::endl;
}

void pause(){
    std::cout << "\nPress any key to continue..." << std::endl;
    getch();
}

void pushStack(Stack& stack, int data){
    Stack* stackElement = new Stack();
    stackElement->number = data;
    stackElement->next = stack.top;
    stack.top = stackElement;

    // std::cout << "[!] Number "<< data << " inserted"<< std::endl;
}

void pushQueue(Queue& queue, int data){
    Queue* queueElement = new Queue();
    queueElement->number = data;
    queueElement->next = nullptr;

    if(queue.front == nullptr){
        queue.front = queueElement;
        queue.back = queueElement;
    } else {
        queue.back->next = queueElement;
        queue.back = queueElement;
    }
}

void printNumberBox(int number, std::string type) {

    if(!(type != "stack")){
        std::cout << "\t[" << number << "]" << std::endl;
        return;
    }

    std::cout << "[" << number << "] ";
    return;

}


void dumpStack(Stack& stack){
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

void populateQueue(Stack& stack, Queue& queue, std::string filter){
    Stack* tmpStackType = stack.top;

    if(tmpStackType == nullptr){
        std::cout << std::endl << "[!] Empty list...";
        return;
    } else {

        while(tmpStackType != nullptr){

            if(filter == "pair")
                if (tmpStackType->number % 2 == 0) pushQueue(queue, tmpStackType->number);

            if (filter == "ood")
                if (tmpStackType->number % 2 != 0) pushQueue(queue, tmpStackType->number);


            tmpStackType = tmpStackType->next;
        }
    }
}

void dumpQueue(Queue& queue, std::string filter) {
    Queue* tmpQueueType = queue.front;

    if(tmpQueueType == nullptr){
        std::cout << std::endl << "[!] Empty Queue...";
        return;
    } else {
        // std::cout << "\n[Queue]" << std::endl;
        std::cout << "\t";
        while(tmpQueueType != nullptr){
            printNumberBox(tmpQueueType->number,"queue");
            tmpQueueType = tmpQueueType->next;
        }
    }
}


