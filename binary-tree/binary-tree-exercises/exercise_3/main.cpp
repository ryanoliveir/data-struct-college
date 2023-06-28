#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <bits/stdc++.h>


using namespace std;

// #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

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

#define COUNT 10


struct BinaryTree{
    int data;
    BinaryTree *left, *right;
};

LOG console;

void continueAndClear();
int menu();

BinaryTree* insert(BinaryTree* tree, int value);
bool search(BinaryTree* tree, int value, bool found);
void sortedDisplay(BinaryTree* tree);
BinaryTree* getRightSubtree(BinaryTree* tree, int value);
bool isEmpty(BinaryTree *tree);


int main(){
    console.enableColorMode();
   
    BinaryTree *root = nullptr;
    BinaryTree *subtree = nullptr;

    int choice, input_value;
    bool found = false;
    
    
    do {
        choice = menu();

        switch (choice) {
            case 1: 
                cout << console.highlight << "[*] Insert a number on Binary Tree [*]" << console.reset << endl;
                cout << endl << console.highlight << "[?]" << console.reset << " Provide the number: ";
                cin >> input_value;

                root = insert(root, input_value);
                
                continueAndClear();
                break;

            case 2:
                cout << console.highlight << "[*] Query the entire Tree in order [*]" << console.reset << endl;
                if (!isEmpty(root))
                    sortedDisplay(root);
                else 
                    cout << endl <<  console.error << "[!] Empty tree [!]" << console.reset << endl;

                continueAndClear();
                break;
            case 3:
                if (!isEmpty(root)){
                    cout << console.highlight << "[*] Query a tree node [*]" << console.reset << endl;
                    cout << endl << console.highlight << "[?]" << console.reset << " Provide the node value: ";
                    cin >> input_value;

                    found = search(root, input_value, found);
                    found == true ? cout << endl << console.highlight << "[*] Node found [*]" << console.reset << endl : cout << endl << console.error << "[!] Node not found [!]" << console.reset << endl;
                    //randomBSTree(11, 6, 14, 3, 7, 13, 15, n, 4)
                    if(found){
                        subtree = getRightSubtree(root, input_value);
                        cout << "[+] Node value: " << subtree->data << endl;

                        if(subtree->right != nullptr ){
                            cout << "[+] Right subtree value: " << subtree->right->data << endl;
                        }else {
                            cout << "[+] Right subtree doesn't exist" << endl;
                        }

                        if(subtree->left != nullptr ){
                            cout << "[+] Left subtree value: " << subtree->left->data << endl;
                        }else {
                            cout << "[+] Left subtree doesn't exist"<< endl;
                        }

                        if(!(subtree->left == nullptr) && !(subtree->right != nullptr)){
                            cout << "[+] The current node doesn't contain subtrees" << endl;
                        }

                    }


                }
                else 
                    cout << endl << console.error << "[!] Empty tree [!]" << console.reset << endl;

                continueAndClear();
                break;
            case 4:
                if (!isEmpty(root)){
                    cout << console.highlight << "[*] Query a tree node [*]" << console.reset << endl;
                    cout << endl << console.highlight << "[?]" << console.reset << " Provide the node value: ";
                    cin >> input_value;

                    found = search(root, input_value, found);
                    found == true ? cout << endl << console.highlight << "[*] Node found [*]" << console.reset << endl : cout << endl << console.error << "[!] Node not found [!]" << console.reset << endl;
                    //randomBSTree(11, 6, 14, 3, 7, 13, 15, n, 4)
                    if(found){
                        subtree = getRightSubtree(root, input_value);
                        cout << "[+] Node value: " << subtree->data << endl;

                        if(subtree->left != nullptr ){
                            cout << "[+] Left subtree value: " << subtree->left->data << endl;
                        }else {
                            cout << "[+] Left subtree doesn't exist" << endl;
                        }

                        if(!(subtree->left == nullptr) && !(subtree->right != nullptr)){
                            cout << "[+] The current node doesn't contain subtrees" << endl;
                        }

                    }
                }
                else 
                    cout << endl << console.error << "[!] Empty tree [!]" << console.reset << endl;

                continueAndClear();
                break;

            

        }  

    } while (choice != 5);

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
        cout << console.highlight << "[*]" << console.underline << " Menu - Arvore " << console.reset << console.highlight << "[*]" << console.reset << endl << endl;

        cout << console.gray << "[1]" << console.reset << " - Insert number" << endl;
        cout << console.gray << "[2]" << console.reset << " - Show all" << endl;
        cout << console.gray << "[3]" << console.reset << " - Show the right subtree of a node" << endl;
        cout << console.gray << "[4]" << console.reset << " - Show the left subtree of a node" << endl;
        cout << console.gray << "[5]" << console.reset << " - Exit" << endl << endl;

        cout << console.highlight << "[?]" << console.reset << " Insira sua escolha: ";
        cin >> choice;

        if(choice < 1 || choice > 4) {
            cout << console.error << endl << "[!] Valor invalido! Tente novamente [!]" << console.reset << endl;
            continueAndClear();
        }
    } while (choice < 1 || choice > 4);
    system("CLS||CLEAR");
    return choice;
}


//37 40 44 47 49
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
        else if(value < tree->data) 
            found = search(tree->left, value, found);
        else 
            found = search(tree->right, value, found);
    }

    
    return found;
}

void sortedDisplay(BinaryTree* tree){
    if(!isEmpty(tree))
    {
        sortedDisplay(tree->left);
        cout << tree->data << " ";
        sortedDisplay(tree->right);
    }
}

BinaryTree* getRightSubtree(BinaryTree* tree, int value) {
    if(!isEmpty(tree)){
        if(tree->data == value)
            return tree;
        else if(tree->data < value)
            return getRightSubtree(tree->right, value);
        else 
            return  getRightSubtree(tree->left, value);
    }

    return nullptr;
}

