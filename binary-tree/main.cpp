#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

// #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

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

struct BinaryTree{
    int data;
    BinaryTree *left, *right;
};

void continueAndClear();
int menu();

BinaryTree* insert(BinaryTree* tree, int value);
bool search(BinaryTree* tree, int value, bool found);
void sortedDisplay(BinaryTree* tree);
bool isEmpty(BinaryTree *tree);


int main(){

    enableColorMode();
    BinaryTree *root = nullptr;

    int choice, input_value;
    bool found = false;

    do {
        choice = menu();

        switch (choice) {
            case 1: 
                cout << highlight << "[*] Inserir numero na Arvore [*]" << reset << endl;
                cout << endl << highlight << "[?]" << reset << " Numero que deseja inserir: ";
                cin >> input_value;

                root = insert(root, input_value);
                
                continueAndClear();
                break;

            case 2:
                cout << highlight << "[*] Consultar um noh da Arvore [*]" << reset << endl;
                cout << endl << highlight << "[?]" << reset << " Numero que deseja consultar: ";
                cin >> input_value;

                if (!isEmpty(root)){
                    found = search(root, input_value, found);
                    found == true ? cout << endl << highlight << "[*] Numero encontrado [*]" << reset << endl : cout << endl << error << "[!] Numero nao encontrado [!]" << reset << endl;
                }
                else 
                    cout << endl << error << "[!] Arvore vazia [!]" << reset << endl;

                continueAndClear();
                break;
            
            case 3:
                cout << highlight << "[*] Consultar toda a Arvore em ordem [*]" << reset << endl;
                if (!isEmpty(root))
                    sortedDisplay(root);
                else 
                    cout << endl << error << "[!] Arvore vazia [!]" << reset << endl;
                continueAndClear();

        }  

    } while (choice != 0);

    return 0;
}


void continueAndClear() {
    cout << endl << gray << "Pressione qualquer tecla para continuar..." << reset;
    getch();
    system("CLS||CLEAR");
}

int menu(){
   int choice;

    do {
        cout << highlight << "[*]" << underline << " Menu - Arvore " << reset << highlight << "[*]" << reset << endl << endl;

        cout << gray << "[1]" << reset << " - Inserir numero na Arvore" << endl;
        cout << gray << "[2]" << reset << " - Consultar um no da Arvore" << endl;
        cout << gray << "[3]" << reset << " - Consultar toda a Arvore em ordem" << endl;
        cout << gray << "[4]" << reset << " - Consultar toda a Arvore em pre-ordem" << endl;
        cout << gray << "[5]" << reset << " - Consultar toda a Arvore em pos-ordem" << endl;
        cout << gray << "[6]" << reset << " - Excluir um no da Arvore" << endl;
        cout << gray << "[7]" << reset << " - Esvaziar a arvore" << endl;
        cout << gray << "[0]" << reset << " - Sair" << endl << endl;

        cout << highlight << "[?]" << reset << " Insira sua escolha: ";
        cin >> choice;

        if(choice < 0 || choice > 7) {
            cout << error << endl << "[!] Valor invalido! Tente novamente [!]" << reset << endl;
            continueAndClear();
        }
    } while (choice <0 || choice > 7);
    system("CLS||CLEAR");
    return choice;
}


bool isEmpty(BinaryTree *tree){
    return tree == nullptr ? true : false;
}

BinaryTree* insert(BinaryTree* tree, int value){
    if(isEmpty(tree)){
        tree = new BinaryTree;
        tree->data = value;
        tree->left = nullptr;
        tree->right = nullptr;
    } 
    else if (value < tree->data)
        tree->left = insert(tree->left, value);
    else
        tree->right = insert(tree->right, value);

    return tree;
}


bool search(BinaryTree* tree, int value, bool found){

    if(!isEmpty(tree) && !found){
        if(tree->data == value)
            found = true;
        else if(tree->data > value)
            found = search(tree->right, value, found);
        else 
            found = search(tree->left, value, found);
    }

    return found;
}

void sortedDisplay(BinaryTree* tree){
    if(!isEmpty(tree))
    {
        sortedDisplay(tree-> left);
        cout << tree->data << " ";
        sortedDisplay(tree-> right);
    }
}
