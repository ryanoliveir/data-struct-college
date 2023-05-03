#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

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
};

struct LinkedList {
    Node *start;
    Node *end;
    int size;
};

void pause();

int showOptions();

bool emptyCheck(LinkedList *list);
void headInsert(LinkedList *list, int number);

void dumpElementsRecursive(Node *current_node);
void dumpElements(LinkedList *list);

bool searchElementRecursive(Node *current_node, int number_input);
bool searchElement(LinkedList *list, int number_input);

bool verifyAscendingOrder(LinkedList *list);


int main(){

    LOG console;
    console.enableColorMode();

    LinkedList list = { nullptr, nullptr, 0 }; 

    
    int chose, number_input;
    bool finded, acending_order;
    
    do {

        system("cls");
        chose  = showOptions();

        switch (chose) {
            case 1:
                system("cls");
                std::cout << "[?] Provide the integer number to insert: ";
                std::cin >> number_input;
                headInsert(&list, number_input);
                break;

            case 2:
                system("cls");
                std::cout << "[+] Dumping list..." << std::endl;
                dumpElements(&list);
                system("pause");
                break;
            
            case 3:
                system("cls");
                std::cout << "[?] Provide the integer number to search: ";
                std::cin >> number_input;
                finded = searchElement(&list, number_input);

                finded == true ? std::cout << "[+] Finded\n" : std::cout << "[-] Not found\n" << std::endl; 
                pause();
                break;

            case 4:
                system("cls");
                acending_order = verifyAscendingOrder(&list);
                acending_order == true ? std::cout << "[+] Arcending order: True \n" : std::cout << "[-] Arcending order: False\n" << std::endl;
                pause();
                break;

            default:
                break;
            
        }

    } while (chose != 5);

    return 0;
}



int showOptions(){
    int option;

	do
	{
		std::cout << "MENU OPTIONS" << std::endl;
		std::cout << "[?] Select an option\n" << std::endl;
		std::cout << "[1] Insert" << std::endl;
        std::cout << "[2] View" << std::endl;
		std::cout << "[3] Search" << std::endl;
		std::cout << "[4] Verify" << std::endl;
		std::cout << "[5] Exit" << std::endl;


		std::cout << "[?] > ";
		std::cin >> option;

		if(option < 1 || option > 5)
			std::cout << "\tEscolha invalida!" << std::endl;

	} while (option < 1 || option > 5);

	return option;
}

void pause(){
    std::cout << "Press any key to continue...";
    getch();
}

bool emptyCheck(LinkedList *list){
    if(list->start == nullptr )
        return true;
    return false;
}

void headInsert(LinkedList *list, int number){
    Node *new_node = new Node();
    new_node->number = number;
    new_node->next = nullptr;

    if(emptyCheck(list)){
        new_node->next = nullptr;
        list->start = new_node;
        list->end = new_node;
    } else {
        new_node->next = list->start;
        list->start = new_node;
    }

    list->size++;
}


void dumpElementsRecursive(Node *current_node){
    if(current_node == nullptr) return;

    std::cout << "(" <<current_node <<")[ "<< current_node->number << " | " << current_node->next << " ]" << std::endl;

    dumpElementsRecursive(current_node->next);
}

void dumpElements(LinkedList *list){
    if (emptyCheck(list)) {
        std::cout << "[!] List empty" << std::endl;
        return;
    }

    dumpElementsRecursive(list->start);
}

// void dumpElements(LinkedList *list){

    

//     if (emptyCheck(list)) {
//         std::cout << "[!] List empty" << std::endl;
//         return;
//     }

//     Node *auxNode = list->start;

//     std::cout << "(node_address)[ value | next_address ]" << std::endl;
//     while (auxNode != nullptr) {
//         std::cout << "(" << auxNode <<")[ "<< auxNode->number << " | " << auxNode->next << " ]" << std::endl;
        
//         auxNode = auxNode->next;
//     }


//     std::cout << "[!] List size: "<< list->size << std::endl;
//     std::cout << std::endl;
    

// }


bool searchElementRecursive(Node* current_node, int number_input){
    if (current_node == nullptr) {
        return false;
    }
    if (current_node->number == number_input) {
        return true;
    }
    return searchElementRecursive(current_node->next, number_input);
}

bool searchElement(LinkedList* list, int number_input) {
    if (emptyCheck(list)) {
        std::cout << "[!] List empty" << std::endl;
        return false;
    }
    return searchElementRecursive(list->start, number_input);
}

// bool searchElement(LinkedList *list, int number_input){
//     if (emptyCheck(list)) {
//         std::cout << "[!] List empty" << std::endl;
//         return false;
//     }

//     Node *auxNode = list->start;

//     while (auxNode != nullptr) {
//         if (auxNode->number == number_input)
//             return true;
//         auxNode = auxNode->next;
//     }

//     return false;
// }

bool verifyAscendingOrder(LinkedList *list){
    if (emptyCheck(list)) {
        std::cout << "[!] List empty" << std::endl;
        return false;
    }   

    Node *auxNode_one = list->start;
    Node *auxNode_two = auxNode_one->next;

    while(auxNode_two != nullptr) {
        std::cout << auxNode_one->number << "  < " << auxNode_two->number << " " << std::endl;
        if (!auxNode_one->number < auxNode_two->number)
            return false;

        auxNode_one = auxNode_two;
        auxNode_two = auxNode_one->next;
    }

    return true;
}
