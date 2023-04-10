#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <windows.h>

// Uncomment the following line to compile in DEV-C++
// #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

const int amount_products = 3; 
const int None = 0;

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


struct Product {
    int dsCode;
    std::string description;
    float price;
};


void registerProduct(int dsCode, std::string description, float price, std::vector<Product> &products);
void listProducts(const std::vector<Product>& products);

void quickSort(std::vector<Product>& vector, int begin, int end);
int partition(std::vector<Product>& vector, int begin, int end);
void sort(std::vector<Product>& vector);

bool sequencialSearchSorted(std::vector<Product>& vector, int target);
bool binarySearch(std::vector<Product>& vector, int target, int& comparisons, int begin = 0, int end = None);



int main(){
    LOG console;
    console.enableColorMode();


    std::vector<Product> products;

    int dsCode_input;
    std::string description_input;
    float price_input;

    int targetProduct, comparisons = 0;

    console.sucess("[*] Please, provide the following data:");
    
    int count = 0;
    do {
        std::cout << "\n[*] Product "<< count + 1 << std::endl;

        std::cout << "[*] Code: ";
        std::cin >> dsCode_input;

        std::cout << "[*] Description: ";
        std::cin >> description_input;

        std::cout << "[*] Price ($): ";
        std::cin >> price_input;

        registerProduct(dsCode_input, description_input, price_input, products);
        count ++;
    } while (count < amount_products);

    std::cout << console.blue() <<"\n[*] Products registered (Sorted): " << console.reset() << products.size() << std::endl;
    sort(products);
    listProducts(products);
    std::cout << console.blue() <<"\n[*] ======================================== " << console.reset() << std::endl;


    console.log("\n[SEARCH PRODUCTS]");
    std::cout << console.blue() <<"\n[*] Product CODE : " << console.reset();
    std::cin >> targetProduct;

    if(sequencialSearchSorted(products, targetProduct)){
        std::cout << console.green() << "\n[*]  The product 'CODE: "<< targetProduct <<"' was finded in vector" << std::endl;
    } else {
        std::cout << console.red() << "\n[*]  The product 'CODE: "<< targetProduct <<"' not finded" << std::endl;
    }


   
    if(binarySearch(products, targetProduct, comparisons)){
        std::cout << "\n[INFO] Verifications (Bynary): "<< comparisons << std::endl;
        std::cout << console.green() << "[*]  The product 'CODE: "<< targetProduct <<"' was finded in vector" << std::endl;
    } else {
        std::cout << "\n[INFO] Verifications (Bynary): "<< comparisons << std::endl;
        std::cout << console.red() << "[*]  The product 'CODE: "<< targetProduct <<"' not finded" << std::endl;
    }

}



void registerProduct(int dsCode, std::string description, float price, std::vector<Product> &products){
    Product product;

    product.dsCode = dsCode;
    product.description = description;
    product.price = price;

    products.push_back(product);

}

void listProducts(const std::vector<Product>& products){

    for (const auto& product : products) {
        std::cout << "[>] Code: "<< product.dsCode << std::endl;
        std::cout << "    Description: "<<  product.description << std::endl;
        std::cout << "    Price ($): "<<  product.price << std::endl;
        std::cout << std::endl;
    }


}

int partition(std::vector<Product>& vector, int begin, int end) {
    Product pivot = vector[end];
    int i = begin;

    Product temp;

    for (int j = begin; j < end; j++) {
        if (vector[j].dsCode <= pivot.dsCode ) {
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

void quickSort(std::vector<Product>& vector, int begin, int end){

    if (begin < end) {
        int pivot = partition(vector, begin, end);
        quickSort(vector, begin, pivot - 1);
        quickSort(vector, pivot + 1, end);


    }
    

}

void sort(std::vector<Product>& vector){
    int begin = 0;
    int end = vector.size() - 1;

    quickSort(vector, begin, end);
}

bool sequencialSearchSorted(std::vector<Product>& vector, int target){
    int verifications = 0;
    for (int i = 0; i < vector.size(); i++){
      
        verifications++;
        if (vector[i].dsCode == target) {
            std::cout << "[INFO] Verifications (Sequential): "<< verifications << std::endl;

            return true;
        }
        verifications++;
        if (!(target >= vector[i].dsCode)) {
            std::cout << "[INFO] Verifications (Sequential): "<< verifications << std::endl;

            return false;
        }
            
    }

    std::cout << "[INFO] Verifications (Sequential): "<< verifications << std::endl;
    return false;

}

bool binarySearch(std::vector<Product>& vector, int target, int& comparisons, int begin, int end){

    if (end == None ) end = vector.size() -1 ;

    if (begin <= end){
        int m = (begin + end) / 2;

        comparisons++;

        if(vector[m].dsCode == target) return true; // finded 

        if(target < vector[m].dsCode){
            comparisons++;
            return binarySearch(vector, target, comparisons, begin, m - 1);

        } else {
            comparisons++;
            return binarySearch(vector, target, comparisons, m + 1, end);

        }
    }

    return false;
}

